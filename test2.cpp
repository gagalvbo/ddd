#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int secret, guess, attempts = 0;
    int difficulty, max_num;
    char play_again;
    
    srand(time(nullptr));
    
    do {
        // 选择难度
        cout << "请选择难度：" << endl;
        cout << "1. 简单（1-50）" << endl;
        cout << "2. 普通（1-100）" << endl;
        cout << "3. 困难（1-200）" << endl;
        cout << "请输入（1/2/3）：";
        cin >> difficulty;
        
        // 根据难度设置范围
        if (difficulty == 1) {
            max_num = 50;
        } else if (difficulty == 2) {
            max_num = 100;
        } else {
            max_num = 200;
        }
        
        secret = rand() % max_num + 1;
        attempts = 0;
        
        cout << "\n欢迎来到猜数字游戏！" << endl;
        cout << "我已经想好了一个1-" << max_num << "之间的数字，你来猜猜看吧！" << endl << endl;
        
        while (true) {
            cout << "请输入你的猜测：";
            cin >> guess;
            attempts++;
            
            if (guess < secret) {
                cout << "太小了！再试试" << endl << endl;
            } else if (guess > secret) {
                cout << "太大了！再试试" << endl << endl;
            } else {
                cout << "恭喜你猜对了！你用了" << attempts << "次猜中了数字" << secret << endl << endl;
                break;
            }
        }
        
        cout << "还想再玩一次吗？(y/n)：";
        cin >> play_again;
        cout << endl;
        
    } while (play_again == 'y' || play_again == 'Y');
    
    cout << "感谢游玩！再见！" << endl;
    
    return 0;
}