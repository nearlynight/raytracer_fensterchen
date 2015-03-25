#ifndef PLANE_HPP
#define PLANE_HPP

#include "Shape.hpp"


class Plane : public Shape {
	public:
		Plane();
		Plane(std::string name, glm::vec3 normal, double d, Material material);
		~Plane();

		/* virtual */ std::string get_name();
		/* virtual */ Material get_material() const;
		/* virtual */ glm::vec3 getNormalAt(glm::vec3 point) const;
		double getD();
		/* virtual */ double intersect(Ray ray);

		void setName(std::string name);
		void setD(double d);
		void setMaterial(Material material);

	private:
		std::string name_;
		glm::vec3 normal_;
		double d_;
		Material material_;
};

#endif