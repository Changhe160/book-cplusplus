/*
*��������Ϸ
*/
#include <iostream>  
#include <string>  
using namespace std;

int main() {
	string target;
	cout << "�����һ�����ʣ�";
	cin >> target;
	cout << string(100, '\n'); //ͨ��100�����У���������ĵ���
	int length = target.length();
	string attempt(length, '*'), badchars; //�ֱ��¼��ǰ��ȷ�Ĳ²�ʹ���Ĳ²� 	 
	int guesses = 6; //����Դ���
	cout << "������׼���ã�����" << length << "����ĸ:" << attempt << endl;
	do{
		char letter;
		cout << "Guess a letter: ";
		cin >> letter;		 
		if (badchars.find(letter) != string::npos || //badchars��attempt������letters  
			attempt.find(letter) != string::npos) { //string::npos��һ����־λ 
			cout << "�Ѿ��¹�����ĸ�����ز�" << endl;
			continue;
		}
		auto loc = target.find(letter);
		if (loc == string::npos) {
			cout << "û�д���ĸ!" << endl;
			--guesses;
			badchars += letter;
		}else {
			cout << "�������ĸ����������!" << endl;
			do {
				attempt[loc] = letter;
				loc = target.find(letter, loc + 1); //����ҵ��ˣ�����һ������λ�ô�loc+1��ʼ 	
			} while (loc != string::npos);
		}
		cout << "��²�ĵ���:" << attempt << endl;
		if (attempt != target)
			cout << "ʣ��" << guesses << " �β´����" << endl;
	} while (guesses > 0 && attempt != target);
	if (guesses > 0)
		cout << " �ɹ��ˣ���ϲ�㣡" << endl;
	else
		cout << "�Բ���ʧ���ˣ��´�����ɣ�������" << target << endl;
}