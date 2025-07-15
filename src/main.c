/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 06:30:22 by mdegache          #+#    #+#             */
/*   Updated: 2025/07/15 09:38:18 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

int	check_ext(char *file, char *ext)
{
	int	i;
	int	j;

	i = ft_strlen(file) - 1;
	j = ft_strlen(ext) - 1;
	if (ft_strlen(file) < 4)
		return (1);
	while (j > 0)
	{
		if (ext[j] != file[i])
			return (1);
		i--;
		j--;
	}
	return (0);	
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		if (check_ext(av[1], ".cub"))
		{
			write(2, "bad extension\n", 14);
			return (1);
		}
		return (0);
	}
	else 
		write(2, "too many or too few arguments\n", 30);
	return (0);
}
