#include "Cat.hpp"  
	
Cat::Cat( void )
{
	_type = "Cat";
	std::cout << _type << " was created from the Cat class." << std::endl;
	_brain = new Brain;
}

Cat::Cat( Cat const & src )
{
	*this = src;
	std::cout << _type << " was copied from the Dog class." << std::endl;
}

Cat::~Cat( void )
{
	delete _brain;
	std::cout << _type << " was destroyed from the Cat class." << std::endl;
}

void	Cat::makeSound( void ) const
{
	std::cout << "Meow Meow!" << std::endl;
}

Brain *	Cat::getBrain( void ) const
{
	return _brain;
}

Cat & Cat::operator=( Cat const & rhs )
{
	if (this != &rhs)
	{
		AAnimal::operator=(rhs);
		if (_brain == NULL)
			_brain = new Brain(*rhs.getBrain());
		else
			*_brain = *rhs.getBrain(); 
	}	
	return *this;
}
