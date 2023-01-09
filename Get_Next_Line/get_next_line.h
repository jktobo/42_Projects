/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 12:30:03 by dkaratae          #+#    #+#             */
/*   Updated: 2022/06/08 13:23:57 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_get_line(char *b, int count_lines, char *part[], int fd);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_join_lines(char *part1, char *part2, int j);
char	*ft_memory_allocate(char *b, int i);
char	*ft_return_line(char *line1);
int		ft_paste_newline(int count_lines, char *line, int j);

#endif
