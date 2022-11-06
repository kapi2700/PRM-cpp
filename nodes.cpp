#include "nodes.hh"

void nodes::generateNodes(int amount, float R)
{
    srand(time(NULL));
    node tmpNode;
    float randomNumber;
    while(N.size()<amount)
    {
        float x=0.0;
        float y=0.0;

        randomNumber=rand();
        x=(int)randomNumber%((int)W->maxGridX*10);
        randomNumber=rand();
        y=(int)randomNumber%((int)W->maxGridY*10);

        tmpNode=node(x,y);

        if(nodeColissionCheck(tmpNode))
        {
            N.push_back(tmpNode);
            connectNode(N.back(),R);
        }
    }
}

int nodes::connectNode(node &connectedNode,float R)
{
    for(int i=0; i<(N.size()-1); i++)
    {
        if(connectedNode.calcdistance(N[i])<R)
        {
            connectedNode.connections++;
            connectedNode.connectedNodes.push_back(&(N[i]));
            N[i].connections++;
            N[i].connectedNodes.push_back(&connectedNode);

            connections++;
        }
    }
    //std::cout<<"Connected to " <<N[N.size()-1].connections << " nodes.\n";
}


bool nodes::nodeColissionCheck(node checkedNode)
{
    for(int i=0; i<W->obstacles.size();i++)
    {
        if(!(W->obstacles[i]->checkCollision(checkedNode.pos[0],checkedNode.pos[1])));
            return false;
    }
    return true;
}