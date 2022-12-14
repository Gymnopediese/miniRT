/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 01:56:53 by albaud            #+#    #+#             */
/*   Updated: 2022/12/14 23:34:57 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"


void trans(double [][4], double [][4], int); //for transpose of matrix
void m_inverse(double [][4], int); //for cofactors of matrix
double determin(double [][4], int); //for determinant of matrix

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

void	m_one(double t[SIZE][SIZE])
{
	int	i;

	i = -1;
	while (++i < SIZE)
		t[i][i] = 1;
}

void	m_rx(double t[SIZE][SIZE], const double teta)
{
	m_clean(t);
	m_one(t);
	t[1][1] = cos(teta);
	t[2][1] = sin(teta);
	t[1][2] = -sin(teta);
	t[2][2] = cos(teta);
}

void	m_ry(double t[SIZE][SIZE], const double teta)
{
	m_clean(t);
	m_one(t);
	t[0][0] = cos(teta);
	t[2][0] = -sin(teta);
	t[0][2] = sin(teta);
	t[2][2] = cos(teta);
}

void	m_rz(double t[SIZE][SIZE], const double teta)
{
	m_clean(t);
	m_one(t);
	t[0][0] = cos(teta);
	t[1][0] = sin(teta);
	t[0][1] = -sin(teta);
	t[1][1] = cos(teta);
}

void	m_print(double t[SIZE][SIZE])
{
	printf("printing matrix\n ");
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

void	m_transform(t_obj *obj, t_scene *scene)
{
	double	t[SIZE][SIZE];
	double	tx;
	double	ty;
	double	tz;
	t_v3	tv;

	if (obj->id != CYLINDRE)
		return ;
		//obj->orientation = (t_v3){1, 1, 1};
	m_clean(obj->transform);
	m_one(obj->transform);
	obj->transform[0][0] = 2;
	m_clean(t);
	m_one(t);
	t[0][3] = obj->pos.x;
	t[1][3] = obj->pos.y;
	t[2][3] = obj->pos.z;
	(void) scene;
	m_mult(obj->transform, t);
	// ty = -asin(obj->orientation.x);
	// tx = -asin(obj->orientation.y / cos(ty));
	// tz = -asin(obj->orientation.y);
	tv = v_mult(&obj->orientation, &(t_v3){0, 1, 1});
	tx = -v_angle(&obj->orientation, &tv);
	tv = v_mult(&obj->orientation, &(t_v3){1, 1, 0});
	tz = -v_angle(&obj->orientation, &tv);
	tv = v_mult(&obj->orientation, &(t_v3){1, 0, 1});
	ty = -v_angle(&obj->orientation, &tv);
	printf("%f %f %f\n",tx, ty,tz);
	m_rx(t, tx);
	m_mult(obj->transform, t);
	m_ry(t, ty);
	m_mult(obj->transform, t);
	m_rz(t, tz);
	m_mult(obj->transform, t);
	m_copy(obj->inverse_transform, obj->transform);
	tx = determin(obj->inverse_transform, 4);
	if(tx == 0)
		error("fuck my life");
	else
		m_inverse(obj->inverse_transform, 4);
	m_print(obj->transform);
	m_print(obj->inverse_transform);
	// m_mult(obj->transform, obj->inverse_transform);
	// m_print(obj->transform);
}

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

// This function is to find the determinant value of matrix . . .

  double determin(double matrix[4][4], int k){
            double deter=0.0, z=1.0, mt[4][4];
            int a, b, c, x, y;
            if(k==1)
           {
           return(matrix[0][0]);
           }
           else
          {
          deter=0;
          for(a=0;a<k;++a){
          x=0;
          y=0;
          for(b=0;b<k;++b){
          for(c=0;c<k;++c){
          mt[b][c]=0;
          if((b != 0) && (c != a))
          {
           mt[x][y]=matrix[b][c];
           if(y<(k-2))
           y++;
           else
           {
           y=0;
           x++;
           }
           }
           }
           }
           deter=deter + z * (matrix[0][a] * determin(mt,k-1));
           z=-1 * z;
           }
           }
           return(deter);
           }

// This function is to find cofactors of matrix . . .

  void m_inverse(double comatr[4][4], int f){
           double matr[4][4], cofact[4][4];
           int a, b, c, d, x, y;
           for(c=0; c<f; ++c){
           for(d=0; d<f; ++d){
           x=0;
           y=0;
           for(a=0;a<f; ++a){
           for(b=0; b<f; ++b){
           if(a != c && b != d)
           {
           matr[x][y]=comatr[a][b];
           if(y<(f-2))
           y++;
           else
           {
           y=0;
           x++;
           }
           }
           }
           }
           cofact[c][d] = pow(-1,c + d) * determin(matr,f-1);
           }
           }
           trans(comatr, cofact, f);
           }

// This function is to transpose of matrix . . .
void trans(double matr[4][4], double m1[4][4], int r){
	double inv_matrix[4][4], tran[4][4], d;
	int a,b;
	for(a=0;a<r;++a){
		for(b=0;b<r;++b){
			tran[a][b]=m1[b][a];
		}
	}
	d=determin(matr, r);
	for(a=0;a<r;++a){
		for(b=0;b<r;++b){
			inv_matrix[a][b]=tran[a][b] / d;
		}
	}
	m_copy(matr, inv_matrix);
}