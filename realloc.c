#include "shell.h"

/**
 * _memcpy - check code.
 * @destination: first pointer.
 * @src: second pointer.
 * @size: size memory.
 * Return: destination.
 */
void *_memcpy(void *destination, const void *src, size_t size)
{
	unsigned char *d = (unsigned char *)destination;
	const unsigned char *s = (const unsigned char *)src;
	size_t i;

	for (i = 0; i < size; i++)
	{
		d[i] = s[i];
	}

	return (destination);
}

/**
 * _getsize - check code.
 * @str: pointer.
 * Return: size.
 */
int _getsize(const char *str)
{
	int size = 0;

	while (str[size] != '\0')
	{
		size++;
	}
	return (size);
}

/**
 * _realloc - reallocate size of a pointer.
 * @ptr: pointer.
 * @size: memory size.
 * Return: new pointer.
 */
void *_realloc(void *ptr, size_t size)
{
	void *new_ptr;
	size_t old_size, copy_size;

	old_size = _getsize(ptr);
	copy_size = (old_size < size) ? old_size : size;
	new_ptr = malloc(size);
	if (new_ptr == NULL)
		return (NULL);
	new_ptr = _memcpy(new_ptr, ptr, copy_size);
	free(ptr);
	return (new_ptr);
}

