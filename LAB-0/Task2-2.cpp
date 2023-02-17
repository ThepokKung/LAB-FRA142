#include <iostream>

using namespace std;

int main(){
    /*Val*/
    float Temp;
    char Val;
    // float Input = scanf("Please enter temperature : %f", &Temp);

    printf("Please enter temperature : ");
    scanf("%f %c", &Temp, &Val);
    // printf("%f %c", Temp, Val);
    // cout << "Please enter temperature : ";
    // cin >> Temp;
    if (Val == "C"){
        printf("");
    }

    return 0;
}