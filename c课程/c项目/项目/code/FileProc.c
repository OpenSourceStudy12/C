
/*
* Release info:
* Author: LiQiang
* Date: 
*/

/*include files*/
#include <stdio.h>


/*MACRO*/
#define MAX_LINE_LEN	128

/*local functions*/

/*
* func: read a line from a file
* param:
* return value:
*/
int get_line_from_file(int fd, char *line, int max_len)
{
	char *p = line;
	int bytes_read;
	int count = 0;

	
	while (1)
	{
		bytes_read = read(fd, p, 1);

		if (bytes_read == 0)
		{
			break;
		}

		if (*p == '\n')
		{
			break;
		}

		
		p ++;
		count ++;

		if (count >= max_len)
		{
			break;
		}
	}

	return bytes_read;
}


int del_space_from_line(char *buf)
{
	char *p = NULL;

	p = buf + strlen(buf) - 1;

	while (p >= buf)
	{
		if (*p == ' ')
		{
			*p = '\0';
		}

		p --;
	}

	*(p+1) = '\n';


	return -1;
}

int main(int argc, char **argv)
{
	int fdr, fdw;
	int ret;
	char line[MAX_LINE_LEN];


	/*open  src file*/
	fdr = open(argv[1], O_RDONLY);

	if (fdr == -1)
	{
		perror("open:");
		return -1;
	}

	/*open  dest file*/
	fdw = open(argv[2], O_WRONLY);

	if (fdw == -1)
	{
		perror("write:");
		return -1;
	}

	/*buffer init*/
	memset(line, 0, MAX_LINE_LEN);


	while (1)
	{
		/*read a line from src file*/
		ret = get_line_from_file(fdr, line, MAX_LINE_LEN);

		if (ret <= 0)
		{
			break;
		}

		/*delete the space from the line*/
		ret = del_space_from_line(line);

		/*write the line to dest file*/
		ret = write_line_to_file(fdw, line);
	}


}






