/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 14:55:13 by romanbtt          #+#    #+#             */
/*   Updated: 2021/08/05 21:56:59 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Integer.hpp"
#include "Float.hpp"
#include "Double.hpp"
#include "Char.hpp"

void	printValues( AScalar * convert )
{
	std::cout << std::fixed;
	try
	{
		std::cout << "char:   " << convert->toChar() << "'" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "int:    " << convert->toInt() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "float:  " << convert->toFloat() << "f" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "double: " << convert->toDouble() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int	main( int argc, char *argv[] )
{
	if (argc != 2)
	{
		std::cout << "The number of argument must be 1." << std::endl;
		return 1;
	}
	try
	{
		std::string scalar = argv[1];
		AScalar* convert = determineScalar(scalar);
		printValues(convert);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}