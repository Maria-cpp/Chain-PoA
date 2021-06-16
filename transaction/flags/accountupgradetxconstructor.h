//
// Created by Mahnoor on 6/9/2021.
//

#ifndef FORWARDBLOCK_CPP_ACCOUNTUPGRADETXCONSTRUCTOR_H
#define FORWARDBLOCK_CPP_ACCOUNTUPGRADETXCONSTRUCTOR_H

#include "../../forwardpoa.h"
#include "../protocoltxconstructor.h"
#include "accountupgradetx.h"
#include <forwardblock-protocol-cpp/src/transactions/traits.h>
#include <spdlog/spdlog.h>
#include <data-types-v0.0.0/src/buffer/binary.h>
#include "../../../utils/mathencodings.h"
#include <forwardblock-protocol-cpp/src/transactions/txflags.h>
namespace ChainPoA
{
class AccountUpgradeTxConstructor : public ProtocolTxConstructor
{
   public:
   AccountUpgradeTxConstructor(ForwardPoA* p, int epoch, int action);
   void beforeSerialize();

   private:
   int m_action;
};
}    // namespace ChainPoA

#endif    // FORWARDBLOCK_CPP_ACCOUNTUPGRADETXCONSTRUCTOR_H
