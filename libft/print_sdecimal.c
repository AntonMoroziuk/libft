/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sdecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:45:01 by amoroziu          #+#    #+#             */
/*   Updated: 2018/11/17 11:17:31 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
static long long int	get_arg(t_format arg_format, va_list args)
{
	if (arg_format.length == 'H')
		return ((long long int)va_arg(args, int));
	else if (arg_format.length == 'h')
		return ((long long int)va_arg(args, int));
	else if (arg_format.length == 'l')
		return ((long long int)va_arg(args, long int));
	else if (arg_format.length == 'L')
		return ((long long int)va_arg(args, long long int));
	return ((long long int)va_arg(args, int));
}

static void				check_sign(char **str, long long int nb,
	t_format arg_format)
{
	char			*temp;

	if (arg_format.flags)
	{	
		if (ft_strchr(arg_format.flags, ' '))
		{
			if (nb > 0)
			{
				temp = *str;
				*str = ft_strjoin(" ", *str);
				ft_strdel(&temp);
			}
		}
		if (ft_strchr(arg_format.flags, '+'))
		{
			if (nb > 0)
			{
				temp = *str;
				*str = ft_strjoin("+", *str);
				ft_strdel(&temp);
			}
		}
	}
}

static void				expand_str(char **str, char c, int add_to_left, int i)
{
	char	*temp;
	char	*extra;
	char	*sign;

	extra = ft_strnew(i);
	extra = ft_memset((void*)extra, c, i);
	temp = *str;
	if (add_to_left)
	{
		sign = ft_strsub(*str, 0, 1);
		if (!ft_isdigit(sign[0]) && c == '0')
		{
			*str = ft_strjoin(extra, ft_strsub(*str, 1, ft_strlen(*str) - 1));
			ft_strdel(&temp);
			temp = *str;
			*str = ft_strjoin(sign, *str);
			ft_strdel(&temp);
		}
		else
			*str = ft_strjoin(extra, *str);
	}
	else
		*str = ft_strjoin(*str, extra);
	ft_strdel(&temp);
}

static int				generate_str(long long int nb, t_format arg_format,
	char **output)
{
	*output = ft_itoa(nb);
	check_sign(output, nb, arg_format);
	if (ft_strlen(*output) < (size_t)arg_format.precision)
		expand_str(output, '0', 1, arg_format.precision - ft_strlen(*output));
	if (ft_strlen(*output) < (size_t)arg_format.mfw)
	{
		if (!arg_format.flags)
			expand_str(output, ' ', 1, arg_format.mfw - ft_strlen(*output));
		else if (ft_strchr(arg_format.flags, '-'))
			expand_str(output, ' ', 0, arg_format.mfw - ft_strlen(*output));
		else if (ft_strchr(arg_format.flags, '0'))
			expand_str(output, '0', 1, arg_format.mfw - ft_strlen(*output));
		else
			expand_str(output, ' ', 1, arg_format.mfw - ft_strlen(*output));
	}
	return (0);
}

int						print_sdecimal(t_format arg_format,
	va_list args, int *count)
{
	long long int	nb;
	char			*output;

	nb = get_arg(arg_format, args);
	if (generate_str(nb, arg_format, &output))
		return (1);
	ft_putstr(output);
	*count += ft_strlen(output);
	return (0);
}
