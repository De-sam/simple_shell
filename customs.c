#include "main.h"
/**
 * str_cmp - Compare two strings in alphabetical order
 * @string1: The first string as an argument to compare
 * @string2: The second string as an argument to compare
 *
 * The function compares two strings, @string1 and @string2, lexicographically.
 * It returns an integer value indicating their relationship:
 *  - 0 if both strings are equal
 *  - a negative value if @string1 is lexicographically smaller than @string2
 *  - a positive value if @stsring2 is lexicographically smaller than @string1
 *
 * Return: The comparison result as described above.
 */


int str_cmp(const char *string1, const char *string2)
{
	while (*string1 != '\0' && *string2 != '\0')
	{
		if (*string1 < *string2)
		{
			return (-1);
		}
		else if (*string1 > *string2)
		{
			return (1);
		}
		string1++;
		string2++;
	}

	if (*string1 == '\0' && *string2 == '\0')
	{
		return (0);
	}
	else if (*string1 == '\0')
	{
		return (-1);
	}
	else
	{
		return (1);
	}
}
#include "main.h"

/**
 *str_cat - a function that concatenates two strings
 *@dest: String that will be appended
 *@src: String to be concatenated
 * Return: returns poiner to @dest
 */

char *str_cat(char *dest, char *src)
{

	int index = 0, dest_length = 0;

	while (dest[index++])
		dest_length++;

	for (index = 0; src[index]; index++)
		dest[dest_length++] = src[index];

	return (dest);
}
#include "main.h"

/**
 *str_len - returns the length of a string
 *@s: is the parameter
 *Return: the string length
 */

size_t str_len(const char *s)
{
	size_t length = 0;

	while (*s++)
	{
		length++;
	}
	return (length);
}

