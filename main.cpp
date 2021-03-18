#include "Node.h"
#include <fstream>

using namespace std;

void preorder(Node** nodes, Node *temp, int p, vector<pair<int, Node *>> depths[]) //nodes[0] int p = 1;
{
	depths[temp->depth].push_back(make_pair(p, temp));
	temp->value = p;
	if (temp->children.size() == 0)
	{
		return;
	}
	for (int i = 0; i < temp->children.size(); i++)
	{
		int a  = temp->children[i];
		preorder(nodes, nodes[a], ++p, depths);
	}
}

int findNthParent(int id, int n, Node *nodes[], vector<pair<int, Node *>> depths[])
{
	int find = nodes[id]->depth - n;
	if (find < 1)
	{
		return -1;
	}
	else
	{
		pair<int, Node *> smallerButBiggest;
		smallerButBiggest.first = 0;
		for (int i = 0; i < depths[find].size(); i++)
		{
			if (depths[find][i].first < nodes[id]->value && depths[find][i].first > smallerButBiggest.first)
			{
				smallerButBiggest = depths[find][i];
			}
		}
		return smallerButBiggest.second->id;
	}
}

int main(int argc, char const *argv[])
{
	string inputFile = "input.txt"; //argv[1];
	string outputFile = "output.txt"; //argv[2];

	ifstream infile;
	infile.open(inputFile);

	ofstream outfile;
	outfile.open(outputFile);

	int nOfNodes;
	infile >> nOfNodes;

	Node* nodes[nOfNodes];
	
	int parentId;
	infile >> parentId;
	nodes[0]  = new Node();
	nodes[0]->parentId = parentId;
	nodes[0]->depth = 0;
	nodes[0]->id = 0;
	int parent, maxDepth = 0;

	for (int i = 1; i < nOfNodes; i++)
	{
		nodes[i] = new Node();
		infile >> parent;
		nodes[i]->parentId = parent;
		nodes[i]->id = i;
		nodes[i]->depth = nodes[parent]->depth + 1;
		nodes[parent]->addChild(i);
		if (maxDepth < nodes[i]->depth)
		{
			maxDepth == nodes[i]->depth;
		}
	}
	vector<pair<int, Node *>> depths[maxDepth];
	preorder(nodes, nodes[0], 1, depths);

	int nOfQueries;
	infile >> nOfQueries;

	int idOfTheInd, n;
	for (int i = 0; i < nOfQueries; i++)
	{
		infile >> idOfTheInd;
		infile >> n;
		cout << "1234567" << endl;
		cout << findNthParent(idOfTheInd, n, nodes, depths)  << endl;
		
		outfile << findNthParent(idOfTheInd, n, nodes, depths)  << endl;
	}

	infile.close();
	outfile.close();
	return 0;
}