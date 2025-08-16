#include <stdio.h>

int isLeap(int year) {
    if (year % 400 == 0) return 1;
    if (year % 100 == 0) return 0;
    if (year % 4 == 0) return 1;
    return 0;
}

int daysInMonth(int month, int year) {
    if (month == 2) {
        return isLeap(year) ? 29 : 28;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    return 31;
}

int isLuckyDate(int day, int month, int year) {
    int x = day * 1000000 + month * 10000 + year;
    return (x % 4 == 0 || x % 7 == 0);
}

int main() {
    int d1, m1, y1, d2, m2, y2;
    scanf("%d-%d-%d", &d1, &m1, &y1);
    scanf("%d-%d-%d", &d2, &m2, &y2);

    int count = 0;

    while (1) {
        if (isLuckyDate(d1, m1, y1)) {
            count++;
        }
        if (d1 == d2 && m1 == m2 && y1 == y2) break;

        d1++;
        if (d1 > daysInMonth(m1, y1)) {
            d1 = 1;
            m1++;
            if (m1 > 12) {
                m1 = 1;
                y1++;
            }
        }
    }

    printf("%d\n", count);
    return 0;
}
