/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validationArgs.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:46:15 by romanbtt          #+#    #+#             */
/*   Updated: 2021/07/13 20:59:48 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

static bool	validationNbArgs( int nbArgs )
{
	if (nbArgs != 4)
	{
		std::cout << "Error: Wrong number of arguments." << std::endl;
		return true;
	}
	return false;
}

static bool	validationEmptyArgs( char **arguments)
{
	bool error;

	error = false;
	if (arguments[1][0] == '\0')
	{
		std::cout << "Error: Filename is empty. " <<std::endl;
		error = true;
	}	
	if (arguments[2][0] == '\0')
	{	
		std::cout << "Error: S1 is empty. " <<std::endl;
		error = true;
	}
	if (arguments[3][0] == '\0')
	{
		std::cout << "Error: S2 is empty. " <<std::endl;
		error = true;
	}
	return error;
}

bool	validationArguments( int nbArgs, char **arguments )
{
	bool error;

	error = false;
	if (validationNbArgs(nbArgs) == true)
		return true;
	else if (validationEmptyArgs(arguments) == true)
		return true;
	return false;
}
