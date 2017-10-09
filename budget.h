#pragma once

#include "transaction.h"

const std::string bills[] = {"Utilities", "Telephone Services", "Cable/Satellite Services", "Rent"};

class budget{
private:
	int m_month;
	std::vector<transaction> m_transactions;
	std::vector<transaction> m_grocery;
	std::vector<transaction> m_bills;
	std::vector<transaction> m_dining;
	std::vector<transaction> m_gas;
	std::vector<transaction> m_income;
	int m_expenses;
	int m_pay;
public:
	budget(int m) : m_month(m){m_expenses=0; m_pay =0;}
	budget(std::vector<transaction> *);
	bool checkMonth(transaction );
	void setBills();
	void setGrocery();
	void setDining();
	void setGas();
	void setIncome();
	void setAll();
	void writeDining(std::ofstream *);
	void writeBills(std::ofstream *);
	void writeGrocery(std::ofstream *);
	void writeGas(std::ofstream *);
	void writeIncome(std::ofstream *);
	void writeAll(std::ofstream *);
	void writeUnaccounted(std::ofstream *);
	void printRemaining();
	void printRemainingSize();
	void writeDifference(std::ofstream *);
	void currentStatus(std::ofstream *);
};

