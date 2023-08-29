const int COMP_EQ   = 0;
const int COMP_MORE = 1;
const int COMP_LESS = -1;

const double EPS            = 1e-9;
const int MAX_STRING_LENGTH = 100;

void clear_buffer    ();
bool compare_eq      (double first, double second);
int  compare_doubles (double first, double second);