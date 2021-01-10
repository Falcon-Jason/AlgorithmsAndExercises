#include <cstdio>
#include <set>

inline bool is_leap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

int months[] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int calc_date(int year, int month, int day) {
    year += (year >= 60 ? 1900 : 2000);

    if (month > 12 || month <= 0) { return 0; }

    months[2] = is_leap(year) ? 29 : 28;
    if (day > months[month] || day <= 0) { return 0; }

    // compress the whole date into one int
    return (year << 9) + (month << 5) + day;
}

// decompress and print the date
void print_date(int date) {
    printf("%04d-%02d-%02d\n", date >> 9, (date >> 5) & 15, date & 31);
}

int main() {
    std::set<int> dates;
    int a, b, c;

    scanf("%d%d%d", &a, &b, &c);

    dates.insert(calc_date(a, b, c));  // y-m-d
    dates.insert(calc_date(c, a, b));  // m-d-y
    dates.insert(calc_date(c, b, a));  // d-m-y

    dates.erase(0);  // clear invalid dates

    // print dates
    for (auto i = dates.begin(); i != dates.end(); i++) {
        print_date(*i);
    }
}