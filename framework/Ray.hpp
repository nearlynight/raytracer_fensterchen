#include <glm/glm.hpp>

struct Ray {
	Ray(glm::vec3 orig, glm::vec3 direc) : origin{orig}, direction{direc} {}
	glm::vec3 origin;
	glm::vec3 direction;
};