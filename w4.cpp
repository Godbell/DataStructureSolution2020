#include <iostream>

using namespace std;

template <class T>
class MyQueueArr
{
private:
    T* arr;
    int front;
    int rear;
    int capacity;
public:
    MyQueue(int c)
    {
        capacity = c;
        arr = new T [capacity];
        front = 0;
        rear = -1;
        for (int i = 0 ; i < capacity ; i++)
        {
            arr[i] = 0;
        }
    }

    void enqueue(T data)
    {
        if (size() == capacity - 1)
            cout << "FULL" << endl;
        else
        {
            rear = (rear + 1) % capacity;
            arr[rear] = data;
        }
    }

    T dequeue()
    {
        if (isEmpty())
            cout << "EMPTY" << endl;
        else
        {
            arr[front] = 0;
            front = (front + 1) % capacity;
        }
        
    }

    int size()
    {
        return ((rear - 1 front + 1 + capacity) % capacity);
    }

    bool isEmpty()
    {
        if ((rear + 1) % capacity == front)
            return true;
        else return false;
    }
};

////////////

template <class T>
class ListNode
{
private:
    T* cursor;
    T value;
public:
    ListNode(T data)
    {
        value = data;
        cursur = NULL;
    }
};

template <class T>
class LinkedList
{
private:
    ListNode<T>* f;
    ListNode<T>* r;
public:
    LL()
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
        ListNode<T> newNode = new ListNode<T>(data);

        if (front == NULL)
            f = r = newNode;
        else
        {
            r->cursor = newNode;
            r = NewNode;
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
            return tmp_int;
        }
        return NULL;
    }

    int size()
    {
        return ((rear - 1 front + 1 + capacity) % capacity);
    }

    bool isEmpty()
    {
        if (f == NULL) return true;
        else return false;
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
    }
    
    T rear()
    {
        if (isEmpty()) cout << Empty << endl;
        else return S->end();
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
            S-> removeFront();
            n--;
        }
    }
};

//////

template <class T>
class Deque
{
private:

public:

};

int main()
{
    int c;

    cin >> c;

    return 0;
}