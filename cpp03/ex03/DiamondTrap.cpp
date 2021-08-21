#include "DiamondTrap.hpp"  
	
DiamondTrap::DiamondTrap( void )
	: ClapTrap(), ScavTrap(), FragTrap()
{
	_name = "Undefined";
	ClapTrap::setName(_name + "_clap_name");
	std::cout << "DiamondTrap "<< _name << " created." << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name + "_clap_name")
{
	_name = name;
	_hitPoints = FragTrap::getHitPointsInit();
	_energyPoints = ScavTrap::getEnergyPointsInit();
	_attackDamage = FragTrap::getAttackDamageInit();
	std::cout << "DiamondTrap "<< _name << " created." << std::endl;
}

DiamondTrap::DiamondTrap( DiamondTrap const & src )
{
	std::cout << "DiamondTrap " << _name << " created by copy." << std::endl;
	*this = src;
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "DiamondTrap "<< _name << " destroyed." << std::endl;
}

void	DiamondTrap::attack( std::string target )
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI( void )
{
	std::cout << "DiamondTrap Hi, my name are " << getName();
	std::cout << " from ClapTrap and " << _name << " from DiamondTrap.";
	std::cout << std::endl;
}

DiamondTrap & DiamondTrap::operator=( DiamondTrap const & rhs )
{
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
		_name = rhs._name;
	}	
	return *this;
}