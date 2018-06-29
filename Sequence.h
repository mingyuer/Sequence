#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <string>
#include <vector>
using namespace std;
class Sequence{
public:
Sequence(string);
~Sequence();
int length();
int numberOf(char);
string longestConsecutive();
string longestRepeated();
private:
string name;
vector<char> content;
};

#endif
