#pragma once

class ClAbstractStringSearch {
      public:
        // pure virtual methods - no instanciation possible
        virtual int* find(char*)      =0;
        virtual int  contains(char*)  =0;
        virtual void preprocess(char*)=0;
};
