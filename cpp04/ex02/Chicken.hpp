#ifndef CHICKEN_H
#define CHICKEN_H

#include "AAnimal.hpp"

class Chicken : public AAnimal
{

	public:

		Chicken( void );
		Chicken( Chicken const & src );
		virtual ~Chicken( void );

		void	makeSound( void ) const;

		Chicken &	operator=( Chicken const & rhs );

};
#endif