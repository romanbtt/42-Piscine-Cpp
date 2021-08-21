#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{

	protected:

		int 		_hitPointsInit;
		int			_energyPointsInit;
		int 		_attackDamageInit;

		virtual int	getHitPointsInit( void );
		virtual int	getEnergyPointsInit( void ); 
		virtual int	getAttackDamageInit( void ); 

	public:

		FragTrap( void );
		FragTrap( std::string Name );
		FragTrap( FragTrap const & src );
		~FragTrap( void );

		void 		highFivesGuys( void );

		FragTrap &	operator=( FragTrap const & rhs );

};
#endif