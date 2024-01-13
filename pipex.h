/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:53:56 by fde-jesu          #+#    #+#             */
/*   Updated: 2024/01/12 23:28:18 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>

typedef struct s_pipex
{
	char	**path_arr1;
	char	**path_arr2;
	char	**cmd1_args;
	char	**cmd2_args;
	char	*path;
	char	*file1;
	char	*file2;
	int		fd1;
	int		fd2;
	char	*cmd_set1;
	char	*cmd_set2;
	char	*cmd1_path;
	char	*cmd2_path;
	char	*cmd1;
	char	*cmd2;	
}t_pipex;

char	**organize_env(char *path, char *cmd, t_pipex *pp);
void	check_comands(t_pipex *pipex);
void	ext(t_pipex *pp);
void	check_files(t_pipex *pipex);
void	init_pipe(t_pipex *pipex, char **argv);
void	find_path(char **env, t_pipex *pipex);
char	*get_access(char *cmd_path, char **path_exec);
void	pp(t_pipex *pipex, char **env);
void	proccess_child2(t_pipex *pp, int *fd, char **env);
void	proccess_child(t_pipex *pp, int *fd, char **env);
void	exit_pipe(t_pipex *pp);

#endif