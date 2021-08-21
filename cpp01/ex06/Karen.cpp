/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 19:00:20 by romanbtt          #+#    #+#             */
/*   Updated: 2021/07/13 21:26:37 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"  
	
Karen::Karen( void )
{
	return ;
}
	
Karen::~Karen( void )
{
	return ;
}

void	Karen::complain( std::string level )
{
	int			i;
	std::string strFunctions[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	t_level		ptrFunctions[4] = { &Karen::debug, &Karen::info,
									&Karen::warning, &Karen::error };

	for (i = 0; i < 4; i++)
	{
		if (level.compare(strFunctions[i]) == 0)
		{
			(this->*ptrFunctions[i])();
			break;
		}
		if (i == 3)
		{
			std::cout << "[ Probably complaining about insignificant ";
			std::cout << " problems ]\n" << std::endl;
		}	
	}
}

void	Karen::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love to get extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger.\n";
	std::cout << "I just love it!\n" << std::endl;
	Karen::info();
}

void	Karen::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon cost more money.\n";
	std::cout << "You don’t put enough!\n";
	std::cout << "If you did I would not have to ask for it!\n";
	std::cout << std::endl;
	Karen::warning();
}

void	Karen::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free.\n";
	std::cout << "I’ve been coming here for years and you just started ";
	std::cout << "working here last month.\n" << std::endl;
	Karen::error();
}

void	Karen::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now.\n";
	std::cout << std::endl;
}
