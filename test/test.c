#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[], char *env[]) {
	int i = 0;
	while (env[i])
	{
    	printf("%s\n", env[i]);
		i++;
	}
    return 0;
}
