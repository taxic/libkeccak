/* See LICENSE file for copyright and license details. */
#include "hex.h"

#include <string.h>



/**
 * Convert a binary hashsum to lower case hexadecimal representation
 * 
 * @param  output   Output array, should have an allocation size of at least `2 * n + 1`
 * @param  hashsum  The hashsum to convert
 * @param  n        The size of `hashsum`
 */
void
libkeccak_behex_lower(char *restrict output, const char *restrict hashsum, size_t n)
{
	output[2 * n] = '\0';
	while (n--) {
		output[2 * n + 0] = "0123456789abcdef"[(hashsum[n] >> 4) & 15];
		output[2 * n + 1] = "0123456789abcdef"[(hashsum[n] >> 0) & 15];
	}
}


/**
 * Convert a binary hashsum to upper case hexadecimal representation
 * 
 * @param  output   Output array, should have an allocation size of at least `2 * n + 1`
 * @param  hashsum  The hashsum to convert
 * @param  n        The size of `hashsum`
 */
void
libkeccak_behex_upper(char *restrict output, const char *restrict hashsum, size_t n)
{
	output[2 * n] = '\0';
	while (n--) {
		output[2 * n + 0] = "0123456789ABCDEF"[(hashsum[n] >> 4) & 15];
		output[2 * n + 1] = "0123456789ABCDEF"[(hashsum[n] >> 0) & 15];
	}
}


/**
 * Convert a hexadecimal hashsum (both lower case, upper
 * case and mixed is supported) to binary representation
 * 
 * @param  output   Output array, should have an allocation size of at least `strlen(hashsum) / 2`
 * @param  hashsum  The hashsum to convert
 */
void
libkeccak_unhex(char *restrict output, const char *restrict hashsum)
{
	size_t n = strlen(hashsum) / 2;
	char a, b;
	while (n--) {
		a = hashsum[2 * n + 0];
		b = hashsum[2 * n + 1];

		a = (char)((a & 15) + (a > '9' ? 9 : 0));
		b = (char)((b & 15) + (b > '9' ? 9 : 0));

		output[n] = (char)((a << 4) | b);
	}
}
