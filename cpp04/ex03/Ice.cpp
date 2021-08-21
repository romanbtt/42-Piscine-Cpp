#include "Ice.hpp"  
	
Ice::Ice( void )
{
	std::cout << "Default constructor Ice called." << std::endl;
	_type = "ice";
}

Ice::Ice( Ice const & src )
{
	std::cout << "Copy constructor Ice called." << std::endl;
	*this = src;
}

Ice::~Ice( void )
{
	std::cout << "Destructor Ice called." << std::endl;
	return ;
}

Ice* Ice::clone( void ) const
{
	Ice *tmp = new Ice;

	return tmp;
}

void Ice::use( ICharacter& target )
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *";
	std::cout << std::endl;
}

Ice & Ice::operator=( Ice const & rhs )
{
	if (this != &rhs)
		AMateria::operator=(rhs);
	return *this;
}