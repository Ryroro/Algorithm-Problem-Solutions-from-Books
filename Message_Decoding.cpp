#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include <sstream>
#include <list>
#include <vector>
using namespace std;
int pow_(int, int);
int pow_add(int, int);
string to_binary(int, int);
int main()
{
	string encode;
	cout << "Enter the key to the code" << endl;
	getline(cin, encode);
	map<string, string> decode;
	int len = encode.size();
	int n = 0;
	int i = 1;
	while (n < len) {
		int max = pow_add(2, i-1);
		for (int j = 0; j < max && n < len; j++) {
			string s = to_binary(j,i);
			decode[s] = encode[n];
			cout << "decode: " << s << endl;
			cout << "encode: " << encode[n] << endl;
			n++;
		}
		i++;
	}
	string code;
	cout << "Enter the code " << endl;
	getline(cin, code);
	i = 0;
	vector<string> text;
	cout << endl;
	while (i < code.size()-3) {
		int length = 0;
		for (int u = 2; u > -1 ; i++, u--) {
			if (code[i] == '1')
				length += pow_(2, u);
		}
		cout << "length is " << length << endl;
		string terminate(length, '1');
		cout << "terminate word is " << terminate << endl; 
		while (1) {
			string s(code, i, length);
			i += length;
			cout << "i is " << i << endl;
			cout << "size of code is " << code.size() << endl;
			if (i >= code.size()-3)
				break;
			cout << "s is " << s << endl;
			if (s == terminate)
				break;
			text.push_back(decode[s]);
		}
		
		
	}
	
	auto begin = text.begin();
	auto end = text.end();
	while (begin != end) {
		cout << *begin;
		begin++;
	}
	cout << endl;

	return 0;

}
			
	

int pow_(int base, int pow)
{
	if (pow == 0)
		return 1;
	int i = 1;
	for (int j = 1; j <= pow; j++)
		i = i* base;
	return i;
}

int pow_add(int base, int pow)
{
	int sum = 0;
	for (int i = 0; i <=pow; i++)
		sum += pow_(base, i);
	return sum;
}

string to_binary(int n, int len)
{
	string s;
	list<char> l;
	while (n > 0) {
		if (n % 2 == 0) {
			l.push_front('0');
			n = n/2;
		}
		else if (n % 2 == 1) {
			l.push_front('1');
			n = (n-1)/2;
		} else if (n == 1) {
			l.push_front('1');
			n = 0;
		}
	}

	while (l.size() < len)
		l.push_front('0');

	auto begin = l.begin();
	auto end = l.end();
	while (begin != end) {
		s.push_back(*begin);
		begin++;
	}
	return s;
}
	
