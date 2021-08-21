#include "Replace.hpp"  
	
Replace::Replace( char* filename, char* s1, char* s2 )
{
	std::string newFilename( filename );

	this->_filename = filename;
	this->_newFilename = newFilename + ".replace";
	this->_oldString = s1;
	this->_newString = s2;
}
	
Replace::~Replace()
{
	return ;
}

void	Replace::readFile( void )
{
	std::ifstream	file;
	std::string		input;

	file.open( this->_filename.c_str() );
	if (file.is_open() == true)
	{
		getline(file, this->_text, '\0');
		file.close();
	}
	else
		std::cout << "Error: Could't open the file." << std::endl;
}

void	Replace::searchText( void )
{
	size_t	found = 0;

	while (found != std::string::npos)
	{
		found = this->_text.find(this->_oldString, found + 1);
		if (found != std::string::npos)
		{
			this->_text.erase(found, this->_oldString.length());
			this->_text.insert(found, this->_newString);
		}
	}
}

void	Replace::writeFile( void )
{
	std::ofstream	file;

	file.open( this->_newFilename.c_str() );
	if (file.is_open() == true)
	{
		file << this->_text;
		file.close();
	}
	else
		std::cout << "Error: Could't open the file." << std::endl;
}

void	Replace::startReplace( void )
{
	this->readFile();
	this->searchText();
	this->writeFile();
}
