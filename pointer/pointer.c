#include <stdio.h>

int a=10;
int b=100;
int* p=NULL;

void func(int *p);

int main()
{
	printf("%s:&a = %p &b = %p &p = %p\r\n",__func__,&a,&b,&p);
	p = &a;
	printf("after p = &a\r\n");
	printf("%s:*p = %d p = %p &p = %p\r\n",__func__,*p,p,&p);
	func(p);
	printf("%s:*p = %d p = %p &p = %p\r\n",__func__,*p,p,&p);
	return 0;
}

void func(int *tp)
{
	printf("\r\n");
	printf("%s:*tp = %d tp = %p &tp = %p\r\n",__func__,*tp,tp,&tp);
	tp = &b;
	printf("after tp = &b\r\n");
	printf("%s:*tp = %d tp = %p &tp = %p\r\n",__func__,*tp,tp,&tp);
	printf("\r\n");
}
