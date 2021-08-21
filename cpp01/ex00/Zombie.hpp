/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 14:20:26 by romanbtt          #+#    #+#             */
/*   Updated: 2021/07/13 22:54:38 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	private:
	
		std::string _name;
		Zombie( void );

	public:

		Zombie( std::string name );
		~Zombie( void );
		
		std::string	getName( void );
		void		setName( std::string name);
		
		void		announce ( void );
		
};

void	randomChump( std::string name );
Zombie*	newZombie( std::string name );

#endif