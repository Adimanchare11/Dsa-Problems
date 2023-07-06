#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;
    TreeNode(T data)
    {
        this->data = data;
    }
    ~TreeNode()
    {
        for(int i=0; i<children.size(); i++)
        {
            delete children[i];
        }
    }
};

//function for taking input levelwise
TreeNode<int> *takeInputLevelwise()
{
    int rootData;
    cout << "Enter data: " << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingnodes;

    pendingnodes.push(root);

    while (pendingnodes.size() != 0)
    {
        TreeNode<int> *front = pendingnodes.front();
        pendingnodes.pop();
        cout << "enter Number of childs of " << front->data << endl;
        int numchild;
        cin >> numchild;
        for (int i = 0; i < numchild; i++)
        {
            int childData;
            cout << "Enter " << i << "th "
                 << "child of " << front->data << ":";
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingnodes.push(child);
        }
    }
    return root;
}

//function to count number of nodes
int numNodes(TreeNode<int> *root)
{
    if(root==NULL) return 0;
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += numNodes(root->children[i]);
    }
    return ans;
}

//Function for printing Tree levelwise
void printlevelwise(TreeNode<int> *root)
{
    if (root == NULL)
        return;

    queue<TreeNode<int> *> q;
    q.push(root);

    while (q.size() != 0)
    {

        TreeNode<int> *front = q.front();
        q.pop();
        cout << front->data << ":";
        for (int i = 0; i < front->children.size(); i++)
        {
            if (i == 0)
            {
                cout << front->children[i]->data;
            }
            else
            {
                cout << "," << front->children[i]->data;
            }
            q.push(front->children[i]);
        }
        cout << endl;
    }
}

//function for taking input
TreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    cout << "Enter Nummber of childs of " << rootData << ":" << endl;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

//Funtion for printing sum of all nodes of a tree
int sumofNodes(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int ans = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += sumofNodes(root->children[i]);
    }
    return ans;
}

//function for printing node with with max data
TreeNode<int> *maxOfNodes(TreeNode<int> *root)
{
    if (root == NULL)
        return NULL;
    int max = root->data;
    TreeNode<int> *Node = root;
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *temp = maxOfNodes(root->children[i]);
        if (temp->data > max)
        {
            max = temp->data;
            Node = temp;
        }
    }
    return Node;
}

//Function for printing height of a tree
int getHeight(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int ans = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        int childheight = getHeight(root->children[i]);
        if (childheight > ans)
        {
            ans = childheight;
        }
    }
    return ans + 1;
}

//Function for printing a tree
void printTree(TreeNode<int> *root)
{
    if (root == NULL)
        return; // Edge Case

    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

//Function for printing tree levelwise
void printatlevelK(TreeNode<int> *root, int k)
{
    if (root == NULL)
        return;

    if (k == 0)
    {
        cout << root->data<<endl;
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        printatlevelK(root->children[i], k - 1);
    }
}

//Function for printing no. of leaf nodes
int getLeafNodeCount(TreeNode<int>* root)
{
    if(root==NULL) return 0;
    int count=0;
    if(root->children.size()==0) return 1;
    for(int i=0;i<root->children.size(); i++)
    {
         count+= getLeafNodeCount(root->children[i]);
    }
    return count;
}

//Funtion for printing preorder traversal of tree
void preorder(TreeNode<int>* root)
{
    if(root==NULL) return;
    cout<<root->data<<",";
    for(int i=0; i<root->children.size(); i++)
    {
        preorder(root->children[i]);
    }
}

//Function for printing postorder traversal of tree
void postorder(TreeNode<int>* root)
{
    if(root==NULL) return;
    for(int i=0; i<root->children.size(); i++)
    {
        postorder(root->children[i]);
    }
    cout<<root->data<<",";
}

//Function for Deleting created tree
void DeleteTree(TreeNode<int>* root)
{
    if(root==NULL) return;
    for(int i=0; i<root->children.size(); i++)
    {
        DeleteTree(root->children[i]);
    }
    delete root;
}

//Function for checking whether the node is present in the tree or not
bool ispresent(TreeNode<int>* root, int x)
{
    if(root==NULL) return false;
    for(int i=0; i<root->children.size(); i++)
    {
        bool value= ispresent(root->children[i],x);
        if(value== true)return true;
    }
    if(root->data==x) return true;
    else return false;
}

//Function for printing number of lager nodes than the entered value of x
int getLargeNodeCount(TreeNode<int>* root,int x)
{
    if(root==NULL) return 0;
    int count=0;
    for(int i=0; i<root->children.size(); i++)
    {
        count+=getLargeNodeCount(root->children[i],x);
    }
    if(root->data>x)
    return 1+count;
    return count;
}

/*1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0 */
int main()
{
    //     TreeNode<int>* root= new TreeNode<int>(1);
    //     TreeNode<int>* Node1= new TreeNode<int>(2);
    //     TreeNode<int>* Node2= new TreeNode<int>(3);

    //     root->children.push_back(Node1);
    //     root->children.push_back(Node2);
    TreeNode<int> *root = takeInputLevelwise();
    printlevelwise(root);
    cout << "Total Number of nodes:" << numNodes(root) << endl;
    cout << "Sum of nodes of tree is: " << sumofNodes(root) << endl;
    cout << "Max of nodes is: " << maxOfNodes(root) << endl;
    cout << "Height of tree is: " << getHeight(root)<<endl;
    
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;
    cout<<"Nodes at level "<<k<<" are: "<<endl;
    printatlevelK(root,k);
    cout<<endl;
    cout<<"No. of leaf nodes are: "<<getLeafNodeCount(root)<<endl;
    cout<<"Preorder Traversal: ";
    preorder(root);
    cout<<endl;
    cout<<"Postorder Traversal: ";
    postorder(root);
    cout<<endl;
    //DeleteTree(root);
    delete root;
}
