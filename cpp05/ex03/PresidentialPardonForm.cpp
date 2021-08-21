/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 19:22:26 by romanbtt          #+#    #+#             */
/*   Updated: 2021/08/02 13:00:15 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"  
	
PresidentialPardonForm::PresidentialPardonForm( void ) : AForm()
{
	return ;
}
	
PresidentialPardonForm::PresidentialPardonForm( std::string target )
	: AForm("presidential pardon", 25, 5), _target(target)
{
	if (target.empty())
		throw NoTargetException();
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src )
	: AForm(src)
{
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	return ;
}

void	PresidentialPardonForm::execute( Bureaucrat const & executor ) const
{
	if (getIsSigned() == false)
		throw FormIsNotSignedException();
	else if (executor.getGrade() > getGradeExecute())
		throw GradeTooLowException();
	std::cout << _target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	if (this != &rhs)
	{
		_target = rhs._target;
		AForm::operator=(rhs);
	}
	return *this;
}

const char * PresidentialPardonForm::NoTargetException::what( void ) const throw()
{
	return "The target need to be named.";
}