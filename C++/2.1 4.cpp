#include <iostream>

using namespace std;

void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a, b;
    
    cout << "=== 变量交换演示 ===" << endl;
    cout << "请输入两个整数: ";
    cin >> a >> b;

    cout << "\n>>> 初始状态: a = " << a << ", b = " << b << endl;
    cout << "--------------------------------" << endl;

    swap(a, b); 
    cout << ">>> 调用 [引用版本] 交换后:" << endl;
    cout << "    a = " << a << ", b = " << b << endl;

    swap(&a, &b); 
    cout << ">>> 调用 [指针版本] 交换后:" << endl;
    cout << "    a = " << a << ", b = " << b << endl;
    
    cout << "--------------------------------\n" << endl;

    system("pause");
    return 0;
}
