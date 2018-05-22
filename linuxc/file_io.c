#include "define.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void write_()
{
	if(write(1, "some data\n", 10) != 10)
	{
		write(2, "error", 5);
	}
}

void read_write_()
{
	char buf[128];
	char msg[128];
	int nread;

	nread = read(0, buf, 128); //read from std input
	if(nread == -1)
	{
		strcpy(msg, "read error");
		write(2, msg, strlen(msg));
	}

	if(write(1, buf, nread) != nread) //write to std output
	{
		strcpy(msg, "write error");
		write(2, msg, strlen(msg));
	}
}