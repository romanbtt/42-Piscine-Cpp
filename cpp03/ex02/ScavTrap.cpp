#include "ScavTrap.hpp"  
	
ScavTrap::ScavTrap( std::string name ) : ClapTrap(name), _gateKeeperMode(false)
{
	std::cout << "ScavTrap "<< name << " created." << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap( ScavTrap const & src )
{
	std::cout << "ScavTrap " << _name << " created by copy." << std::endl;
	*this = src;
}

ScavTrap::ScavTrap( void ) : ClapTrap(), _gateKeeperMode(false)
{
	std::cout << "ScavTrap "<< _name << " created." << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}
	
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap "<< _name << " destroyed." << std::endl;
}

void ScavTrap::guardGate( void )
{
	if (_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << " can't enter in Gate keeper mode ";
		std::cout << "because he/she is dead!" << std::endl;
		return ;
	}
	if (_gateKeeperMode == false)
	{
		std::cout << "ScavTrap " << _name << " has enterred in Gate keeper mode.";
		std::cout << std::endl;
		_gateKeeperMode = true;
	}
	else
	{
		std::cout << "ScavTrap " << _name << " has exited Gate keeper mode.";
		std::cout << std::endl;
		_gateKeeperMode = false;
	}
}

void	ScavTrap::attack( std::string const & target )
{
	if (_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << " canno't attack ";
		std::cout << target << " because he/she is dead!" << std::endl;
	}
	else if (_energyPoints > 0)
	{
		std::cout << "ScavTrap " << _name << " attacks " << target;
		std::cout << ", causing " << getAttackDamage() << " points of damage!";
		std::cout << std::endl;
		_energyPoints -= 5;
	}
	else
	{
		std::cout << "ScavTrap " << _name << " doesn't have enough energy points";
		std::cout << " to attack " << target << std::endl;
	}
}

ScavTrap & ScavTrap::operator=( ScavTrap const & rhs )
{
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
		_gateKeeperMode = false;
	}	
	return *this;
}
