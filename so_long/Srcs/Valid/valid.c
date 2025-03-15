/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afayad <afayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:23:11 by afayad            #+#    #+#             */
/*   Updated: 2024/08/02 16:29:46 by afayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_firstvalid(char *filename)
{
	int	line_check;
	int	element_check;

	line_check = ft_checklignes(filename);
	if (line_check != 1)
		return (0);
	element_check = ft_checkelements(filename);
	if (element_check != 1)
		return (0);
	return (1);
}

int	ft_secondvalid(char **mat, char *filename, int rows, int cols)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < rows)
	{
		if (mat[i] == NULL)
		{
			ft_printf("Error: Matrix row %d is NULL\n", i);
			exit (1);
		}
		while (j < cols)
			j++;
		i++;
	}
	if (ft_checkfirstligne(filename) != 1 || ft_checklastligne(filename) != 1)
		return (0);
	return (1);
}

int	ft_valid(char **mat, char *filename, t_matrixschema x)
{
	int				first_valid_result;

	first_valid_result = ft_firstvalid(filename);
	if (x.rows <= 0 || x.cols <= 0)
		return (0);
	if (first_valid_result == 0)
		return (0);
	if (first_valid_result == 1
		&& ft_secondvalid(mat, filename, x.rows, x.cols) == 1)
		return (1);
	return (0);
}

/* int main(void)
{
	t_matrixschema x;
	char *filename = "output.txt";
	char **mat;

	// Check file validity and number of lines
	if (ft_firstvalid(filename) != 1) {
		printf("File validation failed.\n");
		return (0); // Exit with an error code
	}

	x.rows = ft_countlignes(filename);
	x.cols = ft_countfirstligne(filename);

	// Ensure that line counts are valid
	if (x.rows <= 0 || x.cols <= 0) {
		fprintf(stderr, "Invalid number of rows or columns.\n");
		return (1);
	}

	// Read the matrix from the file
	mat = map2matrix(filename);

	// Check if matrix was successfully allocated
	if (mat == NULL) {
		fprintf(stderr, "Failed to allocate memory for matrix.\n");
		return (1);
	}

	// Perform second validation
	if (ft_secondvalid(mat, filename, x.rows, x.cols) != 1) {
		fprintf(stderr, "Second validation failed.\n");
		// Free the matrix if it was allocated
		for (int i = 0; i < x.rows; ++i)
			free(mat[i]);
		free(mat);
		return (1);
	}

	// Print solution result
	printf("firstvalid: %d\n", ft_firstvalid(filename));
	printf("secondvalid: %d\n", ft_secondvalid(mat, filename, x.rows, x.cols));
	printf("solution: %d\n", ft_solution(mat, x));

	// Free the matrix memory
	for (int i = 0; i < x.rows; ++i)
		free(mat[i]);
	free(mat);

	return (0);
} */
