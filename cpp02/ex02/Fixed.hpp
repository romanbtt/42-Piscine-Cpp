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

		bool operator>( Fixed const & rhs ) const;
		bool operator<( Fixed const & rhs ) const;
		bool operator>=( Fixed const & rhs ) const;
		bool operator<=( Fixed const & rhs ) const;
		bool operator==( Fixed const & rhs ) const;
		bool operator!=( Fixed const & rhs ) const;

		Fixed operator+( Fixed const & rhs ) const;
		Fixed operator-( Fixed const & rhs ) const;
		Fixed operator*( Fixed const & rhs ) const;
		Fixed operator/( Fixed const & rhs ) const;

		Fixed & operator++( void );
		Fixed operator++( int );
		Fixed & operator--( void );
		Fixed operator--( int );

		static Fixed const & min( Fixed const & first, Fixed const & second);
		static Fixed const & max( Fixed const & first, Fixed const & second);

};

std::ostream & operator << ( std::ostream & output, Fixed const & rhs );

#endif