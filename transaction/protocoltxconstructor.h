//
// Created by Mahnoor on 6/9/2021.
//

#ifndef FORWARDBLOCK_CPP_PROTOCOLTXCONSTRUCTOR_H
#define FORWARDBLOCK_CPP_PROTOCOLTXCONSTRUCTOR_H

#include "../forwardpoa.h"
#include <protocol/src/abstractprotocolchain.h>
#include <protocol/src/transactions/abstracttxconstructor.h>

namespace ChainPoA
{
class ProtocolTxConstructor : public Protocol::AbstractTxConstructor
{
   protected:
   Protocol::AbstractProtocolChain* m_p;

   public:
   ProtocolTxConstructor(ForwardPoA* p, int ver, Protocol::AbstractTxFlag* flag, int epoch);
};

}    // namespace ChainPoA


#endif    // FORWARDBLOCK_CPP_PRTOCOLTXCONSTRUCTOR_H
