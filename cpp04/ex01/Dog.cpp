#include "Dog.hpp"  
	
Dog::Dog( void )
{
	_type = "Dog";
	std::cout << _type << " was created from the Dog class." << std::endl;
	_brain = new Brain;
}

Dog::Dog( Dog const & src )
{
	*this = src;
	std::cout << _type << " was copied from the Dog class." << std::endl;
	if (_brain == NULL)
		_brain = new Brain(*src.getBrain());
	else
		*_brain = *src.getBrain(); 
}

Dog::~Dog( void )
{
	delete _brain;
	std::cout << _type << " was destroyed from the Dog class." << std::endl;
}

void	Dog::makeSound( void ) const
{
	std::cout << "Woof Woof!" << std::endl;
}

Brain *	Dog::getBrain( void ) const
{
	return _brain;
}

Dog & Dog::operator=( Dog const & rhs )
{
	if (this != &rhs)
		Animal::operator=(rhs);
	return *this;
}