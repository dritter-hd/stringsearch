#include "ClAbstractStringSearch.h"

#include "ClACStringSearch.h"
#include "ClAGStringSearch.h"
#include "ClBMStringSearch.h"
#include "ClTBMStringSearch.h"
#include "ClBruteForceStringSearch.h"
#include "ClCStringSearch.h"
#include "ClGSStringSearch.h"
#include "ClKMPStringSearch.h"
#include "ClQSStringSearch.h"
#include "ClHStringSearch.h"

class ClFactoryStringSearch {

      private:
              static ClACStringSearch ac_ref;
              static ClAGStringSearch ag_ref;
              static ClBMStringSearch bm_ref;
              static ClTBMStringSearch tbm_ref;
			  static ClBruteForceStringSearch bf_ref;
			  static ClCStringSearch c_ref;
			  static ClGSStringSearch gs_ref;
			  static ClKMPStringSearch kmp_ref;
			  static ClQSStringSearch qs_ref;
			  static ClHStringSearch h_ref;
              
      public:			 
			 ClFactoryStringSearch();			 
			 ~ClFactoryStringSearch();

             static const int BM  = 0;
             static const int TBM = 1;
             static const int AC  = 2;
             static const int AG  = 3;
			 static const int BF  = 4;
			 static const int C   = 5;
			 static const int GS  = 6;
			 static const int KMP = 7;
			 static const int QS  = 8;
			 static const int H   = 9;

			 static ClAbstractStringSearch* getInstance(int type);
};
