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
	cout << string(100, '\n'); //通过100个换行，隐藏输入的单词
	int length = target.length();
	string attempt(length, '*'), badchars; //分别记录当前正确的猜测和错误的猜测 	 
	int guesses = 6; //最大尝试次数
	cout << "单词已准备好，它有" << length << "个字母:" << attempt << endl;
	do{
		char letter;
		cout << "Guess a letter: ";
		cin >> letter;		 
		if (badchars.find(letter) != string::npos || //badchars或attempt中已有letters  
			attempt.find(letter) != string::npos) { //string::npos是一个标志位 
			cout << "已经猜过该字母，请重猜" << endl;
			continue;
		}
		auto loc = target.find(letter);
		if (loc == string::npos) {
			cout << "没有此字母!" << endl;
			--guesses;
			badchars += letter;
		}else {
			cout << "有这个字母，继续加油!" << endl;
			do {
				attempt[loc] = letter;
				loc = target.find(letter, loc + 1); //如果找到了，则下一次搜索位置从loc+1开始 	
			} while (loc != string::npos);
		}
		cout << "你猜测的单词:" << attempt << endl;
		if (attempt != target)
			cout << "剩余" << guesses << " 次猜错机会" << endl;
	} while (guesses > 0 && attempt != target);
	if (guesses > 0)
		cout << " 成功了，恭喜你！" << endl;
	else
		cout << "对不起，失败了，下次再玩吧，单词是" << target << endl;
}