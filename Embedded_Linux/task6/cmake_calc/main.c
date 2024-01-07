#include <stdio.h>
#include "addition.h"
#include "division.h"
#include "modulus.h"
#include "multiplication.h"
#include "subtraction.h"
int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	char operation ;
	float num_1 , num_2 , result;
	printf("Please the operation that you want to do\n");
	scanf("%c",&operation);
	printf("Please number 1 \n");
	scanf("%f",&num_1);
	printf("Please number 2 \n");
	scanf("%f",&num_2);
	switch (operation)
	{
	case '/' :
		result = ( float )division(num_1,num_2);
		printf("%f  /  %f  = %f\n",num_1,num_2,result);
		break;
	case '+' :
		result = sum(num_1,num_2);
		printf("%f  +  %f  = %f\n",num_1,num_2,result);
		break;
	case '-' :
		result = sub(num_1,num_2);
		printf("%f  -  %f  = %f\n",num_1,num_2,result);
		break;
	case '*' :
		result = multiplication(num_1,num_2);
		printf("%f  *  %f  = %f\n",num_1,num_2,result);
		break;
	case '%' :
		result =( float )modulus(num_1,num_2);
		printf("%f  mod  %f  = %fdn",num_1,num_2,result);
		break;	
	default :
		printf("nothing");
		break;
	}
	getchar();

}
