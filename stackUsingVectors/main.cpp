#include <iostream>
#include "stack.h"

using namespace std;

int main(){
    Stack s1;
    s1.push(1);
    s1.push(2);
    cout<<s1.isEmpty()<<endl;
    s1.print();

return 0;
}
