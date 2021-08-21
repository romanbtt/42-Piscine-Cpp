/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 21:56:50 by romanbtt          #+#    #+#             */
/*   Updated: 2021/08/05 21:56:51 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Float.hpp"  
	
Float::Float( void )
{
	return ;
}

Float::Float( std::string value ) : AScalar(value)
{
	_value = strtof(value.c_str(), NULL);
}

Float::Float( Float const & src )
{
	*this = src;
}
	
Float::~Float( void )
{
	return ;
}

int		Float::toInt( void )
{
	if (_scalar == "-inff" || _scalar == "+inff" || _scalar == "nanf")
		throw AScalar::ImpossibleException();
	return static_cast<int>(_value);
}

float	Float::toFloat( void )
{
	int precision =_scalar.size() - _scalar.find('.') - 2;

	if (roundf(_value) == _value)
		precision = 1;
	else if (precision > 6)
		precision = 6;
	std::cout << std::setprecision(precision);
	return _value;
}

double	Float::toDouble( void )
{
	int precision =_scalar.size() - _scalar.find('.') - 2;

	if (round(static_cast<double>(_value)) == static_cast<double>(_value))
		precision = 1;
	else if (precision > 15)
		precision = 15;
	std::cout << std::setprecision(precision);
	return static_cast<double>(_value);
}

char	Float::toChar( void )
{
	if (_value >= 0.0f && _value <= 127.0f)
	{
		if (isprint(_value) == 0)
			throw AScalar::NonDisplayableException();
	}
	else
		throw AScalar::ImpossibleException();
	std::cout << "'";
	return static_cast<char>(_value);
}

Float & Float::operator=( Float const & rhs )
{
	if (this != &rhs)
	{
		AScalar::operator=(rhs);
		_value = rhs._value;
	}
	return *this;
}
