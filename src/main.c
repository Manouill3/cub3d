/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 06:30:22 by mdegache          #+#    #+#             */
/*   Updated: 2025/07/15 12:39:44 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

t_cub  *ft_init(t_cub  *cub)
{
   	cub  = malloc(sizeof(t_cub));
    if (!cub)
        return (NULL);
    return (cub);
}    



int main(int ac, char **av)
{
	t_cub *cub;

	cub = NULL;
	if (ac == 2)
	{
		if (check_ext(av[1], ".cub"))
		{
			write(2, "bad extension\n", 14);
			return (1);
		}
		cub = ft_init(cub);
		ft_parsing(av, cub);
		free_all(cub);
		return (0);
	}
	else 
		write(2, "too many or too few arguments\n", 30);
	return (0);
}
