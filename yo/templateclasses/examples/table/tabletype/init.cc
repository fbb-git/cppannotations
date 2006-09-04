#include "tabletype.ih"

void TableType::init()
{
    if (!d_string.size())                   // no elements
        return;                             // then do nothing

    d_nRows = (d_string.size() + d_nColumns - 1) / d_nColumns;
    d_string.resize(d_nRows * d_nColumns);  // enforce complete table

                                            // determine max width per column,
                                            // and max column width
    for (unsigned col = 0; col < d_nColumns; col++)
    {
        unsigned width = 0;
        for (unsigned row = 0; row < d_nRows; row++)
        {
            unsigned len = stringAt(row, col).length();
            if (width < len)
                width = len;
        }
        d_colWidth[col] = width;

        if (d_maxWidth < width)             // max. width so far.
            d_maxWidth = width;
    }
}
