#ifndef SHAPE_HPP
#define SHAPE_HPP

//#include "color.hpp"
#include "Material.hpp"
#include "Ray.hpp"

class Shape {
	public:
		Shape();

		virtual std::string get_name() {return " "; }
		virtual double intersect(Ray ray) {return 0.0; }
		virtual Material get_material() const {return Material(); }
		virtual glm::vec3 getNormalAt(glm::vec3) const {return glm::vec3(); }
};

#endif