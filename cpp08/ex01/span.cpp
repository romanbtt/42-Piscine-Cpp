/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 21:58:37 by romanbtt          #+#    #+#             */
/*   Updated: 2021/08/18 22:12:00 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"  
	
Span::Span( void ) : _n(0)
{
	return ;
}

Span::Span( unsigned int N ) : _n(N)
{
	return ;
}

Span::Span( Span const & src )
{
	*this = src;
}

Span::~Span( void )
{
	return ;
}

void	Span::addNumber( int value )
{
	if (_values.size() >= _n)
		throw CannotAddNewElementException();
	_values.push_back(value);
}

void	Span::addNumber( iteratorVectorInt begin, iteratorVectorInt end )
{
	if (static_cast<unsigned int>(_values.size() + std::distance(begin, end)) > _n)
		throw CannotAddNewElementException();
	_values.insert(_values.end(), begin, end);
}

unsigned int		Span::shortestSpan( void )
{
	unsigned int shortestSpan = UINT_MAX;

	if (_values.size() < 2)
		throw ElementsLessThanTwoException();
	std::sort(_values.begin(), _values.end());
	for (int i = 0; i < static_cast<int>(_values.size()); i++)
	{
		if (static_cast<unsigned int>(std::abs(_values[i] - _values[i + 1])) < shortestSpan)
			shortestSpan = std::abs(_values[i] - _values[i + 1]);
	}
	return shortestSpan;
}

unsigned int		Span::longestSpan( void )
{
	int	max;
	int	min;

	if (_values.size() < 2)
		throw ElementsLessThanTwoException();
	max = *std::max_element(_values.begin(), _values.end());
	min = *std::min_element(_values.begin(), _values.end());
	return max - min;
}

Span &	Span::operator=( Span const & rhs )
{
	if (this != &rhs)
	{
		_n = rhs._n;
		_values = rhs._values;
	}
	return *this;
}

const char* Span::CannotAddNewElementException::what(void) const throw ()
{
	return "Cannot add a new element in the vector.";
}

const char* Span::ElementsLessThanTwoException::what(void) const throw ()
{
	return "The elements are less than two.";
}