#ifndef AMATERIA_H
#define AMATERIA_H

#include "ICharacter.hpp"
#include <iostream>
#include <string>

class ICharacter;

class AMateria  
{
	protected:

		std::string 		_type;

	public:

		AMateria( void );
		AMateria( std::string const & type );
		AMateria( AMateria const & src );
		virtual ~AMateria( void );

		std::string const & getType( void ) const;
		void				setType( std::string const & type );

		virtual AMateria* 	clone( void ) const = 0;
		virtual void 		use( ICharacter& target );

		AMateria & 			operator=( AMateria const & rhs );

};

#endif