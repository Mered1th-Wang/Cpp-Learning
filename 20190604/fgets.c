#include <func.h>

int main()
{
    FILE * fp = fopen("test", "r");
    char buf[1000] = {0};
    fgets(buf, 100, fp);
    printf("buf = %s\n", buf);
    return 0;
}

