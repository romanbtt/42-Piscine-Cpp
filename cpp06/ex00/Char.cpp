/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Char.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 21:56:37 by romanbtt          #+#    #+#             */
/*   Updated: 2021/08/06 11:04:50 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Char.hpp"  
	
Char::Char( void )
{
	return ;
}

Char::Char( std::string value ) : AScalar(value)
{
	if (isprint(value[0]) == 0)
		throw CharIsNonPrintableException();
	_value = value[0];
}

Char::Char( Char const & src )
{
	*this = src;
}
	
Char::~Char( void )
{
	return ;
}

int		Char::toInt( void )
{
	return static_cast<int>(_value);
}

float	Char::toFloat( void )
{
	int precision = 1;

	std::cout << std::setprecision(precision);
	return static_cast<float>(_value);
}

double	Char::toDouble( void )
{
	int precision = 1;
	
	std::cout << std::setprecision(precision);
	return static_cast<double>(_value);
}

char	Char::toChar( void )
{
	std::cout << "'";
	return _value;
}

Char & Char::operator=( Char const & rhs )
{
	if (this != &rhs)
	{
		AScalar::operator=(rhs);
		_value = rhs._value;
	}
	return *this;
}

const char * Char::CharIsNonPrintableException::what( void ) const throw()
{
	return "The char must be printable.";
}