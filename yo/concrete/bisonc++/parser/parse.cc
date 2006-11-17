// $insert class.ih
#include "parser.ih"

// The FIRST element of SR arrays shown below uses `d_type', defining the
// state's type, and `d_lastIdx' containing the last element's index. If
// d_lastIdx is negative then the state needs a token: if in this state
// d_token is _UNDETERMINED_, nextToken() will be called

// The LAST element of SR arrays uses `d_token' containing the last retrieved
// token (or _UNDETERMINED_ immediately following a SHIFT) to speed up the
// (linear) seach.  Except for the first element of SR arrays, the field
// `d_action' is used to determine what to do next. If positive, it represents
// the next state (used with SHIFT); if zero, it indicates `ACCEPT', if
// negative, -d_action represents the number of the rule to reduce to.

// `lookup()' tries to find d_token in the current SR array. If it fails, and
// there is no default reduction UNEXPECTED_TOKEN is thrown, which is then
// caught by the error-recovery function.

// The error-recovery function will pop elements off the stack until a state
// having type HAS_ERROR_ITEM is found. In these states, input can be SHIFT-ed
// repeatedly until a token is retrieved which is found in the error state's
// SR table. In that case error recovery is successful and the token is
// returned to the `parse()' function. Since the stack has now been reduced to
// a state having an `error . TOKEN' item, TOKEN will be found in the current
// state, and thus parsing may continue.

// So:
//      s_x[] = 
//      {
//                  [_field_1_]         [_field_2_]
//
// First element:   {state-type,        idx of last element},
// Other elements:  {required token,    action to perform},
//                                      ( < 0: reduce, 
//                                          0: ACCEPT,
//                                        > 0: next state)
// Last element:    {set to d_token,    action to perform}
//      }


namespace // anonymous
{
    enum ReservedTokens
    {
       PARSE_ACCEPT     = 0,   // `ACCEPT' TRANSITION
       _UNDETERMINED_   = -2,
       _EOF_            = -1,
       _error_          = 256,
    };
    enum StateType       // modify state/data.cc when this enum changes
    {
        NORMAL,
        HAS_ERROR_ITEM,
        IS_ERROR_STATE,
    };    
    struct PI   // Production Info
    {
        size_t d_nonTerm; // identification number of this production's
                            // non-terminal 
        size_t d_size;    // number of elements in this production 
    };

    struct SR   // Shift Reduce info, see its description above
    {
        union
        {
            int _field_1_;      // initializer, allowing initializations 
                                // of the SR s_[] arrays
            StateType   d_type;
            int         d_token;
        };
        union
        {
            int _field_2_;

            int d_lastIdx;          // if negative, the state uses SHIFT
            int d_action;           // may be negative (reduce), 
                                    // postive (shift), or 0 (accept)
            size_t d_errorState;  // used with Error states
        };
    };

    // $insert staticdata
    
// Productions Info Records:
PI s_productionInfo[] = 
{
     {0, 0}, // not used: reduction values are negative
     {262, 2}, // 1: lines ->  lines line
     {262, 1}, // 2: lines ->  line
     {263, 2}, // 3: line ->  intExpr '\x0a'
     {263, 2}, // 4: line ->  doubleExpr '\x0a'
     {263, 1}, // 5: line ->  '\x0a'
     {263, 2}, // 6: line ->  _error_ '\x0a'
     {260, 3}, // 7: intExpr ->  intExpr '*' intExpr
     {260, 3}, // 8: intExpr ->  intExpr '+' intExpr
     {260, 3}, // 9: intExpr ->  '(' intExpr ')'
     {260, 2}, // 10: intExpr ->  '-' intExpr
     {260, 1}, // 11: intExpr ->  INT
     {261, 3}, // 12: doubleExpr ->  doubleExpr '*' doubleExpr
     {261, 3}, // 13: doubleExpr ->  doubleExpr '*' intExpr
     {261, 3}, // 14: doubleExpr ->  intExpr '*' doubleExpr
     {261, 3}, // 15: doubleExpr ->  doubleExpr '+' doubleExpr
     {261, 3}, // 16: doubleExpr ->  doubleExpr '+' intExpr
     {261, 3}, // 17: doubleExpr ->  intExpr '+' doubleExpr
     {261, 3}, // 18: doubleExpr ->  '(' doubleExpr ')'
     {261, 2}, // 19: doubleExpr ->  '-' doubleExpr
     {261, 1}, // 20: doubleExpr ->  DOUBLE
     {264, 1}, // 21: lines_$ ->  lines
};

// State info and SR transitions for each state.


SR s_0[] =
{
    {{HAS_ERROR_ITEM}, {11}}, // SHIFTING STATE
    { {262}, {   1} }, // lines
    { {263}, {   2} }, // line
    { {260}, {   3} }, // intExpr
    { {261}, {   4} }, // doubleExpr
    { { 10}, {   5} }, // '\x0a'
    { {_error_}, {   6} }, // _error_
    { { 40}, {   7} }, // '('
    { { 45}, {   8} }, // '-'
    { {257}, {   9} }, // INT
    { {258}, {  10} }, // DOUBLE
    { {  0}, {   0} }  // SEARCH SENTINEL
};

SR s_1[] =
{
    {{HAS_ERROR_ITEM}, {11}}, // ACCEPTING STATE
    { {263}, {  11} }, // line
    { {260}, {   3} }, // intExpr
    { {261}, {  12} }, // doubleExpr
    { { 10}, {   5} }, // '\x0a'
    { {_error_}, {   6} }, // _error_
    { { 40}, {   7} }, // '('
    { { 45}, {  13} }, // '-'
    { {257}, {   9} }, // INT
    { {258}, {  10} }, // DOUBLE
    { {_EOF_}, { PARSE_ACCEPT }},
    { {  0}, { -21} }  // DEFAULT REDUCTION
};

SR s_2[] =
{
    {{NORMAL}, {-1}}, // REDUCING STATE
    { {  0}, {  -2} }  // DEFAULT REDUCTION
};

SR s_3[] =
{
    {{NORMAL}, {4}}, // SHIFTING STATE
    { { 10}, {  14} }, // '\x0a'
    { { 42}, {  15} }, // '*'
    { { 43}, {  16} }, // '+'
    { {  0}, {   0} }  // SEARCH SENTINEL
};

SR s_4[] =
{
    {{NORMAL}, {4}}, // SHIFTING STATE
    { { 10}, {  17} }, // '\x0a'
    { { 42}, {  18} }, // '*'
    { { 43}, {  19} }, // '+'
    { {  0}, {   0} }  // SEARCH SENTINEL
};

SR s_5[] =
{
    {{NORMAL}, {-1}}, // REDUCING STATE
    { {  0}, {  -5} }  // DEFAULT REDUCTION
};

SR s_6[] =
{
    {{IS_ERROR_STATE}, {2}}, // SHIFTING STATE
    { { 10}, {  20} }, // '\x0a'
    { {  0}, {   0} }  // SEARCH SENTINEL
};

SR s_7[] =
{
    {{IS_ERROR_STATE}, {7}}, // SHIFTING STATE
    { {260}, {  21} }, // intExpr
    { {261}, {  22} }, // doubleExpr
    { { 40}, {   7} }, // '('
    { { 45}, {  13} }, // '-'
    { {257}, {   9} }, // INT
    { {258}, {  10} }, // DOUBLE
    { {  0}, {   0} }  // SEARCH SENTINEL
};

SR s_8[] =
{
    {{IS_ERROR_STATE}, {7}}, // SHIFTING STATE
    { {261}, {  23} }, // doubleExpr
    { {260}, {  24} }, // intExpr
    { { 40}, {   7} }, // '('
    { { 45}, {  13} }, // '-'
    { {258}, {  10} }, // DOUBLE
    { {257}, {   9} }, // INT
    { {  0}, {  -2} }  // DEFAULT REDUCTION
};

SR s_9[] =
{
    {{IS_ERROR_STATE}, {-1}}, // REDUCING STATE
    { {  0}, { -11} }  // DEFAULT REDUCTION
};

SR s_10[] =
{
    {{IS_ERROR_STATE}, {-1}}, // REDUCING STATE
    { {  0}, { -20} }  // DEFAULT REDUCTION
};

SR s_11[] =
{
    {{NORMAL}, {-1}}, // REDUCING STATE
    { {  0}, {  -1} }  // DEFAULT REDUCTION
};

SR s_12[] =
{
    {{NORMAL}, {4}}, // SHIFTING STATE
    { { 10}, {  25} }, // '\x0a'
    { { 42}, {  18} }, // '*'
    { { 43}, {  26} }, // '+'
    { {  0}, {   0} }  // SEARCH SENTINEL
};

SR s_13[] =
{
    {{IS_ERROR_STATE}, {7}}, // SHIFTING STATE
    { {260}, {  27} }, // intExpr
    { {261}, {  23} }, // doubleExpr
    { { 40}, {   7} }, // '('
    { { 45}, {  13} }, // '-'
    { {257}, {   9} }, // INT
    { {258}, {  10} }, // DOUBLE
    { {  0}, {   0} }  // SEARCH SENTINEL
};

SR s_14[] =
{
    {{NORMAL}, {-1}}, // REDUCING STATE
    { {  0}, {  -3} }  // DEFAULT REDUCTION
};

SR s_15[] =
{
    {{NORMAL}, {7}}, // SHIFTING STATE
    { {260}, {  28} }, // intExpr
    { {261}, {  29} }, // doubleExpr
    { { 40}, {   7} }, // '('
    { { 45}, {  13} }, // '-'
    { {257}, {   9} }, // INT
    { {258}, {  10} }, // DOUBLE
    { {  0}, {   0} }  // SEARCH SENTINEL
};

SR s_16[] =
{
    {{NORMAL}, {7}}, // SHIFTING STATE
    { {260}, {  30} }, // intExpr
    { {261}, {  31} }, // doubleExpr
    { { 40}, {   7} }, // '('
    { { 45}, {  13} }, // '-'
    { {257}, {   9} }, // INT
    { {258}, {  10} }, // DOUBLE
    { {  0}, {   0} }  // SEARCH SENTINEL
};

SR s_17[] =
{
    {{NORMAL}, {-1}}, // REDUCING STATE
    { {  0}, {  -4} }  // DEFAULT REDUCTION
};

SR s_18[] =
{
    {{NORMAL}, {7}}, // SHIFTING STATE
    { {261}, {  32} }, // doubleExpr
    { {260}, {  33} }, // intExpr
    { { 40}, {   7} }, // '('
    { { 45}, {  13} }, // '-'
    { {258}, {  10} }, // DOUBLE
    { {257}, {   9} }, // INT
    { {  0}, {   0} }  // SEARCH SENTINEL
};

SR s_19[] =
{
    {{NORMAL}, {7}}, // SHIFTING STATE
    { {261}, {  34} }, // doubleExpr
    { {260}, {  35} }, // intExpr
    { { 40}, {   7} }, // '('
    { { 45}, {  13} }, // '-'
    { {258}, {  10} }, // DOUBLE
    { {257}, {   9} }, // INT
    { {  0}, {   0} }  // SEARCH SENTINEL
};

SR s_20[] =
{
    {{IS_ERROR_STATE}, {-1}}, // REDUCING STATE
    { {  0}, {  -6} }  // DEFAULT REDUCTION
};

SR s_21[] =
{
    {{IS_ERROR_STATE}, {4}}, // SHIFTING STATE
    { { 41}, {  36} }, // ')'
    { { 42}, {  15} }, // '*'
    { { 43}, {  16} }, // '+'
    { {  0}, {   0} }  // SEARCH SENTINEL
};

SR s_22[] =
{
    {{IS_ERROR_STATE}, {4}}, // SHIFTING STATE
    { { 41}, {  37} }, // ')'
    { { 42}, {  18} }, // '*'
    { { 43}, {  19} }, // '+'
    { {  0}, {   0} }  // SEARCH SENTINEL
};

SR s_23[] =
{
    {{IS_ERROR_STATE}, {1}}, // SHIFTING STATE
    { {  0}, { -19} }  // DEFAULT REDUCTION
};

SR s_24[] =
{
    {{IS_ERROR_STATE}, {3}}, // SHIFTING STATE
    { { 42}, {  15} }, // '*'
    { { 43}, {  16} }, // '+'
    { {  0}, {   0} }  // SEARCH SENTINEL
};

SR s_25[] =
{
    {{NORMAL}, {-1}}, // REDUCING STATE
    { {  0}, {  -4} }  // DEFAULT REDUCTION
};

SR s_26[] =
{
    {{NORMAL}, {7}}, // SHIFTING STATE
    { {261}, {  34} }, // doubleExpr
    { {260}, {  24} }, // intExpr
    { { 40}, {   7} }, // '('
    { { 45}, {  13} }, // '-'
    { {258}, {  10} }, // DOUBLE
    { {257}, {   9} }, // INT
    { {  0}, {   0} }  // SEARCH SENTINEL
};

SR s_27[] =
{
    {{IS_ERROR_STATE}, {1}}, // SHIFTING STATE
    { {  0}, { -10} }  // DEFAULT REDUCTION
};

SR s_28[] =
{
    {{NORMAL}, {3}}, // SHIFTING STATE
    { { 42}, {  15} }, // '*'
    { { 43}, {  16} }, // '+'
    { {  0}, {  -7} }  // DEFAULT REDUCTION
};

SR s_29[] =
{
    {{NORMAL}, {3}}, // SHIFTING STATE
    { { 42}, {  18} }, // '*'
    { { 43}, {  19} }, // '+'
    { {  0}, { -14} }  // DEFAULT REDUCTION
};

SR s_30[] =
{
    {{NORMAL}, {3}}, // SHIFTING STATE
    { { 42}, {  15} }, // '*'
    { { 43}, {  16} }, // '+'
    { {  0}, {  -8} }  // DEFAULT REDUCTION
};

SR s_31[] =
{
    {{NORMAL}, {3}}, // SHIFTING STATE
    { { 42}, {  18} }, // '*'
    { { 43}, {  19} }, // '+'
    { {  0}, { -17} }  // DEFAULT REDUCTION
};

SR s_32[] =
{
    {{NORMAL}, {3}}, // SHIFTING STATE
    { { 42}, {  18} }, // '*'
    { { 43}, {  19} }, // '+'
    { {  0}, { -12} }  // DEFAULT REDUCTION
};

SR s_33[] =
{
    {{NORMAL}, {3}}, // SHIFTING STATE
    { { 42}, {  15} }, // '*'
    { { 43}, {  16} }, // '+'
    { {  0}, { -13} }  // DEFAULT REDUCTION
};

SR s_34[] =
{
    {{NORMAL}, {3}}, // SHIFTING STATE
    { { 42}, {  18} }, // '*'
    { { 43}, {  19} }, // '+'
    { {  0}, { -15} }  // DEFAULT REDUCTION
};

SR s_35[] =
{
    {{NORMAL}, {3}}, // SHIFTING STATE
    { { 42}, {  15} }, // '*'
    { { 43}, {  16} }, // '+'
    { {  0}, { -16} }  // DEFAULT REDUCTION
};

SR s_36[] =
{
    {{IS_ERROR_STATE}, {-1}}, // REDUCING STATE
    { {  0}, {  -9} }  // DEFAULT REDUCTION
};

SR s_37[] =
{
    {{IS_ERROR_STATE}, {-1}}, // REDUCING STATE
    { {  0}, { -18} }  // DEFAULT REDUCTION
};


// State array:
SR *s_state[] =
{
  s_0,  s_1,  s_2,  s_3,  s_4,  s_5,  s_6,  s_7,  s_8,  s_9,
  s_10,  s_11,  s_12,  s_13,  s_14,  s_15,  s_16,  s_17,  s_18,  s_19,
  s_20,  s_21,  s_22,  s_23,  s_24,  s_25,  s_26,  s_27,  s_28,  s_29,
  s_30,  s_31,  s_32,  s_33,  s_34,  s_35,  s_36,  s_37,
};

} // anonymous namespace ends



// If the parsing function call uses arguments, then provide an overloaded
// function.  The code below doesn't rely on parameters, so no arguments are
// required.  Furthermore, parse uses a function try block to allow us to do
// ACCEPT and ABORT from anywhere, even from within members called by actions,
// simply throwing the appropriate exceptions.

ParserBase::ParserBase()
:
    d_stackIdx(-1),
    // $insert debuginit
    d_debug(false),
    d_nErrors(0),
    d_token(_UNDETERMINED_),
    d_nextToken(_UNDETERMINED_)
{}

void ParserBase::clearin()
{
    d_token = d_nextToken = _UNDETERMINED_;
}

void ParserBase::ABORT() const throw(Return) 
{
    throw PARSE_ABORT;
}

void ParserBase::ACCEPT() const throw(Return)
{
    throw PARSE_ACCEPT;
}

void ParserBase::ERROR() const throw(ErrorRecovery)
{
    throw UNEXPECTED_TOKEN;
}


void ParserBase::push(size_t state)
{
    if (static_cast<size_t>(d_stackIdx + 1) == d_stateStack.size())
    {
        size_t newSize = d_stackIdx + 5;
        d_stateStack.resize(newSize);
        d_valueStack.resize(newSize);
    }
    ++d_stackIdx;
    d_stateStack[d_stackIdx] = d_state = state;
    *(d_vsp = &d_valueStack[d_stackIdx]) = d_val;
}

void ParserBase::pop(size_t count)
{
    if (d_stackIdx < static_cast<int>(count))
    {
        ABORT();
    }

    d_stackIdx -= count;
    d_state = d_stateStack[d_stackIdx];
    d_vsp = &d_valueStack[d_stackIdx];
}

size_t ParserBase::top() const
{
    if (d_stackIdx < 0)
    {
        throw DEFAULT_RECOVERY_MODE;
    }

    return d_stateStack[d_stackIdx];
}

size_t ParserBase::reduce(PI const &pi)
{

    pop(pi.d_size);


    return pi.d_nonTerm;
}

void Parser::executeAction(int production)
{
    switch (production)
    {
        // $insert actioncases
        
        case 3:
#line 33 "grammar"
        {
                    display(d_vsp[-1].i);
                }
        break;

        case 4:
#line 39 "grammar"
        {
                    display(d_vsp[-1].d);
                }
        break;

        case 5:
#line 44 "grammar"
        {
                    done();
                }
        break;

        case 6:
#line 50 "grammar"
        {
                    reset();
                }
        break;

        case 7:
#line 57 "grammar"
        {
                    d_val.i = exec('*', d_vsp[-2].i, d_vsp[0].i);
                }
        break;

        case 8:
#line 62 "grammar"
        {
                    d_val.i = exec('+', d_vsp[-2].i, d_vsp[0].i);
                }
        break;

        case 9:
#line 67 "grammar"
        {
                    d_val.i = d_vsp[-1].i;
                }
        break;

        case 10:
#line 73 "grammar"
        {
                    d_val.i = neg(d_vsp[0].i);
                }
        break;

        case 11:
#line 78 "grammar"
        {
                    d_val.i = convert<int>();
                }
        break;

        case 12:
#line 85 "grammar"
        {
                    d_val.d = exec('*', d_vsp[-2].d, d_vsp[0].d);
                }
        break;

        case 13:
#line 90 "grammar"
        {
                    d_val.d = exec('*', d_vsp[-2].d, d(d_vsp[0].i));
                }
        break;

        case 14:
#line 95 "grammar"
        {
                    d_val.d = exec('*', d(d_vsp[-2].i), d_vsp[0].d);
                }
        break;

        case 15:
#line 100 "grammar"
        {
                    d_val.d = exec('+', d_vsp[-2].d, d_vsp[0].d);
                }
        break;

        case 16:
#line 105 "grammar"
        {
                    d_val.d = exec('+', d_vsp[-2].d, d(d_vsp[0].i));
                }
        break;

        case 17:
#line 110 "grammar"
        {
                    d_val.d = exec('+', d(d_vsp[-2].i), d_vsp[0].d);
                }
        break;

        case 18:
#line 115 "grammar"
        {
                    d_val.d = d_vsp[-1].d;
                }
        break;

        case 19:
#line 120 "grammar"
        {
                    d_val.d = neg(d_vsp[0].d);
                }
        break;

        case 20:
#line 126 "grammar"
        {
                    d_val.d = convert<double>();
                }
        break;

    }
}

void Parser::nextToken()
{
    if (d_nextToken == _UNDETERMINED_)
    {
        d_nextToken = lex();
    }
    print();
    if (d_nextToken <= 0)
        d_nextToken = _EOF_;
    d_token = d_nextToken;
}

// if the final transition is negative, then we should reduce by the rule
// given by its positive value
int Parser::lookup()
{
    SR *sr = s_state[d_state];

    int lastIdx = sr->d_lastIdx;        // sentinel-index in the SR_ array

    if (lastIdx < 0)                    // only (maybe) obtain next token
        lastIdx = -lastIdx;             // if the state uses a terminal-token
    else if (d_token == _UNDETERMINED_) // shift and no token is available
        nextToken();

    SR *lastElementPtr = sr + lastIdx;


    lastElementPtr->d_token = d_token;  // set search-token
    
    SR *elementPtr = sr + 1;
    while (elementPtr->d_token != d_token)
        ++elementPtr;

    if (elementPtr == lastElementPtr)   // reached the last element
    {
        if (elementPtr->d_action < 0)   // default reduction
        {
            return elementPtr->d_action;                
        }
        // No default reduction, so token not found, so error.
        throw UNEXPECTED_TOKEN;
    }

    // not at the last element, if non-negative and if 
    // d_token == d_nextToken token has been processed, and nextToken()
    // can be called. 

    if (elementPtr->d_action <= 0)       // a reduction or ACCEPT is found
    {
        return elementPtr->d_action;
    }

    if (d_token == d_nextToken)         // token was processed
    {
        d_nextToken = _UNDETERMINED_;
    }
    d_token = d_nextToken;
    return elementPtr->d_action;
}

    // When an error has occurred, pop elements off the stack until the top
    // state has an error-item. If none is found, the default recovery
    // mode (which is to abort) is activated. 
    //
    // If EOF is encountered without being appropriate for the current state,
    // then the error recovery will fall back to the default recovery mode.
    // (i.e., parsing terminates)
void Parser::errorRecovery()
try
{
    ++d_nErrors;

    error("Syntax error");

    while (s_state[top()][0].d_type != HAS_ERROR_ITEM)
    {
        pop();
    }

    d_token = _error_;                      // specify _error_ as next token
    push(lookup());                         // push the error state

    // In the error state, lookup a token with which we can proceed.
    // It may be a reduce, but normally a shift is indicated
    // If a token is seen which doesn't fit, the catch below will catch the
    // execption thrown by lookup()

    while (true)
    {
            // if on entry here token is already EOF then we've probably been 
            // here before: _error_ accepts EOF, but the state using
            // error nevertheless doesn't. In that case parsing terminates 
        if (d_token == _EOF_)
        {
            throw DEFAULT_RECOVERY_MODE;
        }
        try
        {
            clearin();
            int action = lookup();

            if (action > 0)                 // push a new state
            {
                push(action);
            }
            else if (action < 0)
            {
                executeAction(-action);     // the error's action

                                            // next token is the rule's LHS
                d_token = reduce(s_productionInfo[-action]); 
            }
            return;
        }
        catch (...)
        {
        }
    }
}
catch (ErrorRecovery)       // This means: DEFAULT_RECOVERY_MODE
{
    ABORT();
}

    // The parsing algorithm:
    // Initially, state 0 is pushed on the stack, and d_token is initialized 
    // the first token on the input.
    // The stack's top element is always used to access the current state's
    // SR_ array. 
    // Then, in an eternal loop:
    //  1.  d_token is stored in the final element's d_token
    //      field of the state's SR_ array.
    //  2.  The current token is looked up in the state's SR_ array
    //  3. If the token is found at the last element (so, the token wasn't
    //     really found since we've put it there intially) and the last
    //     element's action field is negative, a default reduce is
    //     performed, and the returned action is the rule to reduce to. This
    //     results in d_token receiving the token value of the rule's LHS
    //     token.
    //  4. If the token is found at an earlier element, the result may also be
    //     a reduce, which is handled as described in 3.
    //  5. If the action is 0, the input is accepted, and parsing stops.
    //  6. If the action is positive, a SHIFT is required. However, d_token
    //     must be reassigned first. If the d_token is equal to d_nextToken,
    //     d_nextToken has been processed, and another token can be
    //     retrieved. Otherwise, d_nextToken is reassigned to d_token.
    //  7. An error occurs if d_token is not found, and the state has no
    //     default reduction
int Parser::parse()
try 
{
    push(0);                                // initial state
    d_nextToken = _UNDETERMINED_;           // First token may not yet be 
                                            // required
    while (true)
    {
        try
        {
            int action = lookup();          // lookup d_token in d_state

            if (action > 0)                 // push a new state
            {
                push(action);
                d_token = _UNDETERMINED_;   // try to process the next token
            }
            else if (action < 0)
            {
                executeAction(-action);
                                            // next token is the rule's LHS
                d_token = reduce(s_productionInfo[-action]); 
            }
            else 
                ACCEPT();
        }
        catch (ErrorRecovery)
        {
            errorRecovery();
        }
    }
}
catch (Return retValue)
{
    return retValue;
}

