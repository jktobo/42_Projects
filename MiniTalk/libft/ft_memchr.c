/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 20:28:07 by dkaratae          #+#    #+#             */
/*   Updated: 2022/04/08 21:52:59 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str1;
	unsigned char	str2;
	size_t			i;

	str1 = ((unsigned char *)s);
	str2 = ((unsigned char)c);
	i = 0;
	while (i < n)
	{
		if (*str1 == str2)
			return (str1);
		str1++;
		i++;
	}
	return (NULL);
}
