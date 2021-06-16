//
// Created by Mahnoor on 6/9/2021.
//

#ifndef FORWARDBLOCK_CPP_TXFACTORY_H
#define FORWARDBLOCK_CPP_TXFACTORY_H

#include "txflagsinterface.h"
#include <protocol/src/abstractprotocolchain.h>
#include <protocol/src/transactions/abstractpreparedTx.h>
#include <protocol/src/transactions/transaction.h>
#include <protocol/src/transactions/txflags.h>
#include <transaction/flags/accountupgradetxconstructor.h>
#include <transaction/flags/registertxconstructor.h>

namespace ChainPoA
{
class ProtocolTxConstructor;

class TxFactory : public TxFlagInterface
{
   private:
   Protocol::AbstractProtocolChain* m_p;

   public:
   TxFactory() = default;
   TxFactory(Protocol::AbstractProtocolChain* p);
   RegisterTxConstructor registerTx(Protocol::PublicKey publicKey, int epoch = NULL);
   AccountUpgradeTxConstructor accountUpgradeTx(int action, int epoch = NULL);
   Protocol::AbstractPreparedTx* decode(Buffer::Binary encoded);

   private:
   int getEpochArg(int epoch = 0);
   ProtocolTxConstructor* createTx(int flag, std::tuple<ForwardPoA*, Protocol::PublicKey*, int ,
                                                        int>args );
};
}    // namespace ChainPoA


#endif    // FORWARDBLOCK_CPP_TXFACTORY_H
