#!/bin/bash

# ============================================================
#  Checker for hotrace (42 rush)
#  Usage: ./checker.sh <path_to_program> [tests_dir]
#
#  Test files structure (in tests/ folder):
#    XX_name.in   → input fed to the program via stdin
#    XX_name.out  → expected output
#
#  Add your own tests by creating matching .in / .out files.
# ============================================================

PROG="${1}"
TESTS_DIR="${2:-$(dirname "$0")/tests}"

# ---- Colors ----
GREEN="\033[0;32m"
RED="\033[0;31m"
YELLOW="\033[0;33m"
RESET="\033[0m"

if [ -z "$PROG" ]; then
    echo "Usage: $0 <path_to_program> [tests_dir]"
    echo "Example: $0 ./hotrace"
    echo "Example: $0 ./hotrace ./my_tests"
    exit 1
fi

if [ ! -x "$PROG" ]; then
    echo -e "${RED}Error: '$PROG' not found or not executable.${RESET}"
    echo "Did you compile? Try: gcc -o hotrace *.c"
    exit 1
fi

if [ ! -d "$TESTS_DIR" ]; then
    echo -e "${RED}Error: tests directory '$TESTS_DIR' not found.${RESET}"
    exit 1
fi

PASS=0
FAIL=0
TOTAL=0

# ---- Run each .in file that has a matching .out ----
for input_file in "$TESTS_DIR"/*.in; do
    [ -f "$input_file" ] || continue

    base="${input_file%.in}"
    expected_file="${base}.out"
    test_name=$(basename "$base")

    if [ ! -f "$expected_file" ]; then
        echo -e "${YELLOW}⚠️  [$test_name] No .out file found, skipping.${RESET}"
        continue
    fi

    TOTAL=$((TOTAL + 1))

    # Run the program with the input file as stdin
    actual=$("$PROG" < "$input_file" 2>/dev/null)
    exit_code=$?

    expected=$(cat "$expected_file")

    if [ "$actual" = "$expected" ]; then
        echo -e "${GREEN}✅  [$TOTAL] $test_name${RESET}"
        PASS=$((PASS + 1))
    else
        echo -e "${RED}❌  [$TOTAL] $test_name${RESET}"

        # Show a readable diff
        echo "    --- Expected ---"
        echo "$expected" | cat -A | sed 's/^/    /'
        echo "    --- Got --------"
        echo "$actual"   | cat -A | sed 's/^/    /'

        # If diff is available, show it nicely
        if command -v diff &>/dev/null; then
            echo "    --- Diff -------"
            diff <(echo "$expected") <(echo "$actual") | sed 's/^/    /'
        fi

        FAIL=$((FAIL + 1))
    fi
done

# ---- Summary ----
echo ""
echo "============================================"
if [ $FAIL -eq 0 ] && [ $TOTAL -gt 0 ]; then
    echo -e "  ${GREEN}Results: $PASS/$TOTAL passed 🎉${RESET}"
elif [ $TOTAL -eq 0 ]; then
    echo -e "  ${YELLOW}No tests found in '$TESTS_DIR'.${RESET}"
    echo "  Create files like: tests/01_mytest.in + tests/01_mytest.out"
else
    echo -e "  ${RED}Results: $PASS/$TOTAL passed ($FAIL failed)${RESET}"
fi
echo "============================================"

[ $FAIL -eq 0 ] && [ $TOTAL -gt 0 ]
exit $?
