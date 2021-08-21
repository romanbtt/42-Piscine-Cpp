#ifndef CAT_H
#define CAT_H

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{

	private:

		Brain	*_brain = NULL;

	public:

		Cat( void );
		Cat( Cat const & src );
		virtual ~Cat( void );

		void	makeSound( void ) const;
		Brain *	getBrain( void ) const;

		Cat &	operator=( Cat const & rhs );

};
#endif