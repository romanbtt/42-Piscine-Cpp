#include "Animal.hpp"  
	
Animal::Animal( void ) : _type("")
{
	std::cout << _type << "Default constructor Animal called." << std::endl;
}

Animal::Animal( Animal const & src )
{
	std::cout << _type << "Copy constructor Animal called." << std::endl;
	*this = src;
}

Animal::~Animal( void )
{
	std::cout << _type << "Destructor Animal called." << std::endl;
}

void	Animal::makeSound( void ) const
{
	std::cout << "No sound!" << std::endl;
}

std::string Animal::getType( void ) const
{
	return _type;
}

Animal & Animal::operator=( Animal const & rhs )
{
	if (this != &rhs)
		_type = rhs.getType();
	return *this;
}
