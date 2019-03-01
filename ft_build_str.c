/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:19:12 by plaurent          #+#    #+#             */
/*   Updated: 2019/03/01 18:21:54 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_set_precision(char *initial, t_asset *asset, int signmode)
{
	size_t	l;
	size_t	length;
	char	*additional;

	if (asset->type == 21 && ft_strchr(asset->flags, '#'))
	{
		asset->precision = (asset->precision <= (int)(ft_strlen(initial))
				? ft_strlen(initial) + 1 : asset->precision);
		asset->precision = (ft_atoi(initial) == 0 ? 1 : asset->precision);
	}
	if (asset->precision > 0)
	{
		l = ft_strlen(initial) - (signmode == -1 ? 1 : 0);
		length = ((size_t)asset->precision > l ? asset->precision - l : 0);
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

static size_t	st_set_length(char *initial, t_asset asset, int signmode)
{
	size_t	length;

	length = (asset.width > ft_strlen(initial) ?
			asset.width - ft_strlen(initial) : 0);
	if (length == 0 && ft_strchr(asset.flags, ' ')
			&& !ft_strchr(asset.flags, '-')
			&& !ft_strchr(asset.flags, '+') && signmode == 1)
		length++;
	return (length);
}

static void	st_set_x_width
	(char *initial, char *additional, t_asset asset, size_t length)
{
	additional[0] = '0';
	additional[1] = (asset.type == 23 ? 'x' : 'X');
	initial[0] = (length > 0 ? '0' : initial[0]);
	initial[1] = (length > 0 ? '0' : initial[0]);
}

char		*ft_set_width(char *initial, t_asset asset, int signmode)
{
	size_t	length;
	char	*additional;

	length = st_set_length(initial, asset, signmode);
	if (!(additional = ft_strnew(length)))
		return (NULL);
	if (length && ft_strchr(asset.flags, '0')
			&& !ft_strchr(asset.flags, '-') && asset.precision == -1)
	{
		additional = ft_memset(additional, '0', length);
		if (ft_strchr(asset.flags, '+') || signmode == -1)
		{
			additional[0] = (signmode == -1 ? '-' : '+');
			initial[0] = (signmode && length > 0 ? '0' : initial[0]);
		}
		else if ((asset.type == 23 || asset.type == 24)
				&& ft_strchr(asset.flags, '#')
				&& (initial[1] == 'x' || initial[1] == 'X'))
			st_set_x_width(initial, additional, asset, length);
		else if (ft_strchr(asset.flags, ' '))
			additional[0] = ' ';
	}
	else
		additional = ft_memset(additional, ' ', length);
	return (additional);
}

char		*ft_addbuild(char *initial, char *additional, t_asset asset)
{
	char *build;

	if (ft_strchr(asset.flags, '-'))
	{
		if (!(build = sp_strnjoin(initial, additional, ft_strlen(additional), 0)))
		{
			free(additional);
			free(initial);
			return (NULL);
		}
	}
	else if (!(build = sp_strnjoin(additional, initial, ft_strlen(initial), 1)))
	{
		free(additional);
		free(initial);
		return (NULL);
	}
	return (build);
}

char		*ft_preparewidth(char *processed, t_asset asset, int signmode)
{
	if ((asset.type == 23 || asset.type == 24) && ft_strchr(asset.flags, '#') &&
			ft_atoi(processed) != 0)
	{
		if (!(processed = sp_strnjoin((asset.type == 23 ? "0x" : "0X"),
						processed, ft_strlen(processed), 1)))
			return (NULL);
	}
	else if (signmode == 1)
	{
		if (ft_strchr(asset.flags, '+'))
		{
			if (!(processed =
						sp_strnjoin("+", processed, ft_strlen(processed), 1)))
				return (NULL);
		}
		else if (ft_strchr(asset.flags, ' ') && ft_strchr(asset.flags, '-'))
			if (!(processed =
						sp_strnjoin(" ", processed, ft_strlen(processed), 1)))
				return (NULL);
	}
	return (processed);
}

char	*ft_build_str(char *initial, t_asset asset, int signmode)
{
	char	*additional;
	char	*final;

	if (signmode)
		signmode = (initial[0] == '-' ? -1 : 1);
	if (!(additional = ft_set_precision(initial, &asset, signmode)))
		return (NULL);
	if (!(asset.precision == 0 && ft_atoi(initial) == 0))
	{
		if (!(final = ft_strjoin(additional, initial)))
			return (NULL);
	}
	else if (!(final = ft_strnew(0)))
		return (NULL);
	if (!(final = ft_preparewidth(final, asset, signmode)))
		return (NULL);
	free(additional);
	if (!(additional = ft_set_width(final, asset, signmode)))
		return (NULL);
	if (!(final = ft_addbuild(final, additional, asset)))
		return (NULL);
	free(additional);
	free(initial);
	return (final);
}
