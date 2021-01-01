#include <deque>
#include <iostream>
#include <map>
#include <vector>

#define SET 1
#define PRINT 2
#define LOCK 3
#define UNLOCK 4
#define END 0

#define POP_BACK(q)         \
    ({                      \
        int __x = q.back(); \
        q.pop_back();       \
        __x;                \
    })
#define POP_FRONT(q)         \
    ({                       \
        int __x = q.front(); \
        q.pop_front();       \
        __x;                 \
    })

using namespace std;

class Statement {
private:
    int op;   // opcode
    int var;  // variable
    int val;  // value

public:
    int opcode() { return op; }
    int variable() { return var; }
    int value() { return val; }

    friend ostream &operator<<(ostream &out, const Statement &stmt);
    friend istream &operator>>(istream &in, Statement &stmt);
};

class Program {
private:
    int index;
    vector<Statement> stmts;

public:
    Program() : index{0}, stmts{} {}

    Statement &get() { return stmts[index++]; }
    void unget() { index--; }

    friend istream &operator>>(istream &in, Program &prog);
    friend ostream &operator<<(ostream &out, const Program &prog);
};

class VirtualMachine {
private:
    constexpr static int OP_COUNT = 5;
    constexpr static int VAR_COUNT = 26;
    constexpr static int TERMINATED = -1;
    vector<Program> progs;
    int prog_count;
    int unit_time[OP_COUNT];
    int quantum;
    deque<int> ready{};
    deque<int> block{};
    int variables[VAR_COUNT];
    bool locked = false;
    void clear();
    int executeSingleStatement(int prog_id);
    int executeProgram(int prog_id);

public:
    friend istream &operator>>(istream &in, VirtualMachine &vm);
    friend ostream &operator<<(ostream &out, const VirtualMachine &vm);
    void execute();
};

int main() {
    VirtualMachine vm;
    string line;
    int times;
    getline(cin, line);
    sscanf(line.data(), "%d", &times);
    // cout << times << endl;
    for (int i = 1; i <= times; i++) {
        getline(cin, line);
        cin >> vm;
        vm.execute();
        if (i != times)
            cout << endl;
    }
}

istream &operator>>(istream &in, Statement &stmt) {
    const static map<string, int> no_arg_op{make_pair("lock", LOCK),
                                            make_pair("unlock", UNLOCK),
                                            make_pair("end", END)};

    string line;
    getline(in, line);
    if (no_arg_op.count(line)) {
        // parse lock, unlock and end statement.
        stmt.op = no_arg_op.at(line);
        stmt.var = stmt.val = 0;
        return in;
    } else if (line.substr(0, 5) == "print") {
        // parse print statement.
        stmt.op = PRINT;
        stmt.var = line.back() - 'a';
        stmt.val = 0;
        return in;
    } else {
        // parse set statement.
        stmt.op = SET;
        stmt.var = line[0] - 'a';
        sscanf(line.substr(line.find('=') + 1).data(), "%d", &stmt.val);
        return in;
    }
}

ostream &operator<<(ostream &out, const Statement &stmt) {
    out << stmt.op << " " << stmt.var << " " << stmt.val;
    return out;
}

istream &operator>>(istream &in, Program &prog) {
    prog.stmts.clear();
    Statement stmt;
    do {
        in >> stmt;
        prog.stmts.push_back(stmt);
    } while (stmt.opcode() != END);
    return in;
}

ostream &operator<<(ostream &out, const Program &prog) {
    for (auto i = prog.stmts.begin(); i != prog.stmts.end(); ++i) {
        out << *i << endl;
    }
    return out;
}

istream &operator>>(istream &in, VirtualMachine &vm) {
    vm.clear();

    string line;
    getline(cin, line);

    sscanf(line.data(), "%d%d%d%d%d%d%d", &vm.prog_count, &vm.unit_time[SET],
           &vm.unit_time[PRINT], &vm.unit_time[LOCK], &vm.unit_time[UNLOCK],
           &vm.unit_time[END], &vm.quantum);

    vm.progs.push_back(Program{});
    for (int i = 0; i < vm.prog_count; i++) {
        vm.progs.push_back(Program{});
        in >> vm.progs.back();
    }
    return in;
}

ostream &operator<<(ostream &out, const VirtualMachine &vm) {
    for (int i = 1; i <= vm.prog_count; i++) {
        out << "[" << i << "]:" << endl;
        out << vm.progs[i] << endl;
    }
    return out;
}

void VirtualMachine::clear() {
    progs.clear();
    ready.clear();
    block.clear();
    for (int i = 0; i < VAR_COUNT; i++) {
        variables[i] = 0;
    }
    locked = false;
}

int VirtualMachine::executeSingleStatement(int prog_id) {
    Statement &toexec = progs[prog_id].get();
    switch (toexec.opcode()) {
        case SET:
            variables[toexec.variable()] = toexec.value();
            break;
        case PRINT:
            cout << prog_id << ": " << variables[toexec.variable()] << endl;
            break;
        case LOCK:
            if (locked) {
                block.push_back(prog_id);
                progs[prog_id].unget();
                return TERMINATED;
            }
            locked = true;
            break;
        case UNLOCK:
            locked = false;
            if (!block.empty()) {
                ready.push_front(POP_FRONT(block));
            }
            break;
        case END:
            return TERMINATED;
    }
    return unit_time[toexec.opcode()];
}

int VirtualMachine::executeProgram(int prog_id) {
    int spent = 0;
    while (spent < quantum) {
        int unit = executeSingleStatement(prog_id);
        if (unit == TERMINATED) {
            return false;
        }
        spent += unit;
    }
    return true;
}

void VirtualMachine::execute() {
    for (int i = 1; i <= prog_count; i++) {
        ready.push_back(i);
    }

    while (!ready.empty()) {
        int prog_id = POP_FRONT(ready);
        bool executing = executeProgram(prog_id);
        if (executing) {
            ready.push_back(prog_id);
        }
    }
}

// Status: Accepted
// Submit: 24190924