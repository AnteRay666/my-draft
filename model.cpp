#include <bits/stdc++.h>
using namespace std;

void qinyou() // 注意亲友团都有偏好。
{
    char a;
    string no;
    string qy2[26][6];
    for (int ii = 0; ii < 26; ii++)
    {
        for (int jj = 0; jj < 6; jj++)
        {
            qy2[ii][jj] += "[";
        }
    }
    int ascii = 65;
    int i = 0;
    int j = 0;
    while (cin >> a)
    {
        if ((int)("%d", a) == 48)
            break;
        if ((int)("%d", a) == ascii)
        {
            cin >> no;
            if (no == "硬卧") // 偏好类型
                qy2[i][j] += "1,";
            cin >> no;
            if (no == "上")
                qy2[i][j] += "2,"; // 偏好位置
            else
                qy2[i][j] += "1,";
            cin >> no;
            if (no == "男")
                qy2[i][j] += "1,"; // 性别
            else
                qy2[i][j] += "2,";
            cin >> no;
            if (no == "是")
                qy2[i][j] += "1,"; // 是否为老人
            else
                qy2[i][j] += "2,";
            j++;
        }
        else
        {
            ascii++;
            i++;
        }
    }
    for (int ii = 0; ii < 26; ii++)
    {
        for (int jj = 0; jj < 6; jj++)
        {
            qy2[ii][jj] += "0";
            qy2[ii][jj] += "]";
        }
    }
    for (int ii = 0; ii < 26; ii++)
    {
        int jj = 0;
        if (qy2[ii][jj] != "[0]")
            cout << qy2[ii][jj] << endl;
        else
            jj++;
        if (jj > 5)
            continue;
    }
}

void sanke() // 散客中含有无偏好群体
{
    string no;
    string sk[300];
    for (int i = 0; i < 300; i++)
    {
        sk[i] = "[";
    }
    int j;
    cin >> no;
    string no1;
    for (j = 0; no != "0"; j++)
    {

        if (no == "软卧")
            sk[j] += "1,";

        else
            sk[j] += "2,";

        cin >> no1; // 偏爱位置1

        if (no1 == "无")
            sk[j] += "0,";
        else if (no1 == "上")
            sk[j] += "3,";
        else if (no1 == "中")
            sk[j] += "2,";
        else
            sk[j] += "1,";

        cin >> no1; // 偏爱位置2
        if (no1 == "无")
            sk[j] += "0,";
        else if (no1 == "上")
            sk[j] += "3,";
        else if (no1 == "中")
            sk[j] += "2,";
        else
            sk[j] += "1,";

        cin >> no1; // 性别

        if (no1 == "男")
            sk[j] += "1,";
        else
            sk[j] += "2,";

        cin >> no1; // 是否为老人

        if (no1 == "是")
            sk[j] += "1,";
        else
            sk[j] += "0,";

        cout << sk[j] << endl;
        cin >> no;
    }

    // test

    for (int i = 0; i < 300; i++)
    {
        sk[i] += "0]";
    }
    for (int i = 0; i < 300; i++)
    {
        cout << sk[i] << endl;
    }
}

int main()
{
    // 部分散客没软硬卧偏好和上下铺偏好。
    // 这里，通过数字电路语言来描述。
    //  qinyou();
    sanke();
    system("pause");
    return 0;
}