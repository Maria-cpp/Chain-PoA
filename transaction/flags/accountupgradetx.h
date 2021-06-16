//
// Created by Mahnoor on 6/9/2021.
//

#ifndef FORWARDBLOCK_CPP_ACCOUNTUPGRADETX_H
#define FORWARDBLOCK_CPP_ACCOUNTUPGRADETX_H

#include "../../../utils/mathencodings.h"
#include <forwardblock-protocol-cpp/src/transactions/abstractpreparedTx.h>
namespace ChainPoA
{
class AccountUpgradeTx : public Protocol::AbstractPreparedTx
{
   public:
   AccountUpgradeTx(const Buffer::Binary& bytes = {""}, Protocol::AbstractProtocolChain* p = nullptr);
   static const int ACTION_UPGRADE = 0x00;
   static const int ACTION_DOWNGRADE = 0x01;
   int m_action;

   void decodeCallback();
   int getAction();
};
}    // namespace ChainPoA

#endif    // FORWARDBLOCK_CPP_ACCOUNTUPGRADETX_H
