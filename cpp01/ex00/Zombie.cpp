/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 13:38:40 by romanbtt          #+#    #+#             */
/*   Updated: 2021/07/13 22:53:42 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string name ) : _name(name)
{
	return ;
}

Zombie::Zombie( void )
{
	return ;
}

Zombie::~Zombie( void )
{
	std::cout << this->_name << " has been killed by Rick Grimes. RIP";
	std::cout << std::endl;
}

std::string	Zombie::getName( void )
{
	return this->_name;
}

void	Zombie::setName( std::string name)
{
	this->_name = name;
}

void	Zombie::announce( void )
{
	std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
