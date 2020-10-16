#include <iostream>
#include <string>

#define ARR_SIZE 10000

using namespace std;

template <class T>
class ProblemArr
{
private:
    int size;
    T* arr;

public:
    ProblemArr(int size)
    {
        this->size = size;

        arr = new int[this->size];
        for (int i = 0 ; i < this->size; i++)
        {
            arr[i] = 0;
        }
    }

    T P_At(int index) const
    {
        return arr[index];
    }

    void P_Add(int index, T value)
    {
        if (arr[index] == 0)
        {
            while (index > 0 && arr[index - 1] == 0)
            {
                index--;
            }
        }
        else
        {
            for (int i = size - 1; i > index; i--)
            {
                arr[i] = arr[i - 1];
            }
        }
        
        arr[index] = value;
    }

    bool P_Set(int index, T value)
    {
        bool state = true;

        if (arr[index] == 0)
            state = false;
        else
            arr[index] = value;

        return state;
    }

    bool Empty()
    {
        for (int i = 0 ; i < size ; i++)
        {
            if (arr[i] != 0)
                return false;
        }
        return true;
    }
};


int main()
{
    ProblemArr<int> myarray(10000);

    // solve

    int numberOfCommands = 0;
    cin >> numberOfCommands;
    for (int i = 0; i < numberOfCommands; i++)
    {
        string command = "";
        cin >> command;

        if (command == "at")
        {
            int index = 0;
            cin >> index;

            cout << myarray.P_At(index) << endl;
        }
        else if (command == "add")
        {
            int index = 0;
            int value = 0;
            cin >> index >> value;

            myarray.P_Add(index, value);
        }
        else if (command == "set")
        {
            int index = 0;
            int value = 0;
            cin >> index >> value;

            if (!myarray.P_Set(index, value))
            {
                cout << 0 << endl;
            }
        }
    }

    return 0;
}

