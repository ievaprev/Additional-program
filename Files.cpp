#include "MyLib.h"
#include "Methods.h"

//This function is used to read the provided text file, line by line and process them
void readFile(string& fileName, map<string, Info>& words) {

	ifstream inFile(fileName);

	try {
		if (!inFile.is_open())
		{
			throw runtime_error("Error while openning the file: " + fileName);
		}

		string line;
		string file = "domains.txt";
		set<string> urlCode = URLCode(file); 

		int count = 1;

		while (getline(inFile, line)) {
			
			string tempLine = line;
			findURL(tempLine, urlCode);  
	 
			string modifiedLine = textCleaning(line);
			wordCount(modifiedLine, words, count);

			count += 1;
		}

		inFile.close();
	}
	catch(const exception& e){
		cout << e.what() << endl;
		exit(EXIT_FAILURE);
	}
	

}

//This function outputs the reocuring words in a output text file
void outputFile(const string& fileName, map<string, Info>& words) {

	stringstream output;

	output << setw(11) << left << "Repetition" << setw(20) << left << "Repeating Words" << setw(14) << left << "Line numbers:" << endl;

	for (const auto& mapp : words) {

		const string& word = mapp.first;
		const Info& info = mapp.second;

		if (info.repetitions > 1) {
			output << setw(11) << left << info.repetitions << setw(20) << left << word;

			
			for (int line : info.lines) {
				output << line << "  ";
			}

			output << endl;
		}
		continue;
	}

	ofstream outfile(fileName); 
	outfile << output.str();
	outfile.flush();
	outfile.close();
}
