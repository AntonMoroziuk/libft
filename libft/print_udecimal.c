/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_udecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:07:59 by amoroziu          #+#    #+#             */
/*   Updated: 2018/11/19 15:08:13 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char						*uitoa(unsigned long long int nb)
{
	int							size;
	char						*res;
	unsigned long long int		temp;

	size = (nb == 0);
	temp = nb;
	while (temp != 0)
	{
		temp /= 10;
		size++;
	}
	MALLOCCHECK_NULL((res = ft_strnew(size)));
	while (size >= 0)
	{
		res[--size] = nb % 10 + '0';
		nb /= 10;
	}
	return (res);
}

static unsigned	long long int	get_arg(t_format arg_format, va_list args)
{
	if (arg_format.length == 'L')
		return ((long long int)va_arg(args, long long int));
	else if (arg_format.length == 'l')
		return ((long long int)va_arg(args, long int));
	else if (arg_format.length == 'h')
		return ((long long int)va_arg(args, int));
	else if (arg_format.length == 'H')
		return ((long long int)va_arg(args, int));
	return ((long long int)va_arg(args, int));
}

static void				expand_str(char **str, char c, int add_to_left, int i)
{
	char	*temp;
	char	*extra;

	extra = ft_strnew(i);
	extra = ft_memset((void*)extra, c, i);
	temp = *str;
	if (add_to_left)
		*str = ft_strjoin(extra, *str);
	else
		*str = ft_strjoin(*str, extra);
	ft_strdel(&temp);
}

static int						generate_str(long long int nb,
	t_format arg_format, char **output)
{
	*output = uitoa(nb);
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

int								print_udecimal(t_format arg_format,
	va_list args, int *count)
{
	unsigned long long int	nb;
	char					*output;

	nb = get_arg(arg_format, args);
	if (generate_str(nb, arg_format, &output))
		return (1);
	ft_putstr(output);
	*count += ft_strlen(output);
	return (0);
}