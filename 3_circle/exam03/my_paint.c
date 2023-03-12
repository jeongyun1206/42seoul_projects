#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>

#define ERROR 1
#define SUCCESS 0

typedef struct draw_info
{
    int width;
    int height;
    char    *bg_char;
    char    *field;
}   t_draw_info;

typedef struct circle
{
    char    type;
    float   x;
    float   y;
    float   radius;
    char    circle_char;
}   t_circle;

int error_message_op_file_corrupted(void)
{
    write(1, "Error: Operation file corrupted\n", ft_strlen("Error: Operation file corrupted\n"));
    return (ERROR);
}

int get_d_info(FILE *file, t_draw_info *d_info)
{
    int scanf_rtn;

    scanf_rtn = fscanf(file, "%d %d %c\n", d_info->width, d_info->height, d_info->bg_char);
    if (scanf_rtn != 3)
        return (ERROR);
    d_info->field = (char *)malloc(sizeof(char) * d_info->width * d_info->height);
    if (!d_info->field)
        return (ERROR);
}

int main(int argc, char **argv)
{
    FILE    *file;
    t_circle    circle_info;
    t_draw_info d_info;

    if (argc != 2)
    {
        write(1, "Error: argument\n", 16);
        return (ERROR);
    }
    file = fopen(argv[1], "r");
    if (!file)
        return (error_message_op_file_corrupted());
    if (get_d_info(file, &d_info) == ERROR)
        return (error_message_op_file_corrupted());
    while (fscanf("%c %f %f %f %c", circle_info.type))
    {
        draw_circle(file, &d_info);
    }
}