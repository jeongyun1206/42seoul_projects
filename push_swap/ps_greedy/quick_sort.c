/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:33:47 by jnho              #+#    #+#             */
/*   Updated: 2022/12/19 16:03:01 by jnho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ps_greedy.h"

void    swap(int *num1, int *num2)
{
    int tmp;

    tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}

void    quick_sort(int *arr, int start, int end)
{
    int  p_idx;
    int  s_idx;
    int  e_idx;

    if (start >= end)
        return ;
    p_idx = start;
    s_idx = start + 1;
    e_idx = end;
    while (s_idx <= e_idx)
    {
        while (s_idx <= end && arr[s_idx] <= arr[p_idx])
            s_idx++;
        while (e_idx > start && arr[e_idx] >= arr[p_idx])
            e_idx--;
        if (s_idx > e_idx)
            swap(&arr[p_idx], &arr[e_idx]);
        else
            swap(&arr[s_idx], &arr[e_idx]);
    }
    quick_sort(arr, start, e_idx - 1);
    quick_sort(arr, e_idx + 1, end);
}