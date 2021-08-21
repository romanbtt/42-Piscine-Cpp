/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 14:49:15 by romanbtt          #+#    #+#             */
/*   Updated: 2021/07/29 22:36:51 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Chicken.hpp"

static void	separator( void )
{
	std::cout << "\033[1;31m-- -- -- -- -- -- -- -- -- -- -- -- -- --\033[0m";
	std::cout << std::endl;
}

int main( void )
{
	{
		std::cout << "\033[1;34mTest Part 1 Simple test\033[0m\n" << std::endl;

		const Animal* j = new Dog();
		separator();
		const Animal* i = new Cat();
		separator();
		const Animal* k = new Chicken();
		separator();

		std::cout << j->getType() << std::endl; // Dog
		separator();
		std::cout << i->getType() << std::endl; // Cat
		separator();
		std::cout << k->getType() << std::endl; // Chicken
		separator();

		j->makeSound(); // Woof Woof!
		separator();
		i->makeSound(); // Meow Meow!
		separator();
		k->makeSound(); // Bwok Bwok!
		separator();
		
		delete j;
		separator();
		delete i;
		separator();
		delete k;
		separator();
	}

	std::cout << "\n" << std::endl;

	{
		std::cout << "\033[1;34mTest Part 2 Array\033[0m\n" << std::endl;

		Animal *arrayAnimal[4];
		
		for (int i = 0; i < 4; i++)
		{
			if (i % 2 == 0)
				arrayAnimal[i] = new Dog;
			else
				arrayAnimal[i] = new Cat;
			separator();
		}
		for (int i = 0; i< 4; i++)
		{
			std::cout << arrayAnimal[i]->getType() << " :";
			arrayAnimal[i]->makeSound();
		}	
		separator();
		for (int i = 0; i < 4; i++)
		{
			delete arrayAnimal[i];
			separator();
		}	
	}

	std::cout << "\n" << std::endl;

	{
		std::cout << "\033[1;34mTest Part 3 Deep copy\033[0m\n" << std::endl;

		Dog *original1 = new Dog;
		separator();
		Cat *original2 = new Cat;
		separator();
		Chicken run;
		separator();
		Dog copy1(*original1);
		separator();
		Cat copy2 = *original2;
		separator();
		std::cout << original1->getType() << "'s idea : " << original1->getBrain()->getIdea(4) << std::endl;
		separator();
		std::cout << original2->getType() << "'s idea : " << original2->getBrain()->getIdea(7) << std::endl;
		separator();
		delete original1;
		separator();
		delete original2;
		separator();
		std::cout << copy1.getType() << "'s idea : " << copy1.getBrain()->getIdea(4) << std::endl;
		separator();
		std::cout << copy2.getType() << "'s idea : " << copy2.getBrain()->getIdea(7) << std::endl;
		separator();
		//run.getBrain(); // Can't compile. Chicken don't have brain
	}
	return 0;
}