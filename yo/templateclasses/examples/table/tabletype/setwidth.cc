#include "tabletype.ih"

void TableType::setWidth(WidthType type)
{
    d_widthFun =
        ((d_widthType = type) == EqualWidth) ?
            &TableType::maxWidth
        :
            &TableType::columnWidth;

    d_tableSupport.setParam(d_widthType == EqualWidth ? d_maxWidth : 0);
}
