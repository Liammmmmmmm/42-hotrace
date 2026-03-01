#!/usr/bin/env python3

# ============================================================
#  Checker hotrace — 42 rush
#  Usage: python3 checker.py <programme> <fichier_input>
#  Ex:    python3 checker.py ./hotrace big_file.txt
# ============================================================

import sys
import subprocess
import time

def usage():
    print("Usage: python3 checker.py <programme> <fichier_input>")
    print("Ex:    python3 checker.py ./hotrace big_file.txt")
    sys.exit(1)

if len(sys.argv) != 3:
    usage()

prog       = sys.argv[1]
input_file = sys.argv[2]

# ---- Lecture du fichier ----
print(f"[*] Lecture de {input_file} ...")
t0 = time.time()

try:
    with open(input_file, 'r') as f:
        lines = f.read().splitlines()
except FileNotFoundError:
    print(f"Erreur: fichier '{input_file}' introuvable.")
    sys.exit(1)

# ---- Parsing : séparer pairs et search keys ----
# Format: key\nvalue\nkey\nvalue\n...\n\nsearchkey\nsearchkey\n...

separator = None
for i, line in enumerate(lines):
    if line == '':
        separator = i
        break

if separator is None:
    print("Erreur: pas de ligne vide trouvée dans le fichier (séparateur manquant).")
    sys.exit(1)

pair_lines   = lines[:separator]
search_lines = [l for l in lines[separator+1:] if l != '']

# Construire le dictionnaire (last value wins pour les doublons)
dictionary = {}
i = 0
while i + 1 < len(pair_lines):
    key   = pair_lines[i]
    value = pair_lines[i+1]
    dictionary[key] = value
    i += 2

t_parse = time.time() - t0
print(f"[*] Parsing OK — {len(dictionary)} clés uniques, {len(search_lines)} recherches ({t_parse:.2f}s)")

# ---- Calcul des réponses attendues ----
expected_lines = []
for key in search_lines:
    expected_lines.append(dictionary.get(key, f"{key}: Not found."))

expected_output = '\n'.join(expected_lines) + '\n'

# ---- Lancement du programme ----
print(f"[*] Lancement de {prog} ...")
t1 = time.time()

try:
    result = subprocess.run(
        [prog],
        input=open(input_file, 'rb').read(),
        capture_output=True,
        timeout=30
    )
except FileNotFoundError:
    print(f"Erreur: programme '{prog}' introuvable. Compilé ?")
    sys.exit(1)
except subprocess.TimeoutExpired:
    print("❌  TIMEOUT — ton programme a dépassé 30 secondes.")
    sys.exit(1)

t_run = time.time() - t1
print(f"[*] Programme terminé en {t_run:.2f}s (exit code: {result.returncode})")

actual_output = result.stdout.decode('utf-8', errors='replace')

# ---- Comparaison ----
expected_list = expected_output.splitlines()
actual_list   = actual_output.splitlines()

errors   = []
max_show = 20  # nombre max d'erreurs affichées

for i, (exp, act) in enumerate(zip(expected_list, actual_list)):
    if exp != act:
        errors.append((i + 1, search_lines[i] if i < len(search_lines) else '?', exp, act))

# Lignes manquantes ou en trop
if len(actual_list) < len(expected_list):
    for i in range(len(actual_list), len(expected_list)):
        errors.append((i + 1, search_lines[i] if i < len(search_lines) else '?', expected_list[i], '<ligne manquante>'))
elif len(actual_list) > len(expected_list):
    for i in range(len(expected_list), len(actual_list)):
        errors.append((i + 1, '?', '<rien attendu>', actual_list[i]))

# ---- Résultat ----
print()
if not errors:
    print(f"✅  PASSED — {len(expected_list)} lignes correctes en {t_run:.2f}s")
else:
    print(f"❌  FAILED — {len(errors)} erreur(s) sur {len(expected_list)} lignes")
    print()
    print(f"{'Ligne':<8} {'Search key':<20} {'Attendu':<30} {'Obtenu'}")
    print("-" * 85)
    for line_no, key, exp, act in errors[:max_show]:
        exp_display = repr(exp) if exp == '' else exp
        act_display = repr(act) if act == '' else act
        print(f"{line_no:<8} {key:<20} {exp_display:<30} {act_display}")
    if len(errors) > max_show:
        print(f"  ... et {len(errors) - max_show} autres erreurs.")
