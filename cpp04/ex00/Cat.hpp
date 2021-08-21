#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"

class Cat : public Animal
{

	public:

		Cat( void );
		Cat( Cat const & src );
		virtual ~Cat( void );

		void	makeSound( void ) const;

		Cat &	operator=( Cat const & rhs );

};
#endif