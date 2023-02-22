/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:15:07 by pdelanno          #+#    #+#             */
/*   Updated: 2023/02/22 17:15:11 by pdelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_eval_format(t_print *tab, char const *format, int i)
{
	while (format[i] != 'c' && format[i] != 's' && format[i] != 'd' && format[i] != 'i'
			&& format[i] != 'u' && format[i] != 'x' && format[i] != 'X'
			&& format[i] != 'p')
	{
		if (format[i] == 48)
		{
			tab->zeroflag = 1;
			i++;
		}
		if (format[i] == 45)
		{
			tab->dash = 1;
			tab->zeroflag = 0;
			i++;
		}
		if (format[i] == 32)
		{
			tab->sp = 1;
			i++;
		}
		if (format[i] == 43)
		{
			tab->pos = 1;
			i++;
		}
		if (format[i] == 35)
		{
			tab->hashtag = 1;
			i++;
		}
		while (format[i] <= 57 && format[i] >= 48)
		{	
			tab->wdt = (tab->wdt * 10) + (format[i] - 48);
			i++;
		}
		if (format[i] == '.')
		{
			i++;
			tab->zeroflag = 0;
			while (format[i] <= 57 && format[i] >= 48)
			{
				tab->prc = (tab->prc * 10) + (format[i] - 48);
				i++;
			}
		}
	}
	if (format[i] == 'c')
		ft_print_char(tab);
	if (format[i] == 's')
		ft_print_str(tab);
	if (format[i] == 'd' || format[i] == 'i')
		ft_print_int(tab);
	if (format[i] == 'u')
		ft_print_unsignedint(tab);
	if (format[i] == 'x')
		ft_print_hexalo(tab);
	if (format[i] == 'X')
		ft_print_hexaup(tab);
	if (format[i] == 'p')
		ft_print_address(tab);
	return (i);
}
