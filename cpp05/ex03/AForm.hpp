/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 12:59:38 by romanbtt          #+#    #+#             */
/*   Updated: 2021/08/02 15:11:08 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
#define AFORM_H

#include <iostream>	
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm  
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

		class FormIsAlreadySignedException : public std::exception
		{
			virtual const char* what() const throw();
		};

		class NoNameException : public std::exception
		{
			virtual const char* what() const throw();
		};

		class FormIsNotSignedException : public std::exception
		{
			virtual const char* what() const throw();
		};
		
	private:

	const std::string		_name;
	bool					_isSigned;
	const int				_gradeSign;
	const int				_gradeExecute;
	

	public:

		AForm( void );
		AForm( std::string name, int gradeSign, int gradeExecute );
		AForm( AForm const & src);
		virtual ~AForm();

		const std::string	getName( void ) const;
		bool				getIsSigned( void ) const;
		int					getGradeSign( void ) const;
		int					getGradeExecute( void ) const;
		void				setIsSigned( bool isSigned );

		void				beSigned( Bureaucrat const & buraucrat );
		virtual void		execute( Bureaucrat const & executor ) const;

		AForm & 			operator=( AForm const & rhs );

};

std::ostream &				operator<<( std::ostream & output, AForm const & rhs );

#endif