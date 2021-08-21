/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 10:27:06 by romanbtt          #+#    #+#             */
/*   Updated: 2021/07/11 20:52:36 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/*
** Constructor of the Contact class.
** Nothing to do in this function.
*/

Contact::Contact( void )
{
	return ;
}

/*
** Destructor of the Contact class.
** Nothing to do in this function.
*/

Contact::~Contact( void )
{
	return ;
}

/*
** Ask for an input and store the string inside _firstName of the instance
** pointed by this.
*/

void		Contact::setFirstName( void )
{
	std::cout << "Enter the first name: ";
	std::getline(std::cin, this->_firstName);
}

/*
** Return the string _firstName of the instance pointed by this.
*/

std::string	Contact::getFirstName( void ) const
{
	return (this->_firstName);
}

/*
** Ask for an input and store the string inside _lastName of the instance
** pointed by this.
*/

void		Contact::setLastName( void )
{
	std::cout << "Enter the last name: ";
	std::getline(std::cin, this->_lastName);
}

/*
** Return the string _lastName of the instance pointed by this.
*/

std::string	Contact::getLastName( void ) const
{
	return (this->_lastName);
}

/*
** Ask for an input and store the string inside _nickname of the instance
** pointed by this.
*/

void		Contact::setNickname( void )
{
	std::cout << "Enter the nickname: ";
	std::getline(std::cin, this->_nickname);
}

/*
** Return the string _nickname of the instance pointed by this.
*/

std::string	Contact::getNickname( void ) const
{
	return (this->_nickname);
}

/*
** Ask for an input and store the string inside _phoneNumber of the instance
** pointed by this.
*/

void		Contact::setPhoneNumber( void )
{
	std::cout << "Enter the phone number: ";
	std::getline(std::cin, this->_phoneNumber);
}

/*
** Return the string _phoneNumber of the instance pointed by this.
*/

std::string	Contact::getPhoneNumber( void ) const
{
	return (this->_phoneNumber);
}

/*
** Ask for an input and store the string inside _darkestSecret of the instance
** pointed by this.
*/

void		Contact::setDarkestSecret( void )
{
	std::cout << "Enter the darkest secret: ";
	std::getline(std::cin, this->_darkestSecret);
}

/*
** Return the string _darkestSecret of the instance pointed by this.
*/

std::string	Contact::getDarkestSecret( void ) const
{
	return (this->_darkestSecret);
}
