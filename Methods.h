#include "MyLib.h"

class Info {
public:
	int repetitions;
	set<int> lines;
};

void findURL(string& textLine, const set<string> urlCode);
set<string> URLCode(string& fileName);
string& textCleaning(string& line); 
void wordCount(string& line, map<string, Info>& words, int& count);
void readFile(string& fileName, map<string, Info>& words);
void outputFile(const string& fileName, map<string, Info>& words);
