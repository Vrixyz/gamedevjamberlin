//
// Hotdog.hpp for  in /home/berger_t//gameDevBerlin
// 
// Made by thierry berger
// Login   <berger_t@epitech.net>
// 
// Started on  Thu Aug 23 05:38:19 2012 thierry berger
// Last update Thu Aug 23 10:16:54 2012 thierry berger
//

#ifndef HOTDOG_HPP
# define HOTDOG_HPP

#include <iostream>

#include <Box2D/Box2D.h>

#include "GameObject.hpp"

class	Hotdog : public GameObject
{
public:
  Hotdog(b2World& w, const float32& pos_x = 0, const float32& pos_y = 11, const float32& size = 2, bool isStatic = true, const std::string& name = "hotdog");
  void	accelerate(float32);
  void	update();
private:
  float32 acceleration;
};

#endif
