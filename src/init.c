#include "rpart.h"
#include "R_ext/Rdynload.h"
#include "node.h"
#include "rpartproto.h"

SEXP init_rpcallback(SEXP rhox, SEXP ny, SEXP nr, SEXP expr1x, SEXP expr2x);
SEXP rpartexp2(SEXP dtimes, SEXP seps);
SEXP pred_rpart(SEXP dimx, SEXP nnode, SEXP nsplit, SEXP dimc,
		SEXP nnum, SEXP nodes2, SEXP vnum, SEXP split2,
		SEXP csplit2, SEXP usesur, SEXP xdata2, SEXP xmiss2);
SEXP honest_estimate_rpart(SEXP dimx, SEXP nnode, SEXP nsplit, SEXP dimc,
                        SEXP nnum, SEXP nodes2, SEXP n1, SEXP wt1, SEXP dev1, SEXP yval1,
                        SEXP vnum, SEXP split2,
                        SEXP csplit2, SEXP usesur, SEXP xdata2, SEXP wt2, SEXP y2,
                        SEXP xmiss2);
static const R_CallMethodDef CallEntries[] = {
    {"init_rpcallback", (DL_FUNC) &init_rpcallback, 5},
    {"rpart", (DL_FUNC) &rpart, 11},
    {"xpred", (DL_FUNC) &xpred, 15},
    {"rpartexp2", (DL_FUNC) &rpartexp2, 2},
    {"pred_rpart", (DL_FUNC) &pred_rpart, 12},
    {"honest_estimate_rpart", (DL_FUNC) &honest_estimate_rpart, 18},
    {NULL, NULL, 0}
};

#include <Rversion.h>
void
R_init_rpart(DllInfo * dll)
{
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
#if defined(R_VERSION) && R_VERSION >= R_Version(2, 16, 0)
    R_forceSymbols(dll, TRUE);
#endif
}
