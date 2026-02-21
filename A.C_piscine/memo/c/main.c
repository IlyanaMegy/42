#include <stdio.h>

int main()
{
	int a = 10;
	int * pa = &a;

	//affiche a
	printf("a = %d, ", a);
	
	//adresse de a
	printf("adresse de a = %p\n", &a);
	printf("pointeur de a pa = %p\n", pa);

	//valeur stockee a l'adresse pa
	printf("la valeur stockee a l'adresse %p est %d\n", pa, *pa);
	

	printf("------------------------------------------------\n");


	int n1 = 1;
	int n2 = 2;

	printf("n1 = %d, (adresse : %p)\n", n1, &n1);
	printf("n2 = %d, (adresse : %p)\n", n2, &n2);

	printf("\n");

	int *c = &n1;
	int *d = &n2;
	int e;

	printf("c = %d\n", *c);
        printf("d = %p\n", d);
	printf("e = %d\n", e);

	e = *c;
	*c = *d;
	*d = e;

	printf("c = %d\n", *c);
        printf("d = %d\n", *d);
	printf("------------------------------------------------\n");

	int f1 = 10/3;
	int f2 = 10%3;
	printf("%d", f1);
	printf("\n");
	printf("%d", f2);
	return 0;
}
