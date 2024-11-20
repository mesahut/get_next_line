#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "get_next_line_bonus.h"
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int fx = open("a.txt", O_CREAT | O_RDONLY, 0777);
    char *s1;
    char *s2;
    char *s3;
    char *s4;
    char *s5;

    s1 = get_next_line(fx);
    s2 = get_next_line(fx);
    s3 = get_next_line(fx);
    s4 = get_next_line(fx);
    s5 = get_next_line(fx);
    printf("%s", s1);
    printf("%s", s2);
    printf("%s", s3);
    printf("%s", s4);
    printf("%s", s5);

    free(s1);
    free(s2);
    free(s3);
    free(s4);
    free(s5);
}
