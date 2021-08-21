/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 15:57:38 by romanbtt          #+#    #+#             */
/*   Updated: 2021/07/13 20:14:48 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void )
{
	Zombie*	horde;
	int		N = 10;
	int		i;

	horde = zombieHorde( N, "Walker" );
	for (i = 0; i < N; i++)
		horde[i].announce();
	delete [] horde;
	return 0;
}