#include "input_mgmt.h"

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

int main(int argc, char **argv)
{
    int     opt;
    char    *mode = NULL;
    int     fromvert = 1;
    int     tovert = 10; // do ustawienia -1 wiele rzeczy później
    char    *filename = NULL;
    double  fromrange = 0;
    double  torange = 1;
    int     rows = 4;
    int     columns = 4;

    char    *progname = argv[0];

    while((opt = getopt(argc, argv, "h:m:f:t:s:n:r:y:z:c:")) != -1)
    {
        switch (opt)
        {
            case 'h':
                view_help(progname);
                break;
            case 'm':
                mode = optarg;
                break;
            case 'f':
                fromvert = atoi(optarg);
                break;
            case 't':
                tovert = atoi(optarg);
                break;
            case 'n':
                filename = optarg;
                break;
            case 'y':
                fromrange = atof(optarg);
                break;
            case 'z':
                torange = atof(optarg);
                break;
            case 'c':
                columns = atof(optarg);
                break;
            case 'r':
                rows = atof(optarg);
                break;
        }
    }

    input_errors_management(mode, fromvert, tovert, filename, fromrange, torange, progname, rows, columns);

    if(strcmp(mode, "read") == 0)
    {
        FILE *inf = fopen(filename, "r");
        if(inf == NULL)
        {
            printf("Could not open file \"%s\".\n", filename);
            exit(EXIT_FAILURE);
        }
    }
    else if(strcmp(mode, "write") == 0)
    {
        FILE *ouf = fopen(filename, "w");
        if(ouf == NULL)
        {
            printf("Could not create file \"%s\".\n", filename);
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}