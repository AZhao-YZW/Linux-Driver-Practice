#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int val = 1;

    int fd = open("/dev/mydev", O_RDWR);

    write(fd, &val, sizeof(val));

    read(fd, &val, sizeof(val));

    return 0;
}
