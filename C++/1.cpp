#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    int n;
    cout << "请输入学生人数: ";
    cin >> n;
    
    cout << "\n================ 学生成绩单 ================" << endl;
    cout << left << setw(12) << "姓名" 
         << setw(10) << "语文" 
         << setw(10) << "数学" 
         << setw(10) << "英语" 
         << setw(10) << "平均分" << endl;
    cout << "--------------------------------------------" << endl;

    for (int i = 0; i < n; i++) {
        string name;
        double chinese, math, english;
        
        cout << "录入第 " << i + 1 << " 位同学 (格式: 姓名 语 数 英): ";
        cin >> name >> chinese >> math >> english;

        double avg = (chinese + math + english) / 3.0;

        cout << left << setw(12) << name 
             << setw(10) << fixed << setprecision(2) << chinese 
             << setw(10) << fixed << setprecision(2) << math 
             << setw(10) << fixed << setprecision(2) << english 
             << setw(10) << fixed << setprecision(2) << avg;

        if (avg >= 90.0) {
            cout << "Excellent";
        }
        cout << endl;
    }
    cout << "============================================\n" << endl;
    
    system("pause"); 
    return 0;
}