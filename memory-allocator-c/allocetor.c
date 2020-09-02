#include "allocetor.h"
#include <stdio.h>
#include <malloc.h>
#define ALIGNMENT 8 
#define LSD 1 
struct MemoryAllocator{
    size_t m_meta_data;
    void * m_ptr_to_data;
};
/* -------------------------------- EZER FUNCTION----------------------------*/
bool isHeapFinish(MemoryAllocator* allocator,void* startBlock);
bool isFree(void * block);
bool  isBlockEnough(MemoryAllocator* allocator,void* startBlock,size_t size)
{
	if(isHeapFinish(allocator,startBlock))
	{
		return false;
	}
	if((*(size_t*)startBlock)>=size)
	{
		return true;	
	}
	if(isFree((char*)startBlock+*(size_t*)startBlock))
	{
		(*(size_t*)startBlock)+=*(size_t*)((char*)startBlock+(*(size_t*)startBlock));
		isBlockEnough(allocator,startBlock,size);
	
	}	
	return false;	

}
bool isHeapFinish(MemoryAllocator* allocator,void* startBlock)
{
	return (startBlock>(allocator->m_ptr_to_data+allocator->m_meta_data))?true:false;
}
bool isFree(void * block)
{
	return (*(size_t*)block)&LSD?false:true;
}
void allocateBlock(size_t * block,size_t size)
{
	size_t save = *block;
	*block = size;
	if (save != size)
	{
		*(block + size) = save - size;
	}
	(*block)++;//to change the status: allocate
}
/*---------------------------------------------------------------------------*/


MemoryAllocator* MemoryAllocator_init(void * memoryPool, size_t size)
{
	size+=sizeof(size_t);
	 MemoryAllocator* heap=(MemoryAllocator*)malloc(sizeof(MemoryAllocator));
	 heap->m_meta_data=size;
	 heap->m_ptr_to_data=memoryPool;
	 *(size_t*)memoryPool=size;
	 
	 return heap;
	
}

void * MemoryAllocatorRelase(MemoryAllocator* allocator)
{
    free(allocator);
}

void * MemoryAllocator_allocate(MemoryAllocator*  allocator,size_t size)
{
	size_t* currBlock=allocator->m_ptr_to_data;
	size +=(ALIGNMENT-(size %  ALIGNMENT))%ALIGNMENT;
	while(!isHeapFinish(allocator,currBlock))
	{
		if(isFree(currBlock))
		{
			if(isBlockEnough(allocator,currBlock,size))
			{
				allocateBlock(currBlock,size);	
				return currBlock+1;
			}		
		}
		currBlock+=(*currBlock|LSD)-1;
		//currBlock-=1;

			
	}
	return NULL;
}

void MemoryAllocator_free(MemoryAllocator* allocator,void * ptr)
{
	
	*(size_t*)ptr^=LSD;
	if((*((char*)ptr+*(size_t*)ptr))^LSD)
	{
		*(size_t*)ptr+=*((char*)ptr+*(size_t*)ptr);
	}
}

size_t MemoryAllocetor_optimize(MemoryAllocator* allocator)
{
	void* currBlock=allocator->m_ptr_to_data;
	size_t max=0;
	while(!isHeapFinish(allocator,currBlock))
	{
		if((*(size_t*)currBlock)^LSD)
		{
			isBlockEnough(allocator,currBlock,allocator->m_meta_data);
			if(max<(*(size_t*)currBlock))
			{
				max=*(size_t*)currBlock;
			}
		}
		currBlock+=*(size_t*)currBlock;
	}
	return max;
}
