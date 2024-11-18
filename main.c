#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <unistd.h>

int main()
{
    int fd = open("a.txt", O_RDWR);

    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));

}
