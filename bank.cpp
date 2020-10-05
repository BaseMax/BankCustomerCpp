#include <iostream>
using namespace std;

typedef struct {
	int deleted=0;
	int code;
	string name;
	int balance;
	string address;
} customer;

customer customers[1000];
int count=0;

void doDeleteByCode(int code) {
	for(int i=0;i<count;i++) {
		if(customers[i].code == code) {
			customers[i].deleted=1;
			if(i == count-1) {
				count--;
			}
		}
	}
}

void doDelete() {
	cout << "Type code of customer: ";
	int code;
	cin >> code;
	doDeleteByCode(code);
}

void doAdd() {
	int index=count;
	for(int i=0;i<count;i++) {
		if(customers[i].deleted==1) {
			index=i;
			break;
		}
	}
	cout << "Type code: ";
	cin >> customers[index].code;
	cout << "Type name: (without space)";
	cin >> customers[index].name;
	cout << "Type balance: ";
	cin >> customers[index].balance;
	cout << "Type address: ";
	cin >> customers[index].address;
	customers[index].deleted=0;
	if(index == count) {
		count++;
	}
}

void doSum() {
	int sum=0;
	for(int i=0;i<count;i++) {
		if(customers[i].deleted==1) {
			continue;
		}
		sum+=customers[i].balance;
	}
	cout << "Sum of balance are "<< sum << "\n";
}

void doExit() {
	cout << "Exit\n";
	exit(1);
}

void doPrint(int i) {
	cout << customers[i].name;
	cout << "           | ";
	cout << customers[i].code;
	cout << "                    | ";
	cout << customers[i].address;
	cout << "                        | ";
	cout << customers[i].balance;
	cout << "\n";
}

void doList() {
	for(int i=0;i<count;i++) {
		if(customers[i].deleted==1) {
			continue;
		}
		cout << " Name          | Code                   | Address                      | Balance\n";
		cout << " ";
		doPrint(i);
		cout << " =========================== \n";
	}
}

int main(int argc, char const *argv[]) {
	while(true) {
		cout << "Type what function you need to run:\n";
		cout << "  1. Add\n";
		cout << "  2. Delete/Remove\n";
		cout << "  3. Sum\n";
		cout << "  4. List\n";
		cout << "  5. Exit\n";
		int i;
		cin >> i;
		switch(i) {
			case 1:
				doAdd();
			break;
			case 2:
				doDelete();
			break;
			case 3:
				doSum();
			break;
			case 4:
				doList();
			break;
			case 5:
				doExit();
			break;
			default:
				cout << "Error!\n";
			break;
		}
		cout << "\n";
	}
	return 0;
}
