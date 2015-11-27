/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/13 17:39:11 by frcugy            #+#    #+#             */
/*   Updated: 2015/10/29 16:55:12 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <dirent.h>
#define NORME struct dirent

int					check_dir(t_uenv *env, char *param)
{
	DIR					*dir;
	DIR					*tsdp;
	NORME				*dirent;

	if ((dir = opendir(".")))
	{
		while ((dirent = readdir(dir)))
		{
			if (ft_strcmp(dirent->d_name, param) == 0)
			{
				tsdp = opendir(dirent->d_name);
				if (tsdp)
				{
					printf("Error -> You can't copy a directory\n");
					send(env->cs, "FAILURE\n", 8, 0);
					closedir(dir);
					return (1);
				}
			}
		}
	}
	closedir(dir);
	return (0);
}

int					sending(t_uenv *env, int fd)
{
	int				length;
	char			*addr;
	struct stat		sb;
	char			*str;

	if (fstat(fd, &sb) == -1)
	{
		printf("Error -> Protected file\n");
		send(env->cs, "FAILURE\n", 8, 0);
		close(fd);
		return (1);
	}
	length = sb.st_size;
	addr = mmap(0, length, PROT_READ, MAP_PRIVATE, fd, 0);
	str = ft_strjoin(ft_itoa(length), "\n");
	send(env->cs, "SUCCESS\n", 8, 0);
	send(env->cs, str, ft_strlen(str), 0);
	send(env->cs, addr, length, 0);
	return (0);
}

void				file_get(t_uenv *env, char *line)
{
	int				fd;
	char			**param;

	param = ft_strsplit(line, ' ');
	if (param[2] != NULL || param[1] == NULL)
	{
		((param[1] == NULL) ? printf("ERROR -> Not enough arguments\n")
			: printf("ERROR -> Too many arguments\n"));
		send(env->cs, "FAILURE\n", 8, 0);
		return ;
	}
	if ((fd = open(param[1], O_RDONLY)) < 0)
	{
		printf("ERROR -> File not found\n");
		send(env->cs, "FAILURE\n", 8, 0);
		return ;
	}
	if (check_dir(env, param[1]) == 1)
		return ;
	if (sending(env, fd) == 1)
		return ;
	close(fd);
}

void				receving(t_uenv *user, int fd)
{
	char			buff[1024];
	char			*line;
	int				r;
	int				maxsize;
	int				b;

	maxsize = 0;
	b = 0;
	ft_bzero(buff, 1024);
	if ((get_next_line(user->cs, &line)) > 0)
		b = ft_atoi(line);
	ft_bzero(buff, 1024);
	while ((r = recv(user->cs, buff, 1024, 0)) > 0)
	{
		maxsize += r;
		buff[r] = '\0';
		write(fd, buff, r);
		ft_bzero(buff, 1024);
		if (maxsize >= b)
			break ;
	}
}

void				file_put(t_uenv *user, char *data)
{
	char			*line;
	int				fd;

	if ((get_next_line(user->cs, &line)) > 0)
	{
		if (ft_strncmp(line, "FAILURE", 7) == 0)
		{
			write(1, "ERROR -> Could not open or create the file\n", 43);
		}
		else if (ft_strncmp(line, "SUCCESS", 7) == 0)
		{
			if ((fd = open(data, O_RDWR | O_CREAT | O_TRUNC, 0777)) == -1)
				write(1, "ERROR -> Could not open or create the file\n", 43);
			else
				receving(user, fd);
			close(fd);
		}
	}
}
