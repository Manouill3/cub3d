/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 06:10:05 by mdegache          #+#    #+#             */
/*   Updated: 2025/07/15 16:59:01 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_point
{
	int	y;
	int	x;

}		t_point;


typedef struct s_cub
{
    char        **map;
	int		    size_ver;
    t_point     cord;
	
}   t_cub;


#endif