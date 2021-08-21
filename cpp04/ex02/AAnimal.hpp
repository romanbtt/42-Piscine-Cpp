#ifndef ANIMAL_H
#define ANIMAL_H
	
#include <iostream>
#include <string>

class AAnimal  
{

	protected:

		std::string		_type;

	public:

		AAnimal( void );
		AAnimal( AAnimal const & src );
		virtual ~AAnimal( void );

		virtual void	makeSound( void ) const = 0;
		std::string		getType( void ) const;

		AAnimal & 		operator=( AAnimal const & rhs );

};
#endif