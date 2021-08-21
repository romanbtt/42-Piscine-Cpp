#include "WrongCat.hpp"  
	
WrongCat::WrongCat( void )
{
	_type = "Wrong cat";
	std::cout << _type << " was created from the WrongCat class." << std::endl;
}

WrongCat::WrongCat( WrongCat const & src )
{
	*this = src;
}

WrongCat::~WrongCat( void )
{
	std::cout << _type << " was destroyed from the WrongCat class." << std::endl;
}

void	WrongCat::makeSound( void ) const
{
	std::cout << "Wrong Meow Meow!" << std::endl;
}

WrongCat & WrongCat::operator=( WrongCat const & rhs )
{
	if (this != &rhs)
		WrongAnimal::operator=(rhs);
	return *this;
}
