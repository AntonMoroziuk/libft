/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:57:46 by amoroziu          #+#    #+#             */
/*   Updated: 2018/11/20 11:57:48 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void						expand_str(char **str, char c,
	int add_to_left, int i)
{
	char					*temp;
	char					*extra;

	extra = ft_strnew(i);
	extra = ft_memset((void*)extra, c, i);
	temp = *str;
	if (add_to_left)
		*str = ft_strjoin(extra, *str);
	else
		*str = ft_strjoin(*str, extra);
	ft_strdel(&temp);
}

static int						generate_str(unsigned char nb,
	t_format arg_format, char **output)
{
	MALLOCCHECK_INT((*output = ft_strnew(2)));
	(*output)[0] = (char)nb;
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

int								print_char(t_format arg_format,
	va_list args, int *count)
{
	unsigned char			nb;
	char					*output;

	nb = (unsigned char)va_arg(args, int);
	if (generate_str(nb, arg_format, &output))
		return (1);
	ft_putstr(output);
	*count += ft_strlen(output);
	return (0);
}