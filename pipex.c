/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarian <lemarian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:57:26 by lemarian          #+#    #+#             */
/*   Updated: 2024/10/21 14:52:00 by lemarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec(char *command, char **ep)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(command, ' ');
	if (access(command, X_OK) == -1)
		path = get_path(cmd[0], ep);
	else
		path = ft_strdup(command);
	if (!path)
	{
		ft_print_error("Command '%s' not found\n", cmd[0]);
		free_array(cmd);
		exit (EXIT_FAILURE);
	}
	if (execve(path, cmd, NULL) == -1)
	{
		ft_print_error("Command '%s' not found\n", cmd[0]);
		free_array(cmd);
		free(path);
		exit (EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

void	exec_child_2(char **av, char **ep, int pipe[2])
{
	int	outfile;

	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
	{
		ft_print_error("%s: Permission denied\n", av[4]);
		close(pipe[0]);
		close(pipe[1]);
		exit(EXIT_FAILURE);
	}
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	dup2(pipe[0], STDIN_FILENO);
	close(pipe[1]);
	close(pipe[0]);
	exec(av[3], ep);
}

void	exec_child_1(char **av, char **ep, int pipe[2])
{
	int	infile;

	if (access(av[1], F_OK) == -1)
	{
		ft_print_error("%s: No such file or directory\n", av[1]);
		close(pipe[0]);
		close(pipe[1]);
		exit(EXIT_FAILURE);
	}
	infile = open(av[1], O_RDONLY);
	if (infile < 0)
	{
		ft_print_error("%s: Permission denied\n", av[1]);
		close(pipe[0]);
		close(pipe[1]);
		exit(EXIT_FAILURE);
	}
	dup2(infile, STDIN_FILENO);
	close(infile);
	dup2(pipe[1], STDOUT_FILENO);
	close(pipe[0]);
	close(pipe[1]);
	exec(av[2], ep);
}

void	parent(char **av, char **ep)
{
	int		end[2];
	pid_t	child_1;
	pid_t	child_2;

	pipe(end);
	child_1 = fork();
	if (child_1 == -1)
		return ;
	if (child_1 == 0)
		exec_child_1(av, ep, end);
	child_2 = fork();
	if (child_2 == -1)
		return ;
	if (child_2 == 0)
		exec_child_2(av, ep, end);
	close(end[0]);
	close(end[1]);
	wait(NULL);
	wait(NULL);
}

int	main(int ac, char **av, char **ep)
{
	if (ac != 5)
	{
		ft_putstr_fd("Wrong argument count\n", 2);
		return (1);
	}
	parent(av, ep);
	return (0);
}
