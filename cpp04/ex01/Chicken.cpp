#include "Chicken.hpp"  
	
Chicken::Chicken( void )
{
	_type = "Chicken";
	std::cout << _type << " was created from the Chicken class." << std::endl;
}

Chicken::Chicken( Chicken const & src )
{
	*this = src;
	std::cout << _type << " was copied from the Chicken class." << std::endl;
}

Chicken::~Chicken( void )
{
	std::cout << _type << " was destroyed from the Chicken class." << std::endl;
}

void	Chicken::makeSound( void ) const
{
	std::cout << "Bwok Bwok!" << std::endl;
}

Chicken & Chicken::operator=( Chicken const & rhs )
{
	if (this != &rhs)
		Animal::operator=(rhs);
	return *this;
}