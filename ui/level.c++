#include "level.h"

void Level::create()
{
  Circle* cell0=new Circle(60, 35, 60);
  Circle* cell1=new Circle(125, 70, 85);

  components = new vector<DrawableComponent*>();
  components -> push_back(cell0);
  components -> push_back(cell1);  
}

vector<DrawableComponent*>* Level::getDrawableComponents()
{
  return components;
}
