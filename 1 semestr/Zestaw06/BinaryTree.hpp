#ifndef BINARYTREE
#define BINARYTREE
#include <iostream>

class BinaryTree
{
private:
    struct Node
    {
        Node *left = nullptr;
        Node *right = nullptr;
        int val;
    };

    Node *root = nullptr;
    int Tsize = 0;
    int Tdepth = 0;

    Node *toolSR(int x, Node *start_node);
    void toolInorder(Node *start_node);
    void toolPreorder(Node *start_node);
    void toolPostorder(Node *start_node);

public:
    void insert(int x);
    Node *search(int x);
    Node *searchRecursive(int x);
    int size();
    int minimum();
    int maximum();
    int depth();
    void inorder();
    void preorder();
    void postorder();
};

void BinaryTree::insert(int x)
{
    if (root == nullptr)
    {
        root = new Node();
        root->val = x;
        Tdepth++;
        Tsize++;

        return;
    }

    Node *temp = root;
    int currentDepth = 1;
    while (true)
    {
        currentDepth++;
        if (x < temp->val)
        {
            if (temp->left == nullptr)
            {
                temp->left = new Node();
                temp->left->val = x;
                Tsize++;
                if (currentDepth > Tdepth)
                {
                    Tdepth = currentDepth;
                }
                break;
            }
            temp = temp->left;
        }
        else
        {
            if (temp->right == nullptr)
            {
                temp->right = new Node();
                temp->right->val = x;
                Tsize++;
                if (currentDepth > Tdepth)
                {
                    Tdepth = currentDepth;
                }
                break;
            }
            temp = temp->right;
        }
    }
}

BinaryTree::Node *BinaryTree::search(int x)
{
    Node *temp = root;
    while (temp != nullptr)
    {
        if (temp->val == x)
        {
            return temp;
        }
        else
        {
            if (x < temp->val)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
    }

    return nullptr;
}

BinaryTree::Node *BinaryTree::toolSR(int x, Node *start_node)
{
    if (start_node == nullptr)
    {
        return nullptr;
    }
    if (start_node->val == x)
    {
        return start_node;
    }
    else if (x < start_node->val)
    {
        return toolSR(x, start_node->left);
    }
    else
    {
        return toolSR(x, start_node->right);
    }
}

BinaryTree::Node *BinaryTree::searchRecursive(int x)
{
    return toolSR(x, root);
}

int BinaryTree::size()
{
    return Tsize;
}

int BinaryTree::minimum()
{
    Node *temp = root;
    while(temp->left != nullptr)
    {
        temp = temp->left;
    }
    return temp->val;
}

int BinaryTree::maximum()
{
    Node *temp = root;
    while(temp->right != nullptr)
    {
        temp = temp->right;
    }
    return temp->val;
}

int BinaryTree::depth()
{
    return Tdepth;
}

void BinaryTree::toolInorder(Node *start_node)
{
    if (start_node != nullptr)
    {
        toolInorder(start_node->left);
        std::cout << start_node->val << std::endl;
        toolInorder(start_node->right);
    }
}

void BinaryTree::inorder()
{
    toolInorder(root);
}

void BinaryTree::toolPreorder(Node *start_node)
{
    if (start_node != nullptr)
    {
        std::cout << start_node->val << std::endl;
        toolPreorder(start_node->left);
        toolPreorder(start_node->right);
    }
}

void BinaryTree::preorder()
{
    toolPreorder(root);
}

void BinaryTree::toolPostorder(Node *start_node)
{
    if (start_node != nullptr)
    {
        toolPostorder(start_node->left);
        toolPostorder(start_node->right);
        std::cout << start_node->val << std::endl;
    }
}

void BinaryTree::postorder()
{
    toolPostorder(root);
}

#endif // BINARYTREE