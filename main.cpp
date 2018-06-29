#include "Sequence.h"
#include <iostream>
using namespace std;
int main(){
Sequence test("dna");
int length=test.length();
int numberOfA=test.numberOf('A');
cout<<"length is: "<<length<<endl;
cout<<"A: "<<numberOfA<<endl;
cout<<"T: "<<test.numberOf('T')<<endl;
cout<<"C: "<<test.numberOf('C')<<endl;
cout<<"G: "<<test.numberOf('G')<<endl;
cout<<test.longestConsecutive()<<endl;
cout<<test.longestRepeated()<<endl;
return 0;
}
