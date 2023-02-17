#include <iostream>

int a,b,c;

int main(){
    // printf("% d %c %f",23,'z',4.1);
    // printf("Hello World Test ");
    // scanf("%d%d%d",&a,&b,&c);
    // printf("%d %d %d",a,b,c);

    // int Test;
    
    // Test = Test01;
    // int 

    return 0;
}

void Test01(){
    int x1 = 5;
    int y1 = x1++;

    int x2 = 5;
    int y2 = x2++;

    int a1 = 5;
    int b1 = 2 + (--a1);

    int a2 = 5;
    int b2 = 2 + (a--);

    printf("X1:%d Y1:%d X2:%d Y1:%d A1:%d B1:%d A1:%d B2:%d",x1,y1,x2,y2,a1,b1,a2,b2);
}
