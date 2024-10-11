#include <stdio.h>
int main()
{
	struct account
	{
		int no;
		float bal;
	};
	struct account a[10];
	{
		int i, acc;
		float balance;
		for (i = 0; i <= 9; i++)
		{
			printf("\nEnter Account No. And Blance: ");
			scanf("%d %f", &acc, &balance);
			a[i].no = acc; a[i].bal = balance;
			printf("%d %f\n", a[i].no, a[i].bal);
		}
	}

}
