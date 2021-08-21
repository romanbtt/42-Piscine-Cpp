#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H
	
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:

		AMateria 		*_sources[4];
		unsigned int	_currIdx;

	public:

		MateriaSource( void );
		MateriaSource( MateriaSource const & src );
		virtual ~MateriaSource();

		unsigned int 	getCurrIdx( void ) const;

		void 			learnMateria( AMateria* source );
		AMateria *		createMateria( std::string const & type );

		MateriaSource &	operator=( MateriaSource const & rhs );

};
#endif