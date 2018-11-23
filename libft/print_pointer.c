/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 12:23:38 by amoroziu          #+#    #+#             */
/*   Updated: 2018/11/23 12:23:40 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		print_pointer(t_format arg_format, va_list args, int *count)
{
	if (arg_format.flags)
		ft_strdel(&arg_format.flags);
	arg_format.length = 'l';
	arg_format.conv = 'x';
	arg_format.flags = ft_strdup("#");
	return (print_uhex(arg_format, args, count));
}