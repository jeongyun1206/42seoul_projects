/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_ele_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:55:35 by jnho              #+#    #+#             */
/*   Updated: 2022/12/16 17:50:29 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

t_deque_element *new_deque_element(int data)
{
    t_deque_element *new_element;
    
    new_element = (t_deque_element *)malloc(sizeof(t_deque_element));
    if (!new_element)
        return (0);
    new_element->front = 0;
    new_element->back = 0;
    new_element->data = data;
    return (new_element);
}

//push_front X: 정수 X를 덱의 앞에 넣는다.
void    dq_push_front(t_deque *deque, int data)
{
    t_deque_element *new_element;

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

//push_back X: 정수 X를 덱의 뒤에 넣는다.
void    dq_push_back(t_deque *deque, int data)
{
    t_deque_element *new_element;

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

//pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
int dq_pop_front(t_deque *deque)
{
    t_deque_element *tmp_element;
    int             rtn_data;

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

//pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
int dq_pop_back(t_deque *deque)
{
    t_deque_element *tmp_element;
    int             rtn_data;

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