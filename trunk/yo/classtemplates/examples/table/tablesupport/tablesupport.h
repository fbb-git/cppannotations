#ifndef INCLUDED_TABLESUPPORT_
#define INCLUDED_TABLESUPPORT_

#include <ostream>
#include <vector>
#include <numeric>

namespace FBB
{

class TableSupport
{
    std::ostream *d_streamPtr;
    size_t d_rows;
    std::vector<size_t> const *d_colWidth;
    size_t d_maxWidth;
    size_t d_tableWidth;

    public:
        TableSupport()
        :
            d_streamPtr(0),
            d_rows(0),
            d_colWidth(0),
            d_maxWidth(0),
            d_tableWidth(0)
        {}

        virtual ~TableSupport()
        {}

        void setParam(std::ostream &ostr, size_t rows,
                        std::vector<size_t> const &colWidth,
                        size_t maxWidth)
        {
            d_streamPtr = &ostr;
            d_rows = rows;
            d_colWidth = &colWidth;
            d_maxWidth = maxWidth;  // 0 if colWidth should be used.
            d_tableWidth = d_maxWidth ?
                                d_maxWidth * colWidth.size()
                            :
                                std::accumulate(colWidth.begin(),
                                                colWidth.end(), 0);
        }

        void setParam(size_t maxWidth)
        {
            d_maxWidth = maxWidth;  // 0 if colWidth should be used.
        }

        size_t tableWidth() const
        {
            return d_tableWidth;
        }

        size_t nColumns() const
        {
            return d_colWidth->size();
        }

        std::ostream &out() const
        {
            return *d_streamPtr;
        }

        virtual void hline(size_t row) const
        {}

        virtual void hline() const
        {}

        virtual void vline(size_t col) const
        {
            if (col)
                *d_streamPtr << ' ';
        }

        virtual void vline() const
        {
            *d_streamPtr << '\n';
        }
};

} // FBB

#endif
