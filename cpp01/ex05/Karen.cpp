/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 19:00:24 by romanbtt          #+#    #+#             */
/*   Updated: 2021/07/13 21:06:48 by romanbtt         ###   ########.fr       */
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
	}
}

void	Karen::debug( void )
{
	std::cout << "I love to get extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger. ";
	std::cout << "I just love it!" << std::endl;
}

void	Karen::info( void )
{
	std::cout << "I cannot believe adding extra bacon cost more money. ";
	std::cout << "You don’t put enough! ";
	std::cout << "If you did I would not have to ask for it!";
	std::cout << std::endl;
}

void	Karen::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I’ve been coming here for years and you just started ";
	std::cout << "working here last month." << std::endl;
}

void	Karen::error( void )
{
	std::cout << "This is unacceptable, I want to speak to the manager now.";
	std::cout << std::endl;
}
