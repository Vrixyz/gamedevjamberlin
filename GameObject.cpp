//
// GameObject.cpp for  in /home/berger_t//gameDevBerlin
// 
// Made by thierry berger
// Login   <berger_t@epitech.net>
// 
// Started on  Thu Aug 23 05:43:47 2012 thierry berger
// Last update Thu Aug 23 14:48:35 2012 thierry berger
//

#include "GameObject.hpp"

GameObject::GameObject(b2World& w, const float32& pos_x, const float32& pos_y, const float32& size, bool isStatic, const std::string& name)
{
  b2BodyDef bDynDef;
  int	density = 1;
  int	restitution = 1;

  this->_size = size;

  bDynDef.type = // isStatic ? b2_staticBody : 
    b2_dynamicBody;
  bDynDef.position.Set(pos_x, pos_y);
  bDynDef.userData = new std::string(name);
  if (isStatic)
    {
      bDynDef.gravityScale = 0;
      density = 3;
      restitution = 0;
    }
  _phBody = w.CreateBody(&bDynDef);
  b2PolygonShape vegShape;
  vegShape.SetAsBox(1, 1);
  b2FixtureDef	fDef;
  fDef.shape = &vegShape;
  fDef.density = density;
  fDef.friction = 0.3;
  fDef.restitution = restitution;
  _phBody->CreateFixture(&fDef);
}

const b2Vec2&	GameObject::getPosition() const
{
  return _phBody->GetPosition();
}

float32	GameObject::getAngle() const
{
  return _phBody->GetAngle();
}

float32 GameObject::getSize() const
{
  return _size;
}

void	GameObject::setPosition(float32 x, float32 y)
{
  _phBody->SetTransform(b2Vec2(x, y), _phBody->GetAngle());
}

void	GameObject::stop()
{
  _phBody->SetLinearVelocity(b2Vec2(0, 0));
}
