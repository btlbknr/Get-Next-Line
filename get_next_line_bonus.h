/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbakaner <fbakaner@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:55:35 by fbakaner          #+#    #+#             */
/*   Updated: 2023/02/23 13:55:43 by fbakaner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*read_line(char *str, int fd);
char	*read_first_line(char *str);
char	*next_read(char *str);

size_t	ft_strlen(const char *s);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *str, char *buff);

#endif
