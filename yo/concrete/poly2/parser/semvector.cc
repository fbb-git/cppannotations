#include "parser.ih"

Parser::STYPE__ Parser::semVector(STYPE__ const &first)
{
    STYPE__ ret = new Semantic<Tag::VECTOR>(
                        vector<shared_ptr<SemBase const>> {first});
    return ret;
}

