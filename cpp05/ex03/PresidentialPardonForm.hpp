#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H
	
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{

	public:

		class NoTargetException : public std::exception
		{
			virtual const char* what() const throw();
		};

	private:

		std::string					_target;
		PresidentialPardonForm( void );

	public:

		PresidentialPardonForm( std::string target );
		PresidentialPardonForm( PresidentialPardonForm const & src );
		virtual ~PresidentialPardonForm( void );

      	void						execute( Bureaucrat const & executor ) const;

		PresidentialPardonForm &	operator=( PresidentialPardonForm const & rhs );

};
#endif