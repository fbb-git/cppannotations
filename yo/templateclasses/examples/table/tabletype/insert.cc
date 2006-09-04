#include "tabletype.ih"

ostream &TableType::insert(ostream &ostr) const
{
    if (!d_nRows)
        return ostr;

    d_tableSupport.setParam(ostr, d_nRows, d_colWidth,
                            d_widthType == EqualWidth ? d_maxWidth : 0);

    for (unsigned row = 0; row < d_nRows; row++)
    {
        d_tableSupport.hline(row);

        for (unsigned col = 0; col < d_nColumns; col++)
        {
            unsigned colwidth = width(col);

            d_tableSupport.vline(col);
            ostr << setw(colwidth) << stringAt(row, col);
        }

        d_tableSupport.vline();
    }
    d_tableSupport.hline();

    return ostr;
}
