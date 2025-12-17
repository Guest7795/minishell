/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarras <jocarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:55:06 by jocarras          #+#    #+#             */
/*   Updated: 2025/12/17 18:16:52 by jocarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

int	main(int argc, char **argv, char **envp)
{
	t_shell	sh;
	char	*line;
	t_cmd	*cmds;

	(void)argc;
	(void)argv;
	sh.envp = envp;      // plus tard vous ferez une copie modifiable
	sh.last_status = 0;

	while (1)
	{
		line = readline("minideath$ ");
		if (!line) // Ctrl-D
			break ;
		if (*line)
			add_history(line);

		cmds = parse_line(line, &sh);
		if (cmds)
			exec_simple(cmds, &sh);
		printf("last_status = %d\n", sh.last_status);
		free_cmds(cmds);

		free(line);
	}
	return (0);
}
