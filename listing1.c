/* 
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* Listing 1. Basic program */
/* Cristos' Blog - http://cristos.x25.pl */

#include <stdio.h>
#include <stdlib.h>

void calculateFoo(double *arr, int size, int val);

int main(int argc, char* argv[])
{
	if (argc < 3)
		return EXIT_FAILURE;

	int a = atoi(argv[1]);
	int b = atoi(argv[2]);

	double *foo = NULL;
	if (b > 0) {
		foo = (double*) malloc(b * sizeof(double));
		if (!foo) {
			printf("Memory allocation error\n");
			return 2;
		}
	}
	else
		return 3;

	calculateFoo(foo, b, a);

	free(foo);

	return EXIT_SUCCESS;
}

void calculateFoo(double *arr, int size, int val)
{
	for (int i=0; i < size; i++) {
		
		arr[i] = (i * val)/6.67;
	}
}
