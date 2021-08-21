/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 21:56:26 by romanbtt          #+#    #+#             */
/*   Updated: 2021/08/06 09:08:57 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serialization.hpp"

void	printData( Data *data )
{
	std::cout << "Favorite color  : " << data->favoriteColor << std::endl;
	std::cout << "Favorite number : " << data->favoriteNumber << std::endl;
	std::cout << "Favorite quote  : " << data->favoriteQuote << std::endl;
	std::cout << "Favorite letter : " << data->favoriteLetter << std::endl;
}

uintptr_t serialize( Data* ptr )
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize( uintptr_t raw )
{
	return reinterpret_cast<Data*>(raw);
}

int	main( void )
{
	uintptr_t rawData = 0;
	Data* dataDeserialize = NULL;
	Data favorite = {"green", 12, "Talk is cheap, show me the code!", 'R'};

	printData(&favorite);
	rawData = serialize(&favorite);
	std::cout << rawData << std::endl;
	dataDeserialize = deserialize(rawData);
	printData(dataDeserialize);
	return 0;
}