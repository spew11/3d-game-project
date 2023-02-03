/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjilee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:15:46 by eunjilee          #+#    #+#             */
/*   Updated: 2023/02/01 19:43:55 by eunjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"

int	q_empty(t_queue *q)
{
	if (!q->front)
		return (1);
	return (0);
}

void	q_append(t_queue *q, int *e)
{
	if (q_empty(q))
	{
		q->front = (t_node *)malloc(sizeof(t_node) * 1);
		if (!q->front)
			exit_error("malloc failed\n");
		q->front->content = e;
		q->front->next = 0;
		q->back = q->front;
	}
	else
	{
		q->back->next = (t_node *)malloc(sizeof(t_node) * 1);
		if (!q->back->next)
			exit_error("malloc failed\n");
		q->back->next->next = 0;
		q->back->next->content = e;
		q->back = q->back->next;
	}
	return ;
}

int	*q_pop(t_queue *q)
{
	t_node	*tmp;
	int		*e;

	tmp = q->front;
	e = q->front->content;
	q->front = q->front->next;
	free(tmp);
	return (e);
}

void	q_clear(t_queue *q)
{
	t_node	*tmp;

	while (q->front)
	{
		tmp = q->front;
		q->front = q->front->next;
		free(tmp->content);
		free(tmp);
	}
	free(q);
	return ;
}
