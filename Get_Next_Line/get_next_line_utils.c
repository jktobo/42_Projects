/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 12:29:55 by dkaratae          #+#    #+#             */
/*   Updated: 2022/06/08 12:29:37 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*res;
	int		i;
	int		c1;
	int		c2;

	i = 0;
	c1 = 0;
	c2 = 0;
	if ((!s1) || (!s2))
		return (NULL);
	while (s1[c1])
		c1++;
	while (s2[c2])
		c2++;
	res = (char *)malloc(sizeof(char) * ((c1 + c2 + 1)));
	if (!res)
		return (NULL);
	while (*s1 != '\0')
		res[i++] = *s1++;
	while (*s2 != '\0')
		res[i++] = *s2++;
	res[i] = '\0';
	return (res);
}

char	*ft_join_lines(char *line1, char *line2, int j)
{
	char	*joined_line;

	line2[j] = '\0';
	joined_line = ft_strjoin(line1, line2);
	free(line1);
	free(line2);
	return (joined_line);
}

char	*ft_memory_allocate(char *b, int i)
{
	int		j;
	char	*size;

	j = 0;
	while (b[i + j] && b[i + j] != '\n')
		j++;
	size = (char *)malloc(sizeof(char) * (j + 1 + (b[i + j] == '\n')));
	if (!size)
		return (NULL);
	return (size);
}

char	*ft_return_line(char *line1)
{
	if (line1[0])
		return (line1);
	free(line1);
	return (NULL);
}

int	ft_paste_newline(int count_lines, char *line, int j)
{
	count_lines++;
	line[j++] = '\n';
	return (count_lines);
}
