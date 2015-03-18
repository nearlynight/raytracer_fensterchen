#ifndef SDFLOADER_HPP
#define SDFLOADER_HPP

#include <vector>
#include <fstream>
#include <iostream>
#include <string>

#include "Material.hpp"

class SdfLoader {
	public:
		//TODO dflt cstr necessary?
		SdfLoader();
		//SdfLoader();
		~SdfLoader();

		// has to inread file, each vector field has one line of sdf file
		// 
		static std::vector<Material> readFile(std::string filename);
		static std::vector<std::string> splitLine(std::string line);	
		

	private:
		//std::vector<std::string> materialVector_;

};

#endif