#include <stack>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

//计算器类
class Calculator
{
public:
	Calculator();
	void getFormat();					//表达式自定义标准格式化
	int getPrior(char c);				//获取算术符号优先级
	void getPostfix();					//后缀表达式转换
	void calResult();					//计算后缀表达式
	void calculate();					//计算方法
	double getResult();					//获取结果

	string operatorSym;					//运算符号
	string infix;						//表达式缓存

private:
	vector<string> postfix;				//后缀表达式向量
	stack<char> symStack;				//符号栈
	stack<double> figStack;				//数字栈
	string stdInfix;					//自定义标准格式化表达式
	double result;						//最终计算结果
};
//Calculator.cpp: 实现文件
#include <stack>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

//绝对值符号个数的奇偶性
enum ABS_ODEVITY {
	ABS_ODD = 1,
	ABS_EVEN = 2,
};

//算术符号优先权等级
enum PRIO_LV {
	PRIO_LV0 = 0,
	PRIO_LV1 = 1,
	PRIO_LV2 = 2,
};

Calculator::Calculator() {				//构造函数，初始化成员变量

	result = 0.0;
}


//表达式自定义标准格式化
void Calculator::getFormat() {

	stdInfix = infix;

	//实现正负数
	//for (int i = 0; i < stdInfix.length(); i++) {					//string下标调用运算符时可能会导致类型溢出
	for (size_t i = 0; i < stdInfix.size(); i++) {					//string.size()返回size_type类型，避免下标运算时的类型溢出
		if (stdInfix[i] == '-' || stdInfix[i] == '+') {				//-x转换为0-x，+x转化为0+x
			if (i == 0) {
				stdInfix.insert(0, 1, '0');
			}
			else if (stdInfix[i - 1] == '(') {
				stdInfix.insert(i, 1, '0');
			}
		}
	}
}

//获取算术符号优先级
int Calculator::getPrior(char c) {

	if (c == '+' || c == '-') {
		return PRIO_LV1;
	}
	else if (c == '*' || c == '/') {
		return PRIO_LV2;
	}
	else {
		return PRIO_LV0;
	}
}

//后缀表达式转换
void Calculator::getPostfix() {

	int absNumeber = ABS_ODD;				//绝对值符号个数的奇偶性
	string tmp;

	//for (int i = 0; i < stdInfix.length(); i++) {
	for (size_t i = 0; i < stdInfix.size(); i++) {					//string.size()返回size_type类型，避免下标运算时的类型溢出
		tmp = "";
		switch (stdInfix[i]) {
		case '+':
		case '-':
		case '*':
		case '/':
		case '(':
		case ')':
			while (!symStack.empty() && symStack.top() != '(') {
				tmp += symStack.top();
				postfix.push_back(tmp);
				symStack.pop();
				tmp = "";
			}
			if (!symStack.empty() && symStack.top() == '(') {
				symStack.pop();							//将左括号出栈丢弃
			}
			break;
		default:
			if ((stdInfix[i] >= '0' && stdInfix[i] <= '9')) {
				tmp += stdInfix[i];
				while (i + 1 < stdInfix.length() && (stdInfix[i + 1] >= '0' && stdInfix[i + 1] <= '9' || stdInfix[i + 1] == '.')) {		//小数处理

					tmp += stdInfix[i + 1];			//是连续的数字，则追加
					i++;
				}
				if (tmp[tmp.length() - 1] == '.') {
					tmp += '0';						//将x.做x.0处理
				}
				postfix.push_back(tmp);
			}
			break;
		}//end switch
	}//end for

	while (!symStack.empty()) {						//将栈中剩余符号加入后缀表达式
		tmp = "";
		tmp += symStack.top();
		postfix.push_back(tmp);
		symStack.pop();
	}
}

//计算后缀表达式
void Calculator::calResult() {

	string tmp;
	double number = 0;
	double op1 = 0, op2 = 0;

	for (int i = 0; i < postfix.size(); i++) {
		tmp = postfix[i];
		if (tmp[0] >= '0' && tmp[0] <= '9') {
			number = atof(tmp.c_str());
			figStack.push(number);
		}
		else if (postfix[i] == "+") {
			if (!figStack.empty()) {
				op2 = figStack.top();
				figStack.pop();
			}
			if (!figStack.empty()) {
				op1 = figStack.top();
				figStack.pop();
			}
			figStack.push(op1 + op2);
		}
		else if (postfix[i] == "-") {
			if (!figStack.empty()) {
				op2 = figStack.top();
				figStack.pop();
			}
			if (!figStack.empty()) {
				op1 = figStack.top();
				figStack.pop();
			}
			figStack.push(op1 - op2);
		}
		else if (postfix[i] == "*") {
			if (!figStack.empty()) {
				op2 = figStack.top();
				figStack.pop();
			}
			if (!figStack.empty()) {
				op1 = figStack.top();
				figStack.pop();
			}
			figStack.push(op1* op2);
		}
		else if (postfix[i] == "/") {
			if (!figStack.empty()) {
				op2 = figStack.top();
				figStack.pop();
			}
			if (!figStack.empty()) {
				op1 = figStack.top();
				figStack.pop(); 
			}
			if (op2 != 0) {
				///除数不为0，未做处理，默认
			}
			figStack.push(op1 / op2);
		}
		
	}//end for
	if (!figStack.empty()) {
		result = figStack.top();
	}
}

//计算方法
void Calculator::calculate() {

	getFormat();				//表达式自定义标准格式化
	getPostfix();				//后缀表达式转换
	calResult();				//获取算术结果
}

//获取结果
double Calculator::getResult() {
	return result;
}
