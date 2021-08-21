/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 15:46:05 by romanbtt          #+#    #+#             */
/*   Updated: 2021/07/13 21:31:14 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	int			i;
	Zombie*		zombies = new Zombie[N];
	std::string index;

	for (i = 0; i < N; i++)
	{
		std::stringstream ss;
		ss << i + 1;
		ss >> index;
		zombies[i].setName( name + index);
	}	
	return zombies;
}