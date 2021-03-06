#include "SdfLoader.hpp"

SdfLoader::SdfLoader() {
//	std::vector<std::string> materialVector_;
}

/*
SdfLoader::SdfLoader(std::vector<std::string> materialVector) {
	materialVector_ = materialVector;
}
*/

SdfLoader::~SdfLoader() { }


void SdfLoader::readFile(std::string filename) {
	std::ifstream ifs (filename);
	char line[256];
	if (ifs.is_open()) {
	  	while (ifs.good()) {
	  		ifs.getline(line, 256);
	    	// std::cout << line;
	    	std::vector<std::string> words = splitLine(line);
	    	int i = 0;
		    while(i < words.size()) {
		    	if(words[i].compare("define") == 0) {
		    		//std::cout << "define gefunden" << std::endl;

		    		// MATERIAL
		    		if(words[i+1].compare("material") == 0) {
		    			//std::cout << "material gefunden" << std::endl;
		    			std::string name = words[i+2];
		    			Color ka = Color(
                            std::stof(words[i + 3]), 
                            std::stof(words[i + 4]), 
                            std::stof(words[i + 5])
                        );
                        Color kd = Color(
                            std::stof(words[i + 6]), 
                            std::stof(words[i + 7]), 
                            std::stof(words[i + 8])
                        );
                        Color ks = Color(
                            std::stof(words[i + 9]), 
                            std::stof(words[i + 10]), 
                            std::stof(words[i + 11])
                        );
                        float m = std::stof(words[i+12]);
                        Material *my_material = new Material(name,ka,kd,ks,m);
                        materials_.push_back(dynamic_cast<Material*>(my_material));
                        i = i + 13;

                    // SPHERE
		    		} else if(words[i+1].compare("shape") == 0) {
		    			if(words[i+2].compare("sphere") == 0) {
		    				std::string name = words[i+3];
		    				glm::vec3 center = glm::vec3(
		    					std::stof(words[i+4]),
		    					std::stof(words[i+5]),
		    					std::stof(words[i+6])
		    					);
		    				double radius = std::stod(words[i+7]);
		    				std::string mat_name = words[i+8];

		    				Material material = getMaterialByName(mat_name);

		    				Sphere *sphere = new Sphere(name, center, radius, material);
		    				shapes_.push_back(dynamic_cast<Sphere*>(sphere));
		    				i = i + 9;

		    			// PLANE
		    			} else if (words[i+2].compare("plane") == 0) {
		    				std::string name = words[i+3];
		    				glm::vec3 normal = glm::vec3(
		    					std::stof(words[i+4]),
		    					std::stof(words[i+5]),
		    					std::stof(words[i+6])
		    					);
		    				double d = std::stod(words[i+7]);
		    				std::string mat_name = words[i+8];
		    			
		    				Material material = getMaterialByName(mat_name);

			    			Plane *plane = new Plane(name, normal, d, material);
			    			shapes_.push_back(dynamic_cast<Plane*>(plane));
			    			i = i + 9;

			    		// BOX
			    		} else if (words[i+2].compare("box") == 0) {
		    				std::string name = words[i+3];
		    				glm::vec3 p1 = glm::vec3(
		    					std::stof(words[i+4]),
		    					std::stof(words[i+5]),
		    					std::stof(words[i+6])
		    				);
		    				glm::vec3 p2 = glm::vec3(
		    					std::stof(words[i+7]),
		    					std::stof(words[i+8]),
		    					std::stof(words[i+9])
		    				);

		    				std::string mat_name = words[i+10];
		    				Material material = getMaterialByName(mat_name);
		    				Box *box = new Box(name, p1, p2, material);
		    				shapes_.push_back(dynamic_cast<Box*>(box));
		    				i = i + 11;

		    			} else {
		    				std::cout << "no shape(s) found" << std::endl;
		    			}

		    		// CAMERA
		    		} else if(words[i+1].compare("camera") == 0) {
		    			std::string name = words[i+2];
		    			double opening_angle = std::stod(words[i+3]);
		    			camera_.name = name;
		    			camera_.opening_angle = opening_angle;
		    			i = i + 4;

		    		// LIGHT SOURCE
		    		} else if (words[i+1].compare("light") == 0 ) {
		    			std::string name = words[i+2];
		    			glm::vec3 pos = glm::vec3(
		    				std::stof(words[i+3]),
		    				std::stof(words[i+4]),
							std::stof(words[i+5])
						);
						Color la = Color(
                            std::stof(words[i + 6]), 
                            std::stof(words[i + 7]), 
                            std::stof(words[i + 8])
                        );
                        Color ld = Color(
                            std::stof(words[i + 9]), 
                            std::stof(words[i + 10]), 
                            std::stof(words[i + 11])
                        );
                        Light *light = new Light(name, pos, la, ld);
		    			lights_.push_back(dynamic_cast<Light*>(light));
		    			i = i + 12;

		    		// DEFINE WITHOUT ADDITIONAL PARAMETERS FOUND
		    		} else {
		    			std::cout << "define found but no corresponding parameters" << std::endl;		    		
		    		}
		    		
		    	} else {
		    		++i;
		    		// std::cout << "Error parsing file " << words[i] << std::endl;
		    	}
		    }
		}	    
	} else {
	    // show message:
	    std::cout << "Error opening file" << std::endl;
	}
}

std::vector<Material*> SdfLoader::getMaterials() {
	return materials_;
}

std::vector<Shape*> SdfLoader::getShapes() {
	return shapes_;
}

std::vector<Light*> SdfLoader::getLights() {
	return lights_;
}

Camera SdfLoader::getCamera() {
	return camera_;
}

std::vector<std::string> SdfLoader::splitLine(std::string line) {
	std::vector<std::string> words;
    std::stringstream ssin(line);
    while (ssin.good()){
        std::string word;
        ssin >> word;
        words.push_back(word);
    }
	return words;
}

Material SdfLoader::getMaterialByName(std::string name) {
	int found_at = -1;
	for (int j = 0; j < materials_.size() && found_at == -1; ++j) {
		if(materials_.at(j)->get_name().compare(name) == 0) {
			found_at = j;
		}
	}
	Material material;
	if(found_at == -1) {
		std::cout << "corresponding material not found: " << name << std::endl;
		material = Material();
	} else {
		material = *materials_.at(found_at);
	}
	return material;
}
