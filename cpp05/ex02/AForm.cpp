/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 12:59:41 by romanbtt          #+#    #+#             */
/*   Updated: 2021/08/01 11:11:20 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"  
	
AForm::AForm( void )
	:_name(""), _isSigned(false), _gradeSign(1), _gradeExecute(1)
{
	if (_name.empty())
		throw NoNameException();
}

AForm::AForm( std::string name, int gradeSign, int gradeExecute )
	: _name(name), _isSigned(false), _gradeSign(gradeSign),
		_gradeExecute(gradeExecute)
{
	if (gradeSign < 1 || gradeExecute < 1)
		throw GradeTooHighException();
	else if (gradeSign > 150 || gradeExecute > 150)
		throw GradeTooLowException();
	else if (name.empty())
		throw NoNameException();
}

AForm::AForm( AForm const & src )
	: _name(src._name), _gradeSign(src._gradeSign),
		_gradeExecute(src._gradeExecute)
{
	*this = src;
}
	
AForm::~AForm( void )
{
	return ;
}

const std::string	AForm::getName( void ) const
{
	return _name;
}

bool	AForm::getIsSigned( void ) const
{
	return _isSigned;
}	

int	AForm::getGradeSign( void ) const
{
	return _gradeSign;
}

int	AForm::getGradeExecute( void ) const
{
	return _gradeExecute;
}

void	AForm::setIsSigned( bool isSigned )
{
	_isSigned = isSigned;
}

AForm &	AForm::operator=( AForm const & rhs )
{
	if (this != &rhs)
		_isSigned = rhs._isSigned;
	return *this;
}

void	AForm::beSigned( Bureaucrat const & bureaucrat )
{
	if (bureaucrat.getGrade() > _gradeSign)
		throw GradeTooLowException();
	else if (_isSigned == true)
		throw FormIsAlreadySignedException();
	_isSigned = true;
}

void	AForm::execute( Bureaucrat const & executor ) const
{
	if (getIsSigned() == false)
		throw FormIsNotSignedException();
	else if (executor.getGrade() > getGradeExecute())
		throw GradeTooLowException();
}

std::ostream &	operator<<( std::ostream & output, AForm const & rhs )
{
	if (rhs.getIsSigned() == true)
	{
		output << rhs.getName() << " is signed and required grade ";
		output << rhs.getGradeSign() << " to be signed and ";
		output << rhs.getGradeExecute() << " to be executed.";
	}
	else
	{
		output << rhs.getName() << " is not signed and required grade ";
		output << rhs.getGradeSign() << " to be signed and ";
		output << rhs.getGradeExecute() << " to be executed.";
	}
	return output;
}

const char * AForm::GradeTooHighException::what( void ) const throw()
{
	return "The grade is too high.";
}

const char * AForm::GradeTooLowException::what( void ) const throw()
{
	return "The grade is too low.";
}

const char * AForm::FormIsAlreadySignedException::what( void ) const throw()
{
	return "The form is already signed.";
}

const char * AForm::NoNameException::what( void ) const throw()
{
	return "The form need to be named.";
}

const char * AForm::FormIsNotSignedException::what( void ) const throw()
{
	return "The form is not signed.";
}
