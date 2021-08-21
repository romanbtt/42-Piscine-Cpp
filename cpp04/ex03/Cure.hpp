#ifndef CURE_H
#define CURE_H

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:

		Cure( void );
		Cure( Cure const & src );
		virtual ~Cure( void );

		Cure*	clone( void ) const;
		void	use( ICharacter& target );

		Cure &	operator=( Cure const & rhs );

};
#endif