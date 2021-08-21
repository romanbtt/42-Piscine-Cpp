/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 16:43:58 by romanbtt          #+#    #+#             */
/*   Updated: 2021/08/18 21:51:42 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>

template< typename T >
typename T::iterator easyFind( T & container, int toFind )
{
	typename T::iterator it;
	
	it = std::find(container.begin(), container.end(), toFind);
	return it;
}
