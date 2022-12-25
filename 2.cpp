#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s1;
    stack<int> s2;

    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);

    s2.push(6);
    s2.push(7);
    s2.push(8);
    s2.push(9);
    s2.push(10);

    stack<int> res;

    int s1_size = s1.size();
    int s2_size = s2.size();

    for (int i = 0; i < s1_size; i++) {
        int val = s1.top();

        if (val % 2 == 0) {
            res.push(val);
        }

        s1.pop();
    }

    for (int i = 0; i < s2_size; i++) {
        int val = s2.top();

        if (val % 2 == 0) {
            res.push(val);
        }

        s2.pop();
    }

    //Вывод
    int res_size = res.size();

    for (int i = 0; i < res_size; i++) {
        cout << res.top() << endl;
        res.pop();
    }
    
}