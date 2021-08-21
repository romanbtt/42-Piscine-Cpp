/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 21:11:42 by romanbtt          #+#    #+#             */
/*   Updated: 2021/07/13 20:42:40 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"
	
HumanA::HumanA( std::string name, Weapon &weapon ) :
	_name(name), _weapon(weapon)
{
	return ;
}

HumanA::~HumanA()
{
	return ;
}

void	HumanA::attack( void )
{
	std::cout << this->_name << " attacks with his ";
	std::cout << this->_weapon.getType() << std::endl;
}
