#include<stdio.h> //��ó����

int main(void) //������ �ϳ��� �־���� void�� ���ľ��� ��������
{
	int i = 10; //������ ����i����
	double f = 12.3; //�Ǽ��� ���� i����
	int* pi = NULL; // ������ ���� pi����

	double* pf = NULL; // ������ ���� pf����
	pi = &i; //������ i�� �ּҸ� �����Ϳ� ����
	pf = &f; //�Ǽ��� f�� �ּҸ� �����Ϳ� ����

	printf("%d %p %d\n", pi, &i, i); //i�� ��� // �ּ� �ҷ��ͼ� ���
	printf("%p %p %lf\n", pf, &f, f);//f�� ���

	return 0;
}
