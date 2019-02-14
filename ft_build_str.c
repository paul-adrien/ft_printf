/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:19:12 by plaurent          #+#    #+#             */
/*   Updated: 2019/02/14 14:33:12 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_set_precision(char *initial, t_asset asset, int signmode)
{
	size_t	l;
	size_t	length;
	char	*additional;

	ft_putstr("P1 |"); // TEST
	ft_putnbr(asset.precision); // TEST
	ft_putstr("|\n"); // TEST
	if (asset.precision > 0)
	{
		l = ft_strlen(initial) - (signmode == -1 ? 1 : 0); // pour les cas ou asset.precision <= strlen a cause du signe (-)
		length = ((size_t)asset.precision > l ? asset.precision - l : 0);
		//if (signmode == -1 && ) par exemple pour (%+ 7.3d / -11)
		//		//	length++;
		if (!(additional = ft_strnew(length)))
			return (NULL);
		additional = ft_memset(additional, '0', length);
		if (signmode == -1 && length > 0)
		{
			additional[0] = '-';
			initial[0] = '0';
		}
		return (additional);
	}
	return (ft_strnew(0));
}

char	*ft_set_width(char *initial, t_asset asset, int signmode)
{
	size_t	length;
	char	*additional;

	length = (asset.width > ft_strlen(initial) ? asset.width - ft_strlen(initial) : 0);

	if (length == 0 && ft_strchr(asset.flags, ' ') && !ft_strchr(asset.flags, '-') && !ft_strchr(asset.flags, '+') && signmode == 1)
		length++; // Pour rajouter l'espace de debut quand length est nul, le num sans signe, et pas cale a gauche
	if (!(additional = ft_strnew(length)))
		return (NULL);
	if (length && ft_strchr(asset.flags, '0') && !ft_strchr(asset.flags, '-') && asset.precision == -1)
	{
		additional = ft_memset(additional, '0', length);
		if (ft_strchr(asset.flags, '+') || signmode == -1)
		{
			additional[0] = (signmode == -1 ? '-' : '+');
			initial[0] = (signmode && length > 0 ? '0' : initial[0]);
		}
		else if (ft_strchr(asset.flags, ' '))
			additional[0] = ' ';
	}
	else
		additional = ft_memset(additional, ' ', length);
	return (additional);
}

char	*ft_addbuild(char *initial, char *additional, t_asset asset)
{
	char *build;

	if (ft_strchr(asset.flags, '-'))
	{
		if (!(build = ft_strjoin(initial, additional)))
		{
			free(additional);
			free(initial);
			return (NULL);
		}
	}
	else
		if (!(build = ft_strjoin(additional, initial)))
		{
			free(additional);
			free(initial);
			return (NULL);
		}
	return (build);
}

char	*ft_preparewidth(char *processed, t_asset asset, int signmode)
{
	if (signmode == 1)
	{
		if (ft_strchr(asset.flags, '+'))
		{
			if (!(processed = sp_strnjoin("+", processed, ft_strlen(processed), 1)))
				return (NULL);
		}
		else if (ft_strchr(asset.flags, ' ') && ft_strchr(asset.flags, '-')) // a peut etre sortir du if signmode pour autres types
			if (!(processed = sp_strnjoin(" ", processed, ft_strlen(processed), 1)))
				return (NULL);
	}
	return (processed);
}

char	*ft_build(char *initial, t_asset asset, int signmode)
{
	char	*additional;
	char	*final;

	if (signmode)
		signmode = (initial[0] == '-' ? -1 : 1);
	if (!(additional = ft_set_precision(initial, asset, signmode)))
		return (NULL);
	ft_putstr("A1 |"); // TEST
	ft_putstr(additional); // TEST
	ft_putstr("|\n"); // TEST
	if (!(asset.precision == 0 && ft_atoi(initial) == 0))
	{
		if (!(final = ft_strjoin(additional, initial)))
			return (NULL);
		ft_putstr("F1 |"); // TEST
		ft_putstr(final); // TEST
		ft_putstr("|\n"); // TEST
	}
	else
		if (!(final = ft_strnew(0)))
			return (NULL);
	if (!(final = ft_preparewidth(final, asset, signmode)))
		return (NULL);
	ft_putstr("F2 |"); // TEST
	ft_putstr(final); // TEST
	ft_putstr("|\n"); // TEST
	//ft_putstr("Final apres la precision : "); // TEST TEST TEST
	//ft_putendl(final); // TEST TEST TEST
	free(additional);
	if (!(additional = ft_set_width(final, asset, signmode)))
		return (NULL);
	ft_putstr("A2 |"); // TEST
	ft_putstr(additional); // TEST
	ft_putstr("|\n"); // TEST
	//
	if (!(final = ft_addbuild(final, additional, asset)))
		return (NULL);
	free(additional);
	free(initial);
	return (final);
}