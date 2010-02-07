#include "tabletype.ih"

void TableType::setWidth(WidthType type)
{
    d_widthFun =
        ((d_widthType = type) == EQUALWIDTH) ?
            &TableType::maxWidth
        :
            &TableType::columnWidth;

    d_tableSupport.setParam(d_widthType == EQUALWIDTH ? d_maxWidth : 0);
}
