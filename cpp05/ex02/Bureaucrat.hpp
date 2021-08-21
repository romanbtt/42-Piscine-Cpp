/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 09:51:04 by romanbtt          #+#    #+#             */
/*   Updated: 2021/08/02 14:58:39 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include "AForm.hpp"

class AForm;

class Bureaucrat  
{

	public:

		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw();
		};

		class NoNameException : public std::exception
		{
			virtual const char* what() const throw();
		};
		
	private:

		const std::string	_name;
		int					_grade;
		Bureaucrat( void );

	public:

		Bureaucrat( std::string name, int grade );
		Bureaucrat( std::string name );
		Bureaucrat( Bureaucrat const & src );
		virtual ~Bureaucrat( void );

		const std::string	getName( void ) const;
		int					getGrade( void ) const;

		void				incrementGrade( void );
		void				decrementGrade( void );
		void				signForm( AForm & form );
		void				executeForm( AForm const & form );

		Bureaucrat &		operator=( Bureaucrat const & rhs );

};

std::ostream &				operator<<( std::ostream & output, Bureaucrat const & rhs );

#endif