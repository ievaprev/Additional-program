#include "MyLib.h"
#include "Methods.h"

//This function is used to disregard any punctuation marks
string& textCleaning(string& line) {

   line.erase(remove_if(line.begin(), line.end(), [](char character) {
        return ::ispunct(character) || isdigit(character) || character == '-' || character == '–' || character == '—';
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

//This function uses regex to find every possible URL
void findURL(string&line) {

    regex regexCode(R"((?:https:\/\/|http:\/\/|www\.)[a-zA-Z0-9\-.]+\.[a-zA-Z]{2,3}(?:\?[a-zA-Z0-9\-._~:/?#\[\]@!$&'()*+,;=%]*)?)");

    string line1 = line;
    smatch urls;

    cout << "URL links: " << endl;

    while (regex_search(line, urls, regexCode)){
       
        cout << urls.str() << endl;
        line1 = urls.suffix().str();
    }
}