const int NOT_ROOTS = 0;
const int ONE_ROOT  = 1;
const int TWO_ROOT  = 2;
const int ERROR     = -1;

const int FIRST_DEGREE  = 1;
const int SECOND_DEGREE = 2;

int line_solver   (double* coeff, double* roots);
int square_solver (int type_eq, double* coeffs, double* roots);
