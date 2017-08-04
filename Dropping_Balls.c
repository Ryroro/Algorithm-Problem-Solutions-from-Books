#include <stdio.h>
#include <math.h>
int main()
{
	int D, I;
	while (scanf("%d%d", &D, &I) == 2) {
		long max = pow(2, D) -1;
		int nodes[max+1];
		nodes[0] = -1;
		for (int i = 1; i <=max; i++)
			nodes[i] = -1;
		long k;
		for (int j = 1; j <=I; j++) {
			k = 1;
			while (k <= ((max+1)/2 -1) ) {
				nodes[k] = -nodes[k];
				if (nodes[k] == -1)
					k = 2*k + 1;
				else if (nodes[k] == 1)
					k = 2*k;
				
			}
		}
		printf("%ld\n", k);
	}

	return 0;
}
