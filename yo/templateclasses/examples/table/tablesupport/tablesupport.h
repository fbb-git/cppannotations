#ifndef _INCLUDED_TABLESUPPORT_
#define _INCLUDED_TABLESUPPORT_

#include <ostream>
#include <vector>
#include <numeric>

namespace FBB
{

class TableSupport
{
    std::ostream *d_streamPtr;
    unsigned d_rows;
    std::vector<unsigned> const *d_colWidth;
    unsigned d_maxWidth;
    unsigned d_tableWidth;

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

        void setParam(std::ostream &ostr, unsigned rows,
                        std::vector<unsigned> const &colWidth,
                        unsigned maxWidth)
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

        void setParam(unsigned maxWidth)
        {
            d_maxWidth = maxWidth;  // 0 if colWidth should be used.
        }

        unsigned tableWidth() const
        {
            return d_tableWidth;
        }

        unsigned nColumns() const
        {
            return d_colWidth->size();
        }

        std::ostream &out() const
        {
            return *d_streamPtr;
        }

        virtual void hline(unsigned row) const
        {}

        virtual void hline() const
        {}

        virtual void vline(unsigned col) const
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
