#include "main.ih"

bool normalFile(char const *fileName)
{
    struct stat fileInfo;

    if (lstat(fileName, &fileInfo))
    {
        cout << "Can't stat `" << fileName << "': skipping\n";
        return false;
    }
    
    return S_ISREG(fileInfo.st_mode);
}


