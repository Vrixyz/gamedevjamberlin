//
// GameObject.hpp for  in /home/berger_t//gameDevBerlin
// 
// Made by thierry berger
// Login   <berger_t@epitech.net>
// 
// Started on  Thu Aug 23 05:40:31 2012 thierry berger
// Last update Tue Sep  4 19:22:03 2012 thierry berger
//

#ifndef GAMEOBJECT_HPP
# define GAMEOBJECT_HPP

#include <iostream>

#include <Box2D/Box2D.h>

class	GameObject
{
public:
  const b2Vec2& getPosition() const;
  float32	getAngle() const;
  const b2Vec2& getExtentsVector() const;
  void	setPosition(float32, float32);
  void	stop();

protected:
  GameObject(b2World& w, const float32& pos_x, const float32& pos_y, const float32& size, bool isStatic = false, const std::string& name = "object");
  float32 getSize() const;
  b2Body* _phBody;
  float32 _size;
};

#endif
