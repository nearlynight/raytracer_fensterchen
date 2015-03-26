#ifndef SDFLOADER_HPP
#define SDFLOADER_HPP

//#include <vector>
#include <fstream>
//#include <iostream>
//#include <string>
#include <glm/glm.hpp>

//#include "Material.hpp"
//#include "Shape.hpp"
#include "Sphere.hpp"
#include "Camera.hpp"
#include "Light.hpp"
#include "Plane.hpp"
#include "Box.hpp"


class SdfLoader {
	public:
		//TODO dflt cstr necessary?
		SdfLoader();
		//SdfLoader();
		~SdfLoader();

		// has to inread file, each vector field has one line of sdf file
		// 
		void readFile(std::string filename);
		std::vector<Material*> getMaterials();
		std::vector<Shape*> getShapes();
		std::vector<Light*> getLights();
		Camera getCamera();
		static std::vector<std::string> splitLine(std::string line);	
		Material getMaterialByName(std::string name);

	private:
		std::vector<Material*> materials_;
		std::vector<Shape*> shapes_;
		std::vector<Light*> lights_;
		Camera camera_;
};

#endif