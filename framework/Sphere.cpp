#include "Sphere.hpp"


Sphere::Sphere() {
    name_ = " ";
	center_ = glm::vec3(10.0,10.0,10.0);
	radius_ = 5.0;
    material_ = Material();
}

Sphere::Sphere(std::string name, glm::vec3 center, double radius, Material material) {
	name_ = name;
    center_ = center;
	radius_ = radius;
    material_ = material;
}

Sphere::~Sphere() { }


std::string Sphere::get_name() {
    return name_;
}

glm::vec3 Sphere::get_center() {
	return center_;
}

double Sphere::get_radius() {
	return radius_;
}

Material Sphere::get_material() {
    return material_;
}


void Sphere::set_name(std::string name) {
    name_ = name;
}

void Sphere::set_center(glm::vec3 center) {
	center_ = center;
}

void Sphere::set_radius(double radius) {
	radius_ = radius;
}

void Sphere::set_material(Material material) {
    material_ = material;
}


// intersect from Sascha

// // // // // // // // // // // // // // // // // // // // // // // // // // // // 

double Sphere::intersect(Ray ray) {

    // parameters of ray
    glm::vec3 p0 = ray.origin;
    glm::vec3 dir = ray.direction;

    // compute parameters for quadratic equation ax^2 + bx + c = 0
    double a = pow(dir.x, 2) + pow(dir.y, 2) + pow(dir.z, 2);
    double b = 2 * (dir.x * (p0.x - center_.x) + dir.y * (p0.y - center_.y) + dir.z * (p0.z - center_.z));
    double c = pow(p0.x - center_.x, 2) + pow(p0.y - center_.y, 2) + pow(p0.z - center_.z, 2) - pow(radius_, 2);

    // compute delta and handle cases
    double delta = pow(b, 2) - 4 * a * c;
    if (delta < 0) {

        // no intersection
        return -1;
    }
    else if (delta == 0) {

        // one intersection
        return (-1 * b) / (2 * a);
    }
    else {

        // two intersections
        double d1 = (-1 * b - sqrt(delta)) / (2 * a);
        double d2 = (-1 * b + sqrt(delta)) / (2 * a);
        return std::min(d1, d2);
    }
}

// // // // // // // // // // // // // // // // // // // // // // // // // // // //
