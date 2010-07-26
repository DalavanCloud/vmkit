//===----- MMTk_Events.cpp - Implementation of the MMTk_Events class  -----===//
//
//                              The VMKit project
//
// This file is distributed under the University of Illinois Open Source 
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "JavaArray.h"
#include "JavaClass.h"
#include "JavaObject.h"
#include "JavaThread.h"
#include "MutatorThread.h"

using namespace j3;

extern "C" void Java_org_j3_mmtk_MMTk_1Events_tracePageAcquired__Lorg_mmtk_policy_Space_2Lorg_vmmagic_unboxed_Address_2I(
    JavaObject* event, JavaObject* space, uintptr_t address, int numPages) {
#ifdef DEBUG
  fprintf(stderr, "Pages acquired by thread %p from space %p at %x (%d)\n", (void*)mvm::Thread::get(), (void*)space, address, numPages);
#endif
}

extern "C" void Java_org_j3_mmtk_MMTk_1Events_tracePageReleased__Lorg_mmtk_policy_Space_2Lorg_vmmagic_unboxed_Address_2I(
    JavaObject* event, JavaObject* space, uintptr_t address, int numPages) {
#ifdef DEBUG
  fprintf(stderr, "Pages released by thread %p from space %p at %x (%d)\n", (void*)mvm::Thread::get(), (void*)space, address, numPages);
#endif
}

extern "C" void Java_org_j3_mmtk_MMTk_1Events_heapSizeChanged__Lorg_vmmagic_unboxed_Extent_2(
    JavaObject* event, uintptr_t heapSize) {
#ifdef DEBUG
  fprintf(stderr, "New heap size : %d\n", (int)heapSize);
#endif
}