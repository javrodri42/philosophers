/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:13:17 by javrodri          #+#    #+#             */
/*   Updated: 2021/03/24 11:30:33 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	  return(-nb);
	return (nb));
}

int main(void)
{
	char a[] = "156"
	printf("[%d]\n", ft_atoi(a));