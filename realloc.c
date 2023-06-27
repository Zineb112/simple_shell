#include "shell.h"

/**
 * _getsize – reallocate size of a pointer.
 *
 * Description: 'resize a pointer ptr'.
 * @src: pointer to change size.
 * @destination: pointer to change size.
 * @size: pointer to change size.
 * Return: new pointer.
 */
void *_memcpy(void *destination, const void *src, size_t size) {
	unsigned char *d = (unsigned char *)destination;
	const unsigned char *s = (const unsigned char *)src;

	for (size_t i = 0; i < size; i++)
	{
		d[i] = s[i];
	}

	return (destination);
}

/**
 * _getsize – reallocate size of a pointer.
 *
 * Description: 'resize a pointer ptr'.
 *
 * @ptr: pointer to change size.
 *
 * Return: new pointer.
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

	old_size = _getsize(ptr);
	copy_size = (old_size < size) ? old_size : size;
	new_ptr = malloc(size);
	if (new_ptr == NULL)
		return (NULL);
	new_ptr = _memcpy(new_ptr, ptr, copy_size);
	free(ptr);
	return (new_ptr);
}

