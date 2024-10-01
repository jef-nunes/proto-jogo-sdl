#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char *bash_script_path = "./tools/rebuild.sh";
    char *args[3]; // Array for the arguments: script + possible parameters + NULL

    // Verify arguments
    if (argc < 2)
    {
        args[0] = bash_script_path; // First argument is the script
        args[1] = NULL; // No additional parameters
    }
    else
    {
        if (strcmp(argv[1], "run") == 0)
        {
            args[0] = bash_script_path;
            args[1] = argv[1]; // Add the "run" argument
            args[2] = NULL; // Terminate the argument list with NULL
        }
        else
        {
            fprintf(stderr, "Invalid argument: %s\n", argv[1]);
            return 1;
        }
    }

    // Execute script
    if (execv(args[0], args) == -1)
    {
        perror("Error calling the script");
        return 1;
    }

    return 0;
}
