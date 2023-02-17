#include <iostream>

using namespace std;

int Emonth = 30;
int CostS = 0;
bool DEBUG = true;

float CalCostIF(int x)
{
    float cash = x;
    float result;
    float total;
    for (int i = 2; i <= Emonth; i++)
    {
        if (i == 15)
        {
            continue;
        }
        else if (i % 2 == 0) // คู่
        {
            result = cash * 1.2;
            cash = result;
        }
        else if (i % 2 == 1) // คี่
        {
            result = cash * 0.8;
            cash = result;
        }
        total += result;
        if (DEBUG == true)
        {
            cout << " DEBUG! Day : " << i << " Result : " << result << " Total : " << total << endl;
        }
    }
    return total;
}

float CalCostWhile(int x)
{
    float cash = x;
    float result;
    float total;
    int date = 1;
    while (date <= Emonth)
    {
        if (date == 1)
        {
            date++;
            continue;
        }
        if (date == 15)
        {
            date++;
            continue;
        }
        else if (date % 2 == 0) // คู่
        {
            result = cash * 1.2;
            cash = result;
        }
        else if (date % 2 == 1) // คี่
        {
            result = cash * 0.8;
            cash = result;
        }
        total += result;
        if (DEBUG == true)
        {
            cout << " DEBUG! Day : " << date << " Result : " << result << " Total : " << total << endl;
        }
        date++;
    }
    return total;
}

int main()
{
    cout << "Input your cost : ";
    cin >> CostS;
    cout << "Start cost : " << CostS << endl;
    // cout << "Total Result : " << CalCost(CostS) << endl;
    // cout << CalCostIF(CostS);
    cout << CalCostWhile(CostS);
    return 0;
}