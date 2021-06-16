//
// Created by Mahnoor on 6/9/2021.
//

#ifndef FORWARDBLOCK_CPP_GENESISTXCONSTRUCTOR_H
#define FORWARDBLOCK_CPP_GENESISTXCONSTRUCTOR_H

#include "../../forwardpoa.h"
#include "../protocoltxconstructor.h"
#include <data-types-v0.0.0/src/buffer/binary.h>
#include "../../chainmaster.h"
#include <protocol/src/transactions/txflags.h>

namespace ChainPoA
{
class GenesisTxConstructor : public ProtocolTxConstructor
{
   public:
       GenesisTxConstructor(ForwardPoA* p, int epoch);

   protected:
       void beforeSerialize();
};
}



#endif    // FORWARDBLOCK_CPP_GENESISTXCONSTRUCTOR_H
