#ifndef BOX_HPP
#define BOX_HPP
#include <iosfwd>
#include <color.hpp>
#include <glm/glm.hpp>
#include "Shape.hpp"

class Box : public Shape {
	public:
		Box();
		Box(std::string name, glm::vec3 p_min, glm::vec3 p_max, Material material);
		~Box();
	
		/* virtual */ std::string get_name();
		/* virtual */ Material get_material() const;
		/* virtual */ double intersect(Ray ray);
		/* virtual */ glm::vec3 getNormalAt(glm::vec3 point) const;
		glm::vec3 getPMin();
		glm::vec3 getPMax();
	
		void setName(std::string name);
		void setPMin(glm::vec3 p1);
		void setPMax(glm::vec3 p2);
		void setMaterial(Material material);
	
	private:
		std::string name_;
		glm::vec3 p_min_;
		glm::vec3 p_max_;
		Material material_;
};
#endif 