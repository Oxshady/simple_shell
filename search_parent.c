/**
 * containsSlash - check contain slash or not
 * @str: pointer to characters
 * Return: one if there is slash zero if not
*/
int containsSlash(char *str)
{
	int i = 0;

	if (!str)
		return (-1);

	i = 0;
	while (str[i])
	{
		if (str[i] == '/')
			return (1);
		i++;
	}
	return (0);
}
