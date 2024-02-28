/**
 * containsSlash - seaech for parent dir
 * @str: pointer to characters
 * Return: int indicate to stat
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
