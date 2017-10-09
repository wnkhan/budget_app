#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <iostream>

class transaction{
protected:
	int m_amount;
	int m_effect;
	std::string m_date;
	std::string m_type;
	std::string m_source;
public:
	transaction(int a,std::string s, std::string t, std::string d)
	:m_amount(a),m_source(s),m_type(t),m_date(d),m_effect(-1){};
	int getAmount();
	int getEffect();
	int getMonth();
	std::string getType();
	void printTransaction();
};

int getInt(std::string);
float getFloat(std::string);
