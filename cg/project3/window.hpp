#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <random>

#include "abcgOpenGL.hpp"
#include "model.hpp"
#include "ground.hpp"

class Window : public abcg::OpenGLWindow
{
protected:
  void onEvent(SDL_Event const &event) override;
  void onCreate() override;

  void onPaint() override;
  void onPaintUI() override;
  void onResize(glm::ivec2 const &size) override;

  void onUpdate() override;
  void onDestroy() override;

private:
  std::default_random_engine m_randomEngine;

  glm::ivec2 m_viewportSize{};

  Model m_model_block;

  Model m_model_car;

  struct Car
  {
    glm::vec3 m_position{};
    float m_angle;
    glm::vec3 m_rotationAxis{};
  };

  Car m_car;
   
  float m_speed{0.0f};
  float m_angleRot{};
  
  glm::mat4 m_viewMatrix{1.0f};
  glm::mat4 m_projMatrix{1.0f};
  float m_FOV{30.0f};

  struct Block
  {
    glm::vec3 m_position{};
    float m_angle;
    glm::vec3 m_rotationAxis{};
  };

  Block m_block;


  Ground m_ground;

  GLuint m_carProgram{};
  GLuint m_blockProgram{};
  //GLuint m_groundProgram{};

  void setupCar(Car &m_car);
  void setupBlock(Block &m_block);
  void randomizeBlock(Block &m_block);
};

#endif
