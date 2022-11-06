#include "world.hh"
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <iostream>

struct node
{
    float pos[2];
    std::vector<node*> connectedNodes;
    int connections=0;
public:
    node()
    {
        pos[0] = 0.0;
        pos[1] = 0.0;
    }
    node(float x, float y)
    {
        pos[0] = x;
        pos[1] = y;
    }

    float calcdistance(node n)
    {
        float X,Y;

        X=pos[0]-n.pos[0];
        Y=pos[1]-n.pos[1];

        float distSq=X*X+Y*Y;
        return sqrt(distSq);
    }
};

class nodes
{
    std::vector<node> N;
public:
    world *W;
    int connections=0;

    void generateNodes(int amount, float R); // amount ilość nodeów do generacji, R- odległość łącząca node'y

    bool nodeColissionCheck(node checkedNode);
    int connectNode(node &connectedNode, float R);
    
    nodes(float X, float Y)
    {
        W = new world(X, Y);
    }

    ~nodes()
    {
        delete W;
    }
    
    
};