#include<stdio.h>

int main(void)
{
    int a = 100;  //일반변수 선언
    int b = 200;  //포인터변수 선언
    int* p;

    p = &a;     // a주소를 포인터변수 p에 저장
    printf("a 주소 = %p\n", &a);            // a의 주소
    printf("p 주소= %p\n", p);             // p의 주소  출력
    printf("a  값= %d\n", a);                // a의 값
    printf("p  값 = %d\n", *p);               // p가 가르키는 주소의 값

    p = &b;    // b주소를 포인터변수 p에 저장
    printf("p 주소 = %p\n", p);               // p의 주소  출력    
    printf("p  값= %d\n", *p);                    // p가 가르키는 주소의 값 

    return 0;
}