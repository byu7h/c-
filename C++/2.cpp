#include <iostream>

using namespace std;

int countVowels(const char* p) {
    int count = 0;
    while (*p != '\0') {
        char c = *p;
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            count++;
        }
        p++;
    }
    return count;
}

int main() {
    const int MAX_LENGTH = 1000;
    char str[MAX_LENGTH];

    cout << "【元音字母统计器】" << endl;
    cout << "请输入一行英文句子: ";
    cin.getline(str, MAX_LENGTH); 

    int vowelCount = countVowels(str);
    
    cout << "----------------------------------" << endl;
    cout << "分析完毕！该句子中包含的元音字母总数为: [ " << vowelCount << " ] 个" << endl;
    cout << "----------------------------------" << endl;

    system("pause");
    return 0;
}