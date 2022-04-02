#include <vector>
#include "circle.h"

#ifndef _LEVEL_
#define _LEVEL_
using namespace std;

class Level
{
public:
  void create();
  vector<DrawableComponent*>* getDrawableComponents(); 

private:  
  vector<DrawableComponent*>* components;
};

#endif // _LEVEL_
