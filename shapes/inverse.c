/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 23:26:34 by albaud            #+#    #+#             */
/*   Updated: 2023/03/19 00:55:46 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"
void	trans(double matr[4][4], double m1[4][4], int r);

// This function is to find the determinant value of matrix . . .
typedef struct s_iter
{
	int	a;
	int	b;
	int	c;
	int	d;
	int	x;
	int	y;
}	t_iter;


double	determin(double matrix[4][4], int k)
{
	double	deter;
	double	z;
	double	mt[4][4];
	t_iter	i;

	deter = 0.0;
	z = 1.0;

	if (k == 1)
		return (matrix[0][0]);
	deter = 0;
	i.a = -1;
	while (++i.a < k)
	{
		i.x = 0;
		i.y = 0;
		i.b = -1;
		while (++i.b < k)
		{
			i.c = -1;
			while (++i.c < k)
			{
				mt[i.b][i.c] = 0;
				if (i.b != 0 && i.c != i.a)
				{
					mt[i.x][i.y] = matrix[i.b][i.c];
					if (i.y < k - 2)
						i.y++;
					else
					{
						i.y = 0;
						i.x++;
					}
				}
			}
		}
		deter = deter + z * (matrix[0][i.a] * determin(mt, k - 1));
		z = -1 * z;
	}
	return (deter);
}

// This function is to find cofactors of matrix . . .
void	m_inverse(double comatr[4][4], int f)
{
	double	matr[4][4];
	double	cofact[4][4];
	t_iter	i;

	i.c = -1;
	while (++i.c < f)
	{
		i.d = -1;
		while (++i.d < f)
		{
			i.x = 0;
			i.y = 0;
			i.a = -1;
			while (++i.a < f)
			{
				i.b = -1;
				while (++i.b < f)
				{
					if (i.a != i.c && i.b != i.d)
					{
						matr[i.x][i.y] = comatr[i.a][i.b];
						if (i.y < f - 2)
							i.y++;
						else
						{
							i.y = 0;
							i.x++;
						}
					}
				}
			}
			cofact[i.c][i.d] = pow(-1, i.c + i.d) * determin(matr, f - 1);
		}
	}
	trans(comatr, cofact, f);
}

// This function is to transpose of matrix . . .
void	trans(double matr[4][4], double m1[4][4], int r)
{
	double	inv_matrix[4][4];
	double	tran[4][4];
	double	d;
	int		a;
	int		b;

	a = -1;
	while (++a < r)
	{
		b = -1;
		while (++b < r)
			tran[a][b] = m1[b][a];
	}
	d = determin(matr, r);
	a = -1;
	while (++a < r)
	{
		b = -1;
		while (++b < r)
			inv_matrix[a][b] = tran[a][b] / d;
	}
	m_copy(matr, inv_matrix);
}
