#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
	private:

		bool 		_gateKeeperMode;

	protected:

		int 		_hitPointsInit;
		int			_energyPointsInit;
		int 		_attackDamageInit;

		virtual int	getHitPointsInit( void );
		virtual	int	getEnergyPointsInit( void ); 
		virtual	int	getAttackDamageInit( void ); 

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