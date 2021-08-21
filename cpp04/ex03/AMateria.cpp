#include "AMateria.hpp"  
	
AMateria::AMateria( void ) : _type("None")
{
	std::cout << "Default constructor AMateria called." << std::endl;
}

AMateria::AMateria( std::string const & type ) : _type(type)
{
	std::cout << _type << " was created from the AMateria class." << std::endl;
}

AMateria::AMateria( AMateria const & src )
{
	std::cout << _type << " was copied from the AMateria class." << std::endl;
	*this = src;
}
	
AMateria::~AMateria( void )
{
	std::cout << _type << " was destroyed from the AMateria class." << std::endl;
}

std::string const & AMateria::getType( void ) const
{
	return _type;
}

void	AMateria::setType( std::string const & type )
{
	_type = type;
}

void 		AMateria::use( ICharacter& target )
{
	std::cout << "* blows some air at " << target.getName() << " *";
	std::cout << std::endl;
}

AMateria & AMateria::operator=( AMateria const & rhs )
{
	(void)rhs;

	return *this;
}