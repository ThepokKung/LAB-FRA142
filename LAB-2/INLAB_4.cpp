#include <iostream>
#include <tuple>

using namespace std;

tuple<int, int> test(int *x1, int *x2)
{
    return make_tuple(*x2, *x1);
}

int main()
{
    int x = 10;
    int y = 20;

    // tuple<int, int> test1(x,y);
    // tuple<int, int> test2(30, 40);
    // cout << get<0>(test1) << " " << get<1>(test1) << endl;
    // cout << get<0>(test2) << " " << get<1>(test2) << endl;
    // // test1.swap(test2);
    // cout << get<0>(test1) << " " << get<1>(test1) << endl;
    // cout << get<0>(test2) << " " << get<1>(test2) << endl;

    tie(x, y) = test(&x, &y);
    cout << x << " " << y << endl;

    return 0;
}