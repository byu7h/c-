#include <iostream>
#include <string>

using namespace std;

// 1. 定义冰箱类
class Fridge {
private:
    string brand;
    bool doorOpen;

public:
    Fridge(string name = "海尔") : brand(name), doorOpen(false) {}

    void openDoor() {
        doorOpen = true;
        cout << "[" << brand << "冰箱] 门已打开。" << endl;
    }

    void closeDoor() {
        doorOpen = false;
        cout << "[" << brand << "冰箱] 门已关闭。" << endl;
    }

    bool isDoorOpen() {
        return doorOpen;
    }

    void showStatus() {
        cout << "冰箱状态：门" << (doorOpen ? "开着" : "关着") << endl;
    }
};

// 2. 定义大象类
class Elephant {
private:
    string name;

public:
    Elephant(string n = "小飞象") : name(n) {}

    void enterFridge(Fridge& fridge) {
        if (fridge.isDoorOpen()) {
            cout << "[" << name << "] 走进了冰箱。" << endl;
        } else {
            cout << "[" << name << "] 发现门关着，进不去！" << endl;
        }
    }
};

// 3. 主程序
int main() {
    cout << "===== 大象装进冰箱程序 =====" << endl;

    Fridge fridge("海尔");
    Elephant elephant("小飞象");

    cout << "\n--- 第一步：打开冰箱门 ---" << endl;
    fridge.openDoor();

    cout << "\n--- 第二步：大象走进冰箱 ---" << endl;
    elephant.enterFridge(fridge);

    cout << "\n--- 第三步：关闭冰箱门 ---" << endl;
    fridge.closeDoor();

    cout << "\n--- 最终状态 ---" << endl;
    fridge.showStatus();

    return 0;
}
