#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class scanner{
private:
	ifstream input;
	string filename;
public:
	scanner(string fn);
	string getWord();
	void getArrayComponents(vector<string> *);
	//void getStringsOnLines(vector<vector<string> > *);
	void getStringsOnLine(vector<string> *);
	string getLineOfCode();
	void getToStart();
	~scanner();
};

bool keep(char );
