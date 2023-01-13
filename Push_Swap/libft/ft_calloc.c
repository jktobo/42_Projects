/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:50:33 by dkaratae          #+#    #+#             */
/*   Updated: 2022/10/01 13:14:27 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;
	size_t	res;

	i = 0;
	if (size && SIZE_MAX / size < count)
		return (NULL);
	res = count * size;
	str = malloc(res);
	if (!str)
		return (NULL);
	while (i < res)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
