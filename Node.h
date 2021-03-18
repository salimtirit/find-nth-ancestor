#include <iostream>
#include <vector>

using namespace std;

#ifndef Node_H
#define Node_H

class Node
{
public:
    Node();
    int id = 0;
    int value;
    int parentId = 0;
    int depth;
    vector<int> children;
    void addChild(int id);
    ~Node();
};

#endif