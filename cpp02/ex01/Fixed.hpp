#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed  
{
	private:

		int					_rawBits;
		static int const	_nbFractionalBits;

	public:

		Fixed( void );
		Fixed( int const input );
		Fixed( float const input );
		Fixed( Fixed const & src );
		~Fixed( void );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		float	toFloat( void ) const;
		int		toInt( void ) const;

		Fixed & operator=( Fixed const & rhs );
		
};

std::ostream & operator<<( std::ostream & output, Fixed const & rhs );

#endif