#include "WrongAnimal.hpp"  
	
WrongAnimal::WrongAnimal( void ) : _type("")
{
	std::cout << "Default constructor WrongAnimal called." << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const & src )
{
	std::cout << "Copy constructor WrongAnimal called." << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "Destructor WrongAnimal called." << std::endl;
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "Wrong No sound!" << std::endl;
}

std::string WrongAnimal::getType( void ) const
{
	return _type;
}

WrongAnimal & WrongAnimal::operator=( WrongAnimal const & rhs )
{
	if (this != &rhs)
		_type = rhs.getType();
	return *this;
}
