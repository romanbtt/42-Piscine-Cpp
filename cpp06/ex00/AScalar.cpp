/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AScalar.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 21:56:29 by romanbtt          #+#    #+#             */
/*   Updated: 2021/08/05 21:56:35 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AScalar.hpp"  
	
AScalar::AScalar( void )
{
	return ;
}

AScalar::AScalar( std::string scalar ) : _scalar(scalar)
{
	return ;
}
	
AScalar::AScalar( AScalar const & src )
{
	*this = src;
}

AScalar::~AScalar( void )
{
	return ;
}

std::string	AScalar::getScalar( void ) const
{
	return _scalar;
}

AScalar & AScalar::operator=( AScalar const & rhs )
{
	if (this != &rhs)
		_scalar = rhs._scalar;
	return *this;
}

const char * AScalar::NonDisplayableException::what( void ) const throw()
{
	return "Non displayable";
}

const char * AScalar::ImpossibleException::what( void ) const throw()
{
	return "impossible";
}

const char * AScalar::WrongScalarValueException::what( void ) const throw()
{
	return "The literal doesn't belong to a type of char, int, float or double.";
}