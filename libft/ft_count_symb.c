/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_symb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 18:03:53 by ddenkin           #+#    #+#             */
/*   Updated: 2018/03/15 18:15:38 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_count_symb(char *line, char c)
{
	int				res;

	res = 0;
	while (*line)
		(*line++ == c) ? res++ : 0;
	return (res);
}
