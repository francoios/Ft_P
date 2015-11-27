/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/18 14:07:12 by frcugy            #+#    #+#             */
/*   Updated: 2015/10/28 16:05:31 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H
# include "../../libft/libft.h"
# include <stdio.h>
# include <sys/socket.h>
# include <netdb.h>
# include <stdlib.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <fcntl.h>
# include <signal.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/mman.h>
# define NORME struct dirent

int					check_dir(char *param);
int					sending(int fd);
void				put_file(char *name);
void				receving(int fd);
void				file_get(char *data);
void				usage(char *str);
int					create_client(char *addr, int port);

int					g_sock;
#endif
