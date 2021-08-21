#ifndef BRAIN_H
#define BRAIN_H
	
#include <iostream>
#include <string>

class Brain  
{
	private:

		std::string	_ideas[100];

	public:

		Brain( void );
		Brain( Brain const & src );
		virtual ~Brain( void );

		std::string getIdea( unsigned int index ) const;
		void		setIdea( unsigned int index, std::string idea );

		Brain & 	operator=( Brain const & rhs );

};
#endif