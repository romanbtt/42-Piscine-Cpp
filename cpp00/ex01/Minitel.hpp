/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minitel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:02:52 by romanbtt          #+#    #+#             */
/*   Updated: 2021/07/12 13:07:45 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITEL_HPP
#define MINITEL_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <sstream>
# include "Contact.hpp"

class Minitel
{
	public:

		Minitel( void );
		~Minitel( void );
		
		void	add( void );
		void	search( void );
		void	inputIndex( void );
		
		void	setIndex( void );
		int		getIndex( void ) const;

		void	setNumberContact( void );
		int		getNumberContact( void ) const;

	private:
	
		Contact	_contact[8];
		int		_index;
		int		_numberContact;
};

#endif