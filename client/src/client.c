/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/18 13:59:23 by frcugy            #+#    #+#             */
/*   Updated: 2015/10/28 16:00:22 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

void					handler(void)
{
	close(g_sock);
	exit(0);
}

void					print_prompt(void)
{
	ft_putstr(C_NONE);
	ft_putstr(C_BOLD);
	ft_putstr("ft_p >> ");
	ft_putstr(C_NONE);
	ft_putstr(C_GRAY);
}

void					get_data(void)
{
	int				r;
	char			*line;

	r = 0;
	while ((r = get_next_line(g_sock, &line)) > 0)
	{
		if (ft_strcmp("SUCCES", line) == 0)
		{
			write(0, "\nSUCCES\n", 8);
			break ;
		}
		else if (ft_strcmp("ERROR", line) == 0)
		{
			write(0, "\nERROR\n", 7);
			break ;
		}
		printf("%s\n", line);
	}
}

int						core(int r, char *buff)
{
	char				**param;

	ft_putstr(C_NONE);
	ft_putstr(C_GREEN);
	buff[r] = '\0';
	param = ft_split_whitespaces(buff);
	send(g_sock, buff, ft_strlen(buff), 0);
	if (ft_strcmp(buff, "quit\n") == 0)
		return (1);
	ft_bzero(buff, 1024);
	if (param[0] && ft_strcmp("get", param[0]) == 0)
		file_get(param[1]);
	else if (param[0] && ft_strcmp("put", param[0]) == 0)
	{
		if (param[1] && param[2] == NULL)
			put_file(param[1]);
		else
			write(1, "ERROR -> Need a file name as second parameter\n", 46);
	}
	else
		get_data();
	print_prompt();
	return (0);
}

int						main(int argc, char **argv)
{
	int					port;
	int					r;
	char				buff[1024];

	if (argc != 3)
		usage(argv[0]);
	port = ft_atoi(argv[2]);
	g_sock = create_client(argv[1], port);
	signal(SIGINT, (void(*)())handler);
	print_prompt();
	while ((r = read(0, buff, 1024)) > 0)
		if (core(r, buff) == 1)
			break ;
	close(g_sock);
	return (0);
}
