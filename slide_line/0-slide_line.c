#include "slide_line.h"

/**
 * slide_line - Slides and merges the line
 * @line: array of number
 * @size: size of the array
 * @direction: direction to slide to (left or right)
 * Return: 1 upon success or 0
 */
int slide_line(int *line, size_t size, int direction)
{
	if (!line || size <= 0)
		return (0);

	if (direction == SLIDE_LEFT)
		return (slide_left(line, size));

	return (slide_right(line, size));
}

/**
 * slide_left - Slides the line to the left
 * @line: array of number
 * @size: size of the array
 * Return: 1 upon success
 */
int slide_left(int *line, size_t size)
{
	size_t i, j;

	for (i = 0; i < size; i++)
	{
		if (line[i] == 0)
			continue;
		for (j = i + 1; j < size; j++)
		{
			/* Merges the numbers */
			if (line[j] == line[i])
			{
				line[i] *= 2;
				line[j] = 0;
				break;
			}
			else if (line[j] != 0)
				break;
		}
	}
	j = 0;
	/* Shifts the element one place to the left */
	for (i = 0; i < size; i++)
	{
		if (line[i] != 0)
			line[j++] = line[i];
	}
	/* Fills the remaining places with zeros */
	for (; j < size; j++)
		line[j] = 0;

	return (1);
}

/**
 * slide_right - Slides the line to the right
 * @line: array of number
 * @size: size of the array
 * Return: 1 upon success
 */
int slide_right(int *line, size_t size)
{
	size_t i, j;

	for (i = size - 1; i < size; i--)
	{
		if (line[i] == 0)
			continue;

		for (j = i - 1; j < size; j--)
		{
			/* Merges the numbers */
			if (line[j] == line[i])
			{
				line[i] *= 2;
				line[j] = 0;
				break;
			}
			else if (line[j] != 0)
				break;
		}
	}
	j = size - 1;
	/* Shifts the element one place to the right */
	for (i = size - 1; i < size; i--)
	{
		if (line[i] != 0)
			line[j--] = line[i];
	}
	/* Fills the remaining places with zeros */
	for (; j < size; j--)
		line[j] = 0;

	return (1);
}
