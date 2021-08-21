/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 12:22:25 by romanbtt          #+#    #+#             */
/*   Updated: 2021/08/02 14:47:29 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

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
		std::cerr << name << " : " << e.what() << std::endl;
		return NULL;
	}
}

AForm* createShrubberyCreationForm( std::string target )
{
	AForm* form;
	
	try
	{
		form = new ShrubberyCreationForm(target);
		return form;
	}
	catch(const std::exception& e)
	{
		if (target.empty())
			target = "<empty>";
		std::cerr << target << " : " << e.what() << std::endl;
		return NULL;
	}
}

AForm* createPresidentialPardonForm( std::string target )
{
	AForm* form;
	
	try
	{
		form = new PresidentialPardonForm(target);
		return form;
	}
	catch(const std::exception& e)
	{
		if (target.empty())
			target = "<empty>";
		std::cerr << target << " : " << e.what() << std::endl;
		return NULL;
	}
}

AForm* createRobotomyRequestForm( std::string target )
{
	AForm* form;
	
	try
	{
		form = new RobotomyRequestForm(target);
		return form;
	}
	catch(const std::exception& e)
	{
		if (target.empty())
			target = "<empty>";
		std::cerr << target << " : " << e.what() << std::endl;
		return NULL;
	}
}

AForm* createForm(Intern *intern, std::string formName, std::string target )
{
	AForm* form;
	
	try
	{
		form = intern->makeForm(formName, target);
		return form;
	}
	catch(const std::exception& e)
	{
		std::cerr << formName << " : " << e.what() << std::endl;
		return NULL;
	}
}

int main ( void )
{
	Bureaucrat* Jeltz = createBureaucrat("Prostetnic Vogon Jeltz", 73);
	Bureaucrat* Kwaltz = createBureaucrat("Prostetnic Vogon Kwaltz", 6);;

	std::cout << *Jeltz << std::endl;
	std::cout << *Kwaltz << std::endl;

	separator();

	Intern someRandomIntern;

	std::cout << someRandomIntern << std::endl;

	AForm* rrf;
	AForm* ppf;
	AForm* scf;
	AForm* other;
	AForm* rrfNoTarget;
	
	separator();

	rrf = createForm(&someRandomIntern, "robotomy request", "Bender");
	ppf = createForm(&someRandomIntern, "presidential pardon", "Ford Perfect");
	scf = createForm(&someRandomIntern, "shrubbery creation", "unbrain_room");

	separator();

	std::cout << *rrf << std::endl;
	std::cout << *ppf << std::endl;
	std::cout << *scf << std::endl;

	separator();

	other = createForm(&someRandomIntern, "other", "target");
	rrfNoTarget = createForm(&someRandomIntern, "robotomy request", "");
	
	(void)other;
	(void)rrfNoTarget;

	separator();
	
	Jeltz->signForm(*rrf);
	increment(Jeltz);
	Jeltz->signForm(*rrf);
	Kwaltz->executeForm(*rrf);
	Jeltz->signForm(*rrf);

	separator();

	Kwaltz->signForm(*ppf);
	Kwaltz->executeForm(*ppf);
	increment(Kwaltz);
	Kwaltz->executeForm(*ppf);

	separator();

	Kwaltz->executeForm(*scf);
	Kwaltz->signForm(*scf);
	Jeltz->executeForm(*scf);

	separator();

	std::cout << *rrf << std::endl;
	std::cout << *ppf << std::endl;
	std::cout << *scf << std::endl;

	delete rrf;
	delete ppf;
	delete scf;
	delete Jeltz;
	delete Kwaltz;

	return 0;
}