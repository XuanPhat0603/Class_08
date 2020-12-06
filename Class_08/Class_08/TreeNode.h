#pragma once
#include<iostream>
using namespace std;
class TreeNode
{
private:
	int m_data;
	TreeNode* m_left;
	TreeNode* m_right;
public:
	TreeNode(int);
	int getData();
	TreeNode* getLeft();
	TreeNode* getRight();
	bool isLeaf();
	int countNodes();
	int getHeight();
	TreeNode* findKeyRecursion(int);
	TreeNode* findKeyIterator(int);
	void addKeyRecursion(int);
	void addKeyInterator(int);
	void printTree();
	TreeNode* minValue();
	TreeNode* deleteNode(int);
};

