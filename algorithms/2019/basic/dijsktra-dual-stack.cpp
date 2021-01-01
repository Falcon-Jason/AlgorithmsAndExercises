#include <cstdio>
#include <cctype>
#include <stack>

using namespace std;

stack<double> values{};
stack<int> operators{};

int calculate_once()
{
    double b = values.top();
    values.pop();

    double a = values.top();
    values.pop();

    int op = operators.top();
    operators.pop();

    double res;
    
    switch(op)
    {
        case '+':
            res = a + b;
            break;
        case '-':
            res = a - b;
            break;
        case '*':
            res = a * b;
            break;
        case '/':
            res = a / b;
            break;
        default:
            return 0;
    }

    values.push(res);
    return 1;
}

int main()
{
    double next_value;
    int next_char;
    
    while((next_char = getchar())!='\n')
    {
        if(isspace(next_char))
        {
            continue;
        }

        if(isdigit(next_char))
        {
            ungetc(next_char, stdin);
            scanf("%lf", &next_value);
            values.push(next_value);
        }
        else
        {
            switch(next_char)
            {
                case '(':
                    break;
                case '+':
                case '-':
                case '*':
                case '/':
                    operators.push(next_char);
                    break;
                case ')':
                    if(!calculate_once())
                    {
                        printf("ERROR\n");
                        return 0;
                    }
            }
        }
    }

    printf("%lg\n", (values.top()));
    return 0;
}