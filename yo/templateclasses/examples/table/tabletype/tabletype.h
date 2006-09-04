#ifndef _INCLUDED_TABLETYPE_
#define _INCLUDED_TABLETYPE_

#include <string>
#include <vector>

#include "../tablesupport/tablesupport.h"

namespace FBB
{

class TableType
{
    public:
        enum WidthType
        {
            EqualWidth,
            ColumnWidth,
        };
        enum FillDirection
        {
            Horizontal,
            Vertical
        };

    private:
//DATA
        TableSupport           *d_tableSupportPtr;
        TableSupport           &d_tableSupport;
        unsigned                d_maxWidth;
        unsigned                d_nRows;
        unsigned                d_nColumns;
        WidthType               d_widthType;
        std::vector<unsigned>   d_colWidth;
        unsigned               (TableType::*d_widthFun)
                                        (unsigned col) const;
        std::string const     &(TableType::*d_indexFun)
                                        (unsigned row, unsigned col) const;
//=
    protected:
//PROT
        std::vector<std::string> d_string;
//=
    public:
        std::ostream &insert(std::ostream &ostr) const;
        void setWidth(WidthType type);

    protected:
        TableType(TableSupport &tableSupport, unsigned nColumns,
                    FillDirection direction);
        TableType(unsigned nColumns, FillDirection direction);
        ~TableType()
        {
            delete d_tableSupportPtr;
        }
        void init();
    private:
        unsigned width(unsigned col) const  // returns correct column width,
        {                                   // given d_widthType
            return (this->*d_widthFun)(col);
        }

        unsigned maxWidth(unsigned) const
        {
            return d_maxWidth;
        }
        unsigned columnWidth(unsigned col) const
        {
            return d_colWidth[col];
        }
                                    // returns string at particular location
        std::string const &stringAt(unsigned row, unsigned col) const
        {
            return (this->*d_indexFun)(row, col);
        }
//INDEX
        std::string const &hIndex(unsigned row, unsigned col) const
        {
            return d_string[row * d_nColumns + col];
        }
        std::string const &vIndex(unsigned row, unsigned col) const
        {
            return d_string[col * d_nRows + row];
        }
//=
};

} // FBB

std::ostream &operator<<(std::ostream &str, FBB::TableType const &tableType);

#endif
/*
    unsigned (TableType::*d_tableWidthFun)() const;

        void updateColumn(unsigned col, unsigned width);

        unsigned maxWidth() const
        {
            return d_maxWidth * d_nColumns;
        }
        unsigned columnSum() const;

        unsigned tableWidth() const
        {
            return (this->*d_tableWidthFun)();
        }

*/
