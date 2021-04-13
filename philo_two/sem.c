/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 13:15:15 by javrodri          #+#    #+#             */
/*   Updated: 2021/04/13 10:20:35 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

char *semaphore_name(char const *src, char *dst, int pos)
{
    int i;

    i = ft_strcpy(dst, src);
    while (pos > 0)
    {
        dst[i++] = (pos % 10) + '0';
        pos /= 10;
    }
    dst[i] = 0;
    return (dst);
}
