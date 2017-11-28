#include "calculatorcategory.ih"

//ctor
CalculatorCategory::CalculatorCategory()
{
    ErrorCondition::instance().addCategory("CalculatorCategory", 
                                            this, equivalent);   
}
//=
