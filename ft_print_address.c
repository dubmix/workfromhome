/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:28:40 by pdelanno          #+#    #+#             */
/*   Updated: 2023/02/22 17:48:02 by pdelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_address(t_print *tab)
{
	long int		nb;
	char 			*base;
	char			tmp[16];
	int 			i;

	nb = va_arg(tab->args, unsigned long);
	base = "0123456789abcdef";
	i = 0;
	while (nb > 0)
	{
		tmp[i] = base[nb % 16];
		nb = nb / 16;
		i++;
	}
	i--;
	write (1, "0x", 2);
	while (i >= 0)
	{
		write(1, &tmp[i], 1);
		i--;
	}
}
