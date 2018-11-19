/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:58:06 by amoroziu          #+#    #+#             */
/*   Updated: 2018/11/19 15:07:13 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
int		get_format(const char *format, int *i, t_format *arg_format)
{
	arg_format->mfw = 0;
	arg_format->flags = ft_strnew(5);
	if (get_flags(format, i, arg_format))
		return (1);
	if (arg_format->mfw == 0)
		if (get_mfw(format, i, *i, arg_format))
			return (1);
	if (get_precision(format, i, arg_format))
		return (1);
	if (get_length(format, i, arg_format))
		return (1);
	if (get_convers(format, i, arg_format))
		return (1);
	/*ft_putendl(arg_format->flags);
	ft_putnbr(arg_format->mfw);
	ft_putchar('\n');
	ft_putnbr(arg_format->precision);
	ft_putchar('\n');
	ft_putchar(arg_format->length);
	ft_putchar('\n');
	ft_putchar(arg_format->conv);
	ft_putchar('\n');*/
	return (0);
}
