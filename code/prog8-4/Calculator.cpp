#include "Calculator.h"

using namespace std;

 vector<string> Calculator::m_oprLib = { "+","-","*","/","%","(",")","#","=" }; // �������

// ȷ�����ȼ�, ֪ʶ����
int Calculator::getPrecedence(const string & s, bool isCurrent) const
{
	if (s == "=")
		return 0;
	else if (s == "#")
		return 1;
	else if (s == ")")
		return 2;
	else if (s == "+" || s == "-")
		return(isCurrent) ? 3 : 4;
	else if (s == "*" || s == "/" || s == "%")
		return(isCurrent) ? 5 : 6;
	else if (s == "(")
		return(isCurrent) ? 11 : 2;
	else
		return -1;
}

// ��ȡ�����
string Calculator::readOpr(string::const_iterator &it)
{
	string t;
	// ���˵Ⱥ��������ȡ�Ĳ�������, ѭ��ֱ�������������ƥ��
	while (!isNum(it))
	{	
		t += *it++;	
		// �����ѭ���Ĺ������ҵ����������������ͬ��, �򷵻�֮
		if (find(m_oprLib.begin(), m_oprLib.end(), t) != m_oprLib.end())
		{
			return t;
		}
	}
}

// ��ȡ������
double Calculator::readNum(string::const_iterator &it)
{
	string t;
	while (isNum(it))
	{
		t += *it++;
	}
	return stod(t);
}


// ����, ʹ�������ջ�Ͳ�����ջ����Ԫ�ؽ��м��㲢�޸�����ջ
void Calculator::calculate()
{
	// ��ʱ, �϶�������һ������
	double b = m_num.top();
	m_num.pop();
	double a;
	double c;
	string temp = m_opr.top();
	// ջ���������ջ
	m_opr.pop();
	// ˫Ŀ�������Ҫ��ջ���ڶ���������Ҳ��ջ
	if (temp == "+")
	{
		a = m_num.top();
		m_num.pop();
		c = a + b;
	}
	else if (temp == "-")
	{
		a = m_num.top();
		m_num.pop();
		c = a - b;
	}
	else if (temp == "*")
	{
		a = m_num.top();
		m_num.pop();
		c = a*b;
	}
	else if (temp == "/")
	{
		a = m_num.top();
		m_num.pop();
		c = a / b;
	}
	else if (temp == "%")
	{
		a = m_num.top();
		m_num.pop();
		c = (int)a % (int)b;
	}
	// ��Ŀ�����ֻ��Ҫһ����������ջ
	else if (temp == "(")
	{
		c = b;
	}
	else if (temp == "#")
	{
		c = b;
		// "#"��Ӧ��ջ
		m_opr.push(temp);
	}
	m_num.push(c);
}

// ���ַ������зָ������������, �˴�������++
void Calculator::process(const string &str)
{
	for (auto it = str.begin(); it != str.end();)
	{
		// ����ǲ�����, ѹջ֮
		if (isNum(it))
		{
			m_num.push(readNum(it));
		}
		// ����������, ѹջ�����
		else
		{
			string o = readOpr(it);
			// ���ջ�����ȼ���, �����
			while(!m_opr.empty() && getPrecedence(o, true) <= getPrecedence(m_opr.top(), false))
			{
				if (o == ")"&&m_opr.top() == "(")
				{
					m_opr.pop();
					break;
				}
				else if (o == "="&&m_opr.top() == "#")
				{
					break;
				}
				calculate();
			}
			// �������")"����ջ, �����, ������ջ
			if (o!=")")
			{
				m_opr.push(o);
			}
		}
	}

}

Calculator::Calculator()
{
	m_opr.push("#");
}


double Calculator::doIt(const string & eqt)
{
	process(eqt);
	return m_num.top();
}
