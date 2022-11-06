#include <iostream>

#include "nodes.hh"

// int PRM()
// {
    
//     return 0;
// }


int main()
{
    int obsType;
    int nodesAmount;
    float nodeDist;
    float x,y;
    bool endLoop=false;

    std::cout<<"How many nodes to generate: ";
    std::cin>>nodesAmount;
    std::cout<<"Min distance of nodes to connect: ";
    std::cin>>nodeDist;
    std::cout<< "Max X: ";
    std::cin>> x;
    std::cout<< "Max Y: ";
    std::cin>> y;

    nodes Nodes(x,y);

    while(true)
    {
        if(endLoop)
            break;
        std::cout<<"0-no more obstacles, 1-rectangle obstacle, 2-circle obstacle: ";
        std::cin>>obsType;

        switch (obsType)
        {
        case 0:
            endLoop=true;
            break;
        case 1:
            float recX, recY;
            float recL, recH;
            std::cout<<"Bottom left corner X: ";
            std::cin>> recX;
            std::cout<<"Bottom left corner Y: ";
            std::cin>>recY;
            std::cout<<"Length: ";
            std::cin>>recL;
            std::cout<<"Height: ";
            std::cin>>recH;
            recObstacle* tmprecObs;
            tmprecObs=new recObstacle(recX,recY,recL,recH);
            Nodes.W->obstacles.push_back((obstacle*)tmprecObs);
        case 2:
            float cirX, cirY, cirR;
            std::cout<<"Circle X: ";
            std::cin>> cirX;
            std::cout<<"Circle Y: ";
            std::cin>>cirY;
            std::cout<<"Circle radius: ";
            std::cin>>cirR;
            cirObstacle* tmpcirObs;
            tmpcirObs=new cirObstacle(cirX, cirY, cirR);
            Nodes.W->obstacles.push_back((obstacle*)tmpcirObs);
        default:
            std::cout<<"Wrong number!\n";
            break;
        }

    }
    // for(int i=0; i<10; i++)
    // {
        //std::cout<<i+1<<" iteration\n";
        Nodes.generateNodes(nodesAmount,nodeDist);
        std::cout<< "Created " << Nodes.connections<< " connections.\n";
    //}
    return 0;
}