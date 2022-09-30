#pragma once
#include "MMS/export.h"

namespace tstl{
    class global_allocation_policy{
    public:
        static void setMemoryManager( MMS::GenericMemoryManager * mm);
        static MMS::GenericMemoryManager *  getMemoryManager();
        static void initializeSystem(MMS::GenericMemoryManager * mm);
    private:
        static MMS::GenericMemoryManager * mms;
    };
}

