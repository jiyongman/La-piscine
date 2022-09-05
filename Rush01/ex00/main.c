/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 19:25:29 by gyoon             #+#    #+#             */
/*   Updated: 2022/05/29 13:03:29 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		solve(int **room, int *view, int solved);
int		**init_room(void);
void	free_room(int **room);
int		init_view(int *list, char *view);
void	print_error(void);
void	print_room(int **room);

int	main(int argc, char **argv)
{
	int	**room;
	int	view[16];
	int	check_view;

	if (argc == 2)
	{
		room = init_room();
		check_view = init_view(view, argv[1]);
		if (check_view != 1)
			print_error();
		else
		{
			solve(room, view, 0);
			print_room(room);
			free_room(room);
		}
	}
	else
		print_error();
	return (0);
}
