//
// Created by Mahnoor on 6/9/2021.
//

#include "forwardpoa.h"
#include <transaction/txfactory.h>


ChainPoA::ForwardPoA::ForwardPoA(const std::string& configPath)
   : AbstractProtocolChain{configPath}, m_txF{new ChainPoA::TxFactory(this)}
{
}


ChainPoA::ChainMaster* ChainPoA::ForwardPoA::chainMaster()
{
   if (m_chainMaster == nullptr) {
      ChainMaster ChainObj(this);
      m_chainMaster = &ChainObj;
   }
   return m_chainMaster;
}

void ChainPoA::ForwardPoA::registerTxFlags(std::shared_ptr<Protocol::TxFlags> flags)
{
   Protocol::LedgerFlags Lflag = flags->ledgerFlags();
   Lflag.append(LedgerEntryFlags::TX_RECEIPT_G_INIT_SUPPLY, true);
   Lflag.append(LedgerEntryFlags::TX_RECEIPT_MINT, true);
   Lflag.append(LedgerEntryFlags::TX_RECEIPT_DEBIT_FEE, false);
   Lflag.append(LedgerEntryFlags::TX_RECEIPT_TRANSFER_DEBIT, false);
   Lflag.append(LedgerEntryFlags::TX_RECEIPT_TRANSFER_CREDIT, true);
   Lflag.append(LedgerEntryFlags::TX_RECEIPT_TRANSFER_FEE, false);
   // TX: GENESIS
   flags->append(createTxFlag(ProtocolConstants::GENESIS_TX_FLAG, "GENESIS"));

   // TX: REGISTER
   flags->append(createTxFlag(TX_FLAG_REGISTER, "REGISTER"));
   Lflag.append(LedgerEntryFlags::TX_RECEIPT_REGISTER, false);
   Lflag.append(LedgerEntryFlags::TX_RECEIPT_REGISTER_REF_COM, true);

   // TX: ACCOUNT_UPGRADE
   flags->append(createTxFlag(TX_FLAG_ACCOUNT_UPGRADE, "ACCOUNT_UPGRADE"));
}

bool ChainPoA::ForwardPoA::isEnabledTxFlag(Protocol::AbstractTxFlag& f, int blockHeightContext)
{
   switch (f.id()) {
   case Protocol::AbstractProtocolChain::GENESIS_TX_FLAG:
      return blockHeightContext == 0;
   default:
      return false;
   }
}

int ChainPoA::ForwardPoA::getForkId(int blockHeightContext)
{
   switch (blockHeightContext) {
   default:
      return m_config->getMForkId();
   }
   return 0;
}

ChainPoA::TxFactory* ChainPoA::ForwardPoA::getTxFactory()
{
   return m_txF;
}

ChainPoA::TxFlag* ChainPoA::ForwardPoA::createTxFlag(int dec, std::string name)
{
   return new ChainPoA::TxFlag(this, dec, name);
}