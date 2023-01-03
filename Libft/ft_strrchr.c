/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:27:00 by dkaratae          #+#    #+#             */
/*   Updated: 2022/04/08 21:54:35 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		t;

	t = 0;
	while (*s)
	{
		if (*s == (char)c)
		{
			str = (char *)s;
			t++;
		}
		s++;
	}
	if (t > 0)
		return (str);
	else if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
