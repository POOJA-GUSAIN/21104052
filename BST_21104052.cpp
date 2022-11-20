#include<bits/stdc++.h>
using namespace std;

class TNode
{
	public:
	int data;
	TNode* left;
	TNode* right;
};

TNode* newNode(int data)
{
	TNode* node = new TNode();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
    return node;
}

// A function to construct Balanced Binary Search Tree from a sorted array 
TNode* sortedArrayToBST(int arr[],
						int start, int end)
{
	if (start > end)
	return NULL;

	int mid = (start + end)/2;
	TNode *root = newNode(arr[mid]);

	root->left = sortedArrayToBST(arr, start,
									mid - 1);
	root->right = sortedArrayToBST(arr, mid + 1, end);

	return root;
}

// A function to print inorder traversal of BST 
void INOrder(TNode* node)
{
	if (node != NULL){
	INOrder(node->left);
	cout << node->data << " ";
	
	INOrder(node->right);
    }
}

// A function to delete an element from array
void DeleteFromArray(int n,int arr[],int key){
    int index= -1;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == key)
        {
            index = i;
            break;
        }
    }

    if(index != -1)
    {
        //shift all the element from index+1 by one position to the left
        for(int i = index; i < n - 1; i++)
            arr[i] = arr[i+1];
    
    for(int j=0;j<n-1;j++){
        cout<<arr[j];}
    cout<<endl;
    cout<<"element deleted from array successfully "<<endl;
    }
}

TNode *minValueNode(TNode *node) {
  TNode *current = node;

  // Find the leftmost leaf
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

//A function to delete from BST
TNode* deleteNodefromTREE(TNode *root, int key) {
  if (root == NULL) return root;

  if (key < root->data)
    root->left = deleteNodefromTREE(root->left, key);
  else if (key > root->data)
    root->right = deleteNodefromTREE(root->right, key);
  else {
    // If the node is with only one child or no child
    if (root->left == NULL) {
      TNode *temp = root->right;
      free(root);
      return temp;
    } 
    else if (root->right == NULL) {
      TNode *temp = root->left;
      free(root);
      return temp;
    }
   // If the node has two children
    TNode *temp = minValueNode(root->right);

    // Place the inorder successor in position of the node to be deleted
    root->data = temp->data;

    // Delete the inorder successor
    root->right = deleteNodefromTREE(root->right, temp->data);
  }
  return root;
}


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    TNode *root = sortedArrayToBST(arr, 0, n-1);
	cout << "INOrder Traversal of constructed BST"<<endl;
	INOrder(root);
    cout<<endl;
    cout<<"enter element to be deleted ";
    int x;  //element to be deleted
    cin>>x;

    DeleteFromArray(n,arr,x);
    cout<<endl;

    deleteNodefromTREE(root,x);
    cout<<"INOrder after deletion from BST"<<endl;
    INOrder(root);
    
    return 0;

}

//space complexity of deleting from an array is O(n);
//space complexity of deletiong using BST is also O(n);
//both array and BST have same space complexity.
