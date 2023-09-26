#include <iostream>
using namespace std;
int count, len;
int recursion(int str[], int n, int i)
{
    count = 0;
    if (((i == n - 1) && (str[i] == 0 || str[i] == 1)) || (i == n))
    {
        for (int k = 0; k < i; k++)
            cout << str[k];
        if (((i == n - 1) && (str[i] == 0 || str[i] == 1)))
        {
            cout << str[i];
        }
        if (i == n)
        {
            cout << '\0';
        }
        for (int k = n; k < len; k++)
            cout << str[k];
        return str[i];
    }

    if (str[i] == str[n - 1])

    {
        for (int k = 0; k < i; k++)
            cout << str[k];
        cout << str[i] << "P" << str[n - 1];
        for (int k = n; k < len; k++)
            cout << str[k];
        cout << endl;
        n--;
        i++;

        recursion(str, n, i);
    }
    else
        cout << "Not in the grammar";
}

int main()
{

    cout << "enter string len: ";
    cin >> len;
    int str[len];
    for (int i = 0; i < len; i++)
    {
        cout << "enter value: ";
        cin >> str[i];
    }

    recursion(str, len, 0);
}