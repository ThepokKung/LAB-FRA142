#include <iostream>

using namespace std;

int main()
{
    int hihi = 10;
    int *Var_For_Change = NULL;
    Var_For_Change = &hihi;
    cout << "Var_For_Change : " << Var_For_Change << endl;
    cout << "Hihi : " << hihi << endl;
    cout << "Hihi : " << &hihi << endl;

    hihi = 20;
    // *Var_For_Change = 20;
    cout << "Var_For_Change : " << *Var_For_Change << endl;
    cout << "Hihi : " << hihi << endl;
    cout << "Hihi : " << &hihi << endl;
    return 0;
}