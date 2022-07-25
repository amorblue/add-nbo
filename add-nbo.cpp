#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint32_t ntohl(uint32_t n) {	
	
	uint32_t n1 = ((n & 0xff000000) >> 24);
	uint32_t n2 = ((n & 0x00ff0000) >> 16);
	uint32_t n3 = ((n & 0x0000ff00) >> 8);
	uint32_t n4 = (n & 0x000000ff);

	return n4<<24 | n3<<16 | n2<<8 | n1;
}

int main(int argc, char* argv[]) {

	char name[]="parkmiju";
	char mobile[]="3759";


	FILE* fp1;
	FILE* fp2;

	uint32_t f1, f2;

	fp1 = fopen(argv[1], "rb");
	fp2 = fopen(argv[2], "rb");

	if (fp1 == NULL || fp2 == NULL)
	{
		printf("ErRrOR");
		exit(0);
	}

	fread(&f1, sizeof(uint32_t), 1, fp1);
	fread(&f2, sizeof(uint32_t), 1, fp2);

	f1 = ntohl(f1);
	f2 = ntohl(f2);

	printf("\n\n[bob11]add-nbo[%s%s]\n\n",name,mobile);
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", f1, f1, f2, f2, f1 + f2, f1 + f2);

	fclose(fp1);
	fclose(fp2);

}

