/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiplication.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:19:07 by kbarbry           #+#    #+#             */
/*   Updated: 2021/11/28 15:51:58 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	matrix_x_vector(t_matrix *m, t_vector *v)
{
	v->x = m->x[0] * v->x + m->x[1] * v->y + m->x[2] * v->z + m->x[3] * v->t;
	v->y = m->y[0] * v->x + m->y[1] * v->y + m->y[2] * v->z + m->y[3] * v->t;
	v->z = m->z[0] * v->x + m->z[1] * v->y + m->z[2] * v->z + m->z[3] * v->t;
	v->t = m->t[0] * v->x + m->t[1] * v->y + m->t[2] * v->z + m->t[3] * v->t;
	if (v->t != 1)
	{
		v->x /= v->t;
		v->y /= v->t;
		v->z /= v->t;
	}
}

void	matrix_x_matrix(t_matrix *m, t_matrix *v)
{
	v->x[0] = m->x[0] * v->x[0] + m->x[1] * v->y[0]
		+ m->x[2] * v->z[0] + m->x[3] * v->t[0];
	v->y[0] = m->y[0] * v->x[0] + m->y[1] * v->y[0]
		+ m->y[2] * v->z[0] + m->y[3] * v->t[0];
	v->z[0] = m->z[0] * v->x[0] + m->z[1] * v->y[0]
		+ m->z[2] * v->z[0] + m->z[3] * v->t[0];
	v->x[1] = m->x[0] * v->x[1] + m->x[1] * v->y[1]
		+ m->x[2] * v->z[1] + m->x[3] * v->t[1];
	v->y[1] = m->y[0] * v->x[1] + m->y[1] * v->y[1]
		+ m->y[2] * v->z[1] + m->y[3] * v->t[1];
	v->z[1] = m->z[0] * v->x[1] + m->z[1] * v->y[1]
		+ m->z[2] * v->z[1] + m->z[3] * v->t[1];
	v->x[2] = m->x[0] * v->x[2] + m->x[1] * v->y[2]
		+ m->x[2] * v->z[2] + m->x[3] * v->t[2];
	v->y[2] = m->y[0] * v->x[2] + m->y[1] * v->y[2]
		+ m->y[2] * v->z[2] + m->y[3] * v->t[2];
	v->z[2] = m->z[0] * v->x[2] + m->z[1] * v->y[2]
		+ m->z[2] * v->z[2] + m->z[3] * v->t[2];
	v->x[2] = m->x[0] * v->x[2] + m->x[1] * v->y[2]
		+ m->x[2] * v->z[2] + m->x[3] * v->t[2];
	v->y[2] = m->y[0] * v->x[2] + m->y[1] * v->y[2]
		+ m->y[2] * v->z[2] + m->y[3] * v->t[2];
	v->z[2] = m->z[0] * v->x[2] + m->z[1] * v->y[2]
		+ m->z[2] * v->z[2] + m->z[3] * v->t[2];
}
