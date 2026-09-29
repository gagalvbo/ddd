#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int secret, guess, attempts = 0;
    int max_num = 100;
    char play_again;
    bool hint_used;
    
    srand(time(nullptr));
    
    do {
        secret = rand() % max_num + 1;
        attempts = 0;
        hint_used = false;  // 每次游戏重置提示
        
        cout << "欢迎来到猜数字游戏！" << endl;
        cout << "我已经想好了一个1-" << max_num << "之间的数字，你来猜猜看吧！" << endl;
        cout << "（输入0可以获得一次提示）" << endl << endl;
        
        while (true) {
            cout << "请输入你的猜测：";
            cin >> guess;
            
            // 提示功能
            if (guess == 0) {
                if (hint_used) {
                    cout << "你已经用过提示了！" << endl << endl;
                } else {
                    int hint_min = (secret > 10) ? secret - 10 : 1;
                    int hint_max = (secret < max_num - 10) ? secret + 10 : max_num;
                    cout << "提示：答案在" << hint_min << "-" << hint_max << "之间" << endl << endl;
                    hint_used = true;
                }
                continue;  // 不算一次猜测
            }
            
            attempts++;
            
            if (guess < secret) {
                cout << "太小了！再试试" << endl << endl;
            } else if (guess > secret) {
                cout << "太大了！再试试" << endl << endl;
            } else {
                cout << "恭喜你猜对了！你用了" << attempts << "次猜中了数字" << secret << endl;
                if (hint_used) {
                    cout << "（你使用了提示）" << endl;
                }
                cout << endl;
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