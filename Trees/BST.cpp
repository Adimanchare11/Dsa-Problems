#include <iostream>
#include <queue>
#include<vector>
using namespace std;

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};

BinaryTreeNode<int> *takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

bool searchInBST(BinaryTreeNode<int>* root, int k)
{
    if(root==NULL) return false;


    if(k<root->data)
    {
       bool val= searchInBST(root->left,k);
       if(val==true) return true;
    }
    if(k>root->data)
    {
        bool val=searchInBST(root->right,k);
        if(val==true) return true;
    }

    if(root->data==k) return true;
    else return false;
}

int minimum(BinaryTreeNode<int>* root)
{
    if(root==NULL) return INT_MAX;

    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

int maximum(BinaryTreeNode<int>* root)
{
    if(root==NULL) return INT_MIN;

    return max(root->data, max(maximum(root->left),maximum(root->right)));
}
bool isBST(BinaryTreeNode<int> *root) {
	if(root==NULL) return true;

    int rightmin= minimum(root->right);
    int leftmax= maximum(root->left);
    bool output= (isBST(root->left) && isBST(root->right) && (root->data>leftmax) && (root->data<rightmin));
    return output;
}

void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
	if(root==NULL) return;


	if(root->data<k1 && root->data<k2)
	{
		elementsInRangeK1K2(root->right, k1, k2);
	}
	if(k1<root->data && root->data>k2)
	{
		elementsInRangeK1K2(root->left, k1, k2);
	}
	if(k1<=root->data && root->data<=k2)
	{
          elementsInRangeK1K2(root->left, k1, k2);
          cout << root->data << " ";
          elementsInRangeK1K2(root->right, k1, k2);
    }
}

//Constructing BST from a sorted array

BinaryTreeNode<int>* constructTreeHelper(int *input, int si, int ei)
{
    if(si>ei) return NULL;

    int mid=(si+ei)/2;
    BinaryTreeNode<int>* root= new BinaryTreeNode<int> (input[mid]);
    root->left= constructTreeHelper(input, si, mid-1);
    root->right= constructTreeHelper(input, mid+1, ei);
    return root;
}

BinaryTreeNode<int>* constructTree(int *input, int n)
{
    constructTreeHelper(input,0,n-1);
}

vector<int>* getPath(BinaryTreeNode<int> *root , int data) {
	// Write your code here
	if(root==NULL) return NULL;

if(root->data==data){
	vector<int>* v= new vector<int>();
	v->push_back(root->data);
	return v;
}

else if(root->data>data)
{
vector<int>* leftoutput= getPath(root->left, data);
   if(leftoutput!=NULL)
	 leftoutput->push_back(root->data);
    return leftoutput;
}

else if(root->data<data)
{
vector<int>* rightoutput= getPath(root->right, data);
if(rightoutput!=NULL)
    rightoutput->push_back(root->data);
    return rightoutput;
}
}

//**************BST CLASS***************************************

class BST
{
    BinaryTreeNode<int>* root;

    public:

    BST()
    {
        root==NULL;
    }

    private:
    BinaryTreeNode<int>* Insert(int data, BinaryTreeNode<int>* node)
    {
        if(root==NULL)
        {
            BinaryTreeNode<int>* newnode= new BinaryTreeNode<int>(data);
            return newnode;
        }

        if(data<node->data)
        {
            node->left= Insert(data, node->left);
        }

        else 
        {
            node->right= Insert(data, node->right);
        }
        return node;

    }

    public:
    void Insert(int data)
    {
        this->root= Insert(data,this->root);

    }

    private:
    BinaryTreeNode<int>* Deletedata(int data, BinaryTreeNode<int>* node)
    {
        if(root==NULL) return NULL;

        if(data<node->data)
        {
            node->left=Deletedata(data, node->left);
            return node;
        }

        else if(data>node->data)
        {
            node->right= Deletedata(data,node->right);
            return node;
        }

        else{

            if(node->left==NULL  && node->right==NULL)
            {
                delete node;
                return NULL;
            } 
            else if(node->left==NULL)
            {
                BinaryTreeNode<int>* temp= node->right;
                node->right=NULL;
                delete node;
                return temp;
            }
            else if(node->right==NULL)
            {
                BinaryTreeNode<int>* temp= node->left;
                node->left=NULL;
                delete node;
                return temp;
            }
            else{

                BinaryTreeNode<int>* minNode= node->right;

                while(minNode!=NULL)
                {
                    minNode= minNode->left;
                }
                int rightMin= minNode->data;
                node->data= rightMin;
                node->right=Deletedata(data, node->right);
                return node;
            }

        }
    }

    public:
    void Delete(int data)
    {
        
    }

    private:
    bool hasData(int data, BinaryTreeNode<int>* node)
    {
        if(node== NULL) return false;

        if(node->data==data)
        {
            return true;
        }
        else if(node->data>data)
        {
            return hasData(data,root->left);
        }
        else
        return hasData(data,root->right);
    }

    public:
    bool hasData(int data)
    {
        return hasData(data,root);
    }

};



int main() {
    BinaryTreeNode<int> *root = takeInput();
    cout<<"BST:"<<((isBST(root))? "true" : "false");
    int k;
    cout<<endl;
    cout<<"Enter Value: ";
    cin >> k;
    cout << ((searchInBST(root, k)) ? "true" : "false");
    delete root;
}