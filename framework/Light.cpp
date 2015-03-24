#include "Light.hpp"

Light::Light(){
	name_ = " ";
	pos_ = glm::vec3(1000,1000,0);
	la_ = Color(0.0, 0.0, 0.0);
	ld_ = Color(0.0, 0.0, 0.0);
}

Light::Light(std::string name, glm::vec3 pos, Color la, Color ld) {
	name_ = name;
	pos_ = pos;
	la_ = la;
	ld_ = ld;
}

std::string Light::getName() {
	return name_;
}

glm::vec3 Light::getPos() {
	return pos_;
}

Color Light::getLa() {
	return la_;
}

Color Light::getLd() {
	return ld_;
}