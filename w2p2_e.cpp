#include <iostream>

using namespace std;

template <class T>
class ListNode
{
private:
    T value;
    ListNode<T>* next;

public:
    ListNode(T _value)
    {
        value = _value;
        next = NULL;
    }

    void Next(ListNode<T>* node)
    {
        next = node;
    }

    ListNode<T>* Next()
    {
        return next;
    }

    T Value()
    {
        return value;
    }
};

template <class T>
class ProblemList
{
private:
    int lastIndex;
    ListNode<T>* head;
    ListNode<T>* tail;

public:
    ProblemList()
    {
        lastIndex = -1;
        head = NULL;
        tail = NULL;
    }

    void addFront(ListNode<T> *node)
    {
        if (Empty())
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->Next(node);
            tail = tail->Next();

            if (lastIndex == 0) head->Next(tail);
        }
        lastIndex++;
    }

    int removeFront()
    {
        if (Empty())
            return -1;

        ListNode<T> remTarget = *(tail);
        
        if (lastIndex > 0)
        {
            IndexPtr(lastIndex - 1)->Next(NULL);
            tail = IndexPtr(lastIndex - 1);
        }

        lastIndex--;

        if (lastIndex == -1)
        {
            head = NULL;
            tail = NULL;
        }

        return remTarget.Value();
    }

    ListNode<T>* frontPtr()
    {
        return tail;
    }

    bool Empty()
    {
        bool state = false;

        if (lastIndex < 0)
        {
            state = true;
        }

        return state;
    }

    ListNode<T>* IndexPtr(int index)
    {
        ListNode<T>* searcher = head;
        for (int i = 0 ; i < index ; i++)
        {
            searcher = searcher->Next();
        }

        return searcher;
    }

    void test()
    {
        ListNode<T>* testrunner = head;
        while (testrunner)
        {
            cout << testrunner->Value() << endl;
            testrunner = testrunner->Next();
        }
    }
};

int main()
{
    ProblemList<int> mylist;

    // solve

    int numberOfCommands = 0;
    cin >> numberOfCommands;
    for (int i = 0; i < numberOfCommands; i++)
    {
        string command = "";
        cin >> command;

        if (command == "addFront")
        {
            int value = 0;
            cin >> value;

            mylist.addFront(new ListNode<int>(value));
        }
        else if (command == "removeFront")
        {
            int result = mylist.removeFront();
            
            cout << result << endl;
        }
        else if (command == "front")
        {
            if (!mylist.frontPtr())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << mylist.frontPtr()->Value() << endl;
            }
        }
        else if (command == "empty")
        {
            if (mylist.Empty())
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        else if (command == "test")
        {
            mylist.test();
        }
    }

    return 0;
}

