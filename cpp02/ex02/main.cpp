/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 16:50:23 by romanbtt          #+#    #+#             */
/*   Updated: 2021/07/15 18:59:22 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {

	std::cout << "----------- Tests 42 -----------\n" << std::endl;

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "\n----------- My tests -----------\n" << std::endl;
	
	Fixed float1( 42.50f );
	Fixed float2( 21.25f );

	std::cout << "Float1 = " << float1 << std::endl;
	std::cout << "Float2 = " << float2 << std::endl;
	std::cout << std::endl;

	std::cout << float1 << " > " << float2 << " ? > " << (float1 > float2);
	std::cout << std::endl;
	std::cout << float1 << " < " << float2 << " ? > " << (float1 < float2);
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << float1 << " >= " << float2 << " ? > " << (float1 >= float2);
	std::cout << std::endl;
	std::cout << float1 << " <= " << float2 << " ? > " << (float1 <= float2);
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << float1 << " == " << float2 << " ? > " << (float1 == float2);
	std::cout << std::endl;
	std::cout << float1 << " != " << float2 << " ? > " << (float1 != float2);
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << float1 << " + " << float2 << " = " << (float1 + float2);
	std::cout << std::endl;
	std::cout << float1 << " - " << float2 << " = " << (float1 - float2);
	std::cout << std::endl;
	std::cout << float1 << " * " << float2 << " = " << (float1 * float2);
	std::cout << std::endl;
	std::cout << float1 << " / " << float2 << " = " << (float1 / float2);
	std::cout << std::endl;
	std::cout << std::endl;
	
	std::cout << "max( " << float1 << ", " << float2 << " ) >  ";
	std::cout << Fixed::max( float1, float2 ) << std::endl;
	std::cout << "min( " << float1 << ", " << float2 << " ) >  ";
	std::cout << Fixed::min( float1, float2 ) << std::endl;
	std::cout << std::endl;

	std::cout << "float1++ > " << float1++ << std::endl;
	std::cout << "float1 > " << float1 << std::endl;
	std::cout << "++float1 > " << ++float1 << std::endl;
	std::cout << "float1 > " << float1 << std::endl;
	std::cout << std::endl;

	std::cout << "float2-- > " << float2-- << std::endl;
	std::cout << "float2 > " << float2 << std::endl;
	std::cout << "--float2 > " << --float2 << std::endl;
	std::cout << "float2 > " << float2 << std::endl;
	return 0;}