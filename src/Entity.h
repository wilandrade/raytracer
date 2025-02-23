#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class Entity
{
	public:
		void LoadProperties(std::ifstream& fileStream);
		virtual void ProcessProperty(std::ifstream& fileStream, std::string propertyName)=0;
};