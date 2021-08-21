#ifndef KAREN_H
#define KAREN_H

#include <iostream>

class Karen  
{
	private:

		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );

	public:

		Karen( void );
		~Karen( void );

		void	complain( std::string level );

};

typedef void	(Karen::*t_level)( void );

#endif