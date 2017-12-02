#include "errorcondition.ih"

//static
ErrorCondition &ErrorCondition::instance()
{
    if (s_instance == 0)
        s_instance = new ErrorCondition;

    return *s_instance;
}
