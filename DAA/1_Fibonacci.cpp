#include <bits/stdc++.h>
using namespace std;

int steps = 0;

void fibonacci(int n)
{
    long long a = 0;
    long long b = 1;
    long long next;

    cout << "Fibonnaci Series: ";
    for (int i = 1; i <= n; i++)
    {
        cout << a << " ";
        next = a + b;
        a = b;
        b = next;
        steps++;
    }
    cout << endl;
    cout << "Step count is: " << steps << endl;
}

int fibonacci_recursive(int n)
{
    steps++;
    if (n <= 1)
    {
        return n;
    }

    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int main()
{
    int n;
    int choice;

    cout << "Enter the number of terms: ";
    cin >> n;

    cout << "1. Iterative" << endl;
    cout << "2. Recursive" << endl;
    cout << "Enter your choice: " << endl;
    cin >> choice;

    if (choice == 1)
    {
        fibonacci(n);
    }
    else if (choice == 2)
    {
        steps = 0;
        for (int i = 0; i < n; i++)
        {
            cout << fibonacci_recursive(i) << " ";
        }
        cout << endl;
        cout << "Steps count: " << steps << endl;
    }
    else
    {
        cout << "Invalid Choice" << endl;
    }

    return 0;
}