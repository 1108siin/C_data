#include<stdio.h>
void call_value(int icopy); //함수 원형
void call_refer(int* ip);

int main(void)
{
	int i = 777; 
	call_value(i);  //함수 호출
	printf("값 호출 : %d\n", i); // 777

	call_refer(&i);// 함수 호출 //i 주소
	printf("참조 호출 : %d\n", i); // 888

	return 0;
}

void call_value(int icopy) {  // icopy <- 777
	icopy = 888;
}
void call_refer(int* ip) { // ip 가 i주소 가르킴
	*ip = 888; // 주소가 가르키는 값 
}