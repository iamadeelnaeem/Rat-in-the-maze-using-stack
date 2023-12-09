//#include <iostream>
//#include<cstring>
//#include"Stack.h"
//#include"Stack.h"
//#include"Stack.cpp"
//using namespace std;
//
////task 2
//// precedence function for operators
//int precedence(char opr) {
//	if (opr == '+' || opr == '-') {
//		return 1;
//	}
//	if (opr == '*' || opr == '/') {
//		return 2;
//	}
//	if (opr == '^') {
//		return 3;
//	}
//	else{
//		return 0;
//	}
//
//}
////is balanced
//bool isBalanced(string exp) {
//	int i=0;
//	Stack<char> obj(1000);
//	while (exp[i]!='\0'){
//		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
//			obj.push(exp[i]);
//		}
//		else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
//		{
//			if (obj.isEmpty()) {
//				cout << "Invalid expression." << endl;
//				return false;
//			}
//			else{
//				if (exp[i]==')' &&obj.Top()=='('){
//					obj.pop();
//				}
//				else if(exp[i] == '}' && obj.Top() == '{'){
//					obj.pop();
//				}
//				else if (exp[i] == ']' && obj.Top() == '['){
//					obj.pop();
//				}
//				else{
//					cout << "Invalid expression." << endl;
//					return false;
//				}
//			}
//		}
//		i++;
//	}
//	if (obj.isEmpty()){
//		return true;
//	}
//	else{
//		return false;
//	}
//}
//
////infix to postfix
//string infixToPostfix(string exp) {
//	//int len = strlen(exp);
//	int i = 0;
//	string postFix;
//	Stack<char> obj(1000);
//
//	while (exp[i] != '\0') {
//		if (exp[i] >= 'a' && exp[i] <= 'z' || exp[i] >= 'A' && exp[i] <= 'Z') {
//			postFix += exp[i];
//			i++;
//		}
//		else if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[' ) {
//			obj.push(exp[i]);
//			i++;
//		}
//		else if (exp[i] == ')') {
//			while (obj.Top() != '(') {
//					postFix += obj.Top();
//					obj.pop();
//				}
//				obj.pop();
//				i++;
//			}
//		else{
//			while (!obj.isEmpty() && precedence(exp[i]) <= precedence(obj.Top())) {
//				postFix += obj.Top();
//				obj.pop();
//			}
//			obj.push(exp[i]);
//			i++;
//		}
//	}
//	while (!obj.isEmpty()) {
//		postFix += obj.Top();
//		obj.pop();
//	}  
//	return postFix;
//}
//	
//int main() {
////infix to postfix
//	string inFix;
//	cout << "Enter an expression: " << endl;
//	cin >> inFix;
//	cout << "'0' for expression not balanced. " << endl;
//	cout << "'1'for expression is balanced. " << endl;
//	cout <<"Expression is: "<< isBalanced(inFix) <<endl;
//	string postFix;
//	postFix = infixToPostfix(inFix);
//	cout << "Postfix is : " << postFix;
//
//	return 0;
//}
