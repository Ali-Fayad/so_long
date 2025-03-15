/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afayad <afayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:00:30 by afayad            #+#    #+#             */
/*   Updated: 2024/07/31 11:33:45 by afayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		clean_up(vars);
		exit(0);
	}
	else if (keycode == 119)
		key_w(vars);
	else if (keycode == 97)
		key_a(vars);
	else if (keycode == 115)
		key_s(vars);
	else if (keycode == 100)
		key_d(vars);
	return (0);
}

void	key_w(t_vars *vars)
{
	int	new_i;
	int	new_j;

	new_i = vars->player_y - 1;
	new_j = vars->player_x;
	if (is_within_bounds2(vars, new_i, new_j)
		&& vars->matrix[new_i][new_j] != '1')
	{
		if (vars->matrix[new_i][new_j] == 'E')
		{
			if (ft_count_collac(vars) == 0)
			{
				clean_up(vars);
				ft_printf("You win! ");
				exit (0);
			}
		}
		else
		{
			vars->matrix[new_i][new_j] = 'P';
			vars->matrix[vars->player_y][vars->player_x] = '0';
			vars->player_y = new_i;
			render_matrix(vars);
		}
	}
}

void	key_s(t_vars *vars)
{
	int	new_i;
	int	new_j;

	new_i = vars->player_y + 1;
	new_j = vars->player_x;
	if (is_within_bounds2(vars, new_i, new_j)
		&& vars->matrix[new_i][new_j] != '1')
	{
		if (vars->matrix[new_i][new_j] == 'E')
		{
			if (ft_count_collac(vars) == 0)
			{
				clean_up(vars);
				ft_printf("You win! ");
				exit (0);
			}
		}
		else
		{
			vars->matrix[new_i][new_j] = 'P';
			vars->matrix[vars->player_y][vars->player_x] = '0';
			vars->player_y = new_i;
			render_matrix(vars);
		}
	}
}

void	key_d(t_vars *vars)
{
	int	new_i;
	int	new_j;

	new_i = vars->player_y;
	new_j = vars->player_x + 1;
	if (is_within_bounds2(vars, new_i, new_j)
		&& vars->matrix[new_i][new_j] != '1')
	{
		if (vars->matrix[new_i][new_j] == 'E')
		{
			if (ft_count_collac(vars) == 0)
			{
				clean_up(vars);
				ft_printf("You win! ");
				exit (0);
			}
		}
		else
		{
			vars->matrix[new_i][new_j] = 'P';
			vars->matrix[vars->player_y][vars->player_x] = '0';
			vars->player_x = new_j;
			render_matrix(vars);
		}
	}
}

void	key_a(t_vars *vars)
{
	int	new_i;
	int	new_j;

	new_i = vars->player_y;
	new_j = vars->player_x - 1;
	if (is_within_bounds2(vars, new_i, new_j)
		&& vars->matrix[new_i][new_j] != '1')
	{
		if (vars->matrix[new_i][new_j] == 'E')
		{
			if (ft_count_collac(vars) == 0)
			{
				clean_up(vars);
				ft_printf("You win! ");
				exit (0);
			}
		}
		else
		{
			vars->matrix[new_i][new_j] = 'P';
			vars->matrix[vars->player_y][vars->player_x] = '0';
			vars->player_x = new_j;
			render_matrix(vars);
		}
	}
}
