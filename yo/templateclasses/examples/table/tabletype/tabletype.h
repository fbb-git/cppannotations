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
        size_t                d_maxWidth;
        size_t                d_nRows;
        size_t                d_nColumns;
        WidthType               d_widthType;
        std::vector<size_t>   d_colWidth;
        size_t               (TableType::*d_widthFun)
                                        (size_t col) const;
        std::string const     &(TableType::*d_indexFun)
                                        (size_t row, size_t col) const;
//=
    protected:
//PROT
        std::vector<std::string> d_string;
//=
    public:
        std::ostream &insert(std::ostream &ostr) const;
        void setWidth(WidthType type);

    protected:
        TableType(TableSupport &tableSupport, size_t nColumns,
                    FillDirection direction);
        TableType(size_t nColumns, FillDirection direction);
        ~TableType()
        {
            delete d_tableSupportPtr;
        }
        void init();
    private:
        size_t width(size_t col) const  // returns correct column width,
        {                                   // given d_widthType
            return (this->*d_widthFun)(col);
        }

        size_t maxWidth(size_t) const
        {
            return d_maxWidth;
        }
        size_t columnWidth(size_t col) const
        {
            return d_colWidth[col];
        }
                                    // returns string at particular location
        std::string const &stringAt(size_t row, size_t col) const
        {
            return (this->*d_indexFun)(row, col);
        }
//INDEX
        std::string const &hIndex(size_t row, size_t col) const
        {
            return d_string[row * d_nColumns + col];
        }
        std::string const &vIndex(size_t row, size_t col) const
        {
            return d_string[col * d_nRows + row];
        }
//=
};

} // FBB

std::ostream &operator<<(std::ostream &str, FBB::TableType const &tableType);

#endif
/*
    size_t (TableType::*d_tableWidthFun)() const;

        void updateColumn(size_t col, size_t width);

        size_t maxWidth() const
        {
            return d_maxWidth * d_nColumns;
        }
        size_t columnSum() const;

        size_t tableWidth() const
        {
            return (this->*d_tableWidthFun)();
        }

*/
