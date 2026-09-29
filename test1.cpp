// C++版本：guess_number.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int secret, guess, attempts = 0;
    char play_again;
    
    srand(time(nullptr));  // C++11推荐用nullptr代替NULL
    
    do {
        secret = rand() % 100 + 1;
        attempts = 0;
        
        cout << "欢迎来到猜数字游戏！" << endl;
        cout << "我已经想好了一个1-100之间的数字，你来猜猜看吧！" << endl << endl;
        
        while (true) {  // C++可以直接用true/false
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