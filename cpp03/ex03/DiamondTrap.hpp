#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"



class DiamondTrap : public ScavTrap, public FragTrap
{
	private:

		std::string		_name;
		
	public:

		DiamondTrap( void );
		DiamondTrap( std::string name );
		DiamondTrap( DiamondTrap const & src);
		~DiamondTrap( void );

		void			attack( std::string target );
		void			whoAmI( void );

		DiamondTrap	&	operator=( DiamondTrap const & rhs );
		
};

#endif