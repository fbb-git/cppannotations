// use -lbobcat to link

#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <bobcat/table>
#include <bobcat/align>
#include <bobcat/tablesupport>

using namespace std;
using namespace FBB;

string keywords = 

"alignas "
"alignof and compl explicit new requires typedef and_eq concept extern not "
"bool delete if private switch void break do inline protected template "
"volatile "
"case double int public this wchar_t catch dynamic_cast long register throw "
"decltype friend or static_cast using bitor default goto or_eq struct "
"virtual "
"nullptr sizeof union axiom continue for operator static unsigned bitand "
"short typeid asm const false not_eq signed typename auto const_cast float "
"try xor_eq constexpr import export "
"while char else mutable reinterpret_cast true xor class enum namespace "
"char16_t char32_t noexcept static_assert thread_local "
"return" ;

struct Support: public TableSupport
{
    void vline(size_t col) const
    {
        if (col > 0)
            out() << ' ';
    }
};

int main()
{
    set<string> keyword;
    istringstream in(keywords);

    copy(istream_iterator<string>(in), istream_iterator<string>(), 
            inserter(keyword, keyword.begin()));

    Support support;
    support << 0;
    for (size_t col = 0; col != 6; ++col)
        support << 1;

    Table table(support, 6, Table::COLUMNWISE);
    table.fill(keyword.begin(), keyword.end());
    for(size_t col = 0; col != 6; ++col)
        table << Align(col, std::left);
    cout << table << '\n';
}



