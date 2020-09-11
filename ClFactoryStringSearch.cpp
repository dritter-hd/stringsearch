#include <stdlib.h>
#include "stdafx.h"

#include "ClFactoryStringSearch.h"

// Instance
ClACStringSearch ClFactoryStringSearch::ac_ref;
ClBMStringSearch ClFactoryStringSearch::bm_ref;
ClTBMStringSearch ClFactoryStringSearch::tbm_ref;
ClAGStringSearch ClFactoryStringSearch::ag_ref;
ClBruteForceStringSearch ClFactoryStringSearch::bf_ref;
ClCStringSearch ClFactoryStringSearch::c_ref;
ClGSStringSearch ClFactoryStringSearch::gs_ref;
ClKMPStringSearch ClFactoryStringSearch::kmp_ref;
ClQSStringSearch ClFactoryStringSearch::qs_ref;
ClHStringSearch ClFactoryStringSearch::h_ref;

ClFactoryStringSearch::ClFactoryStringSearch(){
}

ClFactoryStringSearch::~ClFactoryStringSearch(){
}

ClAbstractStringSearch* ClFactoryStringSearch::getInstance(int type){                                   

// Map
//map<const char*, ClAbstractStringSearch> ref_table;
            
    switch (type){
		case AC: 
				//if (ac_ref* != NULL)	return *ac_ref;
                //ac_ref = new ClACStringSearch();
			return &ClFactoryStringSearch::ac_ref;
        case BM: 
                /*if (bm != NULL)
                return bm;
                bm = new ClBMStringSearch();
                return bm;*/
			return &ClFactoryStringSearch::bm_ref;
        case TBM: 
			return &ClFactoryStringSearch::tbm_ref;
        case AG:
			return &ClFactoryStringSearch::ag_ref;
		case BF:
			return &ClFactoryStringSearch::bf_ref;
		case C:
			return &ClFactoryStringSearch::c_ref;
		case GS:
			return &ClFactoryStringSearch::gs_ref;
		case KMP:
			return &ClFactoryStringSearch::kmp_ref;
		case QS:
			return &ClFactoryStringSearch::qs_ref;
		case H:
			return &ClFactoryStringSearch::h_ref;
		default:
			return NULL;
    }
} 
