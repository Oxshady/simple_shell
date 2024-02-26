#include "main.h"
int _execve(char **vect,char **paths)
{
	char *single_path = NULL;
	char *command_path = NULL;
	int i = 0, ii = 0;
	int sta;
	int strle = 0;
	int stat = 0;

	if (!vect || !paths)
		return -1;
	if (vect[0])
	{
		while (vect[0][ii])
		{
			if (vect[0][ii] == '/')
			{	
				sta = 1;
				break;
			}
			else
				sta = 0;
			ii++;
		}
	}
	if (sta == 0)
	{
	for(i = 0; paths[i] != NULL;i++)
	{
		strle = strlen(paths[i]) - 1;
		if (paths[i][strle] == '/')
		{
			continue;
		}
		else
		{
			single_path = (char *)calloc(sizeof(char) , strlen(paths[i]) + 2);
			if (single_path == NULL)
				return 0;
			strcpy(single_path,paths[i]);
			strcat(single_path,"/");
			command_path = (char *) calloc(sizeof(char) , (strlen(single_path) + strlen(vect[0]) + 1));
			strcpy(command_path,single_path);
			strcat(command_path,vect[0]);
			if (execve(command_path,vect,NULL) == -1)
			{
				stat = 3;
				continue;
			}
			else
				break;
		}
		// printf("path[%i] = %s",i,single_path);
		free(single_path);
		single_path = NULL;
	}
	}
	else
	{
		if (execve(vect[0],vect, NULL) == -1)
			return -1;
	}
	
}
