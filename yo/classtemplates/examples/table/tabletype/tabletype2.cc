#include "tabletype.ih"

TableType::TableType(size_t nColumns,
                        FillDirection direction)
:
    d_tableSupportPtr(new TableSupport()),
    d_tableSupport(*d_tableSupportPtr),
    d_maxWidth(0),
    d_nRows(0),
    d_nColumns(nColumns),
    d_widthType(COLUMNWIDTH),
    d_colWidth(nColumns),
    d_widthFun(&TableType::columnWidth),
    d_indexFun(direction == HORIZONTAL ?
                    &TableType::hIndex
                :
                    &TableType::vIndex)
{}
