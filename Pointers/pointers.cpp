#include <stdio.h>

int main(){

	int a = 10;
	int *p;
	p = &a;
	printf("a = %d \n",a);
	printf("p = %d \n",p);
	printf("&p = %d \n",&p);
	printf("*p = %d \n",*p);
	printf("&a = %d \n",&a);
	*p = 12;
	printf("a = %d \n",a);
	printf("p = %d \n",p);
	printf("&p = %d \n",&p);
	printf("*p = %d \n",*p);
	printf("&a = %d \n",&a);
}
