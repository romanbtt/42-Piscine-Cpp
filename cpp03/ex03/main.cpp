/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 10:53:21 by romanbtt          #+#    #+#             */
/*   Updated: 2021/07/22 14:02:39 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main( void )
{
	ClapTrap angelo("Angelo");
	std::cout << std::endl;
	ScavTrap will("Will");
	std::cout << std::endl;
	FragTrap anthony("Anthony");
	std::cout << std::endl;
	DiamondTrap diego("Diego");
	
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

	diego.whoAmI();

	std::cout << std::endl;

	std::cout << "Hit Points : " << diego.getHitPoints() << std::endl;
	std::cout << "Energy Points : " << diego.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage : " << diego.getAttackDamage() << std::endl;

	std::cout << std::endl;
	
	diego.attack("Anthony");
	anthony.takeDamage(diego.getAttackDamage());

	std::cout << std::endl;

	diego.highFivesGuys();
	diego.guardGate();

	std::cout << std::endl;
	
	return 0;
}
