//
// Vegetable.cpp for  in /home/berger_t//gameDevBerlin
// 
// Made by thierry berger
// Login   <berger_t@epitech.net>
// 
// Started on  Thu Aug 23 04:02:03 2012 thierry berger
// Last update Thu Aug 23 09:37:50 2012 thierry berger
//

#include "Vegetable.hpp"
#include <iostream>

Vegetable::Vegetable(b2World& w, const float32& pos_x, const float32& pos_y, const float32& size, const std::string& name) : GameObject(w, pos_x, pos_y, size)
{
  
}
