/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 01:56:53 by albaud            #+#    #+#             */
/*   Updated: 2023/03/19 00:49:45 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	m_clean(double a[SIZE][SIZE])
{
	int		x;
	int		y;

	x = -1;

	while (++x < SIZE)
	{
		y = -1;
		while (++y < SIZE)
		{
			a[x][y] = 0;
		}
	}
}

void	m_copy(double dest[SIZE][SIZE], double src[SIZE][SIZE])
{
	int		x;
	int		y;

	x = -1;

	while (++x < SIZE)
	{
		y = -1;
		while (++y < SIZE)
		{
			dest[x][y] = src[x][y];
		}
	}
}

void	m_mult(double a[SIZE][SIZE], double b[SIZE][SIZE])
{
	int		x;
	int		y;
	int		z;
	double	t[SIZE][SIZE];

	x = -1;
	m_clean(t);
	while (++x < SIZE)
	{
		y = -1;
		while (++y < SIZE)
		{
			z = -1;
			while (++z < SIZE)
			{
				t[x][z] += a[x][y] * b[y][z];
			}
		}
	}
	m_copy(a, t);
}

void	m_print(double t[SIZE][SIZE], char *name)
{
	printf("printing matrix %s\n ", name);
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			printf("%f ", t[i][j]);
		}
		printf("\n");
	}
}

t_vector	m_4mult(const t_v3 *p, double m[4][4])
{
	t_vector	r;

	// r.x = p->x * m[0][0] + p->y * m[1][0] + p->z * m[2][0] + m[3][0];
	// r.y = p->x * m[0][1] + p->y * m[1][1] + p->z * m[2][1] + m[3][1];
	// r.z = p->x * m[0][2] + p->y * m[1][2] + p->z * m[2][2] + m[3][2];
	// r.w = p->x * m[0][3] + p->y * m[1][3] + p->z * m[2][3] + m[3][3];
	r.x = p->x * m[0][0] + p->y * m[0][1] + p->z * m[0][2] + m[0][3];
	r.y = p->x * m[1][0] + p->y * m[1][1] + p->z * m[1][2] + m[1][3];
	r.z = p->x * m[2][0] + p->y * m[2][1] + p->z * m[2][2] + m[2][3];
	r.w = p->x * m[3][0] + p->y * m[3][1] + p->z * m[3][2] + m[3][3];
	return (r);
}

t_v3	m_3mult(const t_v3 *p, double m[4][4])
{
	t_v3	r;

	// r.x = p->x * m[0][0] + p->y * m[1][0] + p->z * m[2][0] + m[3][0];
	// r.y = p->x * m[0][1] + p->y * m[1][1] + p->z * m[2][1] + m[3][1];
	// r.z = p->x * m[0][2] + p->y * m[1][2] + p->z * m[2][2] + m[3][2];
	// r.w = p->x * m[0][3] + p->y * m[1][3] + p->z * m[2][3] + m[3][3];
	r.x = p->x * m[0][0] + p->y * m[0][1] + p->z * m[0][2] + m[0][3];
	r.y = p->x * m[1][0] + p->y * m[1][1] + p->z * m[1][2] + m[1][3];
	r.z = p->x * m[2][0] + p->y * m[2][1] + p->z * m[2][2] + m[2][3];
	return (r);
}

t_v3	m_3mults(const t_v3 *p, double m[4][4])
{
	t_v3	r;

	// r.x = p->x * m[0][0] + p->y * m[1][0] + p->z * m[2][0] + m[3][0];
	// r.y = p->x * m[0][1] + p->y * m[1][1] + p->z * m[2][1] + m[3][1];
	// r.z = p->x * m[0][2] + p->y * m[1][2] + p->z * m[2][2] + m[3][2];
	// r.w = p->x * m[0][3] + p->y * m[1][3] + p->z * m[2][3] + m[3][3];
	r.x = p->x * m[0][0] + p->y * m[0][1] + p->z * m[0][2];
	r.y = p->x * m[1][0] + p->y * m[1][1] + p->z * m[1][2];
	r.z = p->x * m[2][0] + p->y * m[2][1] + p->z * m[2][2];
	return (r);
}


// void	m_transform(t_obj *obj, t_scene *scene)
// {
// 	double	t[SIZE][SIZE];
// 	double	tx;
// 	// double	ty;
// 	// double	tz;
// 	//t_v3	tv;

// 	m_clean(obj->transform);
// 	m_one(obj->transform);
// 	//###############TRANSPOSE################
// 	m_clean(t);
// 	m_one(t);
// 	t[0][3] = obj->pos.x;
// 	t[1][3] = obj->pos.y;
// 	t[2][3] = obj->pos.z;
// 	m_mult(obj->transform, t);	//####MULT####
// 	//###############TRANSPOSE################
// 	//###############XROTATION################
// 	m_rx(t, obj->orientation.x);
// 	m_mult(obj->transform, t);	//####MULT####
// 	//###############XROTATION################
// 	//###############YROTATION################
// 	m_ry(t, obj->orientation.y);
// 	m_mult(obj->transform, t);	//####MULT####
// 	//###############YROTATION################
// 	//###############ZROTATION################
// 	m_rz(t, obj->orientation.z);
// 	m_mult(obj->transform, t);	//####MULT####
// 	//###############ZROTATION################
// 	//###############SCALING##################
// 	m_clean(t);
// 	m_one(t);
// 	print_vector(scene->camera->pos, "camera");
// 	t[0][0] = obj->scale.x;
// 	t[1][1] = obj->scale.y;
// 	t[2][2] = obj->scale.z;
// 	(void) scene;
// 	m_mult(obj->transform, t);	//####MULT####
// 	//###############SCALING##################
// 	//###############INVERSE##################
// 	m_copy(obj->inverse_transform, obj->transform);
// 	tx = determin(obj->inverse_transform, 4);
// 	if(tx == 0)
// 		error("fuck my life");
// 	else
// 		m_inverse(obj->inverse_transform, 4);
// 	//###############INVERSE##################
// 	// m_mult(obj->transform, obj->inverse_transform);
// 	// m_print(obj->transform);
// }

// int	main(void)
// {
// 	double deter;
	
// 	double a[4][4] = {
// 		{1, 0, 0, 0},
// 		{0, 1, 0, 3},
// 		{0, 0, 1, 4},
// 		{0, 0, 0, 1}
// 	};

// 	double b[4][4] = {
// 		{0.71, 0, 0.71, 0},
// 		{0, 1, 0, 0},
// 		{-0.71, 0, 0.71, 0},
// 		{0, 0, 0, 1}
// 	};

// 	m_mult(a, b);
// 	m_print(a);
	
// }
// int main(){
// 	double matrix[4][4], deter;
// 	int a, b;
// 	deter = determin(matrix, 4);
// 	printf("\n The Determinant of the Matrix is : %f", deter);
// 	return(0);
// }