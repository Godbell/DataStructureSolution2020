#include <iostream>
#include <cstdlib>
#include <ctime>
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
    }

    T P_At(int index) const
    {
        return arr[index];
    }

    void P_Delete(int index)
    {
        for (int i = index; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[size - 1] = 0;
    }

    T P_Find_Max() const
    {
        T maxValue = 0;
        int maxIndex = 0;

        for (int i = 0; i < size; i++)
        {
            if (arr[i] >= maxValue)
            {
                maxValue = arr[i];
                maxIndex = i;
            }
        }

        return maxIndex;
    }

    void P_Set(int index, T value)
    {
        arr[index] = value;
    }
};


int main()
{
    srand(time(0));

    ProblemArr<int> myarray(10000);
    for (int i = 0; i < ARR_SIZE; i++)
    {
        myarray.P_Set(i, rand() % 10000);
    }

    // solve

    int numberOfCommands = 0;
    cin >> numberOfCommands;
    for (int i = 0; i < numberOfCommands; i++)
    {
        string command = "";
        cin >> command;

        if (command == "At")
        {
            int index = 0;
            cin >> index;

            cout << myarray.P_At(index) << endl;
        }
        else if (command == "Delete")
        {
            int index = 0;
            cin >> index;

            myarray.P_Delete(index);
        }
        else if (command == "Set")
        {
            int index = 0;
            int value = 0;
            cin >> index >> value;

            myarray.P_Set(index, value);
        }
        else if (command == "Find_Max")
        {
            cout << myarray.P_At(myarray.P_Find_Max()) << " " << myarray.P_Find_Max() << endl;
        }
    }

    return 0;
}

