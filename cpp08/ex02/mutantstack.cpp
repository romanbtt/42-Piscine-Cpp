/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 21:58:52 by romanbtt          #+#    #+#             */
/*   Updated: 2021/08/18 22:15:50 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"  
	
template < typename T >
MutantStack<T>::MutantStack( void )
{
	return ;
}

template < typename T >
MutantStack<T>::MutantStack( MutantStack<T> const & src )
{
	*this = src;
}

template < typename T >
MutantStack<T>::~MutantStack( void )
{
	return ;
}

template < typename T >
MutantStack<T> &	MutantStack<T>::operator=( MutantStack<T> const & rhs )
{
	if (this != &rhs)
		std::stack<T>::operator=(rhs);
	return *this;
}

template < typename T >
typename MutantStack<T>::iterator MutantStack<T>::begin( void )
{
	return this->c.begin();
}

template < typename T >
typename MutantStack<T>::iterator MutantStack<T>::end( void )
{
	return this->c.end();
}

template class MutantStack<int>;
template class MutantStack<float>;
template class MutantStack<std::string>;
