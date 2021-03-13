#include <stdio.h>
#include "triangle.h"

int main(int argc, char **argv) {
	
    int n = 3;
	
    Triangle* ta[n];
	ta[0] = new_triangle(3,4,5);
	ta[1] = new_triangle(10,8,20);
	ta[2] = new_triangle(5.5,4.2,4.8);

    double total_area = 0;
	for(int i = 0; i < 3; i++)
		if (ta[i] != NULL) {
			total_area += tr_area( ta[i] );
			printf("%s", tr_string(ta[i]).c_str());		
		}
		else
			printf("Invalid Triangle\n");		
			
	printf("Total Area: %8.2lf\n", total_area);		

	//free storage
	for(int i = 0; i < 3; i++)
		del_triangle(ta[i]);

	return 0;
}