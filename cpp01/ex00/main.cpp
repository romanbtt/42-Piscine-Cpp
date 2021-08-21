/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 14:20:18 by romanbtt          #+#    #+#             */
/*   Updated: 2021/07/13 20:10:29 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void )
{
	Zombie*	zombieOnHeap;
	Zombie*	zombieOnHeap2;
	Zombie	zombieOnStack ( "Walker" );

	zombieOnHeap = new Zombie( "Stinky" );
	zombieOnHeap->announce();
	zombieOnStack.announce();
	zombieOnHeap2 = newZombie( "Rotter" );
	zombieOnHeap2->announce();
	randomChump( "Walker Jr" );
	delete zombieOnHeap;
	delete zombieOnHeap2;
	return 0;
}