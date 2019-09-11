/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <ibaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:48:21 by ibaran            #+#    #+#             */
/*   Updated: 2019/07/31 11:52:27 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include "libft.h"

static int		ft_exp(__int128_t nbr, unsigned short base)
{
	if (nbr != 0)
		return (ft_exp(nbr / base, base) + 1);
	return (0);
}

char			*ft_itoa_base(__int128_t nbr, unsigned short base)
{
	int		exp;
	char	*out;
	char	*alph_num;

	out = NULL;
	alph_num = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	exp = ft_exp(nbr, base);
	if (nbr == 0)
		exp = 1;
	if (!(out = (char*)malloc(sizeof(char) * (exp + 1))))
		return (NULL);
	out[exp] = '\0';
	out[0] = '0';
	while (nbr != 0)
	{
		out[exp - 1] = alph_num[(nbr % base)];
		nbr /= base;
		exp--;
	}
	return (out);
}
