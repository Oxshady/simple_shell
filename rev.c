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
		/*Swap characters at start and end indices*/
		char temp = buf[start];

		buf[start] = buf[end];
		buf[end] = temp;

		/*Move indices towards the center*/
		start++;
		end--;
	}
}
