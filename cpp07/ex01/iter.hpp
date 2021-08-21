/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 21:52:54 by romanbtt          #+#    #+#             */
/*   Updated: 2021/08/11 15:15:23 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
#define ITER_H

#include <iostream>
#include <string>
#include <iomanip>

template < typename T >
void	iter(T *array, size_t length, void (*func)(T const &))
{
	if (array == NULL)
		return ;
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

#endif