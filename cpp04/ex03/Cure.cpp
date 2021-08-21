#include "Cure.hpp"  
	
Cure::Cure( void )
{
	std::cout << "Default constructor Cure called." << std::endl;
	_type = "cure";
}

Cure::Cure( Cure const & src )
{
	std::cout << "Copy constructor Cure called." << std::endl;
	*this = src;
}

Cure::~Cure( void )
{
	std::cout << "Destructor Cure called." << std::endl;
}

Cure* Cure::clone( void ) const
{
	Cure *tmp = new Cure;

	return tmp;
}

void Cure::use( ICharacter& target )
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

Cure & Cure::operator=( Cure const & rhs )
{
	if (this != &rhs)
		AMateria::operator=(rhs);
	return *this;
}