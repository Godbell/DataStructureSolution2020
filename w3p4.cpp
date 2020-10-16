#include <iostream>
#include <string>

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

    ListNode()
    {

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
class StackList
{
private:
    int lastIndex;
    ListNode<T>* head;
    ListNode<T>* tail;

public:
    StackList()
    {
        lastIndex = -1;
        head = NULL;
        tail = NULL;
    }

    void push(T elem)
    {
        ListNode<char>* node = new ListNode<char>(elem);
        if (Empty())
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->Next(node);
            tail = tail->Next();

            if (lastIndex == 0)
                head->Next(tail);
        }
        lastIndex++;
    }

    T pop()
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
        else state = false;

        return state;
    }

    ListNode<T>* IndexPtr(int index)
    {
        ListNode<T>* searcher = head;
        for (int i = 0; i < index; i++)
        {
            searcher = searcher->Next();
        }

        return searcher;
    }
};

int BIAS(char oper)
{
    if (oper == '*' || oper == '/') return 3;
    else if (oper == '-' || oper == '+') return 2;
    else if (oper == '(') return 1;
    else return -1;
}

int main()
{
    int N{ 0 };
    cin >> N;

    for (int n = 0; n < N; n++)
    {
        /* SOLUTION */
        char infix[10001];
        for (int i = 0; i < 10001; i++) infix[i] = 0;
        cin >> infix;
        StackList<char> stack;
        
        for (int i = 0; infix[i] != NULL; i++)
        {
            
             if ('0' <= infix[i] && infix[i] <= '9')
                std::cout << infix[i];
            else
            {
                if (infix[i] == '(')
                {
                    stack.push(infix[i]);
                }
                else if (infix[i] == ')')
                {
                    while (!stack.Empty() && stack.frontPtr()->Value() != '(' )
                    {
                        char print = stack.pop();
                        cout << print;
                    }
                    stack.pop();
                }
                else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
                {
                    if (!stack.Empty() && BIAS(infix[i]) >= BIAS(stack.frontPtr()->Value()))
                    {
                        char result = stack.pop();
                        if (result != '(')
                            cout << result;
                    }
                    
                    stack.push(infix[i]);
                }
            }
        }

        while (!stack.Empty())
        {
            char result = stack.pop();
            if (result != '(')
                cout << result;
        }
        std::cout << endl;
    }

    return 0;
}