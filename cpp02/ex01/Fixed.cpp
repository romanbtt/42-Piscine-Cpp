/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:05:16 by romanbtt          #+#    #+#             */
/*   Updated: 2021/07/15 19:27:05 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"  
	
Fixed::Fixed( void ) : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed( int const input )
{
	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = input << this->_nbFractionalBits;
}

Fixed::Fixed( float const input )
{
	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = (int)roundf(input * (1 << this->_nbFractionalBits));
}

Fixed::Fixed( Fixed const & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}
	
Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

int		Fixed::getRawBits( void ) const
{
	return this->_rawBits;
}

void	Fixed::setRawBits( int const raw )
{
	this->_rawBits = raw;
}

float	Fixed::toFloat( void ) const
{
	 return (float)this->_rawBits / (float)(1 << this->_nbFractionalBits);
}

int		Fixed::toInt( void ) const
{
	return this->_rawBits >> this->_nbFractionalBits;
}

Fixed & Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Assignation operator called" << std::endl;
	this->_rawBits = rhs.getRawBits();
	return *this;
}

std::ostream & operator<<(std::ostream & output, Fixed const & rhs)
{
	output << rhs.toFloat();

	return output;
}

int const Fixed::_nbFractionalBits = 8;
