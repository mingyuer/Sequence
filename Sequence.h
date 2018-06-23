#ifndef
#define

class Sequence{
public:
Sequence(string);
int length();
int numberOf(char);
string longestConsecutive();
string longestRepeated();
private:
string name;
vector<char> content;
}

#endif
