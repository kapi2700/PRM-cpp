#include "obstacle.hh"

class cirObstacle
{
    float posX;
    float posY;
    float radius;
public:
    cirObstacle(float x, float y, float r);
    bool checkCollision(float x, float y);
};