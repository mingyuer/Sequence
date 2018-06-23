#include "Sequence.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <vector>
using namespace std;

Sequence::Sequence(string filename){
name=filename;
vector<char> *p=new vector<char>;
ifstream infile("/data/dna.txt");
char c;
while(!infile.eof()){
infile>>c;
if(c!='\r'&&c!='\n'&&c!=' ')
p->push_back(c);
}
p->pop_back();
content=p;
}

int Sequence::length(){
return content.size();
}
int Sequence::numberOf(char base){
int cntA=0;
int cntT=0;
int cntC=0;
int cntG=0;
for(int i=0;i<content.size();++i){
if( content[i]=='A')
cntA++;
else if(content[i]=='T')
cntT++;
else if(content[i]=='C')
cntC++;
else if(content[i]=='G')
cntG++;
}
if(base=='A')
return cntA;
else if(base=='T')
return cntT;
else if(base=='C')
return cntC;
else if(base=='G')
return cntG;
else
return 0;
}

string Sequence::longestConsecutive(){
int max=1;
char maxvalue=content[0];
int cur=1;
for(int i=0;i<content.size();i++){
if(content[i+1]==content[i])
cur++;
else if(max<cur){
max=cur;
maxValue=content[i];
cur=1;
}
}
string s="";
for(int j=0;j<max;j++){
s+=maxvalue;
}
return s;
}

string Sequence::longestRepeated(){
string s;
for(vector<char>::iterator iter=content.begin();iter!=content.end();++iter)
s+=*iter;
string maxstr;
for(int i=0;i<s.length();i++){
for(int j=(s.length()-i);j>=1;j--){
string subs=s.substr(i,j);
int front=s.find(subs);
int back=s.rfind(subs);
if(front!=back&&subs.length()>maxstr.length())
maxstr=subs;
}
return maxstr;
}
}


