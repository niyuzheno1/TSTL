#include "global_allocation_policy.h"

using namespace tstl;

MMS::GenericMemoryManager * global_allocation_policy::mms;

void global_allocation_policy::setMemoryManager( MMS::GenericMemoryManager * mm){
    mms = mm;
}
MMS::GenericMemoryManager *  global_allocation_policy::getMemoryManager(){
    return mms;
}