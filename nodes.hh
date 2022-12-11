#pragma once
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
    bool wasChecked=false;
    bool isTheRoute=false;
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
    
    void toFile()
    {
        ofstream save;
        save.open("out.txt");
        for(int i=0; i<N.size();i++)
        {
            save<<N[i].pos[0]<<"   "<<N[i].pos[1]<<endl;
            save<<endl<<endl;
            // for(int j=N[i].connectedNodes.size()-1; j>=0;j--)
            // {
            //     if(N[i].connectedNodes[j]->pos[0]>W->maxGridX+2)
            //     {
            //         N[i].connectedNodes.erase(N[i].connectedNodes.begin()+j);
            //     }
            //     else
            //     {
            //         if(N[i].connectedNodes[j]->pos[1]>W->maxGridY+2)
            //         {
            //             N[i].connectedNodes.erase(N[i].connectedNodes.begin()+j);
            //         }
            //         else
            //         {
            //         save<<N[i].pos[0]<<"   "<<N[i].pos[1]<<endl;
            //         save<<N[i].connectedNodes[j]->pos[0]<<"   "<<N[i].connectedNodes[j]->pos[1]<<endl<<endl;
            //         }
            //     }

            // }
        }
    }
};