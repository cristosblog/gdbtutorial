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

/* Listing 4. Non-trivial types example */
/* Cristos' Blog - http://cristos.x25.pl */

#include <stdio.h>
#include <stdlib.h>

#define MAX_STR_LEN (40)
#define MAX_ARR_LEN (4)

union the_union {
	unsigned int dword;
	unsigned short word;
	unsigned char byte;
};

struct floating_point {
	float singleprec;
	double doubleprec;
};

struct nice_struct {
	union the_union uni_data;
	double realvalue;
	char string[MAX_STR_LEN];
	struct floating_point fpdata;
};

int main(int argc, char* argv[])
{
	struct nice_struct* ns_arr;
	ns_arr = malloc(MAX_ARR_LEN*sizeof(struct nice_struct));

	for (int i=0; i < MAX_ARR_LEN; i++) {
		ns_arr[i].uni_data.dword = 0xFFFFFF00 + i;
		ns_arr[i].fpdata.doubleprec = i + 0.123456789;
		ns_arr[i].fpdata.singleprec = 2.0f*i + 0.666f;
		ns_arr[i].realvalue = i * 0.0002;
		snprintf(ns_arr[i].string, MAX_STR_LEN, "This is object no. %d", i);
	}

	struct nice_struct nss[MAX_ARR_LEN];
	for (int i=0; i < MAX_ARR_LEN; i++) {
		nss[i].uni_data.byte = i;
		nss[i].fpdata.doubleprec = i * 0.24680246;
		nss[i].fpdata.singleprec = i * 0.1f;
		nss[i].realvalue = nss[i].fpdata.doubleprec * nss[i].fpdata.singleprec;
		snprintf(nss[i].string, MAX_STR_LEN, "This is array index no %d", i);
	}

	free(ns_arr);
	
	return 0;
}


