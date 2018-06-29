#include "Sequence.h"
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
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
content=*p;
}
Sequence::~Sequence(){}


int Sequence::length(){
return content.size();
}
int Sequence::numberOf(char base){
int cnt=0;int i=0;
switch(base){
case 'A':
for( i=0;i<content.size();++i){
if(content[i]=='A')
cnt++;
}
break;
case 'T':
for( i=0;i<content.size();++i){
if(content[i]=='T')
cnt++;
}
break;
case 'C':
for( i=0;i<content.size();i++){
if(content[i]=='C')
cnt++;
}
break;
case 'G':
for( i=0;i<content.size();++i){
if( content[i]=='G')
cnt++;
}

break;
default:cnt=0;
}
return cnt;
}

string Sequence::longestConsecutive(){
int max=1;
char maxvalue=content[0];
int cur=1;
for(int i=0;i<content.size();i++){
if(content[i+1]==content[i])
cur++;
else{
 if(max<cur){
max=cur;
maxvalue=content[i];}
cur=1;
}
}
string s;
s.clear();

for(int j=0;j<max;j++){
s+=maxvalue;
}
return s;
}
int pstrcmp(const void* st1,const void* st2){
return strcmp(*(const char**)st1,*(const char**)st2);
}
int comlen(char* str1,char* str2){
int i=0;
while(*str1&&(*str1++==*str2++)){
++i;
}
return i;
}
string Sequence::longestRepeated(){

int len=content.size();
char* c=new char[len+1];
char** a=new char*[len];
for(int i=0;i<len;++i){
c[i]=content[i];
a[i]=&c[i];
}
c[len]=0;
qsort(a,len,sizeof(char*),pstrcmp);
string repeated;
int max=0;
int thislen=0;
int maxlen=-1;
for(int i=0;i<len-1;++i){
thislen=comlen(a[i],a[i+1]);
if(thislen>maxlen){
maxlen=thislen;
max=i;
}
}
for(int i=0;i<maxlen;++i){
repeated +=a[max][i];
}
return repeated;
}

