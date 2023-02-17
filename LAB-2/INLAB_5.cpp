#include <iostream>

using namespace std;

void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int x = 1;
    int y = 2;

    cout << "BEFOR swap" << endl;
    cout << x << " " << y << endl;
    Swap(&x, &y);

    cout << "AFTER swap" << endl;
    cout << x << " " << y << endl;
    return 0;
}
