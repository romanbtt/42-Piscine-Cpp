#ifndef FLOAT_H
#define FLOAT_H

#include "AScalar.hpp"

class Float : public AScalar
{

	private:

		float	_value;

	public:

		Float( void );
		Float( std::string value );
		Float( Float const & src );
		virtual ~Float();

		int		toInt( void );
		float	toFloat( void );
		double	toDouble( void );
		char	toChar( void );

		Float &	operator=( Float const & rhs );

};
#endif