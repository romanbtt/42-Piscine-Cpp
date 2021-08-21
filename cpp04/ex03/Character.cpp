#include "Character.hpp"  
	
Character::Character( void ) : _name("Unknown"), _currIdx(0)
{
	std::cout << "Default constructor Character called." << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL; 
}

Character::Character( std::string name ) : _name(name), _currIdx(0)
{
	std::cout << _name << " was created from the Character class." << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL; 
}

Character::Character( Character const & src )
{
	std::cout << _name << " was copied from the Character class." << std::endl;
	*this = src;
}

Character::~Character( void )
{
	std::cout << _name << " was destroyed from the Character class." << std::endl;
	for (int i = 0; i < 4; i++)
		if (_inventory[i] != NULL)
			delete _inventory[i];
}

std::string const &	Character::getName( void ) const
{
	return _name;
}

AMateria const &	Character::getInventory( unsigned int index ) const
{
	return *_inventory[index];
}

unsigned int	Character::getCurrIdx( void ) const
{
	return _currIdx;
}

void	Character::equip( AMateria* m )
{
	if (_currIdx < 4 && m != NULL)
		_inventory[_currIdx++] = m;
}

void	Character::unequip( int idx )
{
	if (idx >= 0 && idx < 4 && _inventory[idx] != NULL)
	{
		delete _inventory[idx];
		_inventory[idx] = NULL;
		for (int i = idx + 1; i < 4; i++)
			_inventory[i - 1] = _inventory[i];
		_currIdx--;
	}
}

void	Character::use( int idx, ICharacter &target )
{
	if (idx >= 0 && idx < 4 && _inventory[idx] != NULL)
		_inventory[idx]->use(target);
}

Character & Character::operator=( Character const & rhs )
{
	if (this != &rhs)
	{
		_name = rhs.getName();
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i] != NULL)
				delete _inventory[i];
			_inventory[i] = NULL;
			if (rhs._inventory[i] != NULL)
				_inventory[i] = rhs._inventory[i]->clone();
		}
		_currIdx = rhs.getCurrIdx();
	}
	return *this;
}