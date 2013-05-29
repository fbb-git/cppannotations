#include "tabletype.ih"

std::ostream &operator<<(std::ostream &str, FBB::TableType const &tableType)
{
    return tableType.insert(str);
}
