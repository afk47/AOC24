#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int partOne();
int partTwo();

int main()
{
    printf("%d\n", partOne());
    printf("%d\n", partTwo());
    return 0;
}

int partOne()
{
    int output = 0;

    FILE *file = fopen("input.txt", "r");

    char line[2048];

    if (NULL == file)
        return -1;

    while (fgets(line, sizeof(line), file))
    {

        char *token = strtok(line, " ");
        char *endptr;

        long last = strtol(token, &endptr, 10);

        bool valid = true;

        int state = -1; // -1 undefined, 0 decreasing, 1 increasing
        while ((token = strtok(NULL, " ")) != NULL)
        {

            long curr = strtol(token, &endptr, 10);
            if (state == -1)
            {
                state = curr > last;
            }
            if (state == 0)
            {
                if (!(curr - last <= -1 && curr - last >= -3))
                {
                    valid = false;
                    break;
                }
            }
            else
            {
                if (!(curr - last <= 3 && curr - last >= 1))
                {
                    valid = false;
                    break;
                }
            }

            last = curr;
        }
        if (valid)
            output++;
    }

    fclose(file);
    return output;
}

int partTwo()
{
    int output = 0;

    return output;
}
