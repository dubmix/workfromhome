/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsignedint.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:38:45 by pdelanno          #+#    #+#             */
/*   Updated: 2023/02/22 17:38:48 by pdelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_unsignedint(t_print *tab)
{
	int		nb;
	char	tmp[10];
	int		i;
	
	i = 0;	
	nb = va_arg(tab->args, unsigned int);
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
}
