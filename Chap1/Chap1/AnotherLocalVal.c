#include <stdio.h>


void Recursive(int num) {
	if (num <= 0)
		return;
	printf("Àç±ÍÈ£Ãâ %d \n", num);
	Recursive(num - 1);
}




//int main(void) {
//	Recursive(3);
//	return 0;
//}