#ifndef LIGHT_HPP
#define LIGHT_HPP

#include <string>
#include <glm/glm.hpp>
#include "color.hpp"

class Light {
	public:
		Light();
		Light(std::string name, glm::vec3 pos, Color la, Color ld);
		~Light();

		std::string getName();
		glm::vec3 getPos();
		Color getLa();
		Color getLd();

	private:
		std::string name_;
		glm::vec3 pos_;
		Color la_;
		Color ld_;
};

#endif
