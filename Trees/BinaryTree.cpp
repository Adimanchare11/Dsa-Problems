#include <iostream>
#include <queue>
#include <climits>
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

void printBinaryTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;

    cout << root->data << " : ";
    if (root->left != NULL)
    {
        cout << "L" << root->left->data << ", ";
    }
    if (root->right != NULL)
    {
        cout << "R" << root->right->data;
    }
    cout << endl;
    printBinaryTree(root->left);
    printBinaryTree(root->right);
}



BinaryTreeNode<int> *takeinputLevelwise()
{
    int rootdata;
    cout << "Enter data" << endl;
    cin >> rootdata;
    if (rootdata == -1)
        return NULL;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootdata);

    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        cout << "Enter left child of " << front->data << endl;
        int leftchild;
        cin >> leftchild;
        if (leftchild != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftchild);
            front->left = child;
            pendingNodes.push(child);
        }

        cout << "Enter right child of " << front->data << endl;
        int rightchild;
        cin >> rightchild;
        if (rightchild != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightchild);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

void printlevelwise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":";
        if (front->left != NULL)
        {
            cout << "L" << front->left->data;
            pendingNodes.push(front->left);
        }
        else
            cout << "L:-1";
        cout << ",";

        if (front->right != NULL)
        {
            cout << "R" << front->right->data;
            pendingNodes.push(front->right);
        }
        else
            cout << "R:-1";
        cout << endl;
    }
}

void printLevelByLevel(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    queue<BinaryTreeNode<int> *> pendingnodes;
    pendingnodes.push(root);

    while (pendingnodes.size() != 0)
    {
        int n = pendingnodes.size();
        while (n != 0)
        {

            BinaryTreeNode<int> *front = pendingnodes.front();
            pendingnodes.pop();
            cout << front->data << " ";

            if (front->left != NULL)
            {
                pendingnodes.push(front->left);
            }
            if (front->right != NULL)
            {
                pendingnodes.push(front->right);
            }
            n--;
        }
        cout << endl;
    }
}

int NumNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    return 1 + NumNodes(root->left) + NumNodes(root->right);
}

bool isPresent(BinaryTreeNode<int> *root, int x)
{
    if (root == NULL)
        return false;

    if (root->left != NULL)
    {
        bool value = isPresent(root->left, x);
        if (value == true)
            return true;
    }
    if (root->right != NULL)
    {
        bool value = isPresent(root->right, x);
        if (value == true)
            return true;
    }
    if (root->data == x)
        return true;
    else
        return false;
}

//Function for printing pair sum
int k=0;
void convert(BinaryTreeNode<int>* root, int* arr)
{
    if(root==NULL) return ;

    arr[k++]= root->data;
    convert(root->left,arr);
    convert(root->right, arr);
}

void pairsum(BinaryTreeNode<int>* root, int sum)
{
    int arr[1000000];

    convert(root, arr);
    sort(arr, arr+k);

    int i=0;
    int j=k-1;

    while(i<j)
    {
        if(arr[i]+ arr[j]== sum)
        {
            cout<<arr[i]<<" "<<arr[j]<<endl;
            i++;
            j--;
        }
        else if(arr[i]+ arr[j]< sum)
        {
            j--;
        }
        else if(arr[i]+ arr[j]> sum)
        {
            i++;
        }
    }

}

int heightOfTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    return 1 + max(heightOfTree(root->left), heightOfTree(root->right));
}

bool isBalanced(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
        return true;

    if ((heightOfTree(root->left) - heightOfTree(root->right)) > 1)
        return false;
    else
        return true;
    bool val1 = isBalanced(root->left);
    bool val2 = isBalanced(root->right);
    if (val1 && val2 == true)
        return true;
}

int diameter(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    int option1 = heightOfTree(root->left) + heightOfTree(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);

    return max(option1, max(option2, option3));
}

pair<int, int> heightdiameter(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    pair<int, int> leftans = heightdiameter(root->left);
    pair<int, int> rightans = heightdiameter(root->right);
    int lh = leftans.first;
    int ld = leftans.second;
    int rh = rightans.first;
    int rd = rightans.second;

    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));
    pair<int, int> p;
    p.first = height;
    p.second = diameter;
    return p;
}

pair<int, int> minmax(BinaryTreeNode<int> *root)
{
    // int maxNode= max(root->data,max(root->left->data,root->right->data));
    // int minNode= min(root->data,min(root->left->data,root->right->data));
    // minmax(root->left);
    // minmax(root->right);

    // pair<int,int> p;
    // p.first=minNode;
    // p.second=maxNode;
    // return p;

    //     pair<int,int> ret;
    //     ret.first=0;
    //     ret.second=0;
    // if(root==NULL)
    // {
    //     return ret;
    // }
    pair<int, int> ret = make_pair(INT_MIN, INT_MAX);
    if (root == NULL)
        return ret;

    pair<int, int> leftpair = minmax(root->left);
    pair<int, int> rightpair = minmax(root->right);

    ret.first = min(min(leftpair.first, rightpair.first), root->data);
    ret.second = max(max(leftpair.second, rightpair.second), root->data);
    return ret;
}

