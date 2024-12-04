#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool lineSafe(int *line, int length);
bool lineSafeDamp(int *line, int length);

int main()
{
    int partOne = 0;
    int partTwo = 0;

    FILE *file = fopen("input.txt", "r");

    char line[1000];
    int numbers[100];

    if (NULL == file)
        return -1;

    while (fgets(line, sizeof(line), file))
    {
        int length = 0;
        char *token = strtok(line, " ");
        while (token != NULL)
        {
            numbers[length++] = atoi(token);
            token = strtok(NULL, " ");
        }

        if (lineSafe(numbers, length))
        {
            partOne++;
            partTwo++;
        }
        else if (lineSafeDamp(numbers, length))
        {
            partTwo++;
        }
    }
    fclose(file);

    printf("Part One: %d\nPart Two: %d\n", partOne, partTwo);

    return 0;
}

bool lineSafe(int *line, int length)
{
    bool allinc = true;
    bool alldec = true;
    for (int i = 0; i < length - 1; i++)
    {
        int diff = line[i + 1] - line[i];
        if (diff < 1 || diff > 3)
            allinc = false;
        if (diff > -1 || diff < -3)
            alldec = false;
    }

    return allinc || alldec;
}

bool lineSafeDamp(int *line, int length)
{
    for (int i = 0; i < length; i++)
    {
        int newline[100];
        int idx = 0;
        for (int j = 0; j < length; j++)
        {
            if (j != i)
            {
                newline[idx++] = line[j];
            }
        }
        if (lineSafe(newline, length - 1))
        {
            return true;
        }
    }
    return false;
}
