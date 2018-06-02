
int check_int(char *line)
{
	char *p = line;
	int flag = 0;


	while (*p != '\0')
	{
		if ('0' <= *p <= '9')
		{
		}
		else
		{
			return -1;
		}
	}

	return 0;
}


scanf("%s", name);
my_get_line(name, 128);

/*get a line*/
int my_get_line(char *line, unsigned int MaxLen)
{
	char *p = line;
	unsigned int counter = 0;
	
	while (1)
	{
		*p = getchar();
		counter ++;

		if (counter >= MaxLen)
		{
			printf();

			/*clear*/
			while (getchar() != '\n')
			{
			}

			memset(line, 0, MaxLen);
			return -1;
		}

		if (*p == '\n')
		{
			break;
		}
		else
		{
			p ++;
		}
	}
}



