#include <iostream>

using namespace std;

void callByValue(int val)
{
    cout << "INFUN1 : " << val << endl;
    val = 100;
    cout << "INFUN2 : " << val << endl;
}

void callByReference(int *val)
{
    *val = 200;
}

int main()
{
    int var1 = 1;
    int var2 = 2;

    callByValue(var1);
    callByReference(&var2);

    cout << var1 << endl;
    cout << var2 << endl;
    return 0;
}