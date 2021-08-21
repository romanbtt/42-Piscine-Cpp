/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 20:58:19 by romanbtt          #+#    #+#             */
/*   Updated: 2021/07/11 20:52:53 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitel.hpp"

/*
** Until getline() returns a valid stream.
** We compare the input to the given commands.
** If one of them matches, we call the right function.
** If not, we come back to getline().
*/

int main( void )
{
	std::string	input;
	Minitel		minitel;

	std::cout << "Enter a command: [ADD] [SEARCH] [EXIT] : ";
	while (std::getline(std::cin, input))
	{
		if (input.compare("ADD") == 0)
			minitel.add();
		else if (input.compare("SEARCH") == 0)
			minitel.search();
		else if (input.compare("EXIT") == 0)
		{
			std::cout << "Bye! Thank you for choosing minitel!" << std::endl;
			break;
		}
		else
			std::cout << "Command not found!" << std::endl;
		std::cout << "Enter a command: [ADD] [SEARCH] [EXIT] : ";
	}
	return (0);
}