void mirrorBinaryTree(BinaryTreeNode<int> *root)
{

    if (root == NULL)
        return;

    BinaryTreeNode<int> *child = root->left;
    root->left = root->right;
    root->right = child;

    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
    // if(root->left!=NULL)
    // {
    // 	root->left->data=root->right->data;
    // 	mirrorBinaryTree(root->left);
    // }
    // if(root->right!=NULL)
    // {
    // 	root->right->data=root->left->data;
    // 	mirrorBinaryTree(root->right);
    // }
}

int getsum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int ans = root->data;
    int leftsum = getsum(root->left);
    int rightsum = getsum(root->right);
    return ans + leftsum + rightsum;
}

BinaryTreeNode<int> *removeLeafNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return NULL;

    if (root->left != NULL)
    {
        root->left = removeLeafNodes(root->left);
    }

    if (root->right != NULL)
    {
        root->right = removeLeafNodes(root->right);
    }

    return root;
}

void printNodesWithoutSibling(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
        return;

    if (root->left == NULL && root->right != NULL)
    {
        cout << root->right->data << " ";
    }
    if (root->right == NULL && root->left != NULL)
    {
        cout << root->left->data << " ";
    }
    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);
}

void inorder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << ",";
    inorder(root->right);
}

void preorder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;

    cout << root->data << ",";
    preorder(root->left);
    preorder(root->right);
}

void postorder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << ",";
}

BinaryTreeNode<int> *takeinput()
{
    int rootdata;
    cout << "Enter data: ";
    cin >> rootdata;

    if (rootdata == -1)
        return NULL;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootdata);
    BinaryTreeNode<int> *leftchild = takeinput();
    BinaryTreeNode<int> *rightchild = takeinput();
    root->left = leftchild;
    root->right = rightchild;
    return root;
}

void insertDuplicateNode(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;

    if (root->left != NULL)
    {
        BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(root->data);
        BinaryTreeNode<int> *save = root->left;
        root->left = newNode;
        newNode->left = save;
    }
    else
    {
        BinaryTreeNode<int> *Duplicate= new BinaryTreeNode<int>(root->data);
        root->left=Duplicate;
    }
    insertDuplicateNode(root->left->left);
    insertDuplicateNode(root->right);
}

int getLCA(BinaryTreeNode <int>* root , int a, int b) {
    // Write your code here
	if(root==NULL) return  -1;

	if(root->data==a or root->data==b)
	{
		return root->data;
	}

	int leftLCA = getLCA(root->left, a, b);
	int rightLCA = getLCA(root->right,a,b);

    if(leftLCA==-1 && rightLCA!=-1)
    {
        return rightLCA;
    }
    else if(rightLCA==-1 && leftLCA!=-1)
    {
        return leftLCA;
    }
    else if(rightLCA==-1 && leftLCA==-1)
    {
        return -1;
    }
    else return root->data;

}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main()
{
    // BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    // BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);
    // root->left = node1;
    // root->right = node2;

    BinaryTreeNode<int> *root = takeinputLevelwise();
    printlevelwise(root);
    cout << "Number of Nodes: " << NumNodes(root) << endl;

    // int x;
    // cout << "Enter Data to check: ";
    // cin >> x;
    // cout << (isPresent(root, x)) ? "True" : "false";
    // cout<<endl;

    // cout<<"Height of Tree: "<<heightOfTree(root)<<endl;
    // cout<<"Diameter of Tree: "<<diameter(root)<<endl;

    // mirrorBinaryTree(root);
    // printlevelwise(root);
    // cout<<endl;

    pair<int, int> p = heightdiameter(root);
    cout << "Height: " << p.first << endl;
    cout << "Diameter: " << p.second << endl;

    pair<int, int> pr = minmax(root);
    cout << "MinNode: " << pr.first << endl;
    cout << "MaxNode: " << pr.second << endl;

    cout << "Sum of Nodes: " << getsum(root) << endl;

    cout << "Balanced: " << (isBalanced(root) ? "True" : "False");
    cout << endl;

    cout << "Inorder Traversal:";
    inorder(root);
    cout << endl;

    cout << "Preorder Traversal:";
    preorder(root);
    cout << endl;

    cout << "Postorder Traversal:";
    postorder(root);
    cout << endl;

    cout << "Nodes Without sibling: ";
    printNodesWithoutSibling(root);
    cout << endl;

    int sum;
    cout<<"Enter the sum: ";
    cin>>sum;
    pairsum(root,sum);
    cout<<endl;

    int a,b;
    cout<<"Enter the nodes: ";
    cin>>a,b;
    cout<<"Least common ancestor of the nodes is: "<<getLCA(root,a,b)<<endl;

    insertDuplicateNode(root);

    // removeLeafNodes(root);
    cout << "********************LEVEL BY LEVEL TRAVERSAL **************************" << endl;
    printLevelByLevel(root);

    delete root;

    return 0;
}