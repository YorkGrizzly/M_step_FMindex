#include "create_index.h"

#define SHORT_READ 0
//#define LONG_READ 0

typedef struct
{
#ifdef SHORT_READ
    char *sa;
#endif
#ifdef LONG_READ
    int *sa;
#endif
    int *read_id;
} SuffixArray;

typedef struct
{
    int row_map[ALL_POSS_COMB_CNT];
    char *bwtString;
    SuffixArray *suffix_array;
    int **occ_major;
    char **occ_minor;
} MStepFMIndex;
