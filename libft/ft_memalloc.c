/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pa <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 20:39:30 by pa                #+#    #+#             */
/*   Updated: 2018/11/29 10:44:48 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t s)
{
	void *str;

	str = (void *)malloc(sizeof(size_t) * s);
	if (!str)
		return (NULL);
	ft_bzero(str, s);
	return (str);
}
