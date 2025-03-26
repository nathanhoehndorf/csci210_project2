#include <libgen.h>
#include "types.h"

extern struct NODE* root;
extern struct NODE* cwd;

//make directory
void mkdir(char pathName[]){

    // TO BE IMPLEMENTED
    //
    // YOUR CODE TO REPLACE THE PRINTF FUNCTION BELOW

    

    return;
}

//handles tokenizing and absolute/relative pathing options
struct NODE* splitPath(char* pathName, char* baseName, char* dirName){

    // TO BE IMPLEMENTED
    // NOTE THAT WITHOUT COMPLETING THIS FUNCTION CORRECTLY
    // rm, rmdir, ls, cd, touch COMMANDS WILL NOT EXECUTE CORRECTLY
    // SEE THE PROVIDED SOLUTION EXECUTABLE TO SEE THEIR EXPECTED BEHAVIOR

    // YOUR CODE HERE
    char temp[128];
    strcpy(temp, pathName);
    strcpy(dirName, dirname(temp));
    strcpy(temp, pathName);
    strcpy(baseName, basename(temp));
    
    struct NODE* traversal = root;

    char *s;
    s = strtok(dirName, "/");
    while (s) {    
        if (!traversal->childPtr->name) {
            printf("ERROR: directory %s does not exist", traversal->childPtr->name);
            return NULL;
        }
        traversal = traversal->childPtr;
        s = strtok(0, "/");
    }
    
    return NULL;
}
