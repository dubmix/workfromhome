/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:22:58 by pdelanno          #+#    #+#             */
/*   Updated: 2023/02/22 17:12:11 by pdelanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print *ft_init_tab(t_print *tab)
{
			tab->wdt = 0;
			tab->lenwdt = 1;
			tab->prc = 0;
			tab->zero = 1;
			tab->neg = 0;
			tab->zeroflag = 0;
			tab->dash = 0;
			tab->sp = 0;
			tab->pos = 0;
			tab->hashtag = 0;
			tab->totlen = 0;
			return (tab);
}

int	ft_printf(const char *format, ...)
{
	t_print *tab;
	int		i;
	int		ret;

	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	va_start(tab->args, format);
	ret = 0;
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			ft_init_tab(tab);
			i = ft_eval_format(tab, format, i + 1);
		}
		else
			write(1, &format[i], 1);
	}
	va_end(tab->args);
	free(tab);
	return (ret);
}
