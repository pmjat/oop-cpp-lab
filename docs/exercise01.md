### Exercise 1. Explain what do you learn from following code.

```c++
#include <stdio.h>
#include <stdlib.h>

int main() {

	int *px, *py, *pz;
	px = (int *) malloc( sizeof (int) );
	py = (int *) malloc( sizeof (int) );
	pz = (int *) malloc( sizeof (int) );
	printf("Enter two integer values: ");
	scanf("%d %d", px, py);
	*pz = *px + *py;
	printf("Values pointed by px, py, pz are:\n");
	printf("%d %d %d\n", *px, *py, *pz);
	free(px); free(py); free(pz);

	return 0;

}

```

### Exercise 2. Explain what do you learn from following code.

```c++
#include <stdio.h>
#include <stdlib.h>

void gen_feb( int* x, int N );

int main() {

	int i, N=10;
	int* x; //pointer to access dynamic array. Array resides in heap
	
	x = (int *) malloc( N * sizeof (int) );

	gen_feb( x, N );

	for(i=0; i < N; i++) 
		printf("%d, ", x[i]);

	return 0;

}

void gen_feb( int* x, int N ){
	
	*x++ = 1;
	*x++ = 1;
	N = N - 2;
	while( --N >= 0 ) {
		*x = *(x-1) + *(x-2);
		x++;
	}
	return;
}

```

### Exercise 3. Explain what do you learn from following code.

```c++
#include <stdio.h>
#include <stdlib.h>

int main() {

	int x[10], *y, N=10, n = 6, i;
	
	y = (int *) malloc(  N * sizeof (int) );

	for(i=0; i < n; i++) {
		x[i] = i+1;
		y[i] = (i+1)*10;
	}
	for(i=0; i < n; i++) 
		printf("%d %d\n", x[i], y[i]);

	for(i=0; i < n; i++) 
		printf("%d %d\n", *(x+i), *(y+i) );

	free(y);
	y = x; // we can not write x = y?
	for(i=0; i < n; i++) 
		printf("%d %d\n", x[i], y[i]);

	for(i=0; i < n; i++, y++) 
		printf("%d, ", *y);	printf("\n");
		//we can not increase value of x
	for(i=0, --y; i < n; i++, --y) 
		printf("%d, ", *y);
		
	return 0;

}

```

### Exercise 4. Explain what do you learn from following code.

```c++
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void sort( int* x, int n );
void sortp( int* x, int n );
void sortq( int* x, int n );
int read_array(int**xp);
void process(int* x, int n, int* p_max, int* p_min, double* p_mean);

int main() {

	int i, n, min, max;
	int* x; //pointer to access dynamic array. Array resides in heap	
	double mean;

	n = read_array( &x );
	for(i=0; i < n; i++) 
		printf("%5d\n", x[i]);

	process( x, n, &max, &min, &mean);
	printf("max: %d,   min: %d,  mean: %6.2f\n", max, min, mean);
	
	sort( x, n ); 
	// sortp( x, n ); 
	//sortq( x, n );
	for(i=0; i < n; i++) 
		printf("%5d\n", x[i]);

	return 0;

}

int read_array(int** xp) {

	int n, i;
	
	printf("Enter Number of values: ");
	scanf("%d", &n);
	*xp = (int *) malloc( n * sizeof (int) );

	for (i = 0 ; i < n; i++) 
		scanf("%d", *xp+i );

	return n;
	
}

void process(int* x, int n, int* p_max, int* p_min, double* p_mean) {

	int sum = 0, m=n;
	*p_min = INT_MAX;
	*p_max = INT_MIN;
	while ( --n >= 0 ) {
		sum += *x;
		if( *x < *p_min ) 
			*p_min = *x;
		if( *x > *p_max ) 
			*p_max = *x;
		x++;
	}
	
	*p_mean = (double) sum / m;
	
}

void swap(int* x, int* y) {
	int t = *x;
	*x = *y;
	*y = t;	
}

void sort( int* x, int n ) {
	int i, j;

	for (i = 0 ; i < ( n - 1 ); i++)  {
		for (j = 0 ; j < n - i - 1; j++)  {
			if ( x[j]  > x[j+1] )
				swap( &x[j], &x[j+1]);
		}
	}	
}

void sortp( int* x, int n ) {
	int i, j;
	for (i = 0; i < ( n - 1 ); i++)  {
		for (j = 0 ; j < n - i - 1; j++)  {
			if ( *(x+j)  > *(x+j+1) )
				swap( x+j, x+j+1);
		}
	}	
}

void sortq( int* x, int n ) {
	int i, j;
	int* p;
	for (i = 0; i < ( n - 1 ); i++)  {
		p = x;
		for (j = 0 ; j < n - i - 1; j++)  {
			if ( *p  > *(p+1) )
				swap( p, p+1);
			++p; //advance pointer to next
		}
	}
}```

```