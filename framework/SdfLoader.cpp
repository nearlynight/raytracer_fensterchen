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
                        static Material my_material = Material(name,ka,kd,ks,m);
                        materials_.push_back(dynamic_cast<Material*>(&my_material));
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

		    				int found_at = -1;
		    				for (int j = 0; j < materials_.size() && found_at == -1; ++j) {
		    					if(materials_.at(j)->get_name().compare(mat_name) == 0) {
		    						found_at = j;
		    					}
		    				}

		    				Material material;
		    				if(found_at == -1) {
		    					std::cout << "corresponding material not found: " << mat_name << std::endl;
		    					material = Material();
		    				} else {
		    					material = *materials_.at(found_at);
		    				}

		    				static Sphere sphere = Sphere(name, center, radius, material);
		    				shapes_.push_back(dynamic_cast<Sphere*>(&sphere));
		    			}
		    			i = i + 9;

		    		// CAMERA
		    		} else if(words[i+1].compare("camera") == 0) {
		    			std::string name = words[i+2];
		    			double opening_angle = std::stod(words[i+3]);
		    			camera_.name = name;
		    			camera_.opening_angle = opening_angle;
		    			i = i + 4;
		    		} else {
		    			std::cout << "define found but no corresponding parameters" << std::endl;		    		}
		    		
		    	} else {
		    		++i;
		    		std::cout << "Error parsing file" << std::endl;
		    	}
		    }
		}
	    
	} else {
	    // show message:
	    std::cout << "Error opening file :( " << std::endl;
	}
}

std::vector<Material*> SdfLoader::getMaterials() {
	return materials_;
}

std::vector<Shape*> SdfLoader::getShapes() {
	return shapes_;
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

