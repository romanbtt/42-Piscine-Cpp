/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 11:47:24 by romanbtt          #+#    #+#             */
/*   Updated: 2021/08/02 15:06:01 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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

Form* createForm(std::string formName, int gradeSign, int gradeExecute )
{
	Form* form;
	
	try
	{
		form = new Form(formName, gradeSign, gradeExecute);
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

int main ( void )
{
	Bureaucrat* Jeltz = createBureaucrat("Prostetnic Vogon Jeltz", 51);
	Bureaucrat* Kwaltz = createBureaucrat("Prostetnic Vogon Kwaltz", 80);;

	Form* _28B = createForm("28B", 50, 25);
	Form* _28C = createForm("28C", 70, 45);

	Form* signTooLow = createForm("Sign too low", 151, 50);
	Form* signTooHigh = createForm("Sign too high", 0, 50);
	Form* executeTooLow = createForm("Execute too low", 50, 151);
	Form* executeTooHigh = createForm("Execute too high", 50, 0);
	Form* noName = createForm("", 50, 50);

	(void)signTooLow;
	(void)signTooHigh;
	(void)executeTooLow;
	(void)executeTooHigh;
	(void)noName;

	separator();

	std::cout << *Jeltz << std::endl;
	std::cout << *_28B << std::endl;
	Jeltz->signForm(*_28B);
	increment(Jeltz);
	std::cout << *Jeltz << std::endl;
	Jeltz->signForm(*_28B);
	std::cout << *_28B << std::endl;
	Jeltz->signForm(*_28B);
	
	separator();

	std::cout << *Kwaltz << std::endl;
	std::cout << *_28C << std::endl;
	Kwaltz->signForm(*_28C);
	increment(Kwaltz);
	std::cout << *Kwaltz << std::endl;
	Kwaltz->signForm(*_28C);
	std::cout << *_28C << std::endl;

	delete Jeltz;
	delete Kwaltz;
	delete _28B;
	delete _28C;

	return 0;
}