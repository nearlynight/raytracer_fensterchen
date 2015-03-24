// -----------------------------------------------------------------------------
// Copyright  : (C) 2014 Andreas-C. Bernstein
// License    : MIT (see the file LICENSE)
// Maintainer : Andreas-C. Bernstein <andreas.bernstein@uni-weimar.de>
// Stability  : experimental
//
// Renderer
// -----------------------------------------------------------------------------

#include <math.h>
#include "renderer.hpp"

#define _USE_MATH_DEFINES

Renderer::Renderer(unsigned w, unsigned h, std::string const& file, SdfLoader const& sdfloader)
  : width_(w)
  , height_(h)
  , colorbuffer_(w*h, Color(0.0, 0.0, 0.0))
  , filename_(file)
  , ppm_(width_, height_)
  , sdfloader_(sdfloader)
{}

void Renderer::render() {

  // test Ausgabe
  camera_ = sdfloader_.getCamera();
  shapes_ = sdfloader_.getShapes();
  test();

  // Abstand Camera - Bildflaeche
  double cam_z = tan((90 - camera_.opening_angle / 2) * M_PI / 180) * (width_/2);
  // std::cout << "Camera_Z value: " << cam_z << std::endl;
  // double cam_z = 100;
  camera_.position = glm::vec3(0,0,cam_z);
  // camera_.direction = glm::vec3(0,0,-1);


  // const std::size_t checkersize = 20;


  Ray prim_ray;
  for (unsigned y = 0; y < height_; ++y) {
    for (unsigned x = 0; x < width_; ++x) {
      Pixel p(x,y);

      // parallel projection
      // prim_ray.origin = glm::vec3(x,y,0);
      // prim_ray.direction =  glm::vec3(0,0,-1);

      // perspective projection
      glm::vec3 pointOnImagePlane = glm::vec3((double)x - width_/2 ,(double)y - height_/2 ,0);
      prim_ray.origin = camera_.position;
      prim_ray.direction = pointOnImagePlane - camera_.position;

      p.color = Color(0.0,0.0,0.0);
      for(int i = 0; i < shapes_.size(); ++i) {
        double d = shapes_[i]->intersect(prim_ray);
        if(d != -1) {
          p.color = shapes_[i]->get_material().get_ka();
        }
      }

      /*
      if ( ((x/checkersize)%2) != ((y/checkersize)%2)) {
        p.color = Color(0.0, 1.0, float(x)/height_);
      } else {
        p.color = Color(1.0, 0.0, float(y)/width_);
      }
      */

      write(p);
    }
  }
  ppm_.save(filename_);
}

void Renderer::write(Pixel const& p)
{
  // flip pixels, because of opengl glDrawPixels
  size_t buf_pos = (width_*p.y + p.x);
  if (buf_pos >= colorbuffer_.size() || (int)buf_pos < 0) {
    std::cerr << "Fatal Error Renderer::write(Pixel p) : "
      << "pixel out of ppm_ : "
      << (int)p.x << "," << (int)p.y
      << std::endl;
  } else {
    colorbuffer_[buf_pos] = p.color;
  }

  ppm_.write(p);
}

void Renderer::test(){
  for (int i = 0; i < shapes_.size(); ++i) {
      std::cout << shapes_[i]->get_name() << std::endl;
    }
  std::cout << "Camera: " << camera_.name << std::endl;

  std::vector<Material*> material = sdfloader_.getMaterials(); 
  for (int i = 0; i < material.size(); ++i) {
      std::cout <<  *material[i] << std::endl;
    }
}