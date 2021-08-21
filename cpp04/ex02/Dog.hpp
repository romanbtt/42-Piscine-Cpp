#ifndef DOG_H
#define DOG_H

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{

	private:

		Brain	*_brain = NULL;

	public:

		Dog( void );
		Dog( Dog const & src );
		virtual ~Dog( void );

		void	makeSound( void ) const;
		Brain *	getBrain( void ) const;

		Dog &	operator=( Dog const & rhs );

};
#endif