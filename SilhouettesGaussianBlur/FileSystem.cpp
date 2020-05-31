#include <string>

#include "FileSystem.h"

using namespace std;

static Assimp::Importer importer;

string FileSystem::getExtension(const string &filePath)
{
    return filePath.substr(filePath.find_last_of(".") + 1);
}

bool FileSystem::isExist(const string &filePath)
{
    ifstream fileStream(filePath);
    if (fileStream.is_open() == false)
    {
        cerr << "Can't open : " << filePath << endl;

        return false;
    }

    return true;
}

string FileSystem::readFile(const string &path)
{
    string contents;

    ifstream fileStream(path);
    if (fileStream.is_open() == false)
    {
        cerr << "Can't open : " << path << endl;

        return contents;
    }

    stringstream buffer;
    buffer << fileStream.rdbuf();
    contents = buffer.str();

    fileStream.close();

    return contents;
}

string FileSystem::readShader(const string &name)
{
    return readFile("../Shaders/" + name);
}

void FileSystem::writeFile(const string &path, const string &contents)
{
    ofstream outputStream(path);
    if (outputStream.is_open() == false)
    {
        cerr << "Can't open : " << path << endl;

        return;
    }

    outputStream << contents << endl;

    outputStream.close();
}