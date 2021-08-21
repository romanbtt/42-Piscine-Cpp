/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 09:50:45 by romanbtt          #+#    #+#             */
/*   Updated: 2021/08/02 15:11:27 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
	
Bureaucrat::Bureaucrat( void )
{
	return ;
}
	
Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else if (name.empty())
		throw NoNameException();
	_grade = grade;
}

Bureaucrat::Bureaucrat( std::string name ) : _name(name), _grade(150)
{
	if (name.empty())
		throw NoNameException();
}

Bureaucrat::Bureaucrat( Bureaucrat const & src ) : _name(src._name)
{
	*this = src;
}

Bureaucrat::~Bureaucrat( void )
{
	return ;
}

const std::string	Bureaucrat::getName( void ) const
{
	return _name;
}

int	Bureaucrat::getGrade( void ) const
{
	return _grade;
}

void Bureaucrat::incrementGrade( void )
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade( void )
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm( AForm & form )
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signs " << form.getName() << "." << std::endl;
		form.setIsSigned(true);
	}
	catch(const std::exception& e)
	{
		std::cerr << _name << " cannot sign " << form.getName() << " because : ";
		std::cerr << e.what() << std::endl;
	}
}
void	Bureaucrat::executeForm( AForm const & form )
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executes " << form.getName() << "." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << _name << " cannot execute " << form.getName() << " because : ";
		std::cerr << e.what() << '\n';
	}
}

Bureaucrat & Bureaucrat::operator=( Bureaucrat const & rhs )
{
	if (this != &rhs)
		_grade = rhs._grade;
	return *this;
}

std::ostream &	operator<<( std::ostream & output, Bureaucrat const & rhs )
{
	output << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return output;
}

const char * Bureaucrat::GradeTooHighException::what( void ) const throw()
{
	return "The maximum grade is 1.";
}

const char * Bureaucrat::GradeTooLowException::what( void ) const throw()
{
	return "The minimum grade is 150.";
}

const char * Bureaucrat::NoNameException::what( void ) const throw()
{
	return "The bureaucrat need to be named.";
}