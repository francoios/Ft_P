/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 12:39:01 by frcugy            #+#    #+#             */
/*   Updated: 2015/10/28 17:06:25 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

int					check_dir(char *param)
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
					send(g_sock, "FAILURE\n", 8, 0);
					closedir(dir);
					return (1);
				}
			}
		}
	}
	closedir(dir);
	return (0);
}

int					sending(int fd)
{
	int				length;
	char			*addr;
	struct stat		sb;
	char			*str;

	if (fstat(fd, &sb) == -1)
	{
		printf("Error -> Protected file\n");
		send(g_sock, "FAILURE\n", 8, 0);
		close(fd);
		return (1);
	}
	length = sb.st_size;
	addr = mmap(0, length, PROT_READ, MAP_PRIVATE, fd, 0);
	str = ft_strjoin(ft_itoa(length), "\n");
	send(g_sock, "SUCCESS\n", 8, 0);
	send(g_sock, str, ft_strlen(str), 0);
	send(g_sock, addr, length, 0);
	write(1, "SUCCESS\n", 8);
	return (0);
}

void				put_file(char *name)
{
	int		fd;

	if (ft_strcmp("/", name) == 0)
	{
		printf("Error -> File not found\n");
		send(g_sock, "FAILURE\n", 8, 0);
		return ;
	}
	if ((fd = open(name, O_RDONLY)) < 0)
	{
		printf("Error -> File not found\n");
		send(g_sock, "FAILURE\n", 8, 0);
		return ;
	}
	if (check_dir(name) == 1)
		return ;
	if (sending(fd) == 1)
		return ;
	close(fd);
}

void				receving(int fd)
{
	char			buff[1024];
	char			*line;
	int				r;
	int				maxsize;
	int				b;

	maxsize = 0;
	b = 0;
	ft_bzero(buff, 1024);
	if ((get_next_line(g_sock, &line)) > 0)
		b = ft_atoi(line);
	ft_bzero(buff, 1024);
	while ((r = recv(g_sock, buff, 1024, 0)) > 0)
	{
		maxsize += r;
		buff[r] = '\0';
		write(fd, buff, r);
		ft_bzero(buff, 1024);
		if (maxsize >= b)
			break ;
	}
}

void				file_get(char *data)
{
	char			*line;
	int				fd;

	if ((get_next_line(g_sock, &line)) > 0)
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
			{
				receving(fd);
				write(1, "SUCCESS\n", 8);
			}
			close(fd);
		}
	}
}
