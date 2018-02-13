/*
*猜字谜游戏
*/
#include <iostream>
#include <string>
using namespace std;
int main() {
	string target;
	cout << "请给出一个单词：";
	cin >> target;
	cout << string(100, '\n'); //输出100个换行，用来隐藏输入的单词
	int length = target.length();
	string attempt(length, '*'), badchars; //分别记录当前正确和错误的猜测
	int guesses = 5; //最大尝试次数
	cout << "单词已准备好，它有" << length << "个字母:" << attempt << endl;
	do {
		char letter;
		cout << "请猜测一个字母: ";
		cin >> letter; //badchars或attempt中已有letters
		if (badchars.find(letter) != string::npos ||
			attempt.find(letter) != string::npos) {
			cout << "已经猜过该字母，请重猜" << endl;
			continue; //string::npos匹配失败标志位
		}
		auto loc = target.find(letter); //使用auto自动推导loc类型
		if (loc == string::npos) {
			cout << "没有此字母!" << endl;
			--guesses; //允许错误次数-1
			badchars += letter; //猜错的字母放到badchars里
		}
		else {
			cout << "有这个字母，继续加油!" << endl;
			do {//把attempt里面相应的*用猜对的字母替换
				attempt[loc] = letter;//如果找到了，则下一次搜索从loc+1开始
				loc = target.find(letter, loc + 1);
			} while (loc != string::npos);
		}
		cout << "你猜测的单词:" << attempt << endl;
		if (attempt != target)
			cout << "剩余" << guesses << " 次猜错机会" << endl;
	} while (guesses > 0 && attempt != target);
	if (guesses > 0)
		cout << " 成功了，恭喜你！" << endl;
	else
		cout << "对不起，失败了，下次再挑战吧，单词是" << target << endl;
	return 0;
}
