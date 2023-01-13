/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 07:30:06 by dkaratae          #+#    #+#             */
/*   Updated: 2022/04/07 17:30:04 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	if (start > i)
		len = 0;
	if (len > i - start)
		len = i - start;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!(str))
		return (NULL);
	i = 0;
	while (i < len && s[i] != '\0')
	{
		str[i++] = s[start++];
	}
	str[i] = '\0';
	return (str);
}
