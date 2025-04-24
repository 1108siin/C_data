#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int sum(int x, int y);  // 함수원형
int sub(int x, int y);  // main이 각 함수보다 먼저 나오므로
//미리 컴파일러에게 함수정보 알려줌
int mul(int x, int y);
double div(int x, int y);
void  prn1(int result1);
void prn2(double result2);

int main(void)
{
    int sel;
    int a, b; // a,b는 숫자(정수)를 입력받아서 저장할 변수명
    int res1;  //+,-,* 결과를 저장(정수형 선언)
    double res2; // 나누기(/)는 결과를 실수로 저장

    printf("첫번째 숫자를 입력하세요 : ");
    scanf("%d", &a);
    printf("두번째 숫자를 입력하세요 : ");
    scanf("%d", &b);

    for (int i = 1; i <= 3; i++) // 3번 반복
    {
        printf("원하는 연산을 선택하시오(1:더하기 2: 빼기 3:곱하기 4: 나누기) : ");
        scanf("%d", &sel);

        if (sel == 1)           res1 = sum(a, b);
        else if (sel == 2)     res1 = sub(a, b);
        else if (sel == 3)     res1 = mul(a, b);
        else if (sel == 4)     res2 = div(a, b);

        if (sel == 1 || sel == 2 || sel == 3)
        {
            prn1(res1); break;
        }

        else if (sel == 4) {
            prn2(res2); break;
        }

        else printf("입력 오류! 다시입력하세요.\n");
    }
    return 0;
}

int sum(int x, int y)
{
    int k;
    k = x + y;
    return k;
}

int sub(int x, int y)
{
    int k;
    k = x - y;
    return k;
}

int mul(int x, int y)
{
    int k;
    k = x * y;
    return k;
}

double div(int x, int y)
{
    double q; // 실수형
    q = x / (double)y;
    return q;
}

void  prn1(int result1)// res1-> result1(정수형 받음)
// 반환값이 없이 돌아감(void 함수형 처리)
{
    printf("결과는 %d", result1);//출력완료
    return; // 생략가능
}

void prn2(double result2)
{
    printf("결과는: %.2lf", result2);
    return;
}