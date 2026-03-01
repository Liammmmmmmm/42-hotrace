/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syscall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 18:26:27 by ethebaul          #+#    #+#             */
/*   Updated: 2026/03/01 18:36:34 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syscall.h"

int	set_cpu_affinity(void)
{
	long			ret;

	__asm__ (
		"mov $203, %%rax \n\t"
		"xor %%rdi, %%rdi \n\t"
		"mov $8, %%rsi \n\t"
		"mov $1, %%rdx \n\t"
		"syscall \n\t"
		"mov %%rax, %[ret]"
		: [ret] "=r" (ret)
		:
		: "rax", "rdi", "rsi", "rdx", "rcx", "r11", "memory"
		);
	return (ret);
}

int	set_max_niceness(void)
{
	long	ret;

	asm (
		"mov $141, %%rax \n\t"
		"xor %%rdi, %%rdi \n\t"
		"xor %%rsi, %%rsi \n\t"
		"mov $-20, %%rdx \n\t"
		"syscall \n\t"
		"mov %%rax, %[ret]"
		: [ret] "=r" (ret)
		:
		: "rax", "rdi", "rsi", "rdx", "rcx", "r11"
		);
	return (ret);
}

int	set_best_scheduler(void)
{
	if (set_realtime_scheduler() < 0)
		return (set_realtime_scheduler());
	return (0);
}

int	set_realtime_scheduler(void)
{
	t_sched_param	param;
	long			ret;

	param.sched_priority = 99;
	asm (
		"mov $156, %%rax \n\t"
		"xor %%rdi, %%rdi \n\t"
		"mov $1, %%rsi \n\t"
		"mov %[param_ptr], %%rdx \n\t"
		"syscall \n\t"
		"mov %%rax, %[ret]"
		: [ret] "=r" (ret)
		: [param_ptr] "r" (&param)
		: "rax", "rdi", "rsi", "rdx", "rcx", "r11", "memory"
		);
	return (ret);
}

int	set_batch_scheduler(void)
{
	t_sched_param	param;
	long			ret;

	param.sched_priority = 0;
	asm (
		"mov $156, %%rax \n\t"
		"xor %%rdi, %%rdi \n\t"
		"mov $3, %%rsi \n\t"
		"mov %[param_ptr], %%rdx \n\t"
		"syscall \n\t"
		"mov %%rax, %[ret]"
		: [ret] "=r" (ret)
		: [param_ptr] "r" (&param)
		: "rax", "rdi", "rsi", "rdx", "rcx", "r11", "memory"
		);
	return (ret);
}
