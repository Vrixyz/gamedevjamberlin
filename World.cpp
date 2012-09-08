//
// World.cpp for  in /home/berger_t//gameDevBerlin
// 
// Made by thierry berger
// Login   <berger_t@epitech.net>
// 
// Started on  Thu Aug 23 04:59:47 2012 thierry berger
// Last update Sat Sep  8 19:04:34 2012 thierry berger
//

#include "World.hpp"

World::~World()
{
  app.close();
}

World::World() : _w(b2Vec2(0,-0.02)), app(sf::VideoMode(W_WIDTH, W_HEIGHT), "Food Defense")
{
  timeStep = 1.0f / 60.0f;
  velocityIterations = 6;
  positionIterations = 2;
  //  _w.SetContactListener();
}

#include <iostream>
#include <ctime>

void	World::init()
{
  tomato = new Vegetable(_w);
  hotdog = new Hotdog(_w);
  hotdog->setPosition(-1, -(W_HEIGHT / 2) / 30 + 2);
  timer.reset();
}

void	World::update()
{
  sf::Event event;
  float32	elapsedTime = timer.getElapsedTime();

  std::cout << elapsedTime << std::endl;

  while (app.pollEvent(event))
    {
      if (event.type == sf::Event::Closed ||
	  ((event.type == sf::Event::KeyPressed) &&
	   (event.key.code == sf::Keyboard::Escape)))
	stop();
      if (event.type == sf::Event::JoystickMoved)
	{
	  std::cout << event.joystickMove.joystickId << " " << 
	    event.joystickMove.axis << " " << event.joystickMove.position << std::endl;
	  if (event.joystickMove.axis == sf::Joystick::X)
	    {
	      hotdog->accelerate(event.joystickMove.position);
	    }
	}
    }
  if (elapsedTime > (1 / 60) * 1000000)
    {
      hotdog->update();
      b2Vec2 position = hotdog->getPosition();
      if (position.x > W_WIDTH / 2 / 30)
	{
	  hotdog->setPosition(W_WIDTH / 2 / 30, position.y);
	  hotdog->stop();
	}
      else if (position.x < (- (W_WIDTH / 2 / 30) + 2))
	{
	  hotdog->setPosition(- (W_WIDTH / 2 / 30) + 2, position.y);
	  hotdog->stop();
	}
      else if (position.y < (- (W_HEIGHT / 2 / 30) + 2))
	{
	  hotdog->setPosition(position.x, -(W_HEIGHT / 2) / 30 + 2);
	  // hotdog->stop();
	}
      _w.Step(timeStep, velocityIterations, positionIterations);
      b2Vec2 positionT = tomato->getPosition();
      if (positionT.y < (- (W_HEIGHT / 2 / 30) - 2))
	{
	  tomato->setPosition(position.x, (W_HEIGHT / 2) / 30 + 2);
	  tomato->stop();
	}
      else if (positionT.x < (- (W_WIDTH / 2 / 30) - 2))
	{
	  tomato->setPosition(W_WIDTH / 2 / 30 + 2, positionT.y);
	  // tomato->stop();
	}
      else if (positionT.x > ((W_WIDTH / 2 / 30) + 2))
	{
	  tomato->setPosition(- W_WIDTH / 2 / 30 + 2, positionT.y);
	  // tomato->stop();
	}
      positionT = tomato->getPosition();
      timer.reset();
    }
}

void	World::drawAll()
{

  app.clear();
  app.draw(transformsForView(*tomato));
  app.draw(transformsForView(*hotdog));
  app.display();
}

bool	World::isRunning()
{
  return app.isOpen();
}

void	World::stop()
{
  return app.close();
}

sf::RectangleShape	World::transformsForView(const Vegetable& v)
{
  sf::RectangleShape shape(sf::Vector2f(60, 60));
  const b2Vec2& position = v.getPosition();
  float32 angle = v.getAngle();

  shape.setOrigin(sf::Vector2f(30, 30));
  shape.setFillColor(sf::Color::Red);
  shape.setPosition(position.x * 30 + W_WIDTH / 2 - 30, - position.y * 30 + W_HEIGHT / 2 - 30);
  shape.setRotation(angle);
  return shape;
}

sf::RectangleShape	World::transformsForView(const Hotdog& h)
{
  sf::RectangleShape shape(sf::Vector2f(60, 60));
  const b2Vec2& position = h.getPosition();
  float32 angle = h.getAngle();

  shape.setOrigin(sf::Vector2f(30, 30));
  shape.setFillColor(sf::Color::Yellow);
  shape.setPosition(position.x * 30 + W_WIDTH / 2 - 30, - position.y * 30 + W_HEIGHT / 2 - 30);
  shape.setRotation(angle * 57.295779513082);
  return shape;
}
