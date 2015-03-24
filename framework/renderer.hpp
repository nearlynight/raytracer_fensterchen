// -----------------------------------------------------------------------------
// Copyright  : (C) 2014 Andreas-C. Bernstein
// License    : MIT (see the file LICENSE)
// Maintainer : Andreas-C. Bernstein <andreas.bernstein@uni-weimar.de>
// Stability  : experimental
//
// Renderer
// -----------------------------------------------------------------------------

#ifndef BUW_RENDERER_HPP
#define BUW_RENDERER_HPP

#include "color.hpp"
#include "pixel.hpp"
#include "ppmwriter.hpp"
#include "SdfLoader.hpp"

#include <string>
#include <glm/glm.hpp>


class Renderer
{
public:
  Renderer(unsigned w, unsigned h, std::string const& file, SdfLoader const& sdfloader);

  void render();
  void write(Pixel const& p);
  void test();

  inline std::vector<Color> const& colorbuffer() const
  {
    return colorbuffer_;
  }

private:
  unsigned width_;
  unsigned height_;
  std::vector<Color> colorbuffer_;
  std::string filename_;
  PpmWriter ppm_;
  SdfLoader sdfloader_;

  Camera camera_;
  std::vector<Shape*> shapes_;
};

#endif // #ifndef BUW_RENDERER_HPP
