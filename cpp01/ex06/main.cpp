/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 18:52:35 by romanbtt          #+#    #+#             */
/*   Updated: 2021/07/13 19:09:21 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int	main( int argc, char *argv[])
{
	Karen karen;
	
	if (argc < 2)
	{
		std::cout << "Error: Argument missing." << std::endl;
		return 1;
	}
	else
	{
		karen.complain(argv[1]);
	}
}