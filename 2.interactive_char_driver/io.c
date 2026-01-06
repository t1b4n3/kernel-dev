#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
	char *buf1;
	int fd;

	buf1 = malloc(0x20);
	fd = open("/dev/cdev", O_RDWR);
	read(fd, buf1, 0x18);
	printf("BUF: %s\n", buf1);
	
	sprintf(buf1, "Hello kernelspace");

	write(fd, buf1, strlen(buf1));
	free(buf1);
	return 0;
}
