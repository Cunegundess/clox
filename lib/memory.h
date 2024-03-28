#ifndef clox_memory_h
#define clox_memory_h

#include "common.h"

#define GROW_CAPACITY(capacity) \
  ((capacity) < 8 ? 8 : (capacity) * 2)

#define GROW_ARRAY(type, pointer, oldCount, newCount) \
  (type*)reallocate(pointer, sizeof(type) * (oldCount), \
    sizeof(type) * (newCount))

#define FREE_ARRAY(type, pointer, oldCount) \
  reallocate(pointer, sizeof(type) * (oldCount), 0)

/* 
    The two arguments passed to reallocate() control which operation to perform
 
    oldSize    |          newSize           |   Operation
       0       |          Non-Zero          |   Allocate new block
    Non-Zero   |             0              |   Free Allocation
    Non-Zero   |    Smaller than oldSize    |   Shrink existing allocation
    Non-Zero   |    Larger than oldSize     |   Grow existing allocation
*/

void* reallocate(void* pointer, size_t oldSize, size_t newSize);

#endif
