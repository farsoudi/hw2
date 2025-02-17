#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <algorithm>
#include <set>

template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{
  typename std::set<T>::iterator it1 = s1.begin(); 
  std::set<T> res;
  while (it1 != s1.end()) 
  {
    if (s2.find(*it1) != s2.end())
    {
      res.insert(*it1);
    }
    it1++;
  }
  return res; 
}

template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{
  std::set<T> res;
  typename std::set<T>::iterator it1 = s1.begin(); 
  while (it1 != s1.end()) 
  {
    res.insert(*it1);
    ++it1;
  }
  typename std::set<T>::iterator it2 = s2.begin(); 
  while (it2 != s2.end()) 
  {
    res.insert(*it2); 
    ++it2;
  }
  return res;
}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif
