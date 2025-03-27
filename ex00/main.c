#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	put_n(int r, int c, int n, char *matrix);

int	check_arguments(char *str, int n)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (i % 2 == 0)
		{
			if ((str[i] < '1') || (str[i] > (n + '0')))
				return (0);
			count ++;
		}
		else 
		{
			if (str[i] != 32)
				return (0);
		}
		i++;
	}
	
		if (count != (n * 4))
			return (0);
	return (1);
}

char	**create_matrix(int dim)
{
	char	**matrix;
	int 	cnt;

	cnt = 0;
	matrix = (char **) malloc((dim + 2) * sizeof(char *));
	if (!matrix)
		return (0);
	while (cnt < (dim + 2))
	{
		matrix[cnt] = (char *) malloc((dim + 2) * sizeof(char));
		if (!matrix[cnt])
			return (0);
		cnt ++;
	}
	return (matrix);
}

int	**create_int_matrix(int dim)
{
	int	**matrix;
	int 	i;

	i = 0;
	matrix = malloc(dim * sizeof(int *));
	if (!matrix)
		return (0);
	while (i < dim)
	{
		matrix[i] = malloc(dim * sizeof(int));
		if (!matrix[i])
			return (0);
		i++;
	}
	return (matrix);
}

void	set_int_matrix(int **matrix, int dim)
{
	int i;
	int j;

	i = 0;
	while (i < dim)
	{
		j = 0;
		while (j < dim)
		{
			matrix[i][j] = 0;
			j++;
		}
		i++;	
	}
}


int	is_valid_row(char *matrix, int dim)
{
	int	j;
	int	*row;
	int	dig_idx;

	row = (int *) malloc(dim * sizeof(int *));
	if (!row)
	{
		return (0);
	}
	
	j = 0;
	while (j < dim)
	{
		row[j] = 0;
		j++;
	}
	j = 1;
	while (j <= dim)
	{
		dig_idx = (matrix[j] - '0') - 1;
		row[dig_idx]++;
		j++;
	}
	j = 0;
	while( j < dim)
	{
		if (row[j] != 1)
		{
			free(row);
			return (0);
		}
		j++;
	}
	free(row);
	return (1);
}

void	copy_row(char **matrix, int dim, int i, char *str)
{
	int	j;
	int	k;

	j = 1;
	k = 0;
	while (j <= dim)
	{
		matrix[i][j] = str[k];
		j++;
		k++;
	}
}

void	copy_column(char **matrix, int dim, int j, char *str)
{
	int	i;
	int	k;

	i = 1;
	k = 0;
	while (i <= dim)
	{
		matrix[i][j] = str[k];
		i++;
		k++;
	}
}

void	ft_free(char **matrix, int dim)
{
	int cnt;

	cnt = 0;
	while (cnt < (dim + 2))
	{
		free(matrix[cnt]);
		cnt ++;
	}
	free(matrix);
}

void	retrieve_args(char *args, char *digits, int dim)
{
	int	idx;
	int	count;

	idx = 0;
	count = 0;
	while (count < (dim * 4))
	{
		digits[count] = args[idx];
		count++;
		idx += 2;
	}
}

void	print_matrix(char **matrix, int dim, char p_all)
{
	int i;
	int j;

	if (p_all)
	{
		i = 0;
		while (i < (dim + 2))
		{
			j = 0;
			while (j < (dim + 2))
			{
				write(1, &matrix[i][j], 1);
				j++;
			}
			write(1,"\n", 1);
			i++;	
		}
				
	}
}

void	fill_matrix(char **matrix, int dim, char  digit)
{
	int i;
	int j;

	i = 0;
	while (i < (dim + 2))
	{
		j = 0;
		while (j < (dim + 2))
		{
			matrix[i][j] = digit;
			j++;
		}
		i++;	
	}
}

void	put_args(char **matrix, int dim, char *digits)
{
	copy_row(matrix, dim, 0, digits);
	copy_row(matrix, dim, dim + 1, &digits[dim]);
	copy_column(matrix, dim, 0, &digits[dim * 2]);
	copy_column(matrix, dim, dim + 1, &digits[dim * 3]);
}

