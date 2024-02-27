#include "main.h"
int main(void)
{
	if (chdir("/home") == 0)
		printf("done");
	else
		printf("func");
	return 0;
}