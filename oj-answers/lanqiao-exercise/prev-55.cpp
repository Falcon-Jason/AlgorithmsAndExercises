#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>

enum COMMAND_PATTERN
{
    CLEAR = 0,
    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
    NUM,
    CHANGE,
    EQUAL,
    UNKNOWN = -1,
};

using namespace std;

long long memoriedNumber = 1;  // 记录的上一数字
int memoriedOperator = SUB; // 记录的上一操作符
long long currentAnswer = 0;   // 当前结果值
int currentScale = 10;      // 当前进制

void execute(const string &command); // 执行指令

int main()
{
    int size;
    string command;
    getline(cin, command);
    size = atoi(command.c_str());
    for (int i = 0; i < size; i++)
    {
        getline(cin, command);
        execute(command);
    }
}

COMMAND_PATTERN commandPattern(const string &command_name);
long long parseInt(const string &str);
void printInt(long long val);
void calculate();

void execute(const string &command)
{
    istringstream in(command);
    string name;
    in >> name;
    COMMAND_PATTERN pattern = commandPattern(name);
    switch (pattern)
    {
    case ADD:
    case SUB:
    case MUL:
    case DIV:
    case MOD:
    case CLEAR:
    {
        memoriedOperator = pattern;
        break;
    }
    case NUM:
    {
        string argument;
        in >> argument;
        memoriedNumber = parseInt(argument);
        calculate();
        break;
    }
    case CHANGE:
    {
        in >> currentScale;
        break;
    }
    case EQUAL:
    {
        printInt(currentAnswer);
        putchar('\n');
        break;
    }
    default:
    {
        break;
    }
    }
}

COMMAND_PATTERN commandPattern(const string &command_name)
{
    if (command_name == "CLEAR")
        return CLEAR;
    if (command_name == "ADD")
        return ADD;
    if (command_name == "SUB")
        return SUB;
    if (command_name == "MUL")
        return MUL;
    if (command_name == "DIV")
        return DIV;
    if (command_name == "MOD")
        return MOD;
    if (command_name == "NUM")
        return NUM;
    if (command_name == "CHANGE")
        return CHANGE;
    if (command_name == "EQUAL")
        return EQUAL;
    return UNKNOWN;
}

long long parseInt(const string &str)
{
    long long ans = 0;
    for (string::const_iterator i = str.begin(); i != str.end(); i++)
    {
        if (*i == '-')
            ans = -ans;
        ans *= currentScale;
        ans += isdigit(*i) ? *i - '0' : *i - 'A' + 1;
    }
    return ans;
}
void printInt(long long val)
{
    const static char model[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    if (val < 0)
    {
        putchar('-');
        val = -val;
    }
    if (val / currentScale)
        printInt(val / currentScale);
    putchar(model[val % currentScale]);
}

void calculate()
{
    switch (memoriedOperator)
    {
    case ADD:
        currentAnswer += memoriedNumber;
        break;
    case SUB:
        currentAnswer -= memoriedNumber;
        break;
    case MUL:
        currentAnswer *= memoriedNumber;
        break;
    case DIV:
        currentAnswer /= memoriedNumber;
        break;
    case MOD:
        currentAnswer %= memoriedNumber;
        break;
    case CLEAR:
        currentAnswer = memoriedNumber;
        break;
    default:
        currentAnswer = 0;
        break;
    }
    
}

// Partly Accepted: http://lx.lanqiao.cn/detail.page?submitid=3710259