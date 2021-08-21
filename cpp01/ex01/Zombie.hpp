#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <sstream>

class Zombie
{
	private:

		std::string _name;

	public:

		Zombie( std::string name );
		Zombie( void );
		~Zombie( void );
		
		std::string	getName( void );
		void		setName( std::string name);

		void		announce ( void );

};

Zombie* zombieHorde( int N, std::string name );

#endif