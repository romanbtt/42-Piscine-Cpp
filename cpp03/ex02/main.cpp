/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 10:53:21 by romanbtt          #+#    #+#             */
/*   Updated: 2021/07/22 14:02:21 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void )
{
	ClapTrap angelo("Angelo");
	std::cout << std::endl;
	ScavTrap will("Will");
	std::cout << std::endl;
	FragTrap anthony("Anthony");
	
	std::cout << std::endl;

	angelo.attack("Will");
	will.takeDamage(angelo.getAttackDamage());
	
	std::cout << std::endl;

	will.beRepaired(5);

	std::cout << std::endl;

	will.attack("Angelo");
	angelo.takeDamage(will.getAttackDamage());

	std::cout << std::endl;

	angelo.beRepaired(10);

	std::cout << std::endl;

	will.guardGate();

	std::cout << std::endl;

	anthony.attack("Will");
	will.takeDamage(anthony.getAttackDamage());

	std::cout << std::endl;

	anthony.highFivesGuys();

	std::cout << std::endl;
	
	return 0;
}
