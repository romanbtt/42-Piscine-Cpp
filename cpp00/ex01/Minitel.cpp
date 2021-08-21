/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minitel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:02:49 by romanbtt          #+#    #+#             */
/*   Updated: 2021/07/11 20:54:17 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitel.hpp"

/*
** Constructor of the Minitel class.
** We initialize _index and _numberContact to 0.
** Nothing to do in this function.
*/

Minitel::Minitel( void ) : _index(0), _numberContact(0)
{
	return ;
}

/*
** Destructor of the Minitel class.
** Nothing to do in this function.
*/

Minitel::~Minitel( void )
{
	return ;
}

/*
** If the index is at the last position : 7.
** It means that we need to replace the oldest contact and then come back to
** an index 0.
** Else, we increment the index.
*/

void Minitel::setIndex( void )
{
	if (getIndex() >= 7)
		this->_index = 0;
	else
		this->_index++;
}

/*
** Return the int _index of the instance pointed by this.
*/

int Minitel::getIndex( void ) const
{
	return (this->_index);
}

/*
** Increment the _numberContact if it is not already at 8.
*/

void Minitel::setNumberContact( void )
{
	if (this->getNumberContact() < 8)
		this->_numberContact++;
}

/*
** Return the int _numberContact of the instance pointed by this.
*/

int Minitel::getNumberContact( void ) const
{
	return (this->_numberContact);
}

/*
** We first get the index of the current contact to add.
** Then we call one by one the functions the get the inputs.
** In case of all the fields are empty, we do not save the contact.
** Finally we update the index and the number of contacts inside the minitel.
*/

void	Minitel::add( void )
{
	int index;
	Contact *contact;

	index = this->getIndex();
	contact = &this->_contact[index];
	(*contact).setFirstName();
	(*contact).setLastName();
	(*contact).setNickname();
	(*contact).setPhoneNumber();
	(*contact).setDarkestSecret();
	if ((*contact).getFirstName().length() == 0 &&
		(*contact).getLastName().length() == 0 &&
		(*contact).getNickname().length() == 0 &&
		(*contact).getPhoneNumber().length() == 0 &&
		(*contact).getDarkestSecret().length() == 0)
			return ;
	this->setIndex();
	this->setNumberContact();
}

/*
** If the lenght of the string is more than 10, it will truncate the string
** to only keep the first 10 character and replace the tenth character by a '.'
*/

static std::string truncate( std::string str )
{
    if (str.length() > 10)
         return str.substr(0, 9) + ".";
    return str;
}

/*
** This function print the header of the SEARCH command.
*/

static void	header( void )
{
	std::cout.width(10);
	std::cout << std::right << "Index" << '|';
	std::cout.width(10);
	std::cout << std::right << "First Name" << '|';
	std::cout.width(10);
	std::cout << std::right << "Last Name" << '|';
	std::cout.width(10);
	std::cout << std::right << "Nickname" << '|';
	std::cout << std::endl;
}

/*
** This function print all the fields of a contact.
*/

static void printFullContact( Contact *contact )
{
	std::cout << "First Name     : ";
	std::cout << (*contact).getFirstName() << std::endl;
	std::cout << "Last Name      : ";
	std::cout << (*contact).getLastName() << std::endl;
	std::cout << "Nickname       : ";
	std::cout << (*contact).getNickname() << std::endl;
	std::cout << "Phone Number   : ";
	std::cout << (*contact).getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret : ";
	std::cout << (*contact).getDarkestSecret() << std::endl;
}

/*
** This function ask for an index and try to print all the fields if
** the index is valid and the contact exists.
*/

void Minitel::inputIndex( void )
{
	std::string			indexStr;
	int					indexInt;
	std::stringstream	index;
	Contact 			*contact;

	std::cout << "Enter an index (1 - 8) : ";
	std::getline(std::cin, indexStr);
	index << indexStr;
	index >> indexInt;
	if (indexInt < 1 || indexInt > 8)
		std::cout << "Index should be between 1 and 8." << std::endl;
	else
	{
		if (indexInt > this->_numberContact)
			std::cout << "This index's contact is empty." << std::endl;
		else
		{
			contact = &this->_contact[indexInt - 1];
			printFullContact(contact);
		}
	}
}

/*
** This function print a error message in case there is no contact in
** the minitel.
*/


static void	printNoContact( void )
{
	std::cout << "There are no contact in the minitel!" << std::endl;
	std::cout << "You can add one by using the ADD command." << std::endl;
}

/*
** We first get the number of contact. If there is none, we call printNoContact().
** Else we print the header and the fields of the contacts.
** Finally we call inputIndex() to ask the user a specific contact to print.
*/

void	Minitel::search( void )
{
	Contact	*contact;
	int		numberContact;
	int		i;
	
	numberContact = this->getNumberContact();
	if (numberContact == 0)
	{
		printNoContact();
		return ;
	}
	else
		header();
	for (i = 0; i < numberContact; i++)
	{
		contact = &this->_contact[i];
		std::cout.width(10);
		std::cout << std::right << i + 1 << '|';
		std::cout.width(10);
		std::cout << std::right << truncate((*contact).getFirstName()) << '|';
		std::cout.width(10);
		std::cout << std::right << truncate((*contact).getLastName()) << '|';
		std::cout.width(10);
		std::cout << std::right << truncate((*contact).getNickname()) << '|';
		std::cout << std::endl;
	}
	this->inputIndex();
}
