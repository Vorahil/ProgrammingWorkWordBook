//
// Created by TairanLiu on 24-12-17.
//

#include "Register.h"

/**
 * 注册用户
 * @retur返回用户下标
 */
int Register::registerUserReturnIndex() {
    string input;
    string ct = "0-0-0";
    Customer user[MAX];
    char username[MAX], password[MAX], clockTime[MAX];

    char filename[MAX] = R"(../../resource/users.txt)";

    int userCount = Login::ReadUsersInf(filename, user);

    cout << "输入你的姓名" << endl;
    getline(cin, input);
    strcpy(username, input.c_str());
    cout << "输入密码" << endl;
    getline(cin, input);
    strcpy(password, input.c_str());
    strcpy(clockTime, ct.c_str());
    // 检查用户名是否已经存在
    for (int i = 0; i < userCount; i++) {
        if (strcmp(user[i].getUsersName(), username) == 0) {
            cout << "用户名已注册" << endl;
            return -1;
        }
    }

    // 注册新用户
    user[userCount].setUsersName(username);
    user[userCount].setPassword(password);
    user[userCount].setScore(0);
    user[userCount].setUsersName(clockTime);
    // 将新用户信息写入文件
    FILE *fp = fopen("../../resource/users.txt", "a"); // 打开文件以追加模式写入
    if (!fp) {
        cout << "打开要写入的用户文件时出错" << endl;
        return -1;
    }

    // 写入用户数据到文件
    fprintf(fp, "%s %s %d %s\n", username, password, 0, clockTime);
    fclose(fp);

    createFolder("C:/CodeWork/C/Programming/resource/wrongBook", username);
    cout << "注册成功" << endl;
    return userCount; // 返回新注册用户的索引
}

//创建文件夹
void Register::createFolder(const string &basePath, const std::string &newFolderName) {
    filesystem::path fullPath = filesystem::path(basePath) / newFolderName;
    filesystem::create_directories(fullPath);
}