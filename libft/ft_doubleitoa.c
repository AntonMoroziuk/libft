/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doubleitoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:02:19 by amoroziu          #+#    #+#             */
/*   Updated: 2018/11/23 13:02:20 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_power(double *nb)
{
	int		power;

	power = 0;
	while (*nb >= 1.0)
	{
		power++;
		*nb /= 10;
	}
	return (power);
}

static char	*get_bddigits(double *nb)
{
	char	*res;
	int		power;
	int		i;

	power = get_power(nb);
	res = ft_strnew(power);
	i = -1;
	while (power > 0)
	{
		res[++i] = (int)(*nb * 10) + '0';
		*nb = *nb * 10.0 - (int)(*nb * 10);
		power--;
	}
	return (res);
}

static char	*get_addigits(double *nb, int precision)
{
	char	*res;
	int		i;

	MALLOCCHECK_NULL((res = ft_strnew(precision + 1)));
	i = -1;
	res[++i] = '.';
	while (++i <= precision)
	{
		*nb *= 10;
		res[i] = (int)(*nb) + '0';
		*nb -= (int)(*nb);
	}
	return (res);
}

char		*ft_doubleitoa(double nb, int precision)
{
	if (nb < 9223372036854775807)
		return (ft_strjoin(ft_itoa((long long)nb),
			get_addigits(&nb, precision)));
	return (ft_strjoin(get_bddigits(&nb),
		get_addigits(&nb, precision)));
}