#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

int fun2(const std::string& str, const std::string& sub)
{
	int num = 0;
	size_t len = sub.length();
	if (len == 0)len = 1;//应付空子串调用
	for (size_t i = 0; (i = str.find(sub, i)) != std::string::npos; num++, i += len);
	return num;
}

int main() {

	string file_path = "input.txt";
	string ans_path = "result.txt";
	string str;
	ifstream instream;
	ofstream outstream;

	instream.open(file_path);
	outstream.open(ans_path);
	if (!instream) {
		cout << "error" << endl;
		cout << "请输入正确的文件名：input.txt" << endl;
		return -1;
	}
	getline(instream, str);
	cout << str << endl;
	size_t len = str.size();
	string tmp;
	int pos1 = 0, pos2;
	int ans1, ans2;
	while (1)
	{
		pos1 = str.find('a', pos1);
		pos2 = pos1 + 1;
		pos2 = str.find('a', pos2);
		if ((size_t)pos2 >= len) {
			cout << "finish" << endl;
			break;
		}
		if (pos2 - pos1 >= 21 || pos2 - pos1 <= 3) { //20验证
			cout << "pos1 = " << pos1 << endl;
			cout << "pos2 = " << pos2 << endl;

			tmp = str.substr(pos1 + 1, pos2 - pos1);
			int n = fun2(tmp, "CG");
			int q = 0, u = 0, j = 0;
			while (n--)
			{
				u = tmp.find("CG", q);
				//tmp.insert(tmp.begin() + q, '@');
				//tmp.insert(tmp.begin() + q + 3, '@');
				str.insert(str.begin() + pos1 + 1 + u + j * 2, '@');
				str.insert(str.begin() + pos1 +1 + u + 3 + j * 2, '@');
				q = u + 1;
				j++;
			}

			pos1 = pos2;
			continue;
		}
		else {
			tmp = str.substr(pos1, pos2 - pos1);
			ans1 = tmp.find_first_of("CG");
			ans2 = tmp.find_last_of("CG");
			if (ans1 == string::npos || ans2 == string::npos) {
				pos1 = pos2;
				continue;
			}
			else if (ans1 == ans2) {
				str.insert(str.begin() + pos1 + ans1, '#');
				str.insert(str.begin() + pos1 + ans2 + 2, '#');
			}
			else if (ans1 < ans2)
			{
				str.insert(str.begin() + pos1 + ans1, '#');
				str.insert(str.begin() + pos1 + ans2 + 2, '#');
			}
			else {
				pos1 = pos2;
				continue;
			}
		}
		cout << "pos1 = " << pos1 << endl;
		cout << "pos2 = " << pos2 << endl;

		pos1 = pos2;
	}
	outstream << str << endl;

	instream.close();
	outstream.close();

	return 0;

}
