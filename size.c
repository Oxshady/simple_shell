 #include "main.h"
 int handle(char **tokens,int *status,int *sa,char **envp)
 {
	char buffer[20];
  if (strcmp(tokens[0], "exit") == 0)
        {
            *status = _exitt(tokens);
            if (*status == 0)
                _exit(0);
            else if (*status > 0)
            {
                int length = sprintf(buffer, "%d\n", *status);
                write(STDOUT_FILENO, buffer, length);
                return (*status);//_exit(*status);
            }
            else if (*status == -1)
            return (-1);	//_exit(-1);
        }
        else if (strcmp(tokens[0], "export") == 0)
        {
            sa = 0;
            setenv_unset(tokens, *sa);
            return (-2); // -2
        }
        else if (strcmp(tokens[0], "unset") == 0)
        {
            *sa = 1;
            setenv_unset(tokens, *sa);
            return (-2); // -2
        }
        else if (strcmp(tokens[0], "cd") == 0)
        {
            _chdir(tokens);
            return (-2); // -2
        }
        else if (strcmp(tokens[0], "env") == 0)
        {
            _get_env(envp);
            return (-2); // -2
        }
		else
		{
			return (-3);
		}
		
}