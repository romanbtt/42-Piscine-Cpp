/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Integer.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 21:56:53 by romanbtt          #+#    #+#             */
/*   Updated: 2021/08/05 21:56:54 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Integer.hpp"  
	
Integer::Integer( void )
{
	return ;
}

Integer::Integer( std::string value ) : AScalar(value)
{
	std::stringstream ss(value);

	ss >> _value;
}

Integer::Integer( Integer const & src )
{
	*this = src;
}
	
Integer::~Integer( void )
{
	return ;
}

int		Integer::toInt( void )
{
	return _value;
}

float	Integer::toFloat( void )
{
	std::cout << std::setprecision(1);;
	return static_cast<float>(_value);
}

double	Integer::toDouble( void )
{
	std::cout << std::setprecision(1);
	return static_cast<double>(_value);
}

char	Integer::toChar( void )
{
	if (_value >= 0 && _value <= 127)
	{
		if (isprint(_value) == 0)
			throw AScalar::NonDisplayableException();
	}
	else
		throw AScalar::ImpossibleException();
	std::cout << "'";
	return static_cast<char>(_value);
}

Integer & Integer::operator=( Integer const & rhs )
{
	if (this != &rhs)
	{
		AScalar::operator=(rhs);
		_value = rhs._value;
	}
	return *this;
}