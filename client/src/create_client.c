/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_client.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 15:56:37 by frcugy            #+#    #+#             */
/*   Updated: 2015/10/28 15:57:32 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

void					usage(char *str)
{
	printf("Usage: %s <addr> <port>\n", str);
	exit(-1);
}

int						create_client(char *addr, int port)
{
	int					g_sock;
	struct protoent		*proto;
	struct sockaddr_in	sino;

	if (ft_strcmp("localhost", addr) == 0)
		addr = ft_strdup("127.0.0.1");
	proto = getprotobyname("tcp");
	if (proto == 0)
		return (-1);
	g_sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sino.sin_family = AF_INET;
	sino.sin_port = htons(port);
	sino.sin_addr.s_addr = inet_addr(addr);
	if (connect(g_sock, (const struct sockaddr *)&sino, sizeof(sino)) == -1)
	{
		printf("Connection error\n");
		exit(2);
	}
	return (g_sock);
}
