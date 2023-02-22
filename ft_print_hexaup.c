/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexaup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:45:55 by pdelanno          #+#    #+#             */
/*   Updated: 2023/02/22 17:45:59 by pdelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hexaup(t_print *tab)
{
	int		nb;
	char 	*base;
	char	tmp[10];
	int 	i;

	nb = va_arg(tab->args, unsigned int);
	base = "0123456789ABCDEF";
	i = 0;
	if (tab->hashtag)
		write(1, "0X", 2);
	while (nb > 0)
	{
		tmp[i] = base[nb % 16];
		nb = nb / 16;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(1, &tmp[i], 1);
		i--;
	}
}
