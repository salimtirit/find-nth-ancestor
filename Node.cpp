#include "Node.h"

Node::Node()
{
}

void Node::addChild(int id){
    children.push_back(id);
}

Node::~Node()
{
}