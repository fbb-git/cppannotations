#include "../htmlindex.h"

void IndexEntry::showRefs()
{
    for
    (
        vector<pair<unsigned, unsigned> >::iterator it = labels.begin();
            it != labels.end();
                it++
    )
        cout << "       <a href=" << filenameVector[it->first] << "#an" <<
                         setw(1) << it->second << " target=info>" <<
                        it->second << "</a>&nbsp;\n";
}
