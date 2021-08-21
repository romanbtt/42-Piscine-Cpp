/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 21:11:50 by romanbtt          #+#    #+#             */
/*   Updated: 2021/07/13 20:42:22 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"  
	
Weapon::Weapon( std::string type) : _type(type)
{
	return ;
}
	
Weapon::~Weapon()
{
	return ;
}

std::string const& Weapon::getType() const
{
	return this->_type;
}

void	Weapon::setType( std::string type )
{
	this->_type = type;
}
