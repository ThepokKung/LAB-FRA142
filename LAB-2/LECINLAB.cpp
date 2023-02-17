#include <iostream>
#include <tuple>
using namespace std;

tuple<int, int, char> foo(int n1, int n2)
{
    // Packing values to return a tuple
    return make_tuple(n2, n1, 'a');
}

int main()
{
    // /* 1 */
    // int x = 2;
    // int *ptr_x = NULL;
    // ptr_x = &x;
    // // Check 1
    // cout << ptr_x << endl;
    // cout << x << endl;
    // // Check 2
    // *ptr_x = 7;
    // cout << ptr_x << endl;
    // cout << x << endl;

    /* 2 */
    // int* ptr_y = NULL;
    // cout << ptr_y << endl;
    // int y = 1.5;
    // cout << y << endl;
    // ptr_y = &y;
    // cout << ptr_y << endl;
    // cout << y << endl;

    /* 3 */
    // float *f = NULL;
    // double *d = NULL;
    // // char *c = '\0'; //NOT WORKING
    // bool *b = NULL;
    // cout << f << endl;
    // cout << d << endl;
    // // cout << c << endl;
    // cout << b << endl;

    int a, b;
    char cc;

    // Unpack the elements returned by foo
    tie(a, b, cc) = foo(5, 10);

    cout << "Values returned by tuple: ";
    cout << a << " " << b << " " << cc << endl;

    return 0;
}
