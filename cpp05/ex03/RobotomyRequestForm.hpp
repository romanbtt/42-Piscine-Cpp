#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{

	public:

		class NoTargetException : public std::exception
		{
			virtual const char* what() const throw();
		};

	private:

		std::string				_target;
		RobotomyRequestForm( void );

	public:

		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( RobotomyRequestForm const & src );
		virtual ~RobotomyRequestForm( void );

      	void					execute( Bureaucrat const & executor ) const;

		RobotomyRequestForm &	operator=( RobotomyRequestForm const & rhs );

};
#endif