//
// Vegetable.hpp for  in /home/berger_t//gameDevBerlin
// 
// Made by thierry berger
// Login   <berger_t@epitech.net>
// 
// Started on  Thu Aug 23 03:49:33 2012 thierry berger
// Last update Thu Aug 23 09:38:06 2012 thierry berger
//

#ifndef VEGETABLES_HPP
# define VEGETABLES_HPP

#include <iostream>

#include <Box2D/Box2D.h>
#include "GameObject.hpp"


class	Vegetable : public GameObject
{
public:
  Vegetable(b2World& w, const float32& pos_x = 0, const float32& pos_y = 0, const float32& size = 1, const std::string& name = "object");
};

#endif
