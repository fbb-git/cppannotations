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

/*
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
*/

    // http://en.cppreference.com/w/cpp/keyword
string keywords = R"(
alignas
alignof
and
and_eq
asm
atomic_cancel
atomic_commit
atomic_noexcept
auto
bitand
bitor
bool
break
case
catch
char
char16_t
char32_t
class
compl
concept
const
constexpr
const_cast
continue
co_await
co_return
co_yield
decltype
default
delete
do
double
dynamic_cast
else
enum
explicit
export
extern
false
float
for
friend
goto
if
import
inline
int
long
module
mutable
namespace
new
noexcept
not
not_eq
nullptr
operator
or
or_eq
private
protected
public
register
reinterpret_cast
requires
return
short
signed
sizeof
static
static_assert
static_cast
struct
switch
synchronized
template
this
thread_local
throw
true
try
typedef
typeid
typename
union
unsigned
using
virtual
void
volatile
wchar_t
while
xor
xor_eq 
)";

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



