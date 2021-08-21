/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 12:59:38 by romanbtt          #+#    #+#             */
/*   Updated: 2021/08/02 15:07:00 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#include <iostream>	
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form  
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

		class FormIsAlreadySignedException : public std::exception
		{
			virtual const char* what() const throw();
		};
		
	private:

	const std::string		_name;
	bool					_isSigned;
	const int				_gradeSign;
	const int				_gradeExecute;
	Form( void );

	public:

		Form( std::string name, int gradeSign, int gradeExecute );
		Form( std::string name );
		Form( Form const & src);
		virtual ~Form();

		const std::string	getName( void ) const;
		bool				getIsSigned( void ) const;
		int					getGradeSign( void ) const;
		int					getGradeExecute( void ) const;
		void				setIsSigned( bool isSigned );

		void				beSigned( Bureaucrat const & buraucrat );

		Form & 				operator=( Form const & rhs );

};

std::ostream &				operator<<( std::ostream & output, Form const & rhs );

#endif