#include <iostream>
#include <stack> 
#include <string>

using namespace std;

int main(int argc, char ** argv){

	string entrada;
  
  	stack<int> mystack; 

  	int num1, num2;

	for (int i=1; i<argc; i++) {

		entrada = argv[i];

		if (entrada=="+") {
				num1 = mystack.top(); 
				mystack.pop(); 

				num2 = mystack.top(); 
				mystack.pop(); 

				num1 = num1 + num2;

				mystack.push(num1); 
		}

		else 
			mystack.push(stoi(entrada)); 
	}

	while (!mystack.empty()) { 
        cout << mystack.top(); 
        mystack.pop(); 
    } 

    cout<<endl;

	return 0;
}