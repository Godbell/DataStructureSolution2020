#include <iostream>
#include <vector>
class Node
{
public:
    int value;
    int depth;
    Node* parent;
    std::vector<Node*> children;

    Node(int v = 0, int d = 0)
    {
        depth = d;
        value = v;
    }

    void setParent(Node* node)
    {
        parent = node;
        depth = parent->depth + 1;
    }

    void addChild(Node* node)
    {
        children.push_back(node);
        children.back()->setParent(this);
    }

    void delchild(Node* node)
    {
        for (int i = 0 ; i < children.size() ; i++)
        {
            if (children[i] == node)
            {
                children.erase(children.begin() + i);
            }
        }
    }
};


class TREE
{
public:
    Node* root;
    std::vector<Node*> tree;
    int maxdepth;

    TREE(int rootData)
    {
      tree.push_back(new Node(rootData, 0));
      root = tree.front();
      maxdepth = 0;
    }

    void insrt(int node, int value)
    {
        Node* parentNode = findNodeLinear(node);

        if (parentNode == NULL) return;

        tree.push_back(new Node(value));
        parentNode->addChild(tree.back());

        updateMaxDepth();
    }

    void delte(int value)
    {
        Node* erased = findNodeLinear(value);

        if (erased == NULL) return;

        if (erased == root) return;
        else
        {
            for (Node*& node : erased->children)
            {
                node->setParent(erased->parent);
                erased->parent->addChild(node);
            }
            erased->children.clear();
            erased->parent->delchild(erased);
            delete erased;
        }
        
        updateMaxDepth();
    }

    Node* findNodeLinear(int val)
    {
        for (Node*& node : tree)
        {
            if (node->value == val)
            {
                return node;
            }
        }
        
        return NULL;
    }

    int updateMaxDepth()
    {
        int _md = 0;

        for (Node* node : tree)
        {
            if (node->depth > _md)
            {
                _md = node->depth;
            }
        }

        maxdepth = _md;
        return maxdepth;
    }

};