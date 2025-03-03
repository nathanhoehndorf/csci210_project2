#include "types.h"

extern struct NODE* root;
extern struct NODE* cwd;

//make directory
void mkdir(char pathName[]){

    // TO BE IMPLEMENTED
    //
    // YOUR CODE TO REPLACE THE PRINTF FUNCTION BELOW

    printf("TO BE IMPLEMENTED\n");

    return;
}

//handles tokenizing and absolute/relative pathing options
struct NODE* splitPath(char* pathName, char* baseName, char* dirName){

    // TO BE IMPLEMENTED
    // NOTE THAT WITHOUT COMPLETING THIS FUNCTION CORRECTLY
    // rm, rmdir, ls, cd, touch COMMANDS WILL NOT EXECUTE CORRECTLY
    // SEE THE PROVIDED SOLUTION EXECUTABLE TO SEE THEIR EXPECTED BEHAVIOR

    // YOUR CODE HERE

    /*
    to find the baseName and dirName, find the total count of /. If it is less than or equal to 1, easy
    if it is 2, check if it is easy
    if it is 2 or greater and hard, go from right to left, find /, and the split into two strings
    */

    int pathNameLength = sizeof(pathName) / sizeof(pathName[0]);
    int forwardSlashCount = 0;
    
    for (int i = 0;i < pathNameLength; i++) {

        if (pathName[i] == '/') {
            forwardSlashCount++;
        }

    }

    if (forwardSlashCount == 0) {
        baseName = pathName;
        dirName = "";
    } else if (forwardSlashCount == 1) {
        if (pathName[0] == '/') {
            dirName = "/";
            baseName = pathName;
            memmove(baseName, baseName+1, strlen(baseName));
        } else {
            int slashIndex = 0;
            for (int j = 0; j < pathNameLength; j++) {
                if (pathName[j] == '/') {
                    slashIndex = j;
                    break;
                }
            }
            dirName = pathName;
            dirName[slashIndex] = '\0';

            baseName = pathName;
            memmove(baseName, baseName+slashIndex, strlen(baseName));
        }
    } else if (forwardSlashCount == 2 && pathName[0] == '/') {
            int slashIndex = 0;
            for (int k = 1; k < pathNameLength; k++) {
                if (pathName[k] == '/') {
                    slashIndex = k;
                    break;
                }
            }
            dirName = pathName;
            dirName[slashIndex] = '\0';

            baseName = pathName;
            memmove(baseName, baseName+slashIndex, strlen(baseName));
    } else {

        /*
        two cases:
        1. /dir/dir/file
        remove pathName[0], now same as case 2
        2. dir/dir/file
        look at loop backwards until index of / is found. Then dirName is 0 through the slash index. base name is the slash index to the end
        */
       int slashIndex = 0;
       for (int x = pathNameLength-1; x >= 0; x--) {
            if (pathName[x] == '/') {
                slashIndex = x;
                break;
            }
       }
       slashIndex = pathNameLength - slashIndex; // possibly need to add or subtract by 1

       dirName = pathName;
       dirName[slashIndex] = '\0';

       baseName = pathName;
       memmove(baseName, baseName+slashIndex, strlen(baseName));
    }

    /*
    check and see if its root -- if so, throw an error.
    */
    *cwd->parentPtr->name = dirName;
    cwd->parentPtr->fileType = 'D';
    return NULL;
}
