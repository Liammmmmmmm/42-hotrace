/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syscall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 15:18:28 by ethebaul          #+#    #+#             */
/*   Updated: 2026/03/01 15:24:18 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*mmap(size_t length)
{
	void	*addr;

	__asm__ volatile (
		"mov $9, %%rax \n\t"
		"xor %%rdi, %%rdi \n\t"
		"mov %1, %%rsi \n\t"
		"mov $0x3, %%rdx \n\t"
		"mov $0x22, %%r10 \n\t"
		"mov $-1, %%r8 \n\t"
		"xor %%r9, %%r9 \n\t"
		"syscall \n\t"
		"mov %%rax, %0 \n\t"
		: "=r" (addr)
		: "r" (length)
		: "rax", "rdi", "rsi", "rdx", "r10", "r8", "r9", "rcx", "r11", "memory"
	);
	return (addr);
}

void	*mremap(void *old_addr, size_t old_size, size_t new_size)
{
	void	*new_addr;

	__asm__ volatile (
		"mov $25, %%rax \n\t"
		"mov %1, %%rdi \n\t"
		"mov %2, %%rsi \n\t"
		"mov %3, %%rdx \n\t"
		"mov $1, %%r10 \n\t"
		"syscall \n\t"
		"mov %%rax, %0 \n\t"
		: "=r" (new_addr)
		: "r" (old_addr), "r" (old_size), "r" (new_size)
		: "rax", "rdi", "rsi", "rdx", "r10", "rcx", "r11", "memory"
	);
	return (new_addr);
}
