/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 13:05:24 by javrodri          #+#    #+#             */
/*   Updated: 2021/04/19 13:51:44 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.c"

sem_t	open_semaphore(char const *name, int value)
{
  sem_unlink(name);
  return (sem_open(name, O_CREAT | O_EXCL, 0644, value));
}

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

