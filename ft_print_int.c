/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:19:54 by pdelanno          #+#    #+#             */
/*   Updated: 2023/02/22 17:43:57 by pdelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_int(t_print *tab)
{
	int		nb;
	int		tmp_nb;
	char	tmp[10];
	int		i;
	
	i = 0;	
	nb = va_arg(tab->args, int);
	tmp_nb = nb;
	if (tab->wdt && !tab->zeroflag && !tab->dash)
		ft_right_align(tab, tmp_nb);
	if (tab->sp && nb >= 0)
		write(1, " ", 1);
	if (tab->pos && nb >= 0)
		write(1, "+", 1);
	if (nb == -2147483648)
	{
		write(1, "-2", 2);
		nb = 147483648;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (tab->prc || tab->zeroflag)
	{
		if (tmp_nb < 0)
			tab->zero -= 1;
		ft_precision(tab, tmp_nb);
	}
	while (nb > 0)
	{
		tmp[i] = (nb % 10) + 48;
		nb = nb / 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(1, &tmp[i], 1);
		i--;
	}
	if (tab->wdt && tab->dash)
		ft_left_align(tab, tmp_nb);
}
