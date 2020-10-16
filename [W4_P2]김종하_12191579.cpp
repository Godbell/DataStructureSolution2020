#include <iostream>

using namespace std;

template <class T>
class ListNode
{
public:
    ListNode<T> *cursor;
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
    ListNode<T> *f;
    ListNode<T> *r;
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
        ListNode<T> *newNode = new ListNode<T>(data);

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
            ListNode<T> *tmp = f;
            T tmp_T = f->value;
            f = f->cursor;
            delete tmp;
            return tmp_T;
        }
        return -1;
    }
};

template <class T>
class MyQueueLinked
{
public:
    LinkedList<T> *S;
    int n;


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
        if (n == 0)
            return 1;
        else
            return 0;
    }

    T front()
    {
        if (isEmpty())
            cout << "Empty" << endl;
        else
            return S->front();
        return -1;
    }

    T rear()
    {
        if (isEmpty())
            cout << "Empty" << endl;
        else
            return S->end();
        return -1;
    }

    void enqueue(int e)
    {
        n++;
        S->addEnd(e);
    }

    void dequeue()
    {
        if (isEmpty())
            cout << "Empty" << endl;
        else
        {
            S->removeFront();
            n--;
        }
    }

};

int battle(MyQueueLinked<int>& a, MyQueueLinked<int>& b)
{
    if (a.front() > b.front())
    {
        int remainder = a.front() - b.front();
        a.dequeue();
        b.dequeue();

        if (!a.isEmpty())
            a.S->f->value += (remainder - 1);
        return 1;
    }
    else if (a.front() < b.front())
    {
        int remainder = b.front() - a.front();
        a.dequeue();
        b.dequeue();

        if (!b.isEmpty())
            b.S->f->value += (remainder - 1);
        return 2;
    }
    else
    {
        a.dequeue();
        b.dequeue();
        return 0;
    }
}

int main()
{
    int t = 0;
    cin >> t;

    for (int iter = 0; iter < t; iter++)
    {
        int n = 0;
        cin >> n;

        int p1point = 0;
        int p2point = 0;
        MyQueueLinked<int> p1;
        MyQueueLinked<int> p2;

        for (int i = 0; i < n; i++)
        {
            int card;
            cin >> card;
            p1.enqueue(card);
        }

        for (int i = 0; i < n; i++)
        {
            int card;
            cin >> card;
            p2.enqueue(card);
        }

        for (int i = 0; i < n; i++)
        {
            int result = battle(p1,p2);
            if (result == 1)
            {
                p1point++;
            }
            else if (result == 2)
            {
                p2point++;
            }
        }

        if (p1point > p2point)
            cout << 1 << endl;
        else if (p1point < p2point)
            cout << 2 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}