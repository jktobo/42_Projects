/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <yoyohann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 05:22:10 by yoyohann          #+#    #+#             */
/*   Updated: 2023/02/28 22:50:34 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_join(char *s1, char *s2)
{
	int		len;
	char	*join;

	if (!s2)
		return (s1);
	if (s1)
		len = ft_strlen(s1);
	else
		len = 0;
	join = malloc(ft_strlen(s2) + len + 1);
	if (!join)
		return (NULL);
	ft_strcpy(join, s1);
	ft_strcpy(join + len, s2);
	free(s1);
	return (join);
}
