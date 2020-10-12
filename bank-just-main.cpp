#include <iostream> 
using namespace std; 
typedef struct { 
string name; 
int mojodi; 
string address; 
int code; 
int show=0; // 0 or 1
} data; 
data items[1000]; 
int main() { 
int size=0; 
while(true) { 
cout << "chikar konam:"<<endl; 
cout << "  a Add" << endl; 
cout << "  b Delete/Remove" << endl; 
cout << "  c Sum" << endl; 
cout << "  d List" << endl; 
cout << "  e Exit" << endl; 
char i; 
cin >> i; 
switch(i) { 
case 'a': { 
items[size].show=0; 
cout << "Tell code = "; 
cin >> items[size].code; 
cout << "Tell name = "; //just a string - no space
cin >> items[size].name; 
cout << "Tell mojodi =  "; 
cin >> items[size].mojodi; 
cout << "Tell address = "; 
cin >> items[size].address; 
size++; 
} 
break; 
case 'b': { 
cout << "tell code ="; 
int code; 
cin >> code; 
for(int i=0;i<size;i++) { 
if(items[i].code == code) { 
items[i].show=1; 
if(i == size-1) { 
size--; 
} 
} 
} 
} 
break; 
case 'c': { 
int sum=0; 
for(int i=0;i<size;i++) { 
if(items[i].show==1) { 
continue;
} 
sum+=items[i].mojodi; 
} 
cout << "jame mojodi is "<< sum << endl; 
} 
break; 
case 'd': { 
for(int i=0;i<size;i++) { 
if(items[i].show==1) { 
continue; 
} 
cout << "\nName: ";
cout << items[i].name; 
cout << "\nCode: ";
cout << items[i].code; 
cout << "\nAddress: ";
cout << items[i].address; 
cout << "\nMojodi: ";
cout << items[i].mojodi; 
cout << endl; 
cout << endl; 
} 
} 
break; 
case 'e': { 
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
