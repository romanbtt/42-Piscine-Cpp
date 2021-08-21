/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 17:46:16 by romanbtt          #+#    #+#             */
/*   Updated: 2021/07/12 12:50:17 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <locale>

/*
** Print "* LOUD AND UNBEARABLE FEEDBACK NOISE *" if no arguments was passed
** in parameter. Else, we iterate on each character and print the output of
** toupper to capitalize each character.
*/

int	main( int argc, char *argv[] )
{
	int i;
	int j;

	i = 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (argv[i] != NULL)
		{
			j = 0;
			while (argv[i][j] != '\0')
			{
				std::cout << (char)toupper(argv[i][j]);
				j++;
			}
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}
