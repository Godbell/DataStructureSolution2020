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

    void preorder(Node* node)
    {
        if (!node) return;

        std::cout << node->value << " ";
        for (int i = 0 ; i < node->children.size(); i++)
        {
            preorder(node->children[i]);
        }
    }
    
    void preorder()
    {
        preorder(root);
    }
    
    void postorder(Node* node)
    {
        if (!node) return;
        
        for (int i = 0 ; i < node->children.size(); i++)
        {
            preorder(node->children[i]);
        }

        std::cout << node->value << " ";
    }

    void postorder()
    {
        postorder(root);
    }
};

using namespace std;

int main()
{
    int T = 0;
    cin >> T;

    for (int iter1 = 0 ; iter1 < T ; iter1++)
    {
        int N = 0;
        cin >> N;
        TREE tree(1);

        for (int i = 0 ; i < N ; i++)
        {
            int pnode, value;
            cin >> pnode >> value;

            tree.insrt(pnode, value);
        }

        tree.preorder();
        cout << endl;
    }

    return 0;
}