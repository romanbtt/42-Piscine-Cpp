#include "FragTrap.hpp"  
	
FragTrap::FragTrap( std::string Name ) : ClapTrap(Name)
{
	std::cout << "FragTrap "<< Name << " created." << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap( FragTrap const & src )
{
	std::cout << "FragTrap " << _name << " created by copy." << std::endl;
	*this = src;
}

FragTrap::FragTrap( void ) : ClapTrap()
{
	std::cout << "FragTrap "<< _name << " created." << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
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
	else
	{
		std::cout << "FragTrap "<< _name << " request the highest of fives.";
		std::cout << std::endl;
	}

}

FragTrap & FragTrap::operator=( FragTrap const & rhs )
{
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	return *this;
}
