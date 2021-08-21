#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:

		bool 		_gateKeeperMode;

	public:

		ScavTrap( void );
		ScavTrap( std::string name );
		ScavTrap( ScavTrap const & src );
		~ScavTrap( void );

		void		guardGate( void );
		void		attack( std::string const & target );

		ScavTrap &	operator=( ScavTrap const & rhs );

};
#endif