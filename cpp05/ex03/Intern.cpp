#include "Intern.hpp"  
	
Intern::Intern( void )
{
	return ;
}

Intern::Intern( Intern const & src )
{
	*this = src;
}
	
Intern::~Intern( void )
{
	return ;
}

AForm * Intern::makeForm( std::string formName, std::string target )
{
	AForm* tmp;
	AForm* (Intern::*arrayFormFunc[3])( std::string target );
	std::string	arrayFormName[3] = {"shrubbery creation",
									"robotomy request",
									"presidential pardon"};

	arrayFormFunc[0] = &Intern::makeShrubberyCreation;
	arrayFormFunc[1] = &Intern::makeRobotomyRequest;
	arrayFormFunc[2] = &Intern::makePresidentialPardon;
	for (int i = 0; i < 3; i++)
	{
		if (arrayFormName[i] == formName)
		{
			tmp = (this->*(arrayFormFunc[i]))(target);
			std::cout << "Intern creates " << formName << std::endl;
			return tmp;
		}
		if (i == 2)
			throw UnknownFormException();
	}
	return NULL;
}

AForm *		Intern::makePresidentialPardon( std::string target )
{
	return new PresidentialPardonForm(target);
}

AForm *		Intern::makeRobotomyRequest( std::string target )
{
	return new RobotomyRequestForm(target);
}

AForm *		Intern::makeShrubberyCreation( std::string target )
{
	return new ShrubberyCreationForm(target);
}

Intern &	Intern::operator=( Intern const & rhs )
{
	(void)rhs;
	return *this;
}

std::ostream &	operator<<( std::ostream & output, Intern const & rhs )
{
	(void)rhs;
	output << "An intern, no one knows his name! Who cares!?";
	return output;
}

const char * Intern::UnknownFormException::what( void ) const throw()
{
	return "The form is unknown.";
}