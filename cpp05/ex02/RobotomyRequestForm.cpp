/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 18:37:36 by romanbtt          #+#    #+#             */
/*   Updated: 2021/08/02 12:21:15 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"  
	
RobotomyRequestForm::RobotomyRequestForm( void ) : AForm()
{
	return ;
}
	
RobotomyRequestForm::RobotomyRequestForm( std::string target )
	: AForm("robotomy request", 72, 45), _target(target)
{
	if (target.empty())
		throw NoTargetException();
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src )
	: AForm(src)
{
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	return ;
}

void	RobotomyRequestForm::execute( Bureaucrat const & executor ) const
{
	std::srand(time(NULL));
	if (getIsSigned() == false)
		throw FormIsNotSignedException();
	else if (executor.getGrade() > getGradeExecute())
		throw GradeTooLowException();
	std::cout << "* Loud and unbearable drilling noises *" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << _target << " has not been robotomized successfully." << std::endl;

}

RobotomyRequestForm & RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	if (this != &rhs)
	{
		_target = rhs._target;
		AForm::operator=(rhs);
	}
	return *this;
}

const char * RobotomyRequestForm::NoTargetException::what( void ) const throw()
{
	return "The target need to be named.";
}