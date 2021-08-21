#ifndef INTEGER_H
#define INTEGER_H

#include "AScalar.hpp"

class Integer : public AScalar
{

	private:

		int			_value;

	public:

		Integer( void );
		Integer( std::string value );
		Integer( Integer const & src );
		virtual ~Integer();

		int			toInt( void );
		float		toFloat( void );
		double		toDouble( void );
		char		toChar( void );

		Integer &	operator=( Integer const & rhs );

};
#endif