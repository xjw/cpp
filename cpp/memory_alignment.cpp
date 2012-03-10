#include <iostream>
#include <assert.h>

using namespace std;

/*
 * http://stackoverflow.com/questions/227897/solve-the-memory-alignment-in-c-interview-question-that-stumped-me
 * Q: How would you allocate 1024 bytes of memory, and align it to a 16 byte boundary?
 * and free after allocate
 * http://jongampark.wordpress.com/2008/06/12/implementation-of-aligned-memory-alloc/
 */

void * memset_16aligned() {
    /* allocate a buffer with room to add 0-15 bytes to ensure 16-alignment*/
    void *mem = malloc(1024+15);
    assert(mem); // some kind of error handling
    /* round up to multiple of 16, add 15 and round down by masking*/
    void *ptr = (void *)(((unsigned long)mem + 15) & ~0x0f);

    // free memory
    free(mem);
}

/*
 * For more generic memeory allocation function, without tracking two pointer
 * one to use (ptr) and one to free (mem)
 * idea is to store a pointer which points to real buffer below the aligned buffer
 */
void * aligned_malloc(size_t size, int align) {
    // alignment could not be less than 0
    if (size<0) {
        return NULL;
    }
    // allocate necessary memory for 
    // requested size +
    // alignment +
    // area to store the address of memory returned by malloc
    void *p = malloc(size + align-1 + sizeof(void *));
    if (p == NULL) {
        return NULL;
    }
    // address of the aligned memory according to the align parameter
    void *ptr = (void *) (((unsigned long)p + sizeof(void *) + align-1) & ~(align-1));

    // store th address of mallc() above at the beginning of our total memory area
    *((void **)ptr -1) = p;

    // return the address of aligned memory
    return ptr;
}

void aligned_free(void *p) {
    // Get address of the memory from start of total memory area
    free ( *( (void **)p - 1) );
}

int main() {
    void * ptr = aligned_malloc(10, 4);
    printf("aligned address %ld \n", (unsigned long)ptr);
    aligned_free(ptr);
    return 1;
}
