/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesanche <lesanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:50:17 by alamy             #+#    #+#             */
/*   Updated: 2017/12/12 14:02:52 by lesanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			is_shape_valid(char *str, int length)
{
	int row;
	int col;
	int i;

	if ((length + 1) % 21 != 0 || (length > 546) || length < 20)
		return (0);
	row = 0;
	col = 0;
	i = 0;
	while (i < length)
	{
		if (str[i] != '#' && str[i] != '.' && str[i] != '\n')
			return (0);
		if (str[i] != '\n')
			col++;
		if (str[i] == '\n')
		{
			if (((row % 5 != 4) && col != 4) || ((row % 5 == 4) && col != 0))
				return (0);
			col = 0;
			row++;
		}
		i++;
	}
	return (1);
}

static int	has_neighbor(char **tetri, int i, int j)
{
	int nb_contacts;

	nb_contacts = 0;
	if ((i > 0) && (tetri[i - 1][j] == '#'))
		nb_contacts++;
	if ((j > 0) && (tetri[i][j - 1] == '#'))
		nb_contacts++;
	if ((i < 3) && (tetri[i + 1][j] == '#'))
		nb_contacts++;
	if ((j < 3) && (tetri[i][j + 1] == '#'))
		nb_contacts++;
	return (nb_contacts);
}

static int	is_tetri_valid(char **tetri)
{
	int i;
	int j;
	int full_nb;
	int links;

	links = 0;
	full_nb = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (tetri[i][j] == '#')
			{
				if (has_neighbor(tetri, i, j) == 0)
					return (0);
				links = links + has_neighbor(tetri, i, j);
				full_nb++;
			}
		}
	}
	if (full_nb != 4 || links < 5)
		return (0);
	return (1);
}

int			check_tab(char ***tab, int nb_block)
{
	int num_block;

	num_block = 0;
	while (num_block < nb_block)
	{
		if (is_tetri_valid(tab[num_block]) == 0)
			return (0);
		num_block++;
	}
	return (1);
}
