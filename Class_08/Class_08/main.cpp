#include "TreeNode.h"
int main()
{
	TreeNode* root = new TreeNode(3); // init
	root->addKeyInterator(0); // add key by interator
	root->addKeyInterator(1);
	root->addKeyInterator(2);
	root->addKeyRecursion(4); // add key by recursion
	root->addKeyRecursion(5);
	root->addKeyRecursion(6);
	root->printTree(); // print data

	if (root->isLeaf()) // Check ? leaf : not leaf
		cout << "\n\nLeaf !";
	else cout << "\n\nNot leaf !!";

	if (root->getRight()->getRight()->getRight()->isLeaf()) // Check ? leaf : not leaf
		cout << "\n\nLeaf !";
	else cout << "\n\nNot leaf !!";

	cout << "\n\nHeight : " << root->getHeight(); // Height binary search tree

	if (root->findKeyRecursion(6))// Find key by recurison
		cout << "\n\n" << root->findKeyRecursion(2)->getData();
	else cout << "\n\nNot Found !!";

	if (root->findKeyIterator(-1)) // Find key by iterator
		cout << "\n\n" << root->findKeyIterator(2)->getData();
	else cout << "\n\nNot Found !!";

	cout << "\n\nDelete 0:\n"; // delete node
	root = root->deleteNode(0);
	root->printTree();

	cout << "\n\nDelete 1:\n";
	root = root->deleteNode( 1);
	root->printTree();

	cout << "\n\nDelete 3:\n";
	root = root->deleteNode( 3);
	root->printTree();

	cout << "\n\nDelete 5:\n";
	root = root->deleteNode( 5);
	root->printTree();

	cout << "\n\nDelete -3:\n";
	root = root->deleteNode(-3);
	root->printTree();
	return 0;
}