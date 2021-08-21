#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <iostream>
#include <string>

class WrongAnimal  
{

	protected:

		std::string		_type;

	public:

		WrongAnimal( void );
		WrongAnimal( WrongAnimal const & src );
		virtual ~WrongAnimal( void );

		void			makeSound( void ) const;
		std::string		getType( void ) const;

		WrongAnimal &	operator=( WrongAnimal const & rhs );

};
#endif