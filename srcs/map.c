/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:23:51 by aaires-b          #+#    #+#             */
/*   Updated: 2023/10/26 17:35:53 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

char  **create_map_cpy(char *filename)
{
	char **newmap;
	int i;
	int fd;

	fd = open(filename, O_RDONLY);
	if(fd < 0)
		exit(exit_free("Couldn't open file\n"));
	i = 0;
	newmap = ft_calloc((engine()->map.map_heigth + 1), sizeof(char *));
	if(!newmap)
		return (NULL);
	while (i < engine()->map.map_heigth)
	{
		newmap[i] = get_next_line(fd);
		i++;
	}
	newmap[i] = NULL;
	close(fd);
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
		exit(exit_free("Couldn't open file\n"));
	if(!create_map(filename, fd))
		exit(exit_free("Couldn't create map\n"));
	if(checker_map(filename))
		exit(exit_free("invalid map\n"));
}
