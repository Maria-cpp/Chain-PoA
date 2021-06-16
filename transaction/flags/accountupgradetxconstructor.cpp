//
// Created by Mahnoor on 6/9/2021.
//

#include "accountupgradetxconstructor.h"
ChainPoA::AccountUpgradeTxConstructor::AccountUpgradeTxConstructor(
   ChainPoA::ForwardPoA* p, int epoch, int action)
   : ProtocolTxConstructor{p, 1, p->txFlags()->getWithName("account_upgrade"), epoch}
{
   if (action != AccountUpgradeTx::ACTION_UPGRADE && action != AccountUpgradeTx::ACTION_DOWNGRADE) {
      spdlog::error("AccountUpgradeTxConstructor::{} upgrade.action, OutOfBounds", __FUNCTION__);
      //      throw TxConstructException::Prop("upgrade.action", "OutOfBounds");
   }
   m_action = action;
}

void ChainPoA::AccountUpgradeTxConstructor::beforeSerialize()
{
   Buffer::Binary data;
   data.append(Math::Encode_UInt1LE(m_action));
   m_data = *dynamic_cast<Buffer::Binary*>(data.readOnly(true));
}
