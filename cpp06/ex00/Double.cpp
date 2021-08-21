/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 21:56:46 by romanbtt          #+#    #+#             */
/*   Updated: 2021/08/05 21:56:47 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Double.hpp"  
	
Double::Double( void )
{
	return ;
}

Double::Double( std::string value ) : AScalar(value)
{
	_value = strtod(value.c_str(), NULL);
}

Double::Double( Double const & src )
{
	*this = src;
}
	
Double::~Double( void )
{
	return ;
}

int		Double::toInt( void )
{
	if (_scalar == "-inf" || _scalar == "+inf" || _scalar == "nan"
		|| _value > 2147483647.0 || _value < -2147483648.0)
		throw AScalar::ImpossibleException();
	return static_cast<int>(_value);
}

float	Double::toFloat( void )
{
	int precision = _scalar.size() - _scalar.find('.') - 1;

	if (roundf(static_cast<float>(_value)) == static_cast<float>(_value))
		precision = 1;
	else if (precision > 6)
		precision = 6;
	std::cout << std::setprecision(precision);
	return static_cast<float>(_value);
}

double	Double::toDouble( void )
{
	int precision = _scalar.size() - _scalar.find('.') - 1;

	if (round(_value) == _value)
		precision = 1;
	else if (precision > 15)
		precision = 15;
	std::cout << std::setprecision(precision);
	return _value;
}

char	Double::toChar( void )
{
	if (_value >= 0.0 && _value <= 127.0)
	{
		if (isprint(_value) == 0)
			throw AScalar::NonDisplayableException();
	}
	else
		throw AScalar::ImpossibleException();
	return static_cast<char>(_value);
}

Double & Double::operator=( Double const & rhs )
{
	if (this != &rhs)
	{
		AScalar::operator=(rhs);
		_value = rhs._value;
	}
	return *this;
}