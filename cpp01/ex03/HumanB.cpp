/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 21:11:45 by romanbtt          #+#    #+#             */
/*   Updated: 2021/07/13 22:58:59 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"  
	
HumanB::HumanB( std::string name ) : _name(name)
{
	return ;
}
	
HumanB::~HumanB( void )
{
	return ;
}

void	HumanB::attack( void )
{
	std::cout << this->_name << " attacks with his ";
	std::cout << (*this->_weapon).getType() << std::endl;
}

void	HumanB::setWeapon( Weapon &weapon )
{
	_weapon = &weapon;
}
