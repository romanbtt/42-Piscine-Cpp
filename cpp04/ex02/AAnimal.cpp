#include "AAnimal.hpp"  
	
AAnimal::AAnimal( void ) : _type("")
{
	std::cout << "Default constructor AAnimal called." << std::endl;
}

AAnimal::AAnimal( AAnimal const & src )
{
	std::cout << "Copy constructor AAnimal called." << std::endl;
	*this = src;
}

AAnimal::~AAnimal( void )
{
	std::cout << "Destructor AAnimal called." << std::endl;
}

void	AAnimal::makeSound( void ) const
{
	std::cout << "No sound!" << std::endl;
}

std::string AAnimal::getType( void ) const
{
	return _type;
}

AAnimal & AAnimal::operator=( AAnimal const & rhs )
{
	if (this != &rhs)
		_type = rhs.getType();
	return *this;
}
