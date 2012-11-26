#include <stdio.h>
#include "xz_private.h"

int main() 
{
	struct xz_dec_lzma2 *l = xz_dec_lzma2_create(XZ_SINGLE, 4096);
	struct xz_buf b = {};
	FILE *fp;
	char inbuf[2048];
	char outbuf[2048];

	fp = fopen("out.xz", "rb");
	b.in = inbuf;
	b.in_size = fread(inbuf, 1, sizeof(inbuf), fp);
	b.out = outbuf;
	b.out_size = sizeof(outbuf);

	printf("insize:%d\n", b.in_size);
	printf("run\n");
	xz_dec_lzma2_run(l, &b);
	printf("inpos:%d\n", b.in_pos);
	printf("outpos:%d\n", b.out_pos);
	printf("%s\n", outbuf);

	return 0;
}

