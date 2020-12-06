#include "TreeNode.h"
TreeNode::TreeNode(int data)
{
	m_data = data;
	m_left = nullptr;
	m_right = nullptr;
}
bool TreeNode::isLeaf()
{
	return (m_left == nullptr && m_right == nullptr);
}
int TreeNode::getData()
{
	return m_data;
}
TreeNode* TreeNode::getLeft()
{
	return m_left;
}
TreeNode* TreeNode::getRight()
{
	return m_right;
}
int TreeNode::countNodes()
{
	int count = 1;
	if (m_left)
		count += m_left->countNodes();
	if (m_right)
		count += m_right->countNodes();
	return count;
}
int TreeNode::getHeight()
{
	int h1 = m_left ? m_left->getHeight() : 0;
	int h2 = m_right ? m_right->getHeight() : 0;
	return max(h1, h2) + 1;
}
TreeNode* TreeNode::findKeyRecursion(int key)
{
	if (m_data < key)
		return m_right ? m_right->findKeyRecursion(key) : nullptr;
	if (m_data > key)
		return m_left ? m_left->findKeyRecursion(key) : nullptr;
	return this;
}
TreeNode* TreeNode::findKeyIterator(int key)
{
	TreeNode* node = this;
	while (node)
	{
		if (node->m_data == key)
			return node;
		else if (node->m_data < key)
			node = node->m_right;
		else if (node->m_data > key)
			node = node->m_left;
	}
	return node;
}
void TreeNode::addKeyRecursion(int key)
{
	if (key < m_data)
	{
		if (m_left)
			m_left->addKeyRecursion(key);
		else
		{
			m_left = new TreeNode(key);
			return;
		}
	}
	else
	{
		if (m_right)
			m_right->addKeyRecursion(key);
		else
		{
			m_right = new TreeNode(key);
			return;
		}
	}
}
void TreeNode::addKeyInterator(int key)
{
	TreeNode* node = this;
	while (true)
	{
		if (key < node->m_data)
		{
			if (node->m_left)
				node = node->m_left;
			else
			{
				node->m_left = new TreeNode(key);
				return;
			}
		}
		else
		{
			if (node->m_right)
				node = node->m_right;
			else
			{
				node->m_right = new TreeNode(key);
				return;
			}
		}
	}
}
void TreeNode::printTree()
{
	TreeNode* node = this;
	if (node != nullptr)
	{
		node->m_left->printTree();
		cout << node->m_data << " ";
		node->m_right->printTree();
	}
}
TreeNode* TreeNode::minValue()
{
	TreeNode* current = this;
	while (current && current->m_left != nullptr)
		current = current->m_left;
	return current;
}
TreeNode* TreeNode::deleteNode(int key)
{
	TreeNode* root = this;
	if (!root)
		return root;
	if (key < root->m_data)
		root->m_left = root->m_left->deleteNode(key);
	else if (key > root->m_data)
		root->m_right = root->m_right->deleteNode(key);
	else
	{
		if (!root->m_left)
		{
			TreeNode* temp = root->m_right;
			delete root;
			return temp;
		}
		else if (!root->m_right)
		{
			TreeNode* temp = root->m_left;
			delete root;
			return temp;
		}
		TreeNode* temp = root->m_right->minValue();
		root->m_data = temp->m_data;
		root->m_right = root->m_right->deleteNode(temp->m_data);
	}
	return root;
}