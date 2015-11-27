/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 16:31:26 by frcugy            #+#    #+#             */
/*   Updated: 2015/10/29 15:39:31 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

int					ft_command2(char *data, t_uenv *user, char **param)
{
	if (param[0] && ft_strcmp(param[0], "ls") == 0)
	{
		user = core(user, data);
		send(user->cs, "SUCCES\n", 7, 0);
		return (1);
	}
	else if (param[0] && ft_strcmp(param[0], "cd") == 0)
	{
		ft_cd(&user, ft_strsplit(data, ' '));
		send(user->cs, "SUCCES\n", 7, 0);
		return (1);
	}
	else if (param[0] && ft_strcmp(param[0], "get") == 0)
	{
		file_get(user, data);
		return (1);
	}
	return (0);
}

int					ft_command3(t_uenv *user, char **param)
{
	if (param[0] && ft_strcmp(param[0], "put") == 0)
	{
		if (param[1] && param[2] == NULL)
			file_put(user, param[1]);
		else
		{
			((param[1] == NULL) ? printf("ERROR -> Not enough arguments\n")
			: printf("ERROR -> Too many arguments\n"));
		}
		return (1);
	}
	else if (param[0] && ft_strcmp(param[0], "pwd") == 0 && param[1] == NULL)
	{
		send(user->cs, ft_strjoin(user->pwd, "\n"), ft_strlen(user->pwd) + 1,
		0);
		send(user->cs, "SUCCES\n", 7, 0);
		return (1);
	}
	return (0);
}

int					ft_command4(t_uenv *user, char **param)
{
	if (param[0] && ft_strcmp(param[0], "quit") == 0 && param[1] == NULL)
	{
		send(user->cs, "Exit\n", 5, 0);
		close(user->cs);
		return (0);
	}
	else
	{
		send(user->cs, "Wrong command\n", 14, 0);
		send(user->cs, "ERROR\n", 6, 0);
	}
	return (1);
}

int					ft_command(char *data, t_uenv *user, char *pwd)
{
	char		**param;

	if (data[0] == '\0')
	{
		send(user->cs, "Wrong command\n", 14, 0);
		send(user->cs, "ERROR\n", 6, 0);
		return (1);
	}
	param = ft_split_whitespaces(data);
	(void)pwd;
	if (ft_command2(data, user, param) == 1)
		return (1);
	if (ft_command3(user, param) == 1)
		return (1);
	if (ft_command4(user, param) == 0)
		return (0);
	return (1);
}
