//
// World.hpp for  in /home/berger_t//gameDevBerlin
// 
// Made by thierry berger
// Login   <berger_t@epitech.net>
// 
// Started on  Thu Aug 23 04:53:13 2012 thierry berger
// Last update Mon Sep  3 13:13:48 2012 thierry berger
//

#ifndef WORLD_HPP
# define WORLD_HPP

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include "Vegetable.hpp"
#include "Hotdog.hpp"
#include "TimeCounter.hpp"

#define W_WIDTH 1600
#define W_HEIGHT 800

class	World
{
public:
  ~World();
  World();
  void	init();
  bool	isRunning();
  void	stop();
  void	update();
  void	drawAll();

  Hotdog* hotdog;
  Vegetable* tomato;
  b2World	_w;
  sf::RenderWindow app;

private:
  sf::Shape	transformsForView(const Vegetable&);
  sf::Shape	transformsForView(const Hotdog&);
 
  TimeCounter	timer;
  b2ContactListener contactListener;
  float32 timeStep;
  int32 velocityIterations;
  int32 positionIterations;
};

#endif
