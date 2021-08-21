#ifndef CHARACTER_H
#define CHARACTER_H

#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:

		std::string			_name;
		AMateria 			*_inventory[4];
		unsigned int		_currIdx;

	public:

		Character( void );
		Character( std::string name );
		Character( Character const & src );
		virtual ~Character();

		std::string const &	getName( void ) const;
		AMateria const &	getInventory( unsigned int index ) const;
		unsigned int		getCurrIdx( void ) const;

		void 				equip( AMateria* m );
		void				unequip( int idx );
		void 				use( int idx, ICharacter& target );

		Character &			operator=( Character const & rhs );

};
#endif