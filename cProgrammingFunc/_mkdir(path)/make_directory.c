#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <direct.h> // for _mkdir on windows
#define MKDIR(path) _mkdir(path)
#else
#include <sys/stat.h> // for mkdir on Linux/macOS
#define MKDIR(path) mkdir(path, 0777)
#endif

int main()
{
    const char *folderName = "createdFolder";

    // Create folder if it doesn't exist
    if (MKDIR(folderName) == 0)
    {
        printf("Folder created successfully.\n");
    }
    else if (folderName == "createdFolder") // run if folder exists
    {
        printf("Folder already exists\n");
    }
    else
    {
        perror("Folder could not be created.\n");
    }

    return 0;
}