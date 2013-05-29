4th template <class T1, class T2>
4th void fun(T1 t1, T2 t2)
4th {
4th     cout << "1: fun(T1 t1, T2 t2)\n";
4th }

7th template <class T>
7th void fun(T t, double d)
7th {
7th     cout << "2: fun(T t, double d)\n";
7th }

2nd template <class T>
2nd void fun(T t, int i)
2nd {
2nd     cout << "3: fun(T t, int i)\n";
2nd }

3rd template <>
3rd void fun<int, int>(int i1, int i2)
3rd {
3rd     cout << "4: fun<int, int>(int i1, int i2)\n";
3rd }

1st void fun(int i1, int i2)
1st {
1st     cout << "5: fun(int i1, int i2)\n";
1st }

6th void fun(int i, double d)
6th {
6th     cout << "6: fun(int i, double d)\n";
6th }

5th void fun(double d, int i)
5th {
5th     cout << "7: fun(double d, int i)\n";
5th }

void fun(double d1, double d2)
{
    cout << "8: fun(double d1 double d2)\n";
}

int main()
{
    fun(3, 3);      // two ints
}
    // first run: 5 is selected.
    // 2nd run: drop 5, 3 is selected
    // 3rd run: drop 3, 4 is selected
    // 4th run: drop 4, 1 is selected
    // 5th run: drop 1 results in ambiguity:
    //          3 functions requiring 1 conversion (2, 6, 7)
    //          drop 6 keeps the ambiguity: 2 (1 dir. match, 1 conversion)
    //                                      7 (1 conv., 1 dir. match)
    //          2 and 7 aren't template and expl. special.
    //          drop 7 solves the ambiguity: ordinary 1st arg of 6 wins
    // 6th run: drop 6, 2 is selected
    // 7th run: drop 2, 8 is selected
