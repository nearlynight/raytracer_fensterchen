#include "Sphere.hpp"


Sphere::Sphere() {
	center_ = glm::vec3(10.0,10.0,10.0);
	radius_ = 5.0;
}

Sphere::Sphere(glm::vec3 center, double radius) {
	center_ = center;
	radius_ = radius;
}

Sphere::~Sphere() { }

glm::vec3 Sphere::get_center() {
	return center_;
}

double Sphere::get_radius() {
	return radius_;
}

void Sphere::set_center(glm::vec3 center) {
	center_ = center;
}

void Sphere::set_radius(double radius) {
	radius_ = radius;
}