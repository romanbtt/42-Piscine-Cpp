/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 12:22:48 by romanbtt          #+#    #+#             */
/*   Updated: 2021/08/02 12:21:20 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"  
	
ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm()
{
	return ;
}
	
ShrubberyCreationForm::ShrubberyCreationForm( std::string target )
	: AForm("shrubbery creation", 145, 137), _target(target)
{
	if (target.empty())
		throw NoTargetException();
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src )
	: AForm(src)
{
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	return ;
}

void	ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
{
	std::ofstream	file;
	
	if (getIsSigned() == false)
		throw FormIsNotSignedException();
	else if (executor.getGrade() > getGradeExecute())
		throw GradeTooLowException();
	file.open(_target + "_shrubbery");
	if (file.is_open() == false)
		throw CannotOpenTargetException();
	file << ASCIITREE;
	file.close();
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	if (this != &rhs)
	{
		_target = rhs._target;
		AForm::operator=(rhs);
	}
	return *this;
}

const char * ShrubberyCreationForm::CannotOpenTargetException::what( void ) const throw()
{
	return "The target could not be open.";
}

const char * ShrubberyCreationForm::NoTargetException::what( void ) const throw()
{
	return "The target need to be named.";
}