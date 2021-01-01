// #define DEBUG
#include <iostream>
#include <stack>

using namespace std;

struct person{
    string name;
    bool is_alive;
    bool is_iterated;
    person *first_son;
    person *younger_brother;

    person(string &name){
        this->name = name;
        this->is_alive = true;
        this->is_iterated = false;
        this->first_son = nullptr;
        this->younger_brother = nullptr;
    }
};

person *kings[15000];
int kings_count = 0;
person *emp;

person *find(string &name)
{
    for(int i=0; i<kings_count; i++){
        if(kings[i]->name == name){
            return kings[i];
        }
    }
    return nullptr;
}

void birth(person *father,string &name){
    person *new_born = new person{name};
    kings[kings_count++] = new_born;

    if(father->first_son == nullptr){
        father->first_son = new_born;
        #ifdef DEBUG
        cout << father->name << "'s son is:" << name << endl;
        #endif
        return;
    }

    person *sibling = father->first_son;
    while(sibling->younger_brother!=nullptr){
        sibling = sibling->younger_brother;
    }
    sibling->younger_brother = new_born;
    #ifdef DEBUG
    cout << sibling->name << "'s son is:" << name << endl;
    #endif
}

void death(person *p){
    p->is_alive = false;
}

void print(person *p){
    cout << p->name.c_str() << endl;
}

void do_commands(){
    string command[3];

    cin >> command[0] >> command[1];
    if(command[0] == "birth"){
        cin >> command[2];
        birth(find(command[1]),command[2]);
    }else if(command[0] == "death"){
        find(command[1])->is_alive = false;
    }
}

void show_result(){
    stack<person*> kings;
    person *cur_king = emp;
    kings.push(emp);
    while(!kings.empty()){
        cur_king = kings.top();
        if(cur_king->first_son!=nullptr && !cur_king->first_son->is_iterated){
            kings.push(cur_king = cur_king->first_son);
        }
        else if(cur_king->younger_brother!=nullptr && !cur_king->younger_brother->is_iterated){
            kings.push(cur_king = cur_king->younger_brother);
        }else{
            kings.pop();
        }
        
        if(cur_king->is_alive&&!cur_king->is_iterated){
            print(cur_king);
        }

        cur_king->is_iterated = true;
    }
}

int main(){
    int command_c;
    char name[32];
    cin >> command_c >> name;
    string str_name{name};

    emp = new person(str_name);
    emp -> is_alive = false;
    kings[kings_count++] = emp;

    for(int i=0;i<command_c;i++){
        do_commands();
    }

    show_result();
    return 0;
}
