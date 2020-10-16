#include <iostream>

using namespace std;

template <class T>
class StackArray
{
private:
    int lastIndex;
    T* arr;

public:
    StackArray()
    {
        lastIndex = -1;

        arr = new int[10000];
        for (int i = 0 ; i < 10000; i++)
        {
            arr[i] = 0;
        }
    }

    void push(T value)
    {
        if (lastIndex < 10000 - 1)
        {
            lastIndex += 1;
            arr[lastIndex] = value;
        }
    }

    bool Empty()
    {
        if (lastIndex < 0)
            return true;
        else return false;
    }

    T top()
    {
        if (Empty())
            return NULL;
        else
            return arr[lastIndex];
    }

    T pop()
    {
        if (!Empty())
        {
            T poptarget = arr[lastIndex];
            arr[lastIndex] = NULL;
            lastIndex--;

            return poptarget;
        }
        else return NULL;
    }

    int Size()
    {
        return lastIndex + 1;
    }
};

int main()
{
    StackArray<int> arr;

    int numberOfCommands = 0;
    cin >> numberOfCommands;
    for (int i = 0; i < numberOfCommands; i++)
    {
        string command = "";
        cin >> command;

        if (command == "empty")
        {
            int result = 0;
            if (arr.Empty())
            {
                result = 1;
            }

            cout << result << endl;
        }
        else if (command == "top")
        {
            int result = 0;

            if (arr.top() != NULL)
            {
                result = arr.top();
            }
            else
            {
                result = -1;
            }
            
            cout << result << endl;
        }
        else if (command == "push")
        {
            int value = 0;
            cin >> value;

            arr.push(value);
        }
        else if (command == "pop")
        {
            int result = arr.pop();

            if (result == NULL)
                result = -1;
            
            cout << result << endl;
        }
        else if (command == "size")
        {
            cout << arr.Size() << endl;
        }
    }
}