//
// Main.cpp for  in /home/berger_t//gameDevBerlin
// 
// Made by thierry berger
// Login   <berger_t@epitech.net>
// 
// Started on  Wed Aug 22 16:59:27 2012 thierry berger
// Last update Thu Aug 23 08:20:36 2012 thierry berger
//


#include <iostream>

#include <Box2D/Box2D.h>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "World.hpp"
#include "Vegetable.hpp"
#include "Hotdog.hpp"


int	main(int ac, char **av)
{
  b2Vec2 g(0,-10);
  b2World w(g);

  Vegetable tomato(w, -70, 100);

  World world;
  world.init();
  while (world.isRunning())
    {
      world.update();
      world.drawAll();
    }
  
  return 0;
}
