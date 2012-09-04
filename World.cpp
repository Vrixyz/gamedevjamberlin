//
// World.cpp for  in /home/berger_t//gameDevBerlin
// 
// Made by thierry berger
// Login   <berger_t@epitech.net>
// 
// Started on  Thu Aug 23 04:59:47 2012 thierry berger
// Last update Tue Sep  4 16:57:40 2012 thierry berger
//

#include "World.hpp"

World::~World()
{
  app.Close();
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

  while (app.GetEvent(event))
    {
      if (event.Type == sf::Event::Closed ||
	  ((event.Type == sf::Event::KeyPressed) &&
	   (event.Key.Code == sf::Key::Escape)))
	stop();
      if (event.Type == sf::Event::JoyMoved)
	{
	  std::cout << event.JoyMove.JoystickId << " " << 
	    event.JoyMove.Axis << " " << event.JoyMove.Position << std::endl;
	  if (event.JoyMove.Axis == sf::Joy::AxisX)
	    {
	      hotdog->accelerate(event.JoyMove.Position);
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

  app.Clear();
  app.Draw(transformsForView(*tomato));
  app.Draw(transformsForView(*hotdog));
  app.Display();
}

bool	World::isRunning()
{
  return app.IsOpened();
}

void	World::stop()
{
  return app.Close();
}

sf::Shape	World::transformsForView(const Vegetable& v)
{
  sf::Shape shape = sf::Shape::Rectangle(-30, -30, 30, 30, sf::Color::Red);
  const b2Vec2& position = v.getPosition();
  float32 angle = v.getAngle();
  shape.SetPosition(position.x * 30 + W_WIDTH / 2 - 30, - position.y * 30 + W_HEIGHT / 2 - 30);
  shape.SetRotation(angle);
  return shape;
}

sf::Shape	World::transformsForView(const Hotdog& h)
{
  sf::Shape shape = sf::Shape::Rectangle(-30, -30, 30, 30, sf::Color::Yellow);
  const b2Vec2& position = h.getPosition();
  float32 angle = h.getAngle();

  shape.SetPosition(position.x * 30 + W_WIDTH / 2 - 30, - position.y * 30 + W_HEIGHT / 2 - 30);
  shape.SetRotation(angle * 57.295779513082);
  return shape;
}
