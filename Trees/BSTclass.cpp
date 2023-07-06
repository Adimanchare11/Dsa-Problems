#include <iostream>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

class BST
{
   BinaryTreeNode<int> *root;

    BinaryTreeNode<int> *Insert(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            BinaryTreeNode<int> *newnode = new BinaryTreeNode<int>(data);
            return newnode;
        }

        if (data <= node->data)
        {
            node->left = Insert(data, node->left);
        }

        else
        {
            node->right = Insert(data, node->right);
        }
        return node;
    }

    BinaryTreeNode<int> *Deletedata(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
            return NULL;

        if (data < node->data)
        {
            node->left = Deletedata(data, node->left);
            return node;
        }

        else if (data > node->data)
        {
            node->right = Deletedata(data, node->right);
            return node;
        }

        else
        {

            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                return NULL;
            }
            else if (node->left == NULL)
            {
                BinaryTreeNode<int> *temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }
            else if (node->right == NULL)
            {
                BinaryTreeNode<int> *temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }
            else
            {

                BinaryTreeNode<int> *minNode = node->right;

                while (minNode != NULL)
                {
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                node->data = rightMin;
                node->right = Deletedata(rightMin, node->right);
                return node;
            }
        }
    }

    bool hasData(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
            return false;

        if (node->data == data)
        {
            return true;
        }
        else if (node->data > data)
        {
            return hasData(data, root->left);
        }
        else
            return hasData(data, root->right);
    }

    void printBinaryTree(BinaryTreeNode<int> *root)
    {
        if (root == NULL)
            return;

        cout << root->data << " : ";
        if (root->left != NULL)
        {
            cout << "L:" << root->left->data << ", ";
        }
        if (root->right != NULL)
        {
            cout << "R:" << root->right->data;
        }
        cout << endl;
        printBinaryTree(root->left);
        printBinaryTree(root->right);
    }

public:

    
    BST()
    {
        root == NULL;
    }

    ~BST()
    {
        delete root;
    }

    void Insert(int data)
    {
        this->root = Insert(data, this->root);
    }

    void Delete(int data)
    {
        root = Deletedata(data, root);
    }

    void printBST()
    {
        printBinaryTree(root);
    }
    bool hasData(int data)
    {
        return hasData(data, root);
    }

};

int main()
{
    BST B;
    B.Insert(10);
    B.Insert(20);
    B.Insert(5);
    B.Insert(7);
    B.printBST();
    return 0;
}