#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct _Frac {
	int nu; // numerator
    int de; // denominator
}Frac;

int compare_Two_Frac(const Frac* a, const Frac* b) {
    if((a->nu/a->de)<(b->nu/b->de))
    {
        return 1;
    }
    else if((a->nu/a->de) == (b->nu/b->de))
    {
        return 0;
    }
    else
    {
        return 1;
    }
    // a < b 이면 return 1
    // a = b 이면 return 0	
    // a > b 이면 return -1	
}

void swap_Frac(Frac* a, Frac* b) {
    int temp_nu;
    int temp_de;

    temp_nu = a->nu;
    a->nu = b->nu;
    b->nu = temp_nu;

    temp_de = a->de;
    a->de = b->de;
    b->de = temp_de;

    return;
    // Frac a와 b를 바꾼다.
}

int main(void) {

	FILE* fp = NULL;
	int N;
	fp = fopen("input.txt", "r");
	if (fp == NULL) {
		printf("Error!\n");
		return 0;
	}

	fscanf(fp, "%d\n", &N);
	Frac* arr = (Frac*)calloc(N, sizeof(Frac));
	for (int i = 0; i < N; i++) {
		fscanf(fp, "%d %d", &arr[i].nu, &arr[i].de);
	}
	fclose(fp);

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - 1 - i; j++) {
			if (compare_Two_Frac(&arr[j], &arr[j + 1]) == -1) {
				swap_Frac(&arr[j], &arr[j + 1]);
			}
		}
	}

	//Do not change anything below!
	for (int i = 0; i + 1 < N; i++) {
		assert(compare_Two_Frac(&arr[i], &arr[i + 1]) >= 0);
	}
	free(arr);
	printf("Good!\n");
	return 0;
}
