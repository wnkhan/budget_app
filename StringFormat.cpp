#include "StringFormat.h"

void RemoveQuotes(string *str)
{
	for (int i = 0; i < str->size(); ++i)
	{
		if(str->at(i)=='\"')
		{
			str->erase(str->begin()+i);
		}
	}
}

void RemoveWhiteSpace(string *str)
{
	for (int i = 0; i < str->size(); ++i)
	{
	
		if (isspace(str->at(i)))
		{
			str->erase(str->begin()+i);
		}
	}
}