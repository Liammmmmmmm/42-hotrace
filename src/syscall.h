/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syscall.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 18:29:13 by ethebaul          #+#    #+#             */
/*   Updated: 2026/03/01 18:37:02 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYSCALL_H
# define SYSCALL_H

typedef struct s_sched_param
{
	int	sched_priority;
}	t_sched_param;

int	set_max_niceness(void);
int	set_cpu_affinity(void);
int	set_realtime_scheduler(void);
int	set_best_scheduler(void);
int	set_batch_scheduler(void);

#endif