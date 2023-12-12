/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <yoyohann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 12:02:55 by yonas             #+#    #+#             */
/*   Updated: 2023/02/28 05:35:12 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		s;
	int		e;
	char	*trim;

	s = 0;
	while (s1[s] && ft_chrmatch(s1[s], set))
		s++;
	e = ft_strlen(s1);
	while (e > s && ft_chrmatch(s1[e - 1], set))
		e--;
	trim = (char *) malloc(sizeof(char) * ((e - s) + 1));
	if (trim == 0)
		return (NULL);
	i = 0;
	while (s < e)
		trim[i++] = s1[s++];
	trim[i] = '\0';
	return (trim);
}
