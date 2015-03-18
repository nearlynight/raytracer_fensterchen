#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "color.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class Material {
	public:
		Material();
		Material(std::string name, Color ka, Color kd, Color ks, float m);
		~Material();

		std::string get_name();
		Color get_ka();
		Color get_kd();
		Color get_ks();
		float get_m();

	private:
		std::string name_;
		// ambiente
		Color ka_;
		// diffuse
		Color kd_;
		// spiegelnde Reflexion
		Color ks_;
		// Exponent für spiegelnde Reflexion
		float m_;
};

std::ostream& operator<<(std::ostream& os, Material& m);

#endif