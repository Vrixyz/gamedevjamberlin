//
// Hotdog.cpp for  in /home/berger_t//gameDevBerlin
// 
// Made by thierry berger
// Login   <berger_t@epitech.net>
// 
// Started on  Thu Aug 23 05:56:57 2012 thierry berger
// Last update Tue Sep  4 17:09:47 2012 thierry berger
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
  int movement = acc > 0 ? 1 : (acc == 0 ? 0 : -1);

  _phBody->SetLinearVelocity(b2Vec2((acc + 2 * movement) / 2, 0));
}
