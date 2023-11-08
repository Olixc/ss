#include "shell.h"
#define BUFSIZE 1024

char *_getline(int file) ;
void _memset(char *str, int fill, int n);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

char *_getline(int file)
{
	unsigned int i, index = 0;
	char *buffer;
	static unsigned int buffer_size = BUFSIZE;

	buffer = malloc(sizeof(char) * buffer_size);
	if (buffer == NULL)
	{
		perror("malloc for buffer failed\n");
		return (NULL);
	}
	_memset(buffer, '\0', buffer_size);

	while (1)
	{
		i = read(file, buffer + index, buffer_size - index);
		if (i < (buffer_size - index))
			return (buffer);
		buffer_size *= 2;
		_realloc(buffer, buffer_size, buffer_size / 2);
		if (buffer == NULL)
		{
			perror("realloc failed\n");
			return (NULL);
		}
		index += i;
	}
	if (i == 0)
		_memcpy(buffer, "exit", 5);
	return (buffer);
}

int main()
{
	char *input = NULL;
	/*size_t size = 0;*/
	ssize_t chars_read;

	input = _getline(STDIN_FILENO);

	if (input == NULL)
	{
		printf("Error reading input\n");
	}
	else
	{
		printf("Input: %s\n", input);
		chars_read = strlen(input);
		printf("Characters read: %ld\n", chars_read);
	}

	free(input);
	return 0;
}

void _memset(char *str, int fill, int n)
{
	int i;

	for (i = 0; i < n; i++)
		str[i] = fill;
}

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++) /* copy each byte from src to dest */
	{
		*(dest + i) = *(src + i);
	}

	return (dest);
}

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *p;
	unsigned int i;

	if (new_size == 0 && ptr != NULL) /* free memory if reallocate 0 */
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size) /* return ptr if reallocating same old size */
		return (ptr);

	if (ptr == NULL) /* malloc new size if ptr is originally null */
	{
		p = malloc(new_size);
		if (p == NULL)
			return (NULL);
		else
			return (p);
	}

	p = malloc(new_size); /* malloc and check error */
	if (p == NULL)
		return (NULL);

	/* fill up values up till minimum of old or new size */
	for (i = 0; i < old_size && i < new_size; i++)
		*((char *)p + i) = *((char *)ptr + i);
	free(ptr); /* free old ptr */

	return (p);
}
