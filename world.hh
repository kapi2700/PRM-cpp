#include <vector>
#include "recObstacle.hh"
#include "cirObstacle.hh"

class world
{
public:
    float maxGridX;
    float maxGridY;
    std::vector<obstacle*> obstacles;

public:
    world(float X, float Y)
    {
        maxGridX=X;
        maxGridY=Y;
    }
};