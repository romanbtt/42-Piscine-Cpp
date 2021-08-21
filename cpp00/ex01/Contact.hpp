/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 10:27:09 by romanbtt          #+#    #+#             */
/*   Updated: 2021/07/11 20:52:48 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <sstream>

class Contact
{
	public:

		Contact( void );
		~Contact( void );

		void		setFirstName( void );
		std::string	getFirstName( void ) const;

		void		setLastName( void );
		std::string getLastName( void ) const;

		void		setNickname( void );
		std::string getNickname( void ) const;

		void		setPhoneNumber( void );
		std::string getPhoneNumber( void ) const;
		
		void		setDarkestSecret( void );
		std::string getDarkestSecret( void ) const;

	private:
	
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;
};

#endif
