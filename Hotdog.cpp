//
// Hotdog.cpp for  in /home/berger_t//gameDevBerlin
// 
// Made by thierry berger
// Login   <berger_t@epitech.net>
// 
// Started on  Thu Aug 23 05:56:57 2012 thierry berger
// Last update Thu Aug 23 14:56:48 2012 thierry berger
//

#include "Hotdog.hpp"

Hotdog::Hotdog(b2World& w, const float32& pos_x, const float32& pos_y, const float32& size, bool isStatic, const std::string&) : GameObject(w, pos_x, pos_y, size, isStatic)
{
  acceleration = 0;
}

#include <iostream>

void	Hotdog::update()
{

}

void	Hotdog::accelerate(float32 acc)
{
  if (acc > 1)
    _phBody->SetLinearVelocity(b2Vec2(1, 0));
  else if (acc < -1)
    _phBody->SetLinearVelocity(b2Vec2(-1, 0));
  else
    _phBody->SetLinearVelocity(b2Vec2(0, 0));
}
