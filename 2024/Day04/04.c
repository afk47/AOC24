#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int partOne(const char search[][256], const int length, const int width);
int partTwo(const char search[][256], const int length, const int width);
bool checkDirection(const char search[][256], const int sequence, const int x, const int y, const int dirX, const int dirY);

int main()
{

    FILE *file = fopen("input.txt", "r");

    char search[256][256];
    if (NULL == file)
        return -1;

    int i = 0;
    while (fgets(search[i], sizeof(search[i]), file))
    {
        i++;
    }
    if (ferror(file))
    {
        return ferror(file);
    }

    fclose(file);

    printf("Part One: %d\n", partOne(search, i, strlen(search[0])));
    printf("Part Two: %d\n", partTwo(search, i, strlen(search[0])));

    return 0;
}

int partOne(const char search[][256], const int length, const int width)
{
    int count = 0;
    for (int y = 0; y < length; y++)
    {
        for (int x = 0; x < width - 1; x++)
        {
            if (search[y][x] == 'X')
            {
                count += checkDirection(search, 0, x, y, 0, 1);
                count += checkDirection(search, 0, x, y, 0, -1);
                count += checkDirection(search, 0, x, y, 1, 1);
                count += checkDirection(search, 0, x, y, -1, -1);
                count += checkDirection(search, 0, x, y, 1, -1);
                count += checkDirection(search, 0, x, y, -1, 1);
                count += checkDirection(search, 0, x, y, 1, 0);
                count += checkDirection(search, 0, x, y, -1, 0);
            }
        }
    }
    return count;
}

bool checkDirection(const char search[][256], const int sequence, const int x, const int y, const int dirX, const int dirY)
{
    char next = 'X';
    bool nextInbounds = y + dirY <= 140 && x + dirX <= 140 && x + dirX >= 0 && y + dirY >= 0;
    switch (sequence)
    {
    case 0:
        next = 'M';
        break;
    case 1:
        next = 'A';
        break;
    case 2:
        next = 'S';
        break;
    case 3:
        return true;
        break;
    default:
        return false;
    }
    if (nextInbounds && search[y + dirY][x + dirX] == next)
    {
        return checkDirection(search, sequence + 1, x + dirX, y + dirY, dirX, dirY);
    }
    return false;
}

int partTwo(const char search[][256], const int length, const int width)
{
    int count = 0;
    for (int y = 0; y < length; y++)
    {
        for (int x = 0; x < width - 1; x++)
        {

            if (search[y][x] == 'M')
            {
                if (checkDirection(search, 1, x, y, 1, 1))
                {
                    if (search[y + 2][x] == 'M' && search[y][x + 2] == 'S')
                    {
                        count++;
                    }
                    if (search[y][x + 2] == 'M' && search[y + 2][x] == 'S')
                    {
                        count++;
                    }
                }
                if (checkDirection(search, 1, x, y, -1, -1))
                {
                    if (search[y - 2][x] == 'M' && search[y][x - 2] == 'S')
                    {
                        count++;
                    }
                    if (search[y][x - 2] == 'M' && search[y - 2][x] == 'S')
                    {
                        count++;
                    }
                }
            }
        }
    }
    return count;
}