#include "MateriaSource.hpp"  
	
MateriaSource::MateriaSource( void ) : _currIdx(0)
{
	std::cout << "Default constructor MateriaSource called." << std::endl;
	for (int i = 0; i < 4; i++)
		_sources[i] = NULL; 
}

MateriaSource::MateriaSource( MateriaSource const & src )
{
	std::cout << "Copy constructor MateriaSource called." << std::endl;
	*this = src;
}
	
MateriaSource::~MateriaSource()
{
	std::cout << "Destructor MateriaSource called." << std::endl;
	for (int i = 0; i < 4; i++)
		if (_sources[i] != NULL)
			delete _sources[i];
}

unsigned int	MateriaSource::getCurrIdx( void ) const
{
	return _currIdx;
}

void	MateriaSource::learnMateria( AMateria* source )
{
	if (source != NULL && _currIdx < 4)
		_sources[_currIdx++] = source;
}

AMateria *	MateriaSource::createMateria( std::string const & type )
{
	for (unsigned int i = 0; i < _currIdx; i++)
		if (_sources[i]->getType() == type)
			return _sources[i]->clone();
	return 0;
}

MateriaSource & MateriaSource::operator=( MateriaSource const & rhs )
{
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			if (_sources[i] != NULL)
				delete _sources[i];
			_sources[i] = NULL;
			if (rhs._sources[i] != NULL)
				_sources[i] = rhs._sources[i]->clone();
		}
		_currIdx = rhs.getCurrIdx();
	}
	return *this;
}