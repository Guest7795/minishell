#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>
# include "libft.h"


// ===== ENUMS =====
typedef enum e_redir_type {
	R_IN,
	R_OUT,
	R_APPEND,
	R_HEREDOC
}	t_redir_type;

// ===== STRUCTURES =====
typedef struct s_redir {
	t_redir_type	type;
	char			*target;
	int				heredoc_fd;
	struct s_redir	*next;
}	t_redir;

typedef struct s_cmd {
	char			**argv;
	t_redir			*redirs;
	int				is_builtin;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_shell {
	char	**envp;
	int		last_status;
}	t_shell;

// ===== PARSING =====
t_cmd	*parse_line(char *line, t_shell *sh);

// ===== UTILS =====
void	free_cmds(t_cmd *cmds);

/*EXEC*/
void	exec_simple(t_cmd *cmd, t_shell *sh);

int	builtin_echo(char **argv);

#endif
