/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:09:28 by amoroziu          #+#    #+#             */
/*   Updated: 2018/11/20 14:09:30 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void				expand_str(char **str, char c, int add_to_left, int i)
{
	char	*extra;

	extra = ft_strnew(i);
	extra = ft_memset((void*)extra, c, i);
	if (add_to_left)
		*str = ft_strjoin(extra, *str);
	else
		*str = ft_strjoin(*str, extra);
}

static int				generate_str(t_format arg_format, char **output)
{
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

int						print_string(t_format arg_format,
	va_list args, int *count)
{
	char			*output;

	output = va_arg(args, char *);
	if (generate_str(arg_format, &output))
		return (1);
	ft_putstr(output);
	*count += ft_strlen(output);
	return (0);
}