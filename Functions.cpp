#include "MyLib.h"
#include "Methods.h"

//This function is used to disregard any punctuation marks
string& textCleaning(string& line) {

   line.erase(remove_if(line.begin(), line.end(), [](char character) {
        return ::ispunct(character) || isdigit(character) || character == '-' || character == '—' || character == '—';
        }), line.end());

   transform(line.begin(), line.end(), line.begin(), [](unsigned char character) {
        return tolower(character);
        });
   
    return line;
}

//This function will be used to count how many times the word was repeated in a text
void wordCount(string& line, map<string, Info>& words, int& count) {

    istringstream iss(line); 
    string word;

    while (iss >> word) {
        if (words.find(word) == words.end()) {
            words[word].repetitions = 1; 
        }
        else {
            words[word].repetitions++;
        }
        words[word].lines.insert(count);
    }
}

//This function is used to put all possible domains into a single set
set<string> URLCode(string& fileName) {

    ifstream inFile(fileName);
    set<string> urlCode;

    try {
        if (!inFile.is_open())
        {
            throw runtime_error("Error while openning the file: " + fileName);
        }
        
        string line;

        while (getline(inFile, line)) {

            transform(line.begin(), line.end(), line.begin(), [](unsigned char character) {
                return tolower(character);
                });

            if (!line.empty()) {
                urlCode.insert(string(".") + line); 
                
            }
        }
        inFile.close();
    }
    catch (const exception& e) {
        cout << e.what() << endl;
        exit(EXIT_FAILURE);
    }
    return urlCode; 
}

//This function uses regex to find every possible URL
void findURL(string& line, const set<string> urlCode) {

    istringstream iss(line);
    string word;
    set<string> urls;

    while (iss >> word) {

        while (!word.empty() && ispunct(word.back())) {
            word.pop_back();
        }
        
        for (const auto& url : urlCode) {
            if (word.find(url) != string::npos)
            {
                urls.insert(word);
            }
        }
    }
    for (const auto& url : urls) {
        cout << url << endl;
    }
}
