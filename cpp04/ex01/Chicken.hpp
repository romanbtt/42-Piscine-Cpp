#ifndef CHICKEN_H
#define CHICKEN_H

#include "Animal.hpp"

class Chicken : public Animal
{

	public:

		Chicken( void );
		Chicken( Chicken const & src );
		virtual ~Chicken( void );

		void	makeSound( void ) const;

		Chicken &	operator=( Chicken const & rhs );

};
#endif