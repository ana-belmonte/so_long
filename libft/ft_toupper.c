/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:18:11 by aaires-b          #+#    #+#             */
/*   Updated: 2023/10/02 13:46:28 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int u)
{
	if (u >= 'a' && u <= 'z')
	{
		u -= 32;
	}
	return (u);
}

/*int main()
{
	int u = 97;
	
	printf("%c", ft_toupper(u));
	return (0);
}*/