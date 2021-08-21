#include "Cat.hpp"  
	
Cat::Cat( void )
{
	_type = "Cat";
	std::cout << _type << " was created from the Cat class." << std::endl;
}

Cat::Cat( Cat const & src )
{
	*this = src;
	std::cout << _type << " was created by copy from the Cat class." << std::endl;
}

Cat::~Cat( void )
{
	std::cout << _type << " was destroyed from the Cat class." << std::endl;
}

void	Cat::makeSound( void ) const
{
	std::cout << "Meow Meow!" << std::endl;
}

Cat & Cat::operator=( Cat const & rhs )
{
	if (this != &rhs)
		Animal::operator=(rhs);
	return *this;
}
