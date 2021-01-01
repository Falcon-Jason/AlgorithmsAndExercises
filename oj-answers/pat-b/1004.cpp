#include <iostream>

using namespace std;

class student{
private:
    string _name;
    string _id;
    int _score;

public:
    student(string name,string id,int score) : _name{name},_id{id},_score{score}{}

    student(student &stu):_name{stu._name},_id{stu._id},_score{stu._score}{}

    bool operator>(student &stu){
        return this->_score > stu._score;
    }

    bool operator<(student &stu){
        return this->_score < stu._score;
    }

    student &operator=(student &stu){
        _name = stu._name;
        _id = stu._id;
        _score = stu._score;

        return *this;
    }

    static student *read_stu()
    {
        char name[11], id[11];
        int score;
        cin >> name;
        cin >> id;
        cin >> score;
        return new student{string(name), string(id), score};
    }

    static void print_stu(student stu){
        cout << stu._name.c_str() << ' ' << stu._id.c_str() << endl;
    }

};


int main(int argc, char const *argv[])
{
    int line_c;
    cin >> line_c;

    student s_min = *student::read_stu();
    student s_max = s_min;
    

    for (int i = 0; i < line_c;i++){
        student *ps_cur = student::read_stu();

        if(*ps_cur > s_max)
            s_max = *ps_cur;
        else if(*ps_cur < s_min)
            s_min = *ps_cur;

        delete ps_cur;
    }

    student::print_stu(s_max);
    student::print_stu(s_min);
    return 0;
}
