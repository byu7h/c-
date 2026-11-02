#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>
#include <cstdlib>

using namespace std;

// ================== 1. 声明部分 ==================
const double FEE_RATE = 0.02;        // 充值手续费率
const double WARNING_BALANCE = 10.0; // 低余额警戒值

struct Card {
    int id;           // 学号
    string name;      // 姓名
    double balance;   // 当前余额
    int transactions; // 交易次数
};

namespace card {
    void printSep(char c = '-', int len = 65); // 改变分隔线样式
    Card* createCards(int n);
    void destroyCards(Card* p);
    void inputCards(Card* arr, int n);
    void deposit(Card& c, double amount, double fee = FEE_RATE);
    bool spend(Card& c, double cost);
    bool spend(Card& c, double cost, const string& item);
    void showBalance(const Card& c);
    void viewStudentID(const Card* p);
    int toCent(double amount);
    void printReport(const Card* arr, int n);
}

// ================== 2. 实现部分 ==================
namespace card {

    void printSep(char c, int len) {
        for (int i = 0; i < len; ++i) cout << c;
        cout << endl;
    }

    Card* createCards(int n) {
        try {
            return new Card[n];
        } catch (const bad_alloc& e) {
            cerr << " [系统错误] 内存分配失败：" << e.what() << endl;
            exit(EXIT_FAILURE);
        }
    }

    void destroyCards(Card* p) {
        delete[] p;
    }

    void inputCards(Card* arr, int n) {
        for (int i = 0; i < n; ++i) {
            cout << " 录入第 [" << i + 1 << "/" << n << "] 个账户 (学号 姓名 余额): ";
            try {
                cin >> arr[i].id >> arr[i].name >> arr[i].balance;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    throw runtime_error("格式非法，请输入正确的数据类型！");
                }
                if (arr[i].balance < 0) {
                    throw invalid_argument("余额不可为负数！");
                }
                arr[i].transactions = 0;
            } catch (const exception& e) {
                cout << " [!] 录入失败：" << e.what() << " 请重新输入。\n";
                i--; 
            }
        }
    }

    void deposit(Card& c, double amount, double fee) {
        try {
            if (amount <= 0) throw invalid_argument("充值金额必须大于0！");
            c.balance += amount * (1.0 - fee);
            c.transactions++;
            cout << " [成功] " << c.name << " 充值 " << amount << " 元，扣除手续费后余额为: " << c.balance << " 元\n";
        } catch (const exception& e) {
            cout << " [充值异常] " << e.what() << endl;
        }
    }

    bool spend(Card& c, double cost) {
        try {
            if (cost < 0) throw invalid_argument("消费金额不可为负！");
            if (c.balance < cost) throw runtime_error("余额不足，交易拦截！");
            c.balance -= cost;
            c.transactions++;
            return true;
        } catch (const exception& e) {
            cout << " [消费异常] " << e.what() << endl;
            return false;
        }
    }

    bool spend(Card& c, double cost, const string& item) {
        cout << " -> 尝试消费: " << item << " (" << cost << " 元)" << endl;
        return spend(c, cost);
    }

    void showBalance(const Card& c) {
        cout << fixed << setprecision(2);
        cout << " " << c.name << " 的当前余额: " << c.balance << " 元" << endl;
    }

    void viewStudentID(const Card* p) {
        cout << " 绑定的学号 ID  : " << p->id << endl;
    }

    int toCent(double amount) {
        return static_cast<int>(amount * 100);
    }

    void printReport(const Card* arr, int n) {
        printSep('=', 65);
        // 使用竖线 | 来分割表头，显得更像正规表格
        cout << "| " << left << setw(8) << "ID" 
             << "| " << setw(14) << "Name" 
             << "| " << right << setw(14) << "Balance(元)" 
             << "| " << setw(12) << "Trans" << " |" << endl;
        printSep('-', 65);
        
        cout.setf(ios::fixed); 
        cout << setprecision(2);
        
        for (int i = 0; i < n; ++i) {
            cout << "| " << left << setw(8) << arr[i].id 
                 << "| " << setw(14) << arr[i].name 
                 << "| " << right << setw(14) << arr[i].balance 
                 << "| " << setw(12) << arr[i].transactions << " |" << endl;
        }
        printSep('=', 65);
    }
} 

// ================== 3. 主程序部分 ==================
int main() {
    card::printSep('*', 65);
    cout << ">>> 校园一卡通消费管理系统 v2.0 正在启动 <<<" << endl;
    card::printSep('*', 65);

    cout << "\n请输入需要注册的学生总数: ";
    int n;
    cin >> n;

    Card* accounts = card::createCards(n);

    cout << "\n[ 账户初始化模块 ]" << endl;
    card::inputCards(accounts, n);
    card::printSep();

    cout << "\n[ 业务模拟模块 ] 正在对首个账户进行测试..." << endl;
    // 充值100元
    card::deposit(accounts[0], 100.0); 
    // 消费
    card::spend(accounts[0], 8.5, "食堂午餐");
    card::spend(accounts[0], 2.0, "超市矿泉水");
    card::printSep();

    cout << "\n[ 安全信息查询模块 ]" << endl;
    card::showBalance(accounts[0]);
    card::viewStudentID(&accounts[0]); 
    cout << " 余额(分)转换   : " << card::toCent(accounts[0].balance) << " 分" << endl;
    card::printSep();

    cout << "\n[ 全局数据报表 ]" << endl;
    card::printReport(accounts, n);

    card::destroyCards(accounts);

    system("pause");
    return 0;
}