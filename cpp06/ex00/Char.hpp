#ifndef CHAR_H
#define CHAR_H

#include "AScalar.hpp"

class Char : public AScalar
{

	public:

	class CharIsNonPrintableException : public std::exception
	{
		virtual const char* what() const throw();
	};

	private:

		char	_value;

	public:

		Char( void );
		Char( std::string value );
		Char( Char const & src );
		virtual ~Char();

		int		toInt( void );
		float	toFloat( void );
		double	toDouble( void );
		char	toChar( void );

		Char &	operator=( Char const & rhs );

};
#endif