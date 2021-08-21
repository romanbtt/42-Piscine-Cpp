/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 10:08:43 by romanbtt          #+#    #+#             */
/*   Updated: 2021/07/13 20:59:57 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int		main( int argc, char *argv[] )
{
	if (validationArguments( argc, argv) == true)
		return 1;
	else
	{
		Replace	replace( argv[1], argv[2], argv[3] );
		replace.startReplace();
	}
	return 0;
}
