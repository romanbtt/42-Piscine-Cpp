#ifndef ASCALAR_H
#define ASCALAR_H
	
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <string>
#include <cmath>

class AScalar  
{

	public:

	class NonDisplayableException : public std::exception
	{
		virtual const char* what() const throw();
	};

	class ImpossibleException : public std::exception
	{
		virtual const char* what() const throw();
	};

	class WrongScalarValueException : public std::exception
	{
		virtual const char* what() const throw();
	};
	
	protected:

		std::string 	_scalar;
	
	public:

		AScalar( void );
		AScalar( std::string scalar );
		AScalar( AScalar const & src );
		virtual ~AScalar( void );

		std::string		getScalar( void ) const;

		virtual	int		toInt( void ) = 0;
		virtual	float	toFloat( void ) = 0;
		virtual	double	toDouble( void ) = 0;
		virtual	char	toChar( void ) = 0;

		AScalar & 		operator=( AScalar const & rhs );
};

AScalar * determineScalar( std::string scalar );

#endif