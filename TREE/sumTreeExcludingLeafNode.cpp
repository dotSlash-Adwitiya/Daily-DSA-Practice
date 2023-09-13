#include <iostream>
using namespace std;

// *Calculate and update every node with the sum of all nodes below it (Excluding its own)
class Node {
  public :
    Node* left;
    int data;
    Node* right;

    Node(int data) {
      left = NULL;
      this->data = data;
      right = NULL;
    }
};

//* Function to build a tree
Node *buildtree(Node *root)
{
	int data;
	cin >> data;
	root = new Node(data);
	
  if(data==-1)
		return NULL;
	
	cout << "\nEnter the data of Left child of : " << data << endl;
	root->left=buildtree(root->left);
	

	cout << "\nEnter the data of Right child of : " << data << endl;
	root->right=buildtree(root->right);
	
	return root;
}

//* Inorder Traversal
void inorder(Node* root) {
  if(root == NULL) return;

  inorder(root->left); 
  cout << root->data << " ";
  inorder(root->right); 
}

int calculateSum(Node* &root){

  //* if its a left node,
  //* Then we can be certain that there are no nodes, below this so return its data.
  if(root->left == NULL && root->right == NULL)
    return root->data;

  //* However, if the current node isn't a leaf node then,
  //* It can have 1 or 2 children so we need to check if either exists.

  //* Calculate sum of Left subtree
  int leftSum = 0;
  if(root->left)
    leftSum = calculateSum(root->left);

  //* Calculate sum of Right subtree
  int rightSum = 0;
  if(root->right)
    rightSum = calculateSum(root->right);

  //* Update the current node
  root->data = leftSum + rightSum;

  //* Return current node's data
  return root->data;
}

Node* updateSum(Node* root) {

  //* We make use of a helper function
  calculateSum(root);
  
  return root;
}


int main() {
  Node* root = NULL;
  cout << "Enter root Node's Data : ";
  Node* temp = buildtree(root);
  
  cout << "Before updating the Sum for every Node :" << endl;
  inorder(temp);

  updateSum(temp);

  cout << "\nAfter updating nodes with Sum of Left and Right Sub Tree :" << endl;

  inorder(temp);

  return 0;
}