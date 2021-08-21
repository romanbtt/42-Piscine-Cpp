#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:

		FragTrap( void );
		FragTrap( std::string Name );
		FragTrap( FragTrap const & src );
		~FragTrap( void );

		void 		highFivesGuys( void );

		FragTrap &	operator=( FragTrap const & rhs );

};
#endif