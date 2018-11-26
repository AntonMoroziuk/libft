/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 13:33:39 by amoroziu          #+#    #+#             */
/*   Updated: 2018/11/16 15:27:45 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_flag(char c)
{
	return (c == '#' || c == '0' || c == '-' || c == '+' || c == ' ');
}

int		flag_repeats(char *str)
{
	if (ft_strrchr(str, '#') != ft_strchr(str, '#') ||
		ft_strrchr(str, '0') != ft_strchr(str, '0') ||
		ft_strrchr(str, '-') != ft_strchr(str, '-') ||
		ft_strrchr(str, '+') != ft_strchr(str, '+') ||
		ft_strrchr(str, ' ') != ft_strchr(str, ' '))
		return (1);
	return (0);
}

int		get_flags(const char *format, int *i, t_format *arg_format)
{
	int		j;
	int		k;

	j = 0;
	k = -1;
	while (is_flag(format[*i + j]))
	{
		if (format[*i + j] == '-' || format[*i + j] == '0')
		{
			arg_format->flags[++k] = format[*i + j];
			if (get_mfw(format, i, *i + j + 1, arg_format))
				return (1);
		}
		if (!ft_strchr(arg_format->flags, format[*i + j]))
			arg_format->flags[++k] = format[*i + j];
		j++;
	}
	if (j == 0)
		ft_strdel(&arg_format->flags);
	else if (flag_repeats(arg_format->flags))
		return (1);
	*i += j;
	return (0);
}
