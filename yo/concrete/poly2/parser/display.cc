#include "parser.ih"

void  Parser::display(STYPE__ const &id, STYPE__ &vect)
{
    cout << id->as<Tag::TEXT>() << "(";

    char const *sep = "";
    for (auto &sp: vect->as<Tag::VECTOR>())
    {
        cout << sep;
        switch (sp->tag())
        {
            case Tag::INT:
                cout << sp->as<Tag::INT>();
            break;
            case Tag::TEXT:
                cout << sp->as<Tag::TEXT>();
            break;
            default:
                // Tag::VECTOR intentionally not handled
            break;
        }
        sep = ", ";
    }

    cout << ")\n";
}

