/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 16:30:14 by frcugy            #+#    #+#             */
/*   Updated: 2015/10/28 16:36:06 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

static void			fork_child(t_uenv *user)
{
	int							ret;
	char						pwd[4096];
	char						data[1024];

	getcwd(pwd, 4096);
	while (42)
	{
		if ((ret = recv(user->cs, data, 1024, 0)) > 0)
		{
			data[ret - 1] = '\0';
			printf("[%d] \x1B[33mreceived %d bytes: [%s]\x1B[0m\n",
					user->cs, ret, data);
			if (ft_command(data, user, pwd) == 0)
				return ;
			ft_strclr(data);
		}
		else
			break ;
		ret = 0;
	}
	close(user->cs);
}

int					go_fork(int cs)
{
	pid_t					parent;
	t_uenv					*user;

	user = NULL;
	if ((parent = fork()) == -1)
	{
		return (0);
	}
	if (!parent)
	{
		printf("[\x1B[32mO\x1B[0m] New user [%d] connected\n", cs);
		env_push_back(&user, cs);
		fork_child(user);
		printf("[\x1B[31mX\x1B[0m] User [%d] disconnected\n", cs);
		close(cs);
		return (0);
	}
	return (1);
}
