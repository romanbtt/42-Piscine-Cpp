#include "Brain.hpp"  
	
Brain::Brain( void )
{
	std::string ideas[5] = { "Steal some food",
							"Play with human",
							"Sleep",
							"Sleep again",
							"Pee on the human's bed" };

	for (int i = 0; i < 100; i++)
		_ideas[i] = ideas[i % 5];
	std::cout << "A brand new brain has been created." << std::endl;
}
	
Brain::~Brain( void )
{
	std::cout << "A brain has been destroyed." << std::endl;
}

Brain::Brain( Brain const & src )
{
	*this = src;
	std::cout << "A brain has been copied." << std::endl;
}

std::string Brain::getIdea( unsigned int index ) const
{
	return _ideas[index];
}

void		Brain::setIdea( unsigned int index, std::string idea )
{
	_ideas[index] = idea;
}

Brain & Brain::operator=( Brain const & rhs )
{
	if (this != &rhs)
	{
		for(int i = 0; i < 100; i++)
			_ideas[i] = rhs.getIdea(i);
	}
	return *this;
}