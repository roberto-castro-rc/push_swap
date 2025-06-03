/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulo-c <rpaulo-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 20:00:57 by rpaulo-c          #+#    #+#             */
/*   Updated: 2025/06/02 20:20:04 by rpaulo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_base(const char **nptr, int base)
{
	if (base != 0)
		return (base);
	if (**nptr == '0')
	{
		if (*(*nptr + 1) == 'x' || *(*nptr + 1) == 'X')
		{
			*nptr += 2;
			return (16);
		}
		return (8);
	}
	return (10);
}

static long	convert(const char *nptr, char **endptr, int base, int *sign)
{
	long	result;
	int		digit;

	result = 0;
	while (ft_isdigit(*nptr) || (base == 16 && ft_isxdigit(*nptr)))
	{
		if (ft_isdigit(*nptr))
			digit = *nptr - '0';
		else
			digit = ft_tolower(*nptr) - 'a' + 10;
		if (digit >= base)
			break ;
		if (result > (LONG_MAX - digit) / base)
		{
			if (endptr)
				*endptr = (char *)nptr;
			return (LONG_MAX + (*sign == 1));
		}
		result = result * base + digit;
		nptr++;
	}
	if (endptr)
		*endptr = (char *)nptr;
	return (result * *sign);
}

long	ft_strtol(const char *nptr, char **endptr, int base)
{
	int	sign;

	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	base = get_base(&nptr, base);
	if (base < 2 || base > 36)
	{
		if (endptr)
			*endptr = (char *)nptr;
		return (0);
	}
	return (convert(nptr, endptr, base, &sign));
}
