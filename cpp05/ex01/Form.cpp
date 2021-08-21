/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 12:59:41 by romanbtt          #+#    #+#             */
/*   Updated: 2021/08/02 15:04:25 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"  
	
Form::Form( void ) : _gradeSign(1), _gradeExecute(1)
{
	return ;
}

Form::Form( std::string name, int gradeSign, int gradeExecute )
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

Form::Form( std::string name )
	:_name(name), _isSigned(false), _gradeSign(1), _gradeExecute(1)
{
	if (name.empty())
		throw NoNameException();
}

Form::Form( Form const & src )
	: _name(src._name), _gradeSign(src._gradeSign),
		_gradeExecute(src._gradeExecute)
{
	*this = src;
}
	
Form::~Form( void )
{
	return ;
}

const std::string	Form::getName( void ) const
{
	return _name;
}

bool	Form::getIsSigned( void ) const
{
	return _isSigned;
}	

int	Form::getGradeSign( void ) const
{
	return _gradeSign;
}

int	Form::getGradeExecute( void ) const
{
	return _gradeExecute;
}

void	Form::setIsSigned( bool isSigned )
{
	_isSigned = isSigned;
}

Form &	Form::operator=( Form const & rhs )
{
	if (this != &rhs)
		_isSigned = rhs._isSigned;
	return *this;
}

void	Form::beSigned( Bureaucrat const & bureaucrat )
{
	if (bureaucrat.getGrade() > _gradeSign)
		throw GradeTooLowException();
	else if (_isSigned == true)
		throw FormIsAlreadySignedException();
	_isSigned = true;
}

std::ostream &	operator<<( std::ostream & output, Form const & rhs )
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

const char * Form::GradeTooHighException::what( void ) const throw()
{
	return "The grade is too high.";
}

const char * Form::GradeTooLowException::what( void ) const throw()
{
	return "The grade is too low.";
}

const char * Form::NoNameException::what( void ) const throw()
{
	return "The form need to be named.";
}

const char * Form::FormIsAlreadySignedException::what( void ) const throw()
{
	return "The form is already signed.";
}