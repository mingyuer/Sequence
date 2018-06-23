#include "Sequence.h"
#include <iostream>
using namespace std;
int main(){
Sequence test=new Sequence("dna");
int length=test.length();
int numberOfA=test.numberOf('A');
string longestC=test.longestConsecutive();
string longestR=test.longestRepeated();
cout<<"length is: "<<length<<endl;
cout<<"number of 'A' is: "<<numberOfA<<endl;
cout<<"longest consecutive is: "<<longestC<<endl;
cout<<"longesr repeated is: "<<longestR<<endl;
return 0;
}