void to_int(char *args, int *constraints, int dim)
{
	int i;

	i = 0;
	while (i < dim * 4)
	{
		constraints[i] = args[i] - '0';
		i++;
	}
}

void	print_grid(int **matrix, int dim)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while(i < dim)
	{
		j = 0;
		while (j < dim)
		{
			if (j != 0)
				write(1, " ", 1);
			c = matrix[i][j] + '0';
			write(1, &c, 1);
			j++;
		}
		write(1 , "\n", 1);
		i++;
	}
}


int	is_valid(int **matrix, int size, int pos, int num)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (matrix[pos / size][i] == num)
			return (0);
		if (matrix[i][pos % size] == num)
			return (0);
		i++;
	}
	return (1);
}

int	up_count(int **matrix, int dim, int view)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	while (i < dim)
	{
		if (matrix[i][view] > max)
		{
			max = matrix[i][view];
			count++;
		}
		i++;
	}
	return (count);
}

int	down_count(int **matrix, int dim, int view)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	while (i < dim)
	{
		if (matrix[dim - i - 1][view] > max)
		{
			max = matrix[dim - i - 1][view];
			count++;
		}
		i++;
	}
	return (count);
}

int	left_count(int **matrix, int dim, int view)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	while (i < dim)
	{
		if (matrix[view][i] > max)
		{
			max = matrix[view][i];
			count++;
		}
		i++;
	}
	return (count);
}

int	right_count(int **matrix, int dim, int view)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	while (i < dim)
	{
		if (matrix[view][dim - i - 1] > max)
		{
			max = matrix[view][dim - i - 1];
			count++;
		}
		i++;
	}
	return (count);
}


int	check_all(int **matrix, int dim, int *constraint)
{
	int	i;

	i = 0;
	while (i < dim)
	{
		if (up_count(matrix, dim, i) != constraint[i])
			return (0);
		if (down_count(matrix, dim, i) != constraint[dim + i])
			return (0);
		if (left_count(matrix, dim, i) != constraint[dim * 2 + i])
			return (0);
		if (right_count(matrix, dim, i) != constraint[dim * 3 + i])
			return (0);
		i++;
	}
	return 1;
}


int	solve(int **matrix, int dim, int pos, int *constraint)
{
	int	num;
	int x;
	int y;

	if (pos == dim * dim)
	{
		if (check_all(matrix, dim, constraint))
		{
			print_grid(matrix, dim);
			return (1);
		}
		return (0);
	}
	num = 1;
	x = pos % dim;
	y = pos / dim;
	while (num <= dim)
	{
		if (is_valid(matrix, dim, pos, num))
		{
			matrix[y][x] = num;
			if (solve(matrix, dim, pos + 1, constraint))
				return (1);
			matrix[y][x] = 0;
		}
		num++;
	}
	return (0);
}


int	main(int argc, char **argv)
{
	int	dim;
	//char	**matrix;
	int	**int_matrix;
	char	*args;
	int constraints[36];

	// char test[] = {'1','2','3','4'};
	// printf("%d", is_valid_row(test, 4));
	//matrix = NULL;
	//args = NULL;
	dim = 4;
	if (argc == 2)
	{
		if (check_arguments(argv[1], dim) == 0)
			//return print_error("Input not valid\n");
			printf ("error\n");

		args = (char *) malloc(dim * 4 * sizeof(char));
		retrieve_args(argv[1], args, dim);
		// matrix = create_matrix(dim);
		// fill_matrix(matrix, dim, '0');
		// put_args(matrix, dim, args);
		// print_matrix(matrix, dim, 1);

		int_matrix = create_int_matrix(dim);
		set_int_matrix(int_matrix, dim);
		to_int(args, constraints, dim);
		solve(int_matrix, dim, 0, constraints);
	}
	free(args);
	// ft_free(matrix, dim);
	return (0);
}

/*void	put_n(int r, int c, int n, char *matrix)
{
	
}*/
