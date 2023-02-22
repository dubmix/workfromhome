/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:38:19 by pdelanno          #+#    #+#             */
/*   Updated: 2023/02/22 17:38:21 by pdelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_str(t_print *tab)
{
	char	*str;
	int		i;
	int		prc;

	prc = tab->prc;	
	str = va_arg(tab->args, char *);
	i = 0;
	if (tab->wdt && !tab->dash)
		ft_right_align(tab, ft_strlen(tab, str));
	if (prc > 0)
	{
		while (prc > 0 && str[i])
		{
			write(1, &str[i], 1);
			prc -= 1;
			i++;
		}
	}		
	else
	{
		while (str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	if (tab->wdt && tab->dash)
		ft_left_align(tab, ft_strlen(tab, str));
}
