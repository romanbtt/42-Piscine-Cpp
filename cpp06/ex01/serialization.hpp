#ifndef SERIALIZATION_H
#define SERIALIZATION_H

#include <iostream>

struct Data
{
	std::string favoriteColor;
	int			favoriteNumber;
	std::string	favoriteQuote;
	char		favoriteLetter;
};

Data*			deserialize(uintptr_t raw);
uintptr_t		serialize(Data* ptr);

#endif