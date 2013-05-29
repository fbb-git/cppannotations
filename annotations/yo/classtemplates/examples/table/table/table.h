#ifndef INCLUDED_TABLE_
#define INCLUDED_TABLE_

#include <sstream>
#include "../tabletype/tabletype.h"

namespace FBB
{

//HEAD
template <typename Iterator>
class Table: public TableType
{
//=
    public:
//CONS
        Table(Iterator const &begin, Iterator const &end,
                size_t nColumns, FillDirection direction);
        Table(Iterator const &begin, Iterator const &end,
                TableSupport &tableSupport,
                size_t nColumns, FillDirection direction);
//=
    private:
        void fill(Iterator begin, Iterator const &end);
};

//FILL
template <typename Iterator>
void Table<Iterator>::fill(Iterator it, Iterator const &end)
{
    while (it != end)
    {
        std::ostringstream str;
        str << *it++;
        d_string.push_back(str.str());
    }
    init();
}
//=

//CONSIMP
template <typename Iterator>
Table<Iterator>::Table(Iterator const &begin, Iterator const &end,
                TableSupport &tableSupport,
                size_t nColumns, FillDirection direction)
:
    TableType(tableSupport, nColumns, direction)
{
    fill(begin, end);
}

template <typename Iterator>
Table<Iterator>::Table(Iterator const &begin, Iterator const &end,
                size_t nColumns, FillDirection direction)
:
    TableType(nColumns, direction)
{
    fill(begin, end);
}
//=

} // FBB

#endif
