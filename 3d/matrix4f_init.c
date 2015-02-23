/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4f_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 13:48:39 by rbenjami          #+#    #+#             */
/*   Updated: 2015/02/19 16:48:34 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

MAT4	*init_perspective(float fov, float aspect, float z_near, float z_far)
{
	MAT4	*res;
	float	tan_half_fov;
	float	z_range;

	if ((res = (MAT4 *)ft_memalloc(sizeof(MAT4))) == NULL)
		return (NULL);
	tan_half_fov = tanf(fov / 2.0f);
	z_range = z_near - z_far;
	res->m[0][0] = 1.0f / (tan_half_fov * aspect);
	res->m[0][1] = 0;
	res->m[0][2] = 0;
	res->m[0][3] = 0;
	res->m[1][0] = 0;
	res->m[1][1] = 1.0f / tan_half_fov;
	res->m[1][2] = 0;
	res->m[1][3] = 0;
	res->m[2][0] = 0;
	res->m[2][1] = 0;
	res->m[2][2] = (-z_near - z_far) / z_range;
	res->m[2][3] = 2.0f * z_far * z_near / z_range;
	res->m[3][0] = 0;
	res->m[3][1] = 0;
	res->m[3][2] = 0;
	res->m[3][3] = 1;
	return (res);
}
