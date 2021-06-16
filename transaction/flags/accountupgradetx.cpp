//
// Created by Mahnoor on 6/9/2021.
//

#include "accountupgradetx.h"

ChainPoA::AccountUpgradeTx::AccountUpgradeTx(
   const Buffer::Binary& bytes, Protocol::AbstractProtocolChain* p)
   : AbstractPreparedTx(p, bytes)
{
}

void ChainPoA::AccountUpgradeTx::decodeCallback()
{
   if (m_data.value().empty()) {
      spdlog::error("AccountUpgradeTx::{} Transaction data not present", __FUNCTION__);
      //      throw TxDecodeException::Incomplete($this, 'Transaction data not present');
   }

   std::string action = m_data.raw();
   if (action.size() != 1) {
      spdlog::error("AccountUpgradeTx::{} Invalid accountUpgrade tx data", __FUNCTION__);
      //      throw TxDecodeException::Incomplete($this, 'Invalid accountUpgrade tx data');
   }
   m_action = Math::Decode_UInt1LE(action);
}

int ChainPoA::AccountUpgradeTx::getAction()
{
   return m_action;
}
