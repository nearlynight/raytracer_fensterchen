#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <glm/glm.hpp>
//#include "Material.hpp"
#include "Shape.hpp"

class Sphere : public Shape {
	public:
		Sphere();
		Sphere(std::string name, glm::vec3 center, double radius, Material material);
		~Sphere();

		/* virtual */ std::string get_name();
		/* virtual */ Material get_material() const;
		/* virtual */ double intersect(Ray ray);
		/* virtual */ glm::vec3 getNormalAt(glm::vec3 intersection_point) const;

		glm::vec3 get_center();
		double get_radius();
		

		void set_name(std::string);
		void set_center(glm::vec3);
		void set_radius(double);
		void set_material(Material);

		
	private:
		std::string name_;
		glm::vec3 center_;
		double radius_;
		Material material_;


};


#endif