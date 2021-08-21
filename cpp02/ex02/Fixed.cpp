/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 16:52:01 by romanbtt          #+#    #+#             */
/*   Updated: 2021/07/15 19:06:48 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"  
	
Fixed::Fixed( void ) : _rawBits(0)
{
	return ;
}

Fixed::Fixed( int const input )
{
	this->_rawBits = input << this->_nbFractionalBits;
}

Fixed::Fixed( float const input )
{
	this->_rawBits = (int)roundf(input * (1 << this->_nbFractionalBits));
}

Fixed::Fixed( Fixed const & src )
{
	*this = src;
}
	
Fixed::~Fixed( void )
{
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
	this->_rawBits = rhs.getRawBits();
	return *this;
}

bool Fixed::operator>( Fixed const & rhs ) const
{
	return this->toFloat() > rhs.toFloat();
}

bool Fixed::operator<( Fixed const & rhs ) const
{
	return this->toFloat() < rhs.toFloat();
}

bool Fixed::operator>=( Fixed const & rhs ) const
{
	return this->toFloat() >= rhs.toFloat();
}

bool Fixed::operator<=( Fixed const & rhs ) const
{
	return this->toFloat() <= rhs.toFloat();
}

bool Fixed::operator==( Fixed const & rhs ) const
{
	return this->toFloat() == rhs.toFloat();
}

bool Fixed::operator!=( Fixed const & rhs ) const
{
	return this->toFloat() != rhs.toFloat();
}

Fixed Fixed::operator+( Fixed const & rhs ) const
{
	return this->toFloat() + rhs.toFloat();
}

Fixed Fixed::operator-( Fixed const & rhs ) const
{
	return this->toFloat() - rhs.toFloat();
}

Fixed Fixed::operator*( Fixed const & rhs ) const
{
	return this->toFloat() * rhs.toFloat();
}

Fixed Fixed::operator/( Fixed const & rhs ) const
{
	return this->toFloat() / rhs.toFloat();
}

Fixed & Fixed::operator++( void )
{
	this->_rawBits++;
	return *this;
}

Fixed Fixed::operator++( int )
{
	Fixed temp(*this);
	this->operator++();
	return temp;
}

Fixed & Fixed::operator--( void )
{
	this->_rawBits--;
	return *this;
}

Fixed Fixed::operator--( int )
{
	Fixed temp(*this);
	this->operator--();
	return temp;
}

std::ostream & operator<<(std::ostream & output, Fixed const & rhs)
{
	output << rhs.toFloat();

	return output;
}

Fixed const & Fixed::min( Fixed const & first, Fixed const & second)
{
	if (first < second)
		return first;
	else
		return second;
}

Fixed const & Fixed::max( Fixed const & first, Fixed const & second)
{
	if (first > second)
		return first;
	else
		return second;
}

int const Fixed::_nbFractionalBits = 8;
