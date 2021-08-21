/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 14:49:15 by romanbtt          #+#    #+#             */
/*   Updated: 2021/07/30 12:20:59 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

static void	separator( void )
{
	std::cout << "\033[1;31m-- -- -- -- -- -- -- -- -- -- -- -- -- --\033[0m";
	std::cout << std::endl;
}

int main( void )
{
	{
		std::cout << "\033[1;34mTest Part 1 Polymorphism\033[0m\n" << std::endl;
	
		const Animal* meta = new Animal();
		separator();
		const Animal* j = new Dog();
		separator();
		const Animal* i = new Cat();
		separator();
		const Dog k;
		separator();
		const Dog l(k);
		separator();

		Dog roma;

		roma = l;
		
		std::cout << meta->getType() << " " << std::endl; // Nothing
		separator();
		std::cout << j->getType() << " " << std::endl; // Dog
		separator();
		std::cout << i->getType() << " " << std::endl; // Cat
		separator();
		std::cout << k.getType() << " " << std::endl; // Dog
		separator();
		std::cout << l.getType() << " " << std::endl; //Dog
		separator();
		i->makeSound(); // Meow Meow!
		separator();
		j->makeSound(); // Woof Woof!
		separator();
		k.makeSound(); // Woof Woof!
		separator();
		l.makeSound(); // Woof Woof!
		separator();
		meta->makeSound(); // No sound!
		separator();
		delete meta;
		separator();
		delete j;
		separator();
		delete i;
		separator();
	}
	
	std::cout << "\n" << std::endl;

	{
		std::cout << "\033[1;34mTest Part 2 Polymorphism\033[0m\n" << std::endl;

		const WrongAnimal* meta = new WrongAnimal();
		separator();
		const WrongAnimal* k = new WrongCat();
		separator();
		const WrongCat l;
		separator();
		const WrongCat j(l);
		separator();

		std::cout << meta->getType() << " " << std::endl; // Nothing
		separator();
		std::cout << k->getType() << " " << std::endl; // Wrong cat
		separator();
		std::cout << l.getType() << " " << std::endl; // Wrong cat
		separator();
		std::cout << j.getType() << " " << std::endl; // Wrong cat
		separator();
		k->makeSound(); // Wrong Meow Meow!
		separator();
		l.makeSound(); // Wrong Meow Meow!
		separator();
		j.makeSound(); // Wrong Meow Meow!
		separator();
		meta->makeSound(); // Wrong No sound!
		separator();
		delete meta;
		separator();
		delete k;
		separator();
	}

	return 0;
}