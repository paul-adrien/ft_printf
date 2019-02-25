/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:07:11 by eviana            #+#    #+#             */
/*   Updated: 2019/02/20 13:21:34 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char * restrict format, ...)
{
	va_list	ap;
	char	**tab;
	char	*print;
	int		printlength;

	va_start(ap, format);
	tab = ft_formattotab(format);
	if (!(print = ft_dispatcher(tab, ap)))
		return (-1); // CHECKER LES VALEURS DE RETOUR DE PRINTF
	ft_putstr(print);
	printlength = ft_strlen(print);
	va_end(ap);
	return (printlength); // CHECKER LES VALEURS DE RETOUR DE PRINTF
}
