#include "ClapTrap.hpp"  

ClapTrap::ClapTrap( std::string name )
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap "<< name << " created." << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const & src)
{
	std::cout << "ClapTrap " << _name << " created by copy." << std::endl;
	*this = src;
}

ClapTrap::ClapTrap( void )
	: _name("Undefined"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap "<< _name << " created." << std::endl;
}
	
ClapTrap::~ClapTrap( void )
{
	std::cout << "ClapTrap "<< _name << " destroyed." << std::endl;
}

void	ClapTrap::attack( std::string const & target)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " canno't attack ";
		std::cout << target << " because he/she is dead!" << std::endl;
	}
	else if (_energyPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target;
		std::cout << ", causing " << getAttackDamage() << " points of damage!";
		std::cout << std::endl;
		_energyPoints -= 5;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " doesn't have enough energy points";
		std::cout << " to attack " << target << std::endl;
	}	
}

void		ClapTrap::takeDamage( unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << getName();
		std::cout << " is already dead." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << getName();
	std::cout << " has been attacked and lost " << amount << " points!";
	std::cout << std::endl;
	_hitPoints -= amount;
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << getName() << " has been killed.";
		std::cout << std::endl;
	}
}

void		ClapTrap::beRepaired( unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << getName();
		std::cout << " is dead. You can't revive him." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << getName();
	std::cout << " has restored and wins " << amount << " points of health!";
	_hitPoints += amount;
	std::cout << std::endl;
}

std::string	ClapTrap::getName( void ) const
{
	return _name;
}

void		ClapTrap::setName( std::string name)
{
	_name = name;
}

int			ClapTrap::getHitPoints( void ) const
{
	return _hitPoints;
}

void		ClapTrap::setHitPoints( unsigned int hitPoints)
{
	_hitPoints = hitPoints;
}

int			ClapTrap::getEnergyPoints() const
{
	return _energyPoints;
}

void		ClapTrap::setEnergyPoints( unsigned int energyPoints)
{
	_energyPoints = energyPoints;
}

int			ClapTrap::getAttackDamage() const
{
	return _attackDamage;
}

void		ClapTrap::setAttackDamage( unsigned int attackDamage )
{
	_attackDamage = attackDamage;
}

ClapTrap & 	ClapTrap::operator=( ClapTrap const & rhs )
{
	if (this == &rhs)
		return *this;
	_name = rhs.getName();
	_hitPoints = rhs.getHitPoints();
	_energyPoints = rhs.getEnergyPoints();
	_attackDamage = rhs.getAttackDamage();
	return *this;
}
