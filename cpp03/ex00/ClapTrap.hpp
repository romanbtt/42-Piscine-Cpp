#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>
#include <string>

class ClapTrap  
{
	private:

		std::string		_name;
		int				_hitPoints;
		int				_energyPoints;
		int				_attackDamage;

	public:

		ClapTrap( void );
		ClapTrap( std::string name );
		ClapTrap( ClapTrap const & src );
		~ClapTrap();

		void 			attack( std::string const & target );
		void 			takeDamage( unsigned int amount );
		void			beRepaired( unsigned int amount );

		std::string		getName( void ) const;
		void			setName( std::string name );

		int				getHitPoints( void ) const;
		void			setHitPoints( unsigned int hitPoints );

		int				getEnergyPoints( void ) const;
		void			setEnergyPoints( unsigned int energyPoints );

		int				getAttackDamage( void ) const;
		void			setAttackDamage( unsigned int attackDamage );

		ClapTrap & 		operator=( ClapTrap const & rhs );
};
#endif