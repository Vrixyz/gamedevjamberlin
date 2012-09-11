//
// TimeCounter.hpp for  in /home/berger_t//plazza-2015-moros_a
// 
// Made by thierry berger
// Login   <berger_t@epitech.net>
// 
// Started on  Fri Apr 13 23:00:06 2012 thierry berger
// Last update Tue Sep  4 16:57:50 2012 thierry berger
//

#ifndef TIME_COUNTER_HPP
# define TIME_COUNTER_HPP

#include <stdio.h>
#include <time.h>
#include <sys/time.h>

class	TimeCounter
{
public:
  TimeCounter()
  {
    this->reset();
  }
  void	reset()
  {
    gettimeofday(&m_time, 0);
  }
  int32	getElapsedTime() // in second
  {
    struct timeval	now;

    gettimeofday(&now, 0);
    return ((now.tv_sec * 1000000 + now.tv_usec) - (m_time.tv_sec * 1000000 + m_time.tv_usec));
  }
private:
  struct timeval	m_time;
};

#endif
