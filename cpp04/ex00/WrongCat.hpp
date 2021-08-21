#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{

	public:

		WrongCat( void );
		WrongCat( WrongCat const & src );
		virtual ~WrongCat( void );

		void		makeSound( void ) const;

		WrongCat &	operator=( WrongCat const & rhs );
		
};
#endif