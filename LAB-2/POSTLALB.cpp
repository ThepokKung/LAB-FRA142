#include <iostream>

using namespace std;

void one_for_two(int *x, int *y, int *z)
{
    for (int i = 0; i < 10; i++)
    {
        // cout << *(x + i) << endl;
        if (*(x + i) % 2 == 0)
        {
            *(y + (i / 2)) = *(x + i);
        }
        else if (*(x + i) % 2 == 1)
        {
            *(z + (i / 2)) = *(x + i);
        }
    }
}

void Call_AR(int *x)
{
    for (int i = 0; i < 5; i++)
    {
        cout << *(x + i) << endl;
    }
}

int main()
{
    int a[10] = {1, 1, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[5];
    int c[5];
    one_for_two(a, b, c);

    Call_AR(b);
    cout << "=========" << endl;
    Call_AR(c);

    cout << "========   " << endl;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;  
    return 0;
}