#include "allocetor.h"
#include <malloc.h>

int main()
{
	void * heap=malloc(1000);
	MemoryAllocator* m=MemoryAllocator_init(heap,1000);
	printf("%ld\n", *((size_t*)heap-1)^1);
	void * tmp=MemoryAllocator_allocate(m,10);
	printf("%ld\n", *((size_t*)tmp-1)^1);
	void * tmp1=MemoryAllocator_allocate(m,17);
	printf("%ld\n", *((size_t*)tmp1-1)^1);
	void * tmp2=MemoryAllocator_allocate(m,5);
	printf("%ld\n", *((size_t*)tmp2-1)^1);
	void * tmp3=MemoryAllocator_allocate(m,5);
	printf("%ld\n", *((size_t*)tmp3-1)^1);
	void * tmp4=MemoryAllocator_allocate(m,30);
	printf("%ld\n", *((size_t*)tmp4-1)^1);
	MemoryAllocator_free(heap,m);
	printf("%ld\n", *((size_t*)tmp4-1));

	free(heap);
	return 0;
}
