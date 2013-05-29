#include "tabletype.ih"

TableType::TableType(TableSupport &tableSupport, size_t nColumns,
                        FillDirection direction)
:
    d_tableSupportPtr(0),
    d_tableSupport(tableSupport),
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
