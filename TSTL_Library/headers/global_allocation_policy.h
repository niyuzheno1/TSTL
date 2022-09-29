#pragma once
#include "MMS/export.h"

namespace tstl{
    class global_allocation_policy{
    public:
        static void setMemoryManager( MMS::GenericMemoryManager * mm);
        static MMS::GenericMemoryManager *  getMemoryManager();
    private:
        static MMS::GenericMemoryManager * mms;
    };
}

