/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mfw.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:48:47 by amoroziu          #+#    #+#             */
/*   Updated: 2018/11/16 15:24:13 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		pseudo_atoi(const char *str, int start)
{
	int		res;

	res = 0;
	while (ft_isdigit(str[start]))
	{
		res = res * 10 + str[start] - '0';
		start++;
	}
	return (res);
}

int				get_mfw(const char *format, int *i, int start,
	t_format *arg_format)
{
	int		j;

	j = 0;
	while (ft_isdigit(format[start + j]))
		j++;
	arg_format->mfw = MAX(pseudo_atoi(format, start), arg_format->mfw);
	(*i) += j;
	return (0);
}

int				get_precision(const char *format, int *i, t_format *arg_format)
{
	int		j;

	j = 0;
	//arg_format->precision = -1;
	if (format[*i] == '.')
	{
		(*i)++;
		while (ft_isdigit(format[*i + j]))
			j++;
		arg_format->precision = pseudo_atoi(format, *i);
		(*i) += j;
	}
	return (0);
}
