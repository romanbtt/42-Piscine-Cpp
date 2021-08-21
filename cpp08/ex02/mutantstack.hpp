/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 21:58:49 by romanbtt          #+#    #+#             */
/*   Updated: 2021/08/18 22:14:28 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <stack>
#include <iterator>
#include <iostream>

template<typename T>
class MutantStack : public std::stack<T>  
{

	public:

		MutantStack( void );
		MutantStack( MutantStack<T> const & src );
		virtual ~MutantStack( void );

		MutantStack<T> &	operator=( MutantStack<T> const & rhs );

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin( void );
		iterator end( void );

};
#endif