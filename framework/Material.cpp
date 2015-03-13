#include "Material.hpp"

Material::Material() {
	name_ = " ";
	ka_ = Color(0,0,0);
	kd_ = Color(0,0,0);
	ks_ = Color(0,0,0);
	m_ = 0;
}

Material::Material(std::string name, Color ka, Color kd, Color ks, float m) {
	name_ = name;
	ka_ = ka;
	kd_ = kd;
	ks_ = ks;
	m_ = m;
}

Material::~Material() {
}

std::string Material::get_name() {
	return name_;
}

Color Material::get_ka() {
	return ka_;
}

Color Material::get_kd() {
	return kd_;
}

Color Material::get_ks() {
	return ks_;
}

float Material::get_m() {
	return m_;
}