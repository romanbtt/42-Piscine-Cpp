#ifndef ICE_H
#define ICE_H

#include "AMateria.hpp"

class Ice : public AMateria
{

	public:

		Ice( void );
		Ice( Ice const & src );
		virtual ~Ice( void );

		Ice*	clone( void ) const;
		void	use( ICharacter& target );

		Ice &	operator=( Ice const & rhs );

};
#endif