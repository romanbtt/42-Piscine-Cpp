/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 20:28:29 by romanbtt          #+#    #+#             */
/*   Updated: 2021/07/13 20:17:41 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"

int	main( void )
{
	std::string string = "HI THIS IS BRAIN";
	std::string *strinPTR = &string;
	std::string &stringREF = string;

	std::cout << "Adress in memory of :\n" << std::endl;
	std::cout << "variable string     : " << &string << std::endl;
	std::cout << "pointer stringPTR   : " << strinPTR << std::endl;
	std::cout << "reference stringREF : " << &stringREF << std::endl;
	
	std::cout << "\nContent of :\n" << std::endl;
	std::cout << "pointer stringPTR   : " << *strinPTR << std::endl;
	std::cout << "reference stringREF : " << stringREF << std::endl;
	return 0;
}