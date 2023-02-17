#include <iostream>

using namespace std;

int x = 0;
int y = 0;

int Road_map[] = {1, 2, 1, 3, 1, 2, 2, 1, 3, 2, 4, 1, 2, 3, 1, 4, 1, 2, 1, 3, 1, 2, 1, 1, 4};
int N_Road_map = sizeof(Road_map) / sizeof(int);
void Switch_XY(int tempval)
{
    switch (tempval)
    {
    case 1:
        y += 1;
        break;
    case 2:
        x -= 1;
        break;
    case 3:
        y -= 1;
        break;
    case 4:
        x += 1;
        break;

    default:
        cout << "What?";
        break;
    }
}

void IF_XY(int tempval){
    if (tempval == 1){
        y +=1 ;
    } else if (tempval == 2){
        x -= 1;
    } else if (tempval == 3){
        y -= 1;
    } else if (tempval == 4){
        x += 1;
    } else {
        cout << "What";
    }
}   

void Nay_Walker_to_the_moon()
{
    for (int i = 1; i <= N_Road_map; i++)
    {
        cout << "Round : " << i << " Val : " << Road_map[i - 1] << endl;
        int temp = Road_map[i - 1];
        // Switch_XY(temp);
        IF_XY(temp);
        cout << "X postition : " << x << " Y postition : " << y << endl;
    }
}

int Print_Array()
{
    for (const auto &e : Road_map)
    {
        cout << e << std::endl;
    }
    return 0;
}

int main()
{
    // Print_Array();
    // cout << N_Road_map;
    Nay_Walker_to_the_moon();
    cout << "Result X postition : " << x << " Y postition : " << y << endl;
    return 0;
}