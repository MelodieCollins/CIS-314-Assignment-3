#include <stdio.h>
#include <stdlib.h>

long f(long x, long y, long z) {
	//assume x is in %rdi, y is in %rsi, z is in %rdx
	//%rax holds return value
	
	//addq %rsi, %rdx
	z = y+z;
	//imulq %rdx, %rdi
	x = z*x;
	//salq $63, %rdx
	z = z<<63;
	//sarq $63, %rdx
	z = z>>63;
	//movq %rdi, %rax
	long value = x;
	//xorq %rdx, %rax
	value = value^z;

	return value;
}

int main() {
	printf("f(%ld, %ld, %ld): %ld\n", 1L, 2L, 4L, f(1L,2L,4L)); //6
	printf("f(%ld, %ld, %ld): %ld\n", 3L, 5L, 7L, f(3L,5L,7L)); //36
	printf("f(%ld, %ld, %ld): %ld\n", 10L, 20L, 30L, f(10L,20L,30L)); //500
}
