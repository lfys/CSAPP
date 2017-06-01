#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	struct stat statp;
	char *type, *readok;

	stat(argv[1], &statp);
	if(S_ISREG(statp.st_mode))
	    type = "regular";
	else if(S_ISDIR(statp.st_mode))
	    type = "directory";
	else
		type = "other";
	if((statp.st_mode & S_IRUSR))
		readok = "yes";
	else
		readok = "no";

	printf("type: %s, read: %s\n", type, readok);
	exit(0);
}
