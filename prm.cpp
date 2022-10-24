#include <iostream>

#include "nodes.hh"

// int PRM()
// {
    
//     return 0;
// }


int main()
{
    int nodesAmount;
    float nodeDist;
    float x,y;

    std::cout<<"How many nodes to generate: ";
    std::cin>>nodesAmount;
    std::cout<<"Min distance of nodes to connect: ";
    std::cin>>nodeDist;
    std::cout<< "Max X: ";
    std::cin>> x;
    std::cout<< "Max Y: ";
    std::cin>> y;
    nodes Nodes(x,y);
    Nodes.generateNodes(nodesAmount,nodeDist);

    std::cout<< "Created " << Nodes.connections<< " connections.";

    return 0;
}