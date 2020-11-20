/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrock <bbrock@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 13:15:01 by bbrock            #+#    #+#             */
/*   Updated: 2020/11/20 15:38:06 by bbrock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H
# include <stdlib.h>
# include <errno.h>

size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *str1, const char *str2);
int		ft_strcmp(const char *str1, const char *str2);
int		ft_write(int handle, void *buf, int count);
int		ft_read(int handle, void *buf, int count);
char	*ft_strdup(const char *str);

#endif
