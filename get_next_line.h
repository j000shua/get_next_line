/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinguet <jlinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:30:14 by jlinguet          #+#    #+#             */
/*   Updated: 2024/01/26 16:16:55 by jlinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

# include <stddef.h>

char	*get_next_line(int fd);

size_t	ft_strlen(char *s);
char	*ft_strchr(char *str, int chr);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);

#endif
