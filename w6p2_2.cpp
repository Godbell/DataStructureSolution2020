#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node
{
public:
    int value;
    int depth;
    Node* parent;
    vector<Node*> children;

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
    vector<Node*> tree;
    int maxdepth;

    TREE()
    {
      tree.push_back(new Node(1, 0));
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
     
    void printChilds(int node)
    {
        Node* toprint = findNodeLinear(node);

        if (toprint == NULL || toprint->children.size() == 0)
            cout << 0 << endl;
        else
        for (Node* child : toprint->children)
        {
            cout << child->value << " ";
        }
        cout << endl;
    }

    void printSiblings(int node)
    {
        Node* danode = findNodeLinear(node);

        if (danode == NULL)
        {
            cout << 0 << endl;
            return;
        }

        Node* parent = danode->parent;
        if (parent == NULL || parent->children.size() <= 1)
        {
            cout << danode->value << endl;
        }
        else
        {
            for (Node* child : parent->children)
            {
                cout << child->value << " ";
            }
            cout << endl;
        }
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


int main()
{
    int N = 0;
    int M = 0;
    cin >> N >> M;
    TREE tree;

    for (int iter = 0 ; iter < N ; iter++)
    {
        int parent = 0;
        int child = 0;

        cin >> parent >> child;
        tree.insrt(parent, child);
    }

    for (int iter = 0 ; iter < M ; iter++)
    {
        int depth;
        cin >> depth;
        
        if (tree.maxdepth < depth)
        {
            cout << 0 << endl;
            continue;
        }

        int max = -1;
        for (Node* node : tree.tree)
        {
            if (max == -1 && node->depth == depth)
            {
                max = node->value;
            }
            else if (node->depth == depth && max < node->value)
            {
                max = node->value;
            }

        }

        cout << max << endl;
    }

    return 0;
}