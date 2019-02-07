/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recutabetarg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:03:22 by plaurent          #+#    #+#             */
/*   Updated: 2019/02/07 16:48:28 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_check_type(char *tab)
{
	int		i;
	int		n;

	i = 0;
	while (tab[i] != '\0')
		i++;
	i--;
	if (tab[i] == 'd' ? n = 1 : n = 0)
	if (tab[i] == 'i' ? n = 2 : n = 0)
	if (tab[i] == 'o'|| tab[i] == 'u' || tab[i] == 'x' || tab[i] == 'X' ?
			n = 3 : n = 0)
	if (tab[i] == 'c' ? n = 4 : n = 0)
	if (tab[i] == 's' ? n = 5 : n = 0)
	if (tab[i] == 'p' ? n = 6 : n = 0)
	if (tab[i] == 'f' ? n = 7 : n = 0)
}
