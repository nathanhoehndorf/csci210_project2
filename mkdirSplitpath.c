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

struct NODE* searchChild(struct NODE* parent, const char* name) {
    struct NODE* current = parent->childPtr;
    while(current) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->siblingPtr;
    }

    return NULL;
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

    char *s = strtok(dirName, "/");
    while (s) {   
        traversal = searchChild(traversal, s); 
        if (!traversal) {
            printf("ERROR: directory %s does not exist", s);
            return NULL;
        }
        s = strtok(NULL, "/");
    }
    
    return traversal;
}
