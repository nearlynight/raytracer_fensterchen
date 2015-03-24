#include <glm/glm.hpp>

struct Camera {
	//Ray(glm::vec3 orig, glm::vec3 direc) : origin{orig}, direction{direc} {}
	double opening_angle;
	glm::vec3 position;
	glm::vec3 direction;
	std::string name;
};