#include <iostream>
#include <algorithm>
using namespace std;

// Gobal Var
float Save[7];

void inputVal()
{
    for (int i = 0; i <= 6; i++)
    {
        cout << "INPUT Number " << i + 1 << " : ";
        cin >> Save[i];
    }
}

void CallSave()
{
    for (int i = 0; i <= 6; i++)
    {
        cout << "Save " << i + 1 << " : " << Save[i] << endl;
    }
}

// void min_max_fun()
// {
//     cout << "Max : " << max(Save);
// }

int main()
{
    cout << "Enter 7 Floating number : " << endl;
    inputVal();
    CallSave();
    return 0;
}