#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <glm/glm.hpp>
#include "Ray.hpp"

class Sphere {
	public:
		Sphere();
		Sphere(glm::vec3 center, double radius);
		~Sphere();

		glm::vec3 get_center();
		double get_radius();

		void set_center(glm::vec3);
		void set_radius(double);

		bool intersect(Ray ray);
	private:
		glm::vec3 center_;
		double radius_;


};


#endif