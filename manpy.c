#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int BUFSIZE = 1024;

int main(int argc, char** argv) {

    char *cmd;
    char *module;
    char *object;
    char *temp;
    
    int c, n;

    if (argc < 2) {
        printf("Too few arguments provided.\nUsage: manpy <module> <object>\n");
        return 1;
    } else if (argc > 3) {
        printf("Too many arguments provided.\nUsage: manpy <module> <object>\n");
        return 1;
    }

    module = (char *) malloc(BUFSIZE/2);
    strncpy(module, argv[1], BUFSIZE/2);
    
    if (argc == 2) {
        object = module;
    } else {
        object = (char *) malloc(BUFSIZE/2);
        strncpy(object, argv[2], BUFSIZE/2);
        n = strlen(module);
        c = strncmp(module, object, n);
        if (c != 0) {
            temp = (char *) malloc(BUFSIZE/2);
            snprintf(temp, n + strlen(object) + 2, "%s.%s", module, object);
            free(object);
            object = temp;
        }
    }

    cmd = (char *) malloc(BUFSIZE/2);
    snprintf(cmd, BUFSIZE, "python -Ic \"import %s; print(%s.__doc__)\" | less\n",
        module, object); 

    system(cmd);
}
