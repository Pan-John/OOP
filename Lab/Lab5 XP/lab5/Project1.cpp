#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

int s1_len, s2_len;
char hextable[16] = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' };

int add(char s1[], char s2[]) {
    int i, j;
    int num1[100] = { 0 }, num2[100] = { 0 };
    for (i = s1_len - 1, j = 0; i >= 0; i--, j++) {
        num1[j] = s1[i] - '0';
        if (num1[j] > 9)
            num1[j] -= 39;
    }
    for (i = s2_len - 1, j = 0; i >= 0; i--, j++) {
        num2[j] = s2[i] - '0';
        if (num2[j] > 9)
            num2[j] -= 39;
    }

    for (i = 0; i < 100; i++) {
        num1[i] += num2[i];
        if (num1[i] >= 16) {
            num1[i] -= 16;
            num1[i + 1]++;
        }
    }

    i = 99;
    while (i >= 0 && num1[i] == 0) {
        i--;
    }
    if (i > 0) {
        for (; i >= 0; i--) {
            cout << hextable[num1[i]];
        }
        cout << endl;
    }
    else {
        cout << "error" << endl;
    }
    return 0;
}

int minuss(char s1[], char s2[]) {
    int i, j;
    int num1[100] = { 0 }, num2[100] = { 0 };
    if (s1_len < s2_len) {
        for (i = s1_len - 1, j = 0; i >= 0; i--, j++) {
            num2[j] = s1[i] - '0';
            if (num2[j] > 9)
                num2[j] -= 39;
        }
        for (i = s2_len - 1, j = 0; i >= 0; i--, j++) {
            num1[j] = s2[i] - '0';
            if (num1[j] > 9)
                num1[j] -= 39;
        }
    }
    else {
        if (strcmp(s1, s2) > 0) {
            for (i = s1_len - 1, j = 0; i >= 0; i--, j++) {
                num1[j] = s1[i] - '0';
                if (num1[j] > 9)
                    num1[j] -= 39;
            }
            for (i = s2_len - 1, j = 0; i >= 0; i--, j++) {
                num2[j] = s2[i] - '0';
                if (num2[j] > 9)
                    num2[j] -= 39;
            }
        }
        else if (strcmp(s1, s2) < 0) {
            cout << "-";
            for (i = s1_len - 1, j = 0; i >= 0; i--, j++) {
                num2[j] = s1[i] - '0';
                if (num2[j] > 9)
                    num2[j] -= 39;

            }
            for (i = s2_len - 1, j = 0; i >= 0; i--, j++) {
                num1[j] = s2[i] - '0';
                if (num1[j] > 9)
                    num1[j] -= 39;
            }
        }
        else {
            cout << "0" << endl;
            return 0;
        }
    }


    for (i = 0; i < 100; i++) {
        num1[i] -= num2[i];
        if (num1[i] < 0) {
            num1[i] += 16;
            num1[i + 1]--;
        }
    }

    i = 99;
    while (i > 0 && num1[i] == 0) {
        i--;
    }
    for (; i >= 0; i--) {
        cout << hextable[num1[i]];
    }
    cout << endl;
    return 0;
}

int main() {
    int lines;
    char oper;
    string str;
    stringstream ss;
    ifstream input;

    input.open("input1.txt");
    getline(input, str);
    ss << str;
    ss >> lines;
    for (int k = 0; k < lines; k++) {
        char s1[100] = { 0 }, s2[100] = { 0 };
        getline(input, str);

        int flag = 0, i = 0, j = 0, l = 0;
        while (flag != 1) {
            if ((str[i] == '+' || str[i] == '-') && (i != 0)) {
                s1_len = i;
                oper = str[i];
                flag = 1;
                for (j = i + 1; j < str.length(); j++) {
                    s2[l] = str[j];
                    l++;
                }
                s2_len = l;
            }
            else {
                s1[i] = str[i];
                i++;
            }
        }

        cout << k + 1 << endl;
        cout << "num1: " << s1 << endl;
        cout << "num2: " << s2 << endl;
        cout << "result: ";

        if (s1[0] == '-' && oper == '-') {//-a-b
            char s3[100] = { 0 };
            for (int m = 1; m < s1_len; m++) {
                s3[m - 1] = s1[m];
            }
            s1_len--;
            cout << "-";
            add(s3, s2);
        }
        else if (s1[0] != '-' && oper == '+') {//a+b
            add(s1, s2);
        }
        else if (s1[0] == '-' && oper == '+') {//-a+b
            char s3[100] = { 0 };
            for (int m = 1; m < s1_len; m++) {
                s3[m - 1] = s1[m];
            }
            s1_len--;
            minuss(s3, s2);
        }
        else {//a-b
            minuss(s1, s2);
        }
        cout << endl;
    }

    input.close();
    system("pause");
    return 0;
}