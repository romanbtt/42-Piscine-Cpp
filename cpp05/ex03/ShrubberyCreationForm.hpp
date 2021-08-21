/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 12:22:45 by romanbtt          #+#    #+#             */
/*   Updated: 2021/08/02 13:00:07 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H
	
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
   public:

   	class CannotOpenTargetException : public std::exception
		{
			virtual const char* what() const throw();
		};

      class NoTargetException : public std::exception
		{
			virtual const char* what() const throw();
		};
      
	private:

		std::string             _target;
		ShrubberyCreationForm( void );

	public:

		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( ShrubberyCreationForm const & src );
		virtual ~ShrubberyCreationForm( void );

      void                    execute( Bureaucrat const & executor ) const;

		ShrubberyCreationForm & operator=( ShrubberyCreationForm const & rhs );

};

#define ASCIITREE "                    .o00o\n\
                   o000000oo\n\
                  00000000000o\n\
                 00000000000000\n\
              oooooo  00000000  o88o\n\
           ooOOOOOOOoo  ```''  888888\n\
         OOOOOOOOOOOO'.qQQQQq. `8888'\n\
        oOOOOOOOOOO'.QQQQQQQQQQ/.88'\n\
        OOOOOOOOOO'.QQQQQQQQQQ/ /q\n\
         OOOOOOOOO QQQQQQQQQQ/ /QQ\n\
           OOOOOOOOO `QQQQQQ/ /QQ'\n\
             OO:F_P:O `QQQ/  /Q'\n\
                \\. \\|  // |\n\
                d  \\ |_////\n\
                qP| \\ _' `|Ob\n\
                   \\ / \\  Op\n\
                   |  | O| |\n\
           _       /\\ \\/ /\n\
            `---__/|_\\   //|  __\n\
                  `-'  `-'`-'-'"

#endif