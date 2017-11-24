/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 18:43:50 by akoller           #+#    #+#             */
/*   Updated: 2017/10/11 21:20:33 by akoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**ptr;

	i = -1;
	j = 0;
	if (!s || !(ptr = (char **)malloc(sizeof(char *) * (ft_wordup(s, c) + 1))))
		return (NULL);
	while (++i < ft_wordup(s, c))
	{
		k = 0;
		if (!(ptr[i] = ft_strnew(ft_wordup(&s[j], c) + 1)))
			ptr = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			ptr[i][k++] = s[j++];
		ptr[i][j] = '\0';
	}
	ptr[i] = 0;
	return (ptr);
}
