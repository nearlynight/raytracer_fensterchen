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


std::vector<Material> SdfLoader::readFile(std::string filename) {
	//std::vector<std::string> materialVectorString;
	std::vector<Material> materialVector;

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
                        materialVector.push_back(Material(name,ka,kd,ks,m));
                        i = i + 13;

		    		} else {
		    			// add here for light, shape
		    			std::cout << " schade eigentlich" << std::endl;
		    		}
		    	} else {
		    		++i;
		    		std::cout << "schade eigentlich" << std::endl;
		    	}
		    }
		}
	    
	} else {
	    // show message:
	    std::cout << "Error opening file :( " << std::endl;
	}

	
	return materialVector;
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