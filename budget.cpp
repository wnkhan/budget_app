#include "budget.h"

budget::budget(std::vector<transaction> *all)
{
	for (int i = 0; i < all->size(); ++i)
	{
		if (checkMonth(all->at(i)))
		{
			m_transactions.push_back(all->at(i));
		}
	}
}

bool budget::checkMonth(transaction single)
{
	if (single.getMonth()==9)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void budget::setGrocery()
{
	for(int i=0;i<m_transactions.size();++i)
	{
		if(m_transactions[i].getType().compare("Groceries")==0)
		{
			m_grocery.push_back(m_transactions[i]);
			m_transactions.erase(m_transactions.begin()+i);
			i--;
		}
	}
}

void budget::setDining()
{
	for (int i = 0; i < m_transactions.size(); ++i)
	{
		if(m_transactions[i].getType().compare("Restaurants/Dining")==0)
		{
			m_dining.push_back(m_transactions[i]);
			m_transactions.erase(m_transactions.begin()+i);
			i--;
		}
	}
}

void budget::setGas()
{
	for (int i = 0; i < m_transactions.size(); ++i)
	{
		if(m_transactions[i].getType().compare("Gasoline/Fuel")==0)
		{
			m_gas.push_back(m_transactions[i]);
			m_transactions.erase(m_transactions.begin()+i);
			i--;
		}
	}
}


void budget::setBills()
{
	for(int i=0;i<m_transactions.size();++i)
	{
		for(int j=0;j<4;j++)
		{
			if(m_transactions[i].getType().compare(bills[j])==0)
			{
				m_bills.push_back(m_transactions[i]);
				m_transactions.erase(m_transactions.begin()+i);
				i--;
			}
		}
	}
}

void budget::setIncome()
{
	for (int i = 0; i < m_transactions.size(); ++i)
	{
		if(m_transactions[i].getType().compare("Income")==0)
		{
			m_income.push_back(m_transactions[i]);
			m_transactions.erase(m_transactions.begin()+i);
			i--;
		}
	}
}

void budget::setAll()
{
	setGrocery();
	setDining();
	setGas();
	setBills();
	setIncome();
}

void budget::writeBills(std::ofstream *out)
{
	int total =0;
	for(int i=0;i<m_bills.size();i++)
	{
		total+=m_bills[i].getAmount();
	}
	m_expenses += total;
	*out << "Amount spent on Bills: " << total << std::endl;
}


void budget::writeDining(std::ofstream *out)
{
	int total = 0;
	for (int i = 0; i < m_dining.size(); ++i)
	{
		if (m_dining[i].getAmount()<0)
		{
			int temp = m_dining[i].getAmount() * -1;
			total += temp;
		}
		else
		{
			total+= m_dining[i].getAmount();
		}
	}
	m_expenses += total;
	*out << "Amount spent on Dining: " << total << std::endl;
}
void budget::writeGrocery(std::ofstream *out)
{
	int total =0;
	for(int i=0;i<m_grocery.size();i++)
	{
		total += m_grocery[i].getAmount();
	}
	m_expenses += total;
	*out << "Amount spent on Grocery: " << total << std::endl;
}

void budget::writeGas(std::ofstream *out)
{
	int total =0;
	for(int i=0;i<m_gas.size();i++)
	{
		total += m_gas[i].getAmount();
	}
	m_expenses += total;
	*out << "Amount spent on Gas: " << total << std::endl;
}

void budget::writeIncome(std::ofstream *out)
{
	int total =0;
	for(int i=0;i<m_income.size();i++)
	{
		total += m_income[i].getAmount();
	}
	m_pay += total;
	*out << "Amount of income: " << total << std::endl;
}

void budget::writeAll(std::ofstream *out)
{
	writeBills(out);
	writeDining(out);
	writeGrocery(out);
	writeGas(out);
	writeIncome(out);
}


void budget::writeUnaccounted(std::ofstream *out)
{
	int total =0;
	for(int i=0;i<m_transactions.size();i++)
	{
		total += m_transactions[i].getAmount();
	}
	*out << "Amount unaccounted for: " << total << std::endl;
}

void budget::printRemaining()
{
	for (int i = 0; i < m_transactions.size(); ++i)
	{
		m_transactions[i].printTransaction();
	}
}

void budget::printRemainingSize()
{
	std::cout << "Remaining transactions: " << m_transactions.size() << std::endl;
}


void budget::writeDifference(std::ofstream *out)
{
	*out << "Expense difference is: " << m_expenses << std::endl;
}

void budget::currentStatus(std::ofstream *out)
{
	*out << "Expenses are: " << m_expenses << std::endl;
	*out << "Income is: " << m_pay << std::endl;
}