/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarras <jocarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:51:04 by jocarras          #+#    #+#             */
/*   Updated: 2025/12/17 16:44:43 by jocarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_echo(char **argv)
{
	int	i;
	int	j;
	int	newline;

	i = 1;
	newline = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[i][j] == 'n')
			j++;
		if (argv[i][0] == '-' && j > 1 && argv[i][j] == '\0')
		{
			newline = 0;
			i++;
		}
		else
			break ;
	}
	while (argv[i])
	{
		write(1, argv[i], ft_strlen(argv[i]));
		if (argv[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (newline == 1)
		write(1, "\n", 1);
	return (0);
}



