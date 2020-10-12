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

int main() {
	while(true) {
		cout << "Type what function you need to run:"<<endl;
		cout << "  1. Add" << endl;
		cout << "  2. Delete/Remove" << endl;
		cout << "  3. Sum" << endl;
		cout << "  4. List" << endl;
		cout << "  5. Exit" << endl;
		int i;
		cin >> i;
		switch(i) {
			case 1: {
				customers[count].deleted=0;
				cout << "Type code: ";
				cin >> customers[count].code;
				cout << "Type name: (without space)";
				cin >> customers[count].name;
				cout << "Type balance: ";
				cin >> customers[count].balance;
				cout << "Type address: ";
				cin >> customers[count].address;
				count++;
			}
			break;
			case 2: {
				cout << "Type code of customer: ";
				int code;
				cin >> code;
				for(int i=0;i<count;i++) {
					if(customers[i].code == code) {
						customers[i].deleted=1;
						if(i == count-1) {
							count--;
						}
					}
				}
			}
			break;
			case 3: {
				int sum=0;
				for(int i=0;i<count;i++) {
					if(customers[i].deleted==1) {
						continue;
					}
					sum+=customers[i].balance;
				}
				cout << "Sum of balance are "<< sum << "" << endl;
			}
			break;
			case 4: {
				for(int i=0;i<count;i++) {
					if(customers[i].deleted==1) {
						continue;
					}
					cout << " Name          | Code                   | Address                      | Balance" << endl;
					cout << " ";
					cout << customers[i].name;
					cout << "           | ";
					cout << customers[i].code;
					cout << "                    | ";
					cout << customers[i].address;
					cout << "                        | ";
					cout << customers[i].balance;
					cout << endl;
					cout << " =========================== " << endl;
				}
			}
			break;
			case 5: {
				cout << "Exit" << endl;
				return 0;
			}
			break;
			default:
				cout << "Error!" << endl;
			break;
		}
		cout << endl;
	}
	return 0;
}
