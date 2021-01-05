#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char **argv)
{

    time_t rawtime;
    struct tm *timeinfo;
    char buffer [128];

    if (argc == 1) {
        rawtime = time(&rawtime);
        timeinfo = localtime (&rawtime);
        strftime (buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
        printf("%lu -> %s\n", rawtime, buffer);
        return 0;
    }

    if (argc != 2) {
        printf("Usage: \n  td 1609830795");
        return 0;
    }

    if (strlen(argv[1]) != 9 && strlen(argv[1]) != 10) {
        printf("WARNING: timestamp formart incorrect, length = %lu", strlen(argv[1]));
        return 0;
    }

    rawtime = (unsigned int) atoi(argv[1]);
    timeinfo = localtime (&rawtime);
    strftime (buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
    printf("%s\n", buffer);
    return 0;
}