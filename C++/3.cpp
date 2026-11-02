#include <iostream>
#include <iomanip>

using namespace std;

inline double square(double x) {
    return x * x;
}

double power(double base, int exponent = 2) {
    double result = 1.0;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

double calc(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) {
                cout << "? 错误: 除数不能为 0!" << endl;
                return 0.0;
            }
            return a / b;
        default: return 0.0;
    }
}

double calc(int a, int b, char op) {
    return calc(static_cast<double>(a), static_cast<double>(b), op);
}

int main() {
    cout << fixed << setprecision(2); 

    double num1, num2;
    char op;
    
    cout << "=== 多功能数学计算器 ===" << endl;
    cout << "请输入两个数字和运算符号 (空格分隔): ";
    cin >> num1 >> num2 >> op;

    cout << "\n--- 数学运算结果 ---" << endl;
    cout << "1. 第一个数字的平方: " << square(num1) << endl;
    cout << "2. 第一个数字的默认乘幂(2次方): " << power(num1) << endl;
    cout << "3. 第一个数字的3次幂: " << power(num1, 3) << endl;
    
    double res = calc(num1, num2, op);
    if (!(op == '/' && num2 == 0)) {
        cout << "4. 四则运算(" << op << "): " << num1 << " " << op << " " << num2 << " = " << res << endl;
    }
    cout << "--------------------\n" << endl;

    system("pause");
    return 0;
}