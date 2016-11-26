#ifndef EXPLORER_H
#define EXPLORER_H

#include "Folder.h"
class Explorer
{
    public:
        Explorer(std::string rootPath);
        ~Explorer();
        void ls();
        std::string pwd();
        void cd(std::string path);

    protected:

    private:
        Folder* rootFolder;
        Folder* currentFolder;
};

#endif // EXPLORER_H
