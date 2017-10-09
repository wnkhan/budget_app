#include "scanner.h"

scanner::scanner(string fn)
{

	input.open(fn);

}

string scanner::getWord()
{
	vector<char> letter;
	string temp;
	letter.push_back(input.get());
	int i = 0;
	while(isalpha(letter[i]))
	{
		temp += letter[i];
		i++;
		letter.push_back(input.get());
	}
	return temp;
}

void scanner::getArrayComponents(vector<string> *ArrayStuff)
{	
	char letter;
	int count = 0;
	int stringnumber = 0;
	bool foundstart = false;
	letter = input.get();
	while(letter!='}')
	{
		if (letter=='{')
		{
			foundstart = true;
			ArrayStuff->push_back("");
		}
		else if(foundstart)
		{
			if (letter == ',')
			{
				stringnumber++;
				ArrayStuff->push_back("");
			}
			else
			{
				ArrayStuff->at(stringnumber) += letter;
			}
		}
		else if(count<50)
		{
			count++;
		}
		else
		{
			cout << "Not finding start of array!!!" << endl;
		}
		letter = input.get();
	}
}
void scanner::getStringsOnLine(vector<string> *strings)
{
	char temp = input.get();
	strings->push_back("");
	bool check = false;
	int i=0;
	while(temp!='\n')
	{
		if (keep(temp))
		{
			strings->at(i)+=temp;
			check = true;
		}
		else
		{
			if (check)
			{
				i++;
				strings->push_back("");
				check = false;
			}
			
		}
		temp = input.get();
	}
}

/*void scanner::getStringsOnLines(vector<vector<string> > *stringy)
{
	
	while(!input.eof())
	{
		vector<string> oneline;
		getStringsOnLine(&oneline);
		stringy->push_back(oneline);
	}

}*/

void scanner::getToStart()
{
	char temp;
	temp = input.get();
	int i =0;
	while(temp != '{')
	{
		temp = input.get();
	}
}

string scanner::getLineOfCode()
{
	vector<char> letter;
	string temp;
	letter.push_back(input.get());
	int i = 0;
	while(letter[i]!=';')
	{
		temp += letter[i];
		i++;
		letter.push_back(input.get());
	}
	temp += ";";
	return temp;
}


scanner::~scanner()
{
	input.close();
}

bool keep(char temp)
{
	if (isalnum(temp))
	{
		return true;
	}
	else if(temp == '/' || temp == '.' || temp ==' ' || temp == '&' || temp == ';' )
	{
		return true;
	}
	else if(temp== ' ')
	{
		return true;
	}
	else
	{
		return false;
	}
}
