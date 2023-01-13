/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 12:29:59 by dkaratae          #+#    #+#             */
/*   Updated: 2022/09/05 02:37:53 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_line(char *b, int count_lines, char *line[], int fd)
{
	int			count;
	static int	i;
	int			j;

	if (b[i] == '\n')
		i++;
	while (count_lines == 0 || b[i] != '\n')
	{
		if (b[i] == '\0')
		{
			count = read(fd, b, BUFFER_SIZE);
			if (count <= 0)
				return (ft_return_line(line[0]));
			b[count] = '\0';
			i = 0;
		}
		line[1] = ft_memory_allocate(b, i);
		j = 0;
		while (b[i] && b[i] != '\n')
			line[1][j++] = b[i++];
		if (b[i] == '\n')
			count_lines = ft_paste_newline(count_lines, line[1], j++);
		line[0] = ft_join_lines(line[0], line[1], j);
	}
	return (ft_return_line(line[0]));
}

char	*get_next_line(int fd)
{
	static char	b[BUFFER_SIZE * (2 * (BUFFER_SIZE > 0) - 1) + 1];
	int			count_lines;
	char		*line[2];

	count_lines = 0;
	if (read(fd, 0, 0) != 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line[0] = (char *)malloc(sizeof(char) * (1));
	if (!line[0])
		return (NULL);
	line[0][0] = '\0';
	return (ft_get_line(b, count_lines, line, fd));
}
