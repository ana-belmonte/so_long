/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:48:51 by aaires-b          #+#    #+#             */
/*   Updated: 2023/10/13 13:00:24 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	ft_linesize(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n' )
		i++;
	return (i);
}

char	*ft_create(char *s1, char *s2)
{
	char	*newstr;
	int		i;
	int		j;

	newstr = (char *)malloc((ft_linesize(s1) + ft_linesize(s2) + 1));
	if (!newstr)
		return (NULL);
	i = 0;
	j = -1;
	while (s1 && s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2 && s2[++j])
	{
		newstr[i++] = s2[j];
		if (s2[j] == '\n')
			break ;
	}
	newstr[i] = '\0';
	free(s1);
	return (newstr);
}

void	cleanbuffer(char *buffer, int *flag)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (buffer[i])
	{
		if (*flag == 1)
		{
			buffer[j] = buffer[i];
			j++;
		}
		if (buffer[i] == '\n')
			*flag = 1;
		buffer[i] = 0;
		i++;
	}
}
