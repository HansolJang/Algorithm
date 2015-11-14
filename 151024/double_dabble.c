#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

namespace {
	char *_Table = "0123456789" \
	"abcdefghijklmnopqrstuvwxyz" \
	"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
}
/*
This function takes an array of n unsigned _Ty,
each holding a value in the range [0, 4294967295],
representing a number in the range [0, 2**(32n)-1].
CAUTION!!! _Ty MUST BE UNSIGNED!!! NOT SIGNED!!!
arr[0] is the most significant "digit".
This function returns a new array containing the given
number as a string of arbitrary radix digits.
For the sake of brevity, this example assumes that
malloc, calloc and realloc will never fail.
*/
template <typename _Ty>

void double_dabble(int n, const _Ty *arr, char **result, int radix = 10)
{
	int sarr = sizeof(_Ty) << 3; /* length of arr type in bits */
	int nbits = sarr*n; /* length of arr in bits */
	int nscratch = int(ceil(nbits*log10(double(2))/log10(double(radix)))); /* length of scratch in bytes */
	char *scratch = (char*)calloc(1 + nscratch, sizeof( *scratch ));
	int i, j, k, bits;
	int smin = nscratch - 1; /* speed optimization */
	int bound = radix >> 1; /* boundary of adding carry */
	int carry = (0x100 - radix) >> 1;
	char **isadd;
	if (radix & 1) /* if Odd radix */
	{
		isadd = (char**)malloc(nscratch << 2);
		bound += 1;
	}
	for (i=0; i < n; ++i) {
		bits = sarr;
		while (bits--) {
	/* This bit will be shifted in on the right. */
			int shifted_in = (arr[i] & (1 << bits))? 1: 0;
	/* Add carry everywhere that scratch[k] >= bound. */
			if (radix & 1) /* if Odd radix, save added scratch[j]'s address */
			{
				k = 0;
				for (j=smin; j < nscratch; ++j)
				{
					if (scratch[j] >= bound)
					{
						scratch[j] += carry;
						isadd[k++] = &scratch[j];
					}
				}
			}
			else /* if Even radix, just adding */
			{
				for (j=smin; j < nscratch; ++j)
					if (scratch[j] >= bound)
						scratch[j] += carry;
			}
	/* Shift scratch to the left by one position. */
			if (scratch[smin] & 0x80)
				smin -= 1;
			for (j=smin; j < nscratch - 1; ++j) {
				scratch[j] <<= 1;
				if (scratch[j+1] & 0x80)
					scratch[j] |= 1;
			}
/* Shift in the new bit from arr. */
			scratch[nscratch-1] <<= 1;
			scratch[nscratch-1] |= shifted_in;
/* If Odd raix, there is a difference from even radix. */
			if (radix & 1)
			{
				while (k)
					++(*isadd[--k]);
				for (j = nscratch - 1; j >= smin; --j)
				{
					if (scratch[j] >= radix)
					{
						scratch[j] -= radix;
						for (k = j - 1; ; --k)
						{
							if (++scratch[k] != 0)
								break;
						}
					}
				}
				if (j == smin - 1 && scratch[j] != 0) smin--;
			}
		}
	}
		/* Remove leading zeros from the scratch space. */
	for (k=0; k < nscratch-1; ++k)
		if (scratch[k] != 0) break;
	nscratch -= k;
	memmove(scratch, scratch+k, nscratch+1);
	/* Convert the scratch space using _Table. */
	for (k=0; k < nscratch; ++k)
		scratch[k] = _Table[scratch[k]];
	/* Resize and return the resulting string. */
	*result = (char*)realloc(scratch, nscratch+1);
	if (radix & 1)
		free(isadd);
	return;
}
/*
 This test driver should print the following decimal values:
 246
 16170604
 1059756703745
 246
 1056562003564
 4537899251503615442945
 Hello
*/
 int main(void)
 {
 	unsigned short arr[] = { 246, 48748, 1 };
 	char *text = NULL;
 	int i;
 	for (i=0; i < 3; ++i) {
 		double_dabble(i+1, arr, &text);
 		printf("%s\n", text);
 		free(text);
 	}
 	unsigned int brr[] = { 246, 48748, 1 };
 	for (i=0; i < 3; ++i) {
 		double_dabble(i+1, brr, &text);
 		printf("%s\n", text);
 		free(text);
 	}
 	unsigned int b = 598628343;
 	double_dabble(1, &b, &text, 61);
 	printf("%s
 		\n", text);
 	free(text);
 	return 0;
 }