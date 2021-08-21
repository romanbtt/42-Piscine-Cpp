#ifndef DOUBLET_H
#define DOUBLET_H

#include "AScalar.hpp"

class Double : public AScalar
{

	private:

		double	_value;

	public:

		Double( void );
		Double( std::string value );
		Double( Double const & src );
		virtual ~Double();

		int		toInt( void );
		float	toFloat( void );
		double	toDouble( void );
		char	toChar( void );

		Double & operator=( Double const & rhs );

};
#endif