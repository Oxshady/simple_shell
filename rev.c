/**
 * revstr - Reverses a string
 * @buf: The string to reverse
 * @i: The length of the string
 */
void revstr(char *buf, int i)
{
	int start = 0;
	int end = i - 1;

	while (start < end)
	{
		char temp = buf[start];

		buf[start] = buf[end];
		buf[end] = temp;
		start++;
		end--;
	}
}
