#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <random>

#include "abcgOpenGL.hpp"
#include "model.hpp"
#include "ground.hpp"

class Window : public abcg::OpenGLWindow {
protected:
  void onEvent(SDL_Event const &event) override;
  void onCreate() override;
  void onUpdate() override;
  void onPaint() override;
  void onPaintUI() override;
  void onResize(glm::ivec2 const &size) override;
  void onDestroy() override;

private:
  std::default_random_engine m_randomEngine;

  glm::ivec2 m_viewportSize{};

  Model m_model;

  struct Star {
    glm::vec3 m_position{};
    /* glm::vec3 m_rotationAxis{}; */
  };

  std::array<Star, 1> m_stars;

  /* float m_angle{}; */
   
  float m_speed{0.0f};
  
  glm::mat4 m_viewMatrix{1.0f};
  glm::mat4 m_projMatrix{1.0f};
  float m_FOV{30.0f};

  Ground m_ground;

  GLuint m_program{};

  void randomizeStar(Star &star);
};

#endif