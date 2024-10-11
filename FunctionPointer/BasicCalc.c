/*This program will implement the basic calc using array of function pointers
* Created : 7 October 2024
* Author : Pruthviraj 165490
*/
#include <stdio.h>
int add(int iA, int iB)
{
	return iA + iB;
}/*End add()*/
int sub(int iA, int iB)
{
	return iA - iB;
}/*End sub()*/
int mul(int iA, int iB)
{
	return iA * iB;
}/*End sub()*/
int div(int iA, int iB)
{
	return iA / iB;
}/*End div()*/
int main()
{
	int (*iFoo[4])(int, int) = {add, sub, mul, div};
	
	int iResult1 = iFoo[0](5, 5);
	int iResult2 = iFoo[1](10, 5);
	int iResult3 = iFoo[2](5, 2);
	int iResult4 = iFoo[3](18, 2);
	
	printf("Result 1(5 + 5)		: %d\n", iResult1);
	printf("Result 2(10 - 5)	: %d\n", iResult2);
	printf("Result 3(5 * 2)		: %d\n", iResult3);
	printf("Result 4(18 / 2)	: %d\n", iResult4);
}/*End main()*/
