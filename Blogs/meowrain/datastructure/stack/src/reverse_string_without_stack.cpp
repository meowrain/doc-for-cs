#include <iostream>
#include <string>
using namespace std;
void reverse_string(string &s) {
    int len = s.length();
    for (int i = 0; i < len / 2; i++) {
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
}
int main(void) {
    string s = "hello";
    cout << "The valine of s is: " << s << endl;
    reverse_string(s);
    cout << "The reverse result of s is: " << s << endl;
    return 0;
}