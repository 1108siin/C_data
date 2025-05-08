#include<stdio.h> //전처리기

int main(void) //무조건 하나만 있어야함 void는 형식없음 생략가능
{
	int i = 10; //정수형 변수i선언
	double f = 12.3; //실수형 변수 i선언
	int* pi = NULL; // 포인터 변수 pi선언

	double* pf = NULL; // 포인터 변수 pf선언
	pi = &i; //정수형 i의 주소를 포인터에 대입
	pf = &f; //실수형 f의 주소를 포인터에 대입

	printf("%d %p %d\n", pi, &i, i); //i값 출력 // 주소 불러와서 출력
	printf("%p %p %lf\n", pf, &f, f);//f값 출력

	return 0;
}
