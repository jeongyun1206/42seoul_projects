/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_ele_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:55:35 by jnho              #+#    #+#             */
/*   Updated: 2022/12/21 15:16:48 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

t_deque_element	*new_deque_element(int data)
{
	t_deque_element	*new_element;

	new_element = (t_deque_element *)malloc(sizeof(t_deque_element));
	if (!new_element)
		return (0);
	new_element->front = 0;
	new_element->back = 0;
	new_element->data = data;
	return (new_element);
}

void	dq_push_front(t_deque *deque, int data)
{
	t_deque_element	*new_element;

	new_element = new_deque_element(data);
	if (!new_element)
		return (delete_deque(deque));
	deque->element_cnt++;
	if (!deque->rear && !deque->head)
	{
		deque->rear = new_element;
		deque->head = new_element;
		return ;
	}
	new_element->back = deque->head;
	deque->head->front = new_element;
deque->head = new_element;
}

void	dq_push_back(t_deque *deque, int data)
{
	t_deque_element	*new_element;

	new_element = new_deque_element(data);
	if (!new_element)
		return (delete_deque(deque));
	deque->element_cnt++;
	if (!deque->rear && !deque->head)
	{
		deque->rear = new_element;
		deque->head = new_element;
		return ;
	}
	new_element->front = deque->rear;
	deque->rear->back = new_element;
	deque->rear = new_element;
}

int	dq_pop_front(t_deque *deque)
{
	t_deque_element	*tmp_element;
	int				rtn_data;

	if (dq_empty(deque))
		return (-1);
	tmp_element = deque->head;
	deque->head = deque->head->back;
	if (deque->head)
		deque->head->front = 0;
	rtn_data = tmp_element->data;
	free(tmp_element);
	deque->element_cnt--;
	if (dq_empty(deque))
		deque->rear = 0;
	return (rtn_data);
}

int	dq_pop_back(t_deque	*deque)
{
	t_deque_element	*tmp_element;
	int				rtn_data;

	if (dq_empty(deque))
		return (-1);
	tmp_element = deque->rear;
	deque->rear = deque->rear->front;
	if (deque->rear)
		deque->rear->back = 0;
	rtn_data = tmp_element->data;
	free(tmp_element);
	deque->element_cnt--;
	if (dq_empty(deque))
		deque->head = 0;
	return (rtn_data);
}
