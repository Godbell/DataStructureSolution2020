template <class T>
class SequenceList
{

private:
    struct Node
    {
        T elem;
        Node* prev;
        Node* next;
    };

public:
    class Iterator
    {
    private:
        Node* node;
        Iterator(Node* n)
        {
            node = n;
        }
    public:
        int& operator*()
        {
            return node->elem;
        }

        bool operator==(const Iterator& p) const
        {
            return (node == p.elem);
        }
        bool operator!= (const Iterator& p) const
        {
            return !(node == p.elem);
        }
        SequenceList<T>::Iterator& operator++()
        {
            node = node->next;
            return *this;
        }
        SequenceList<T>::Iterator& operator--()
        {
            node = node->prev;
            return *this;
        }
        SequenceList<T>::Iterator& operator++(int a)
        {
            Iterator temp = *this;
            node = node->next;
            return temp;
        }
        SequenceList<T>::Iterator& operator--(int a)
        {
            Iterator temp = *this;
            node = node->prev;
            return temp;
        }

        friend class SequenceList<T>;
    };

//

private:
    int length;
    Node* header;
    Node* trailer;

public:
    typedef typename SequenceList<T>::Iterator t_Iterator;

    SequenceList()
    {
        length = 0;
        header = new Node;
        trailer = new Node;
        header->next = trailer;
        trailer->prev = header;
    }

    void insert(const typename SequenceList<T>::t_Iterator& p, const int& elem)
    {
        Node* pNode = p.node;
        Node* pPrev = pNode->prev;
        Node* pIns = new Node;

        pIns->elem = elem;

        pIns->next = pNode;
        pNode->prev = pIns;
        pIns->prev = pPrev;
        pPrev->next = pIns;
    }

    void insertFront(const int& elem)
    {
        insert(begin(), elem);
    }

    void insertBack(const int& elem)
    {
        insert(end(), elem);
    }

    void erase(const typename SequenceList<T>::t_Iterator& p)
    {
        Node* pErase = p.node;
        Node* pNext = pErase->next;
        Node* pPrev = pErase->prev;

        pPrev->next = pNext;
        pNext->prev = pPrev;
        delete pErase;
        this->length--;
    }

    void eraseFront()
    {
        erase(begin());
    }

    void eraseBack()
    {
        erase(--end());
    }

    int size() const
    {
        return length;
    }

    bool empty() const
    {
        return (length == 0);
    }

    typename SequenceList<T>::t_Iterator begin() const
    {
        return SequenceList<T>::Iterator(header->next);
    }

    typename SequenceList<T>::t_Iterator end() const
    {
        return SequenceList<T>::Iterator(trailer);
    }

    typename SequenceList<T>::t_Iterator atIndex(int index) const
    {
        SequenceList<T>::Iterator beginIter = begin();
        for (int i = 0 ; i < index ; i++)
        {
            ++beginIter;
        }
        return beginIter;
    }

    int indexOf(const typename SequenceList<T>::t_Iterator& p) const
    {
        typename SequenceList<T>::t_Iterator beginIter = begin();
        int i = 0;

        while (beginIter != p)
        {
            ++beginIter();
            ++i;
        }

        return i;
    }
};
#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;

    SequenceList<int> sl;
    typename SequenceList<int>::t_Iterator iter = sl.begin();

    for (int i = 0 ; i < T ; i++)
    {
        string command = "";
        cin >> command;

        if (command == "insert")
        {
            
        }

        else if (command == "erase")
        {
            
        }

        else if (command == "begin")
        {
            
        }

        else if (command == "end")
        {
            
        }

        else if (command == "++")
        {
            
        }

        else if (command == "--")
        {
            
        }

        else if (command == "print")
        {
            
        }

        else if (command == "size")
        {
            
        }
    }
}