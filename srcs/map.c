/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:23:51 by aaires-b          #+#    #+#             */
/*   Updated: 2023/10/15 16:07:06 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

char  **create_map_cpy(char **map)
{
	char **newmap;
	int i;

	i = 0;
	newmap = ft_calloc((engine()->map.map_heigth + 1), sizeof(char *));
	if(!newmap)
		return (NULL);
	while (map[i])
	{
		newmap[i] = map[i];
		i++;
	}
	return(newmap);
}
void pass_file_tomap(int fd, int heigth)
{
	int i;

	i = 0;
	while(i < heigth)
	{
		engine()->map.map_grid[i]= get_next_line(fd);
		i++;
		//printf("i: %d\n", i);
		//printf("heigth : %d\n", heigth);
	}
	engine()->map.map_grid[i]= NULL;
}
int create_map(char *filename, int fd)
{
	int heigth;
	char *line;

	line = get_next_line(fd);
	heigth = 1;
	free(line);
	while(heigth > 0)
	{
		
		line = get_next_line(fd);
		if(line == NULL)
			break ;
		heigth++;
		//printf("heigth : %d\n", heigth);
		free(line);
	}	
	if(!line && heigth > 0)
		engine()->map.map_grid = malloc(sizeof(char *) * (heigth + 1));
	if(!engine()->map.map_grid)
		return (0);
	close(fd);
	pass_file_tomap(open(filename, O_RDONLY), heigth);
	engine()->map.map_heigth = heigth;
	return(1);
}

void readfile(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if(fd < 0)
		exit(exit_free("Couldn't open file"));
	if(!create_map(filename, fd))
		exit(exit_free("Couldn't create map"));
	// while(i < game->map.map_heigth)
	// {
		// printf("%s", game->map.map_grid[i]);
		// i++;
	// }
	if(checker_map())
		exit(exit_free("invalid map"));
}
