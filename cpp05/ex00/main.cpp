/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 11:47:24 by romanbtt          #+#    #+#             */
/*   Updated: 2021/08/02 14:55:31 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

static void	separator( void )
{
	std::cout << "\033[1;31m-- -- -- -- -- -- -- -- -- -- -- -- -- --\033[0m";
	std::cout << std::endl;
}

void		increment( Bureaucrat * bureaucrat )
{
	try
	{
		bureaucrat->incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << bureaucrat->getName() << " : " << e.what() << std::endl;
	}
}

void		decrement( Bureaucrat * bureaucrat )
{
	try
	{
		bureaucrat->decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << bureaucrat->getName() << " : " << e.what() << std::endl;
	}
}

Bureaucrat* createBureaucrat( std::string name, int grade )
{
	try
	{
		return new Bureaucrat(name, grade);
	}
	catch( const std::exception& e )
	{
		if (name.empty())
			name = "<empty>";
		std::cerr << name << " : " << e.what() << std::endl;
		return NULL;
	}
}

int main( void )
{
	Bureaucrat* tooLow = createBureaucrat("tooLow", 151);
	Bureaucrat* tooHigh = createBureaucrat("tooHigh", 0);
	Bureaucrat* noName = createBureaucrat("", 50);
	Bureaucrat* Jeltz = createBureaucrat("Prostetnic Vogon Jeltz", 150);
	Bureaucrat* Kwaltz = createBureaucrat("Prostetnic Vogon Kwaltz", 1);

	(void)tooLow;
	(void)tooHigh;
	(void)noName;
	
	separator();

	decrement(Jeltz);
	increment(Kwaltz);

	separator();

	increment(Jeltz);
	decrement(Kwaltz);

	std::cout << *Jeltz << std::endl;
	std::cout << *Kwaltz << std::endl;

	delete Jeltz;
	delete Kwaltz;

	return 0;
}