#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed  
{
	private:

		int					_rawBits;
		static int const	_nbFractionalBits;

	public:

		Fixed( void );
		Fixed( Fixed const & src );
		~Fixed( void );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		Fixed & operator=( Fixed const & rhs);

};
#endif