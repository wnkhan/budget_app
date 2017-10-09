#include <iostream>
#include <string>

#include "scanner.h"
#include "budget.h"
#include "transaction.h"

int main(int argc, char *argv[]) {

	ofstream out("output.txt");
	string argument1 = argv[1];

	scanner file(argument1);

	vector<transaction> all;
	for (int i = 0; i < 64; i++) {
		vector<string> temp;
		file.getStringsOnLine(&temp);
		int a = stoi(temp[temp.size() - 1]);
		transaction s(a, temp[2], temp[temp.size() - 2], temp[1]);
		all.push_back(s);
	}

	budget september(&all);
	september.currentStatus(&out);
	september.printRemainingSize();

	september.setAll();
	september.writeAll(&out);
	september.currentStatus(&out);


	september.printRemainingSize();

	out.close();

	return 0;
}

