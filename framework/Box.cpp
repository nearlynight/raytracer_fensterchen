#include "box.hpp"
#include <ostream>
#include <cmath>
#include <algorithm>

Box::Box() {
	name_ = "";
	p_min_ = glm::vec3();
	p_max_ = glm::vec3();
	material_ = Material();
}

Box::Box(std::string name, glm::vec3 p_min, glm::vec3 p_max, Material material) : name_{ name }, p_min_{ p_min }, p_max_{ p_max }, material_{ material } {}

Box::~Box() {}


double Box::intersect(Ray ray) {

	// t values for equation of front, back, top, bottom, left, right
	float ts[] = { -1, -1, -1, -1, -1, -1};
	
	
	// float t_front;
	if (ray.direction.z != 0) {
		// front 
		ts[0] = (p_min_.z - ray.origin.z) / ray.direction.z;
		glm::vec3 p_front = ray.origin + ts[0] * ray.direction;
		if (!(p_front.x < p_max_.x && p_front.x > p_min_.x  &&  p_front.y < p_max_.y && p_front.y > p_min_.y)) {
			ts[0] = -1;
		}
		// back
		ts[1] = (p_max_.z - ray.origin.z) / ray.direction.z;
		glm::vec3 p_back = ray.origin + ts[1] * ray.direction;
		if (!(p_back.x < p_max_.x && p_back.x > p_min_.x  &&  p_back.y < p_max_.y && p_back.y > p_min_.y)) {
			ts[1] = -1;
		}
	}

	if (ray.direction.y != 0) {
		// top
		ts[2] = (p_max_.y - ray.origin.y) / ray.direction.y;
		glm::vec3 p_top = ray.origin + ts[2] * ray.direction;
		if (!(p_top.x < p_max_.x && p_top.x > p_min_.x  &&  p_top.z > p_max_.z && p_top.z < p_min_.z)) {
			ts[2] = -1;
		}
		// bottom
		ts[3] = (p_min_.y - ray.origin.y) / ray.direction.y;
		glm::vec3 p_bottom = ray.origin + ts[3] * ray.direction;
		if (!(p_bottom.x < p_max_.x && p_bottom.x > p_min_.x  &&  p_bottom.z > p_max_.z && p_bottom.z < p_min_.z)) {
			ts[3] = -1;
		}
	}

	if (ray.direction.x != 0) {
		// left
		ts[4] = (p_min_.x - ray.origin.x) / ray.direction.x;
		glm::vec3 p_left = ray.origin + ts[4] * ray.direction;
		if (!(p_left.y < p_max_.y && p_left.y > p_min_.y  &&  p_left.z > p_max_.z && p_left.z < p_min_.z)) {
			ts[4] = -1;
		}
		// right
		ts[5] = (p_max_.x - ray.origin.x) / ray.direction.x;
		glm::vec3 p_right = ray.origin + ts[5] * ray.direction;
		if (!(p_right.y < p_max_.y && p_right.y > p_min_.y  &&  p_right.z > p_max_.z && p_right.z < p_min_.z)) {
			ts[5] = -1;
		}
	}

	float final_t = -1;
	for ( int i = 0; i < 6; ++i) {
		if (ts[i] > 0 && (ts[i] < final_t || final_t == -1)) {
			final_t = ts[i];
		}
	}
	return (double)final_t;
}

// GETTER
std::string Box::get_name() {
	return name_;
}
Material Box::get_material() const {
	return material_;
}
glm::vec3 Box::getNormalAt(glm::vec3 point) const {
	if (point.x == p_min_.x)
		return glm::vec3(-1, 0, 0);
	else if (point.x == p_max_.x)
		return glm::vec3(1, 0, 0);
	else if (point.y == p_min_.y)
		return glm::vec3(0, -1, 0);
	else if (point.y == p_max_.y)
		return glm::vec3(0, 1, 0);
	else if (point.z == p_min_.z)
		return glm::vec3(0, 0, 1);
	else if (point.z == p_max_.z)
		return glm::vec3(0, 0, -1);
	else
		return glm::vec3();
}

glm::vec3 Box::getPMin() {
	return p_min_;
}
glm::vec3 Box::getPMax() {
	return p_max_;
}

// SETTER
void Box::setName(std::string name) {
	name_ = name;
}
void Box::setPMin(glm::vec3 p_min) {
	p_min_ = p_min;
}
void Box::setPMax(glm::vec3 p_max) {
	p_max_ = p_max;
}
void Box::setMaterial(Material material) {
	material_ = material;
}