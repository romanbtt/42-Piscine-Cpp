/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 21:52:50 by romanbtt          #+#    #+#             */
/*   Updated: 2021/08/12 10:31:54 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

static void	separator( void )
{
	std::cout << "\033[1;31m-- -- -- -- -- -- -- -- -- -- -- -- -- --\033[0m";
	std::cout << std::endl;
}

void	isRounded( float const &n )
{
	int		integer = n;
	float	floatRounded = integer;	

	std::cout << std::fixed << std::setprecision(2);
	if (n == floatRounded)
		std::cout << n << " is rounded" << std::endl;
	else
		std::cout << n << " is not rounded" << std::endl;
}

void	isPrime( int const &n )
{
	bool isPrime = true;

	if (n == 0 || n == 1)
		isPrime = false;
	else
	{
		for (int i = 2; i <= n / 2; i++)
		{
			if (n % i == 0)
			{
				isPrime = false;
                break;
			}
		}
	}
	if (isPrime)
        std::cout << n << " is a prime number" << std::endl;
    else
        std::cout << n << " is not a prime number" << std::endl;
}

void	decode( std::string const &message )
{
	for (int i = 0; message[i] != '\0'; i++)
	{
		if (message[i] == 0x61 || message[i] == 0x41)
			std::cout << static_cast<char>(message[i] + 0x19);
		else if (message[i] == 0x20)
			std::cout << static_cast<char>(0x20);
		else
			std::cout << static_cast<char>(message[i] - 0x01);
	}
	std::cout << std::endl;
}

void	typeLetter( char const &letter )
{
	std::string vowels = "aAeEiIoOuUyY";

	if (vowels.find(letter) != std::string::npos)
		std::cout << letter << " is a vowel" << std::endl;
	else
		std::cout << letter << " is a consonant" << std::endl;
}

int	main( void )
{
	{
		int array[10] = {7, 9, 11, 13, 15, 23, 27, 29, 37, 39};
		int	*array2 = NULL;
	
		iter(array, 10, isPrime);
		iter(array2, 10, isPrime);
	}
	separator();
	{
		std::string messages[3] = {"Uijt nfttbhf xbt fodpefe",
									"53 jt gps uif csbwf",
									"Ubml jt difbq- tipx nf uif dpef"};
		std::string *messages2 = NULL;

		iter(messages, 3, decode);
		iter(messages2, 3, decode);
	}
	separator();
	{
		char letters[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
						'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
						'W', 'X', 'Y', 'Z'};
		char *letters2 = NULL;
	 	
		iter(letters, 26, typeLetter);
		iter(letters2, 26, typeLetter);
	}
	separator();
	{
		float array[10] = {10.2f, 10.0f, 42.24f, 24.0f, 24.5f, 85.0f, 96.0f, 100.0f, 99.99f, 12.12};
		float *array2 = NULL;
	 	
		iter(array, 10, isRounded);
		iter(array2, 10, isRounded);
	}
	return 0;
}