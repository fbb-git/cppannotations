    #include <iostream>
    #include "matrix.h"
    using namespace std;

    int main(int argc, char **argv)
    {
        Matrix<3, 2> matrix(cin);

        Matrix<1, 2> colMargins(matrix);
        cout << "Column marginals:\n";
        cout << colMargins[0] << " " << colMargins[1] << '\n';

        Matrix<3, 1> rowMargins(matrix);
        cout << "Row marginals:\n";
        for (size_t idx = 0; idx < 3; idx++)
            cout << rowMargins[idx] << '\n';

        cout << "Sum total: " << Matrix<1, 1>(matrix) << '\n';
    }
    /*
        Generated output from input: 1 2 3 4 5 6

        Column marginals:
        9 12
        Row marginals:
        3
        7
        11
        Sum total: 21
    */
