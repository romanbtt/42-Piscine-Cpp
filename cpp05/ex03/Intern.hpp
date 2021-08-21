#ifndef INTERN_H
#define INTERN_H
	
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp" 

class Intern  
{

	public:

		Intern( void );
		Intern( Intern const & src );
		virtual ~Intern( void );

		AForm *		makeForm( std::string formName, std::string target );
		AForm *		makePresidentialPardon( std::string target );
		AForm *		makeRobotomyRequest( std::string target );
		AForm *		makeShrubberyCreation( std::string target );

		Intern &	operator=( Intern const & rhs );

		class UnknownFormException : public std::exception
		{
			virtual const char* what() const throw();
		};

};

std::ostream &				operator<<( std::ostream & output, Intern const & rhs );

#endif