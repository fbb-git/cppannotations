#include <regex>
#include <iostream>
using namespace std;

int main()
{
	const char *reg_esp = "[ ,.\\t\\n;:]" ;  // List of separator characters.
	 
	regex rgx(reg_esp) ;  // 'regex' is an instance of the template class
	                      // 'basic_regex' with argument of type 'char'.
	cmatch match ;  // 'cmatch' is an instance of the template class
	                // 'match_results' with argument of type 'const char *'.
	const char *target = "Polytechnic University of Turin " ;
	 
	// Identifies all words of 'target' separated by characters of 'reg_esp'.
	if( regex_search( target, match, rgx ) )
	{
	  // If words separated by specified characters are present.
	 
	  const size_t n = match.size();
	  for( size_t a = 0 ; a < n ; a++ )
	  {
	    string str( match[a].first, match[a].second ) ;
	    cout << str << "\n" ;
	  }
	}
}
