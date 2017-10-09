#include "transaction.h"

int transaction::getAmount()
{
	return m_amount;
}

int transaction::getEffect()
{
	return m_effect;
} 

int transaction::getMonth()
{
	std::string month("");
	for (int i = 0; i < m_date.size(); ++i)
	{
		if (m_date[i]=='/' || m_date[i] == '\\')
		{
			break;
		}
		else
		{
			if(isdigit(m_date[i]))
			month += m_date[i];
		}
	}
	int mo = getInt(month);
	return mo;
}

std::string transaction::getType()
{
	return m_type;
}

void transaction::printTransaction()
{
	std::cout << "Amount: " << m_amount << std::endl;
	std::cout << "Date: " << m_date << " " << m_type << " " <<  m_source << std::endl;
}

int getInt(std::string number)
{
	std::vector<char> digits;	        
	int out =0;
	if(!number.empty())
	{	
		for(int i=0;i<number.size();i++)
	    {
	        if(number[i]!='.'&& isdigit(number[i]))
            {    
              digits.push_back(number[i]);
            }
            else
            {
	     		break;
            }
        }
        int base = 1;
        for(int i=digits.size()-1;i<digits.size();i--)
        {
            out += base * (digits[i]-48);
            base *= 10;
        }
    }
    return out;
}

float getFloat(std::string number)
{
	bool decimal = false;
	std::vector<char> whole;
	std::vector<char> partial;
	for (int i = 0; i < number.size(); ++i)
	{
		if(number[i]=='.')decimal = true;
		if (decimal)
		{
			partial.push_back(number[i]);
		}
		else
		{
			whole.push_back(number[i]);
		}
	}
	int base =1;
	float total = 0;
	for (int i = 0; i < whole.size(); ++i)
	{
		/* code */
	}
	return total;
}