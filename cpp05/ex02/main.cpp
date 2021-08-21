/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 12:22:25 by romanbtt          #+#    #+#             */
/*   Updated: 2021/08/02 12:36:28 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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

AForm* createForm( std::string formName, int gradeSign, int gradeExecute )
{
	AForm* form;
	
	try
	{
		form = new AForm(formName, gradeSign, gradeExecute);
		return form;
	}
	catch(const std::exception& e)
	{
		if (formName.empty())
			formName = "<empty>";
		std::cerr << formName << " : " << e.what() << std::endl;
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

int main ( void )
{
	std::ofstream	file;
	
	Bureaucrat* Jeltz = createBureaucrat("Prostetnic Vogon Jeltz", 146);
	Bureaucrat* Kwaltz = createBureaucrat("Prostetnic Vogon Kwaltz", 6);;

	AForm* noTargetShrubbery = createShrubberyCreationForm("");
	AForm* noTargetRobotomy = createRobotomyRequestForm("");
	AForm* noTargetPresidential = createPresidentialPardonForm("");

	(void)noTargetShrubbery;
	(void)noTargetRobotomy;
	(void)noTargetPresidential;

	separator();
	
	AForm* room14 = createShrubberyCreationForm("room14");
	AForm* arthurDent = createRobotomyRequestForm("Arthur Dent");
	AForm* fordPerfect = createPresidentialPardonForm("Ford Perfect");

	std::cout << *Jeltz << std::endl;
	std::cout << *Kwaltz << std::endl;

	separator();

	Jeltz->signForm(*room14);
	increment(Jeltz);
	Jeltz->signForm(*room14);
	Kwaltz->executeForm(*room14);
	
	separator();

	Jeltz->signForm(*arthurDent);
	Jeltz->executeForm(*arthurDent);
	std::cout << *arthurDent << std::endl;

	separator();

	Kwaltz->signForm(*arthurDent);
	Kwaltz->executeForm(*arthurDent);
	std::cout << *arthurDent << std::endl;

	separator();

	Kwaltz->signForm(*fordPerfect);
	Kwaltz->executeForm(*fordPerfect);
	increment(Kwaltz);
	std::cout << *Kwaltz << std::endl;
	Kwaltz->executeForm(*fordPerfect);

	return 0;
}