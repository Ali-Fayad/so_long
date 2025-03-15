/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afayad <afayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:13:30 by afayad            #+#    #+#             */
/*   Updated: 2024/08/02 17:09:08 by afayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	init_and_load_matrix(t_vars *vars, char *filename)
{
	vars->matrix = map2matrix(filename);
	if (!vars->matrix)
	{
		ft_printf("Failed to load matrix from file\n");
		exit (1);
	}
	vars->rows = ft_countlignes(filename);
	vars->cols = ft_countfirstligne(filename);
	printf("Matrix dimensions: %d rows x %d cols\n", vars->rows, vars->cols);
	return (1);
}

static int	validate_and_solve(t_vars *vars, char *filename)
{
	if (!ft_valid(vars->matrix, filename,
			(t_matrixschema){vars->rows, vars->cols}))
	{
		ft_printf("Map validation failed\n");
		exit (1);
	}
	if (!ft_solution(vars->matrix, (t_matrixschema){vars->rows, vars->cols}))
	{
		ft_printf("No valid solution found\n");
		exit (1);
	}
	return (1);
}

int	main(void)
{
	t_vars	*vars;
	char	*filename;

	filename = "output.txt";
	vars = init_mlx();
	if (!vars)
		return (EXIT_FAILURE);
	if (!init_and_load_matrix(vars, filename))
	{
		clean_up(vars);
		return (EXIT_FAILURE);
	}
	if (!validate_and_solve(vars, filename))
	{
		clean_up(vars);
		return (EXIT_FAILURE);
	}
	load_resources(vars);
	mlx_key_hook(vars->win, key_hook, vars);
	render_matrix(vars);
	mlx_loop(vars->mlx);
	clean_up(vars);
	return (EXIT_SUCCESS);
}
