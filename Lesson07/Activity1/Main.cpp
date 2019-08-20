#include"Stack.h"

int main(){
    try {
        Stack<int> si;
        displayStackStats<int>(si);
        si.push(22);
        si.push(426);
        cout << "Top of stack contains " << si.top() << endl;
        si.push(57);
        displayStackStats<int>(si);
        cout << "Top of stack contains " << si.top() << endl;

        si.pop();
        cout << "Top of stack contains " << si.top() << endl;

        si.pop();
        displayStackStats<int>(si);

        Stack<char> sc;
        sc.push('d');
        sc.push('l');
        displayStackStats<char>(sc);
        cout << "Top of char stack contains:" << sc.top() << endl;
    }
    catch(string str){
        cout << "Error : " << str << endl;
    }
    catch(...){
        cout << "Error : Unexpected exception caught " << endl;
    }
    return 0;
}
