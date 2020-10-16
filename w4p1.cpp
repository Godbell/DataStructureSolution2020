#include <iostream>

using namespace std;

template <class T>
class ListNode
{
public:
    ListNode<T>* cursor;
    T value;
    ListNode(T data)
    {
        value = data;
        cursor = NULL;
    }
};

template <class T>
class LinkedList
{
public:
    ListNode<T>* f;
    ListNode<T>* r;
    LinkedList()
    {
        f = NULL;
        r = NULL;
    }

    T front()
    {
        return f->value;
    }

    T end()
    {
        return r->value;
    }

    void addEnd(T data)
    {
        ListNode<T>* newNode = new ListNode<T>(data);


        if (f == NULL)
            f = r = newNode;
        else
        {
            r->cursor = newNode;
            r = newNode;
        }
    }

    T removeFront()
    {
        if (f != NULL)
        {
            ListNode<T>* tmp = f;
            T tmp_T = f->value;
            f = f->cursor;
            delete tmp;
            return tmp_T;
        }
        return -1;
    }
};

template<class T>
class MyQueueLinked
{
private:
    LinkedList<T>* S;
    int n;
public:
    MyQueueLinked()
    {
        S = new LinkedList<T>();
        n = 0;
    }

    int size()
    {
        return n;
    }

    int isEmpty()
    {
        if (n==0) return 1;
        else return 0;
    }

    T front()
    {
        if (isEmpty()) cout << "Empty" << endl;
        else return S->front();
        return -1;
    }
    
    T rear()
    {
        if (isEmpty()) cout << "Empty" << endl;
        else return S->end();
        return -1;
    }

    void enqueue(int e)
    {
        n++;
        S->addEnd(e);
    }

    void dequeue()
    {
        if (isEmpty()) cout << "Empty" << endl;
        else
        {
            cout << front() << endl;
            S-> removeFront();
            n--;
        }
    }
};

int main()
{
    int s = 0;
    int n = 0;
    
    cin >> s >> n;

    MyQueueLinked<int> q;

    for (int iter = 0 ; iter < n ; iter++)
    {
        string command;
        cin >> command;

        if (command == "enqueue")
        {
            int data;
            cin >> data;

            if (q.size() < s)
                q.enqueue(data);
            else cout << "Full" << endl;
        }

        else if (command == "dequeue")
        {
            q.dequeue();
        }
        
        else if (command == "size")
        {
            cout << q.size() << endl;
        }

        else if (command == "isEmpty")
        {
            cout << q.isEmpty() << endl;
        }

        else if (command == "front")
        {
            if (q.isEmpty()) cout << "Empty" << endl;
            else cout << q.front() << endl;
        }

        else if (command == "rear")
        {
            if (q.isEmpty()) cout << "Empty" << endl;
            else cout << q.rear() << endl;
        }
    }

    return 0;
}