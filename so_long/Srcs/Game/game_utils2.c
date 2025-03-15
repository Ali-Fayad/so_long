/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afayad <afayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:58:29 by afayad            #+#    #+#             */
/*   Updated: 2024/08/02 15:04:51 by afayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_within_bounds2(t_vars *vars, int i, int j)
{
	return (i >= 0 && i < vars->rows && j >= 0 && j < vars->cols);
}

int	ft_count_collac(t_vars *vars)
{
	int	i;
	int	j;
	int	count;
	int	rows;
	int	cols;

	i = 0;
	count = 0;
	rows = vars->rows;
	cols = vars->cols;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (vars->matrix[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	ft_startposition(t_vars *vars)
{
	int	i;
	int	j;
	int	rows;
	int	cols;

	i = 0;
	rows = vars->rows;
	cols = vars->cols;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (vars->matrix[i][j] == 'P')
			{
				vars->player_x = j;
				vars->player_y = i;
				break ;
			}
			j++;
		}
		i++;
	}
}

/* int main()
{
	t_vars	*vars;
	char	*filename = "output.txt";

	vars = malloc(sizeof(t_vars));
	vars->matrix = map2matrix(filename);
	vars->cols = ft_countfirstligne(filename);
	vars->rows = ft_countlignes(filename);
	int i = ft_count_collac(vars);
	printf("%d\n", i);
} */
