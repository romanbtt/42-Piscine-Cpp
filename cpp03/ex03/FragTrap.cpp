#include "FragTrap.hpp"  
	
FragTrap::FragTrap( std::string Name ) : ClapTrap(Name)
{
	std::cout << "FragTrap "<< Name << " created." << std::endl;
	_hitPoints = _hitPointsInit = 100;
	_energyPoints = _energyPointsInit = 100;
	_attackDamage = _attackDamageInit = 30;
}

FragTrap::FragTrap( FragTrap const & src )
{
	std::cout << "FragTrap " << _name << " created by copy." << std::endl;
	*this = src;
}

FragTrap::FragTrap( void ) : ClapTrap()
{
	std::cout << "FragTrap "<< _name << " created." << std::endl;
	_hitPoints = _hitPointsInit = 100;
	_energyPoints = _energyPointsInit = 100;
	_attackDamage = _attackDamageInit = 30;
}
	
FragTrap::~FragTrap()
{
	std::cout << "FragTrap "<< _name << " destroyed." << std::endl;
}

void FragTrap::highFivesGuys( void )
{
	if (_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << " can't request any high five ";
		std::cout << "because he/she is dead!" << std::endl;
	}
	std::cout << "FragTrap "<< _name << " request the highest of fives.";
	std::cout << std::endl;
}

int	FragTrap::getHitPointsInit( void )
{
	return _hitPointsInit;
}

int	FragTrap::getEnergyPointsInit( void )
{
	return _energyPointsInit;
}

int	FragTrap::getAttackDamageInit( void )
{
	return _attackDamageInit;
}

FragTrap & FragTrap::operator=( FragTrap const & rhs )
{
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	return *this;
}
