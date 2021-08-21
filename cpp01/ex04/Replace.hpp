#ifndef REPLACE_H
#define REPLACE_H
	
#include <iostream>
#include <string>
#include <fstream>

class Replace  
{
	private:

		std::string	_filename;
		std::string	_newFilename;
		std::string	_oldString;
		std::string	_newString;
		std::string	_text;
		void	readFile( void );
		void	searchText( void );
		void	writeFile( void );

	public:

		Replace( char* filename, char* s1, char* s2 );
		~Replace();

		void	startReplace( void );

};

bool	validationArguments( int nbArgs, char **arguments );

#endif