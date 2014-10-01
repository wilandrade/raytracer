#include "Entity.h"

void Entity::LoadProperties(std::ifstream& fileStream)
{
	std::string stringToken; //buffer for the string we're reading from the file stream

	fileStream >> stringToken;

	std::string propertiesEndDelimiter = "}";

	while ( stringToken != propertiesEndDelimiter )
	{
		ProcessProperty(fileStream, stringToken);
		fileStream >> stringToken;
	}

}


void Entity::ProcessProperty(std::ifstream& fileStream, std::string propertyName)
{
	std::cout << "\t -" << propertyName << " is not a valid property. Please check syntax" << std::endl;
}