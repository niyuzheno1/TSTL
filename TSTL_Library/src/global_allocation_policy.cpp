#include "global_allocation_policy.h"
#include "node.h"
using namespace tstl;

MMS::GenericMemoryManager * global_allocation_policy::mms;

void global_allocation_policy::setMemoryManager( MMS::GenericMemoryManager * mm){
    mms = mm;
}
MMS::GenericMemoryManager *  global_allocation_policy::getMemoryManager(){
    return mms;
}

//initializeSystem
void global_allocation_policy::initializeSystem(MMS::GenericMemoryManager * mm){
    node::nil = node();
    node::nil.sz = 0;
    mms = mm;
}