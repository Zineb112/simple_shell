#include "shell.h"
#include <string.h>

/**
 * _realloc – reallocate size of a pointer.
 *
 * Description: 'resize a pointer ptr'.
 *
 * @ptr: pointer to change size.
 * @size: old size of ptr.
 *
 * Return: new pointer.
 */


void *_realloc(void *ptr, size_t size)
{
	void *new_ptr;
	size_t old_size, copy_size;

	old_size = get_size(ptr);
	copy_size = (old_size < size) ? old_size : size;
	new_ptr = malloc(size);
	if (new_ptr == NULL)
		return (NULL);
	new_ptr = memcpy(new_ptr, ptr, copy_size);
	free(ptr);
	return (new_ptr);
}

