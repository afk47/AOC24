#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int partOne();
int partTwo();

int main()
{

    FILE *file = fopen("input.txt", "r");

    char line[256];
    if (NULL == file)
        return -1;

    while (fgets(line, sizeof(line), file))
    {
    }
    fclose(file);

    printf("Part One: %d\n", partOne());
    printf("Part Two: %d\n", partTwo());

    return 0;
}