/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determineScalar.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:35:17 by romanbtt          #+#    #+#             */
/*   Updated: 2021/08/06 11:39:56 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Integer.hpp"
#include "Float.hpp"
#include "Double.hpp"
#include "Char.hpp"

bool	isInteger( std::string scalar )
{
	int integer;
	std::stringstream ss(scalar);

	if (ss >> integer && !(ss >> scalar))
		return true;
	return false;
}

bool	isDouble( std::string scalar )
{
	char *ptr;
	
	if (scalar == "-inf" || scalar == "+inf" || scalar == "nan")
		return true;
	if (scalar.empty() || scalar.find('.') == std::string::npos
		|| scalar.find('e') != std::string::npos)
		return false;
	strtod(scalar.c_str(), &ptr);
	if (*ptr == '\0')
		return true;
	return false;
}

bool	isFloat( std::string scalar )
{
	char *ptr;
	size_t len = scalar.length();
	
	if (scalar == "-inff" || scalar == "+inff" || scalar == "nanf")
		return true;
	if (scalar.empty() || scalar.find('.') == std::string::npos
		|| scalar.find('e') != std::string::npos)
		return false;
	strtof(scalar.c_str(), &ptr);
	if (*ptr == 'f' && scalar[len - 1] == 'f' && scalar[len - 2] != 'f')
		return true;
	return false;
}

bool	isChar( std::string scalar )
{
	if (scalar.length() != 1)
		return false;
	return true;
}

AScalar * determineScalar( std::string scalar )
{
	if (isInteger(scalar))
		return new Integer(scalar);
	else if (isFloat(scalar))
		return new Float(scalar);
	else if (isDouble(scalar))
		return new Double(scalar);
	else if (isChar(scalar))
		return new Char(scalar);
	else
		throw AScalar::WrongScalarValueException();
}