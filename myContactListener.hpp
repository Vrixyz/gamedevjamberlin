//
// myContactListener.hpp for  in /home/berger_t//gameDevBerlin
// 
// Made by thierry berger
// Login   <berger_t@epitech.net>
// 
// Started on  Thu Aug 23 09:43:15 2012 thierry berger
// Last update Thu Aug 23 09:43:48 2012 thierry berger
//

#ifndef MY_CONTACT_LISTENER
# define MY_CONTACT_LISTENER

#include <iostream>

class MyContactListener : public b2ContactListener
{
  void BeginContact(b2Contact* contact) {
  
    //check if fixture A was a ball
    void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
    if ( bodyUserData )
      static_cast<Ball*>( bodyUserData )->startContact();
  
    //check if fixture B was a ball
    bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
    if ( bodyUserData )
      static_cast<Ball*>( bodyUserData )->startContact();
  
  }
  
  void EndContact(b2Contact* contact) {
  
    //check if fixture A was a ball
    void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
    if ( bodyUserData )
      static_cast<Ball*>( bodyUserData )->endContact();
  
    //check if fixture B was a ball
    bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
    if ( bodyUserData )
      static_cast<Ball*>( bodyUserData )->endContact();
  
  }
};

#endif
