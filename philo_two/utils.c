/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:13:17 by javrodri          #+#    #+#             */
/*   Updated: 2021/04/20 12:59:37 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

#define MIN_INT -2147483648
#define MAX_INT 2147483647

static int	check(const char **str)
{
	int	is_negative;

	while (**str == ' ' || **str == '\t' || **str == '\n'
		|| **str == '\v' || **str == '\f' || **str == '\r')
		(*str)++;
	is_negative = 0;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			is_negative = 1;
		(*str)++;
	}
	return (is_negative);
}

int	ft_atoi(const char *str)
{
	unsigned int	nb;
	int				i;
	int				is_negative;

	is_negative = check(&str);
	i = 0;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (!is_negative && nb > (unsigned int)MAX_INT)
			return (-1);
		else if (nb > (unsigned int)MIN_INT)
			return (0);
		nb = nb * 10 + (*str - 48);
		++str;
	}
	if ((int)is_negative)
		return (-nb);
	return (nb);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		++i;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
