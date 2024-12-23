#include "MyLib.h"
#include "Methods.h"

int main()
{
    locale::global(std::locale("lt_LT.UTF-8"));
    string fileName;
    map<string, Info> wordMap;

    cout << "Please type the file name from which you want to read the text: " << endl;
    cin >> fileName;

    readFile(fileName, wordMap);
    outputFile("output.txt", wordMap);
}
