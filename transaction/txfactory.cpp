//
// Created by Mahnoor on 6/9/2021.
//

#include "txfactory.h"
#include "protocoltxconstructor.h"

ChainPoA::TxFactory::TxFactory(Protocol::AbstractProtocolChain* p) : m_p(p) {}

ChainPoA::RegisterTxConstructor ChainPoA::TxFactory::registerTx(Protocol::PublicKey publicKey, int epoch)
{
   ChainPoA::RegisterTxConstructor* Ptx = dynamic_cast<ChainPoA::RegisterTxConstructor*>(createTx(
      ChainPoA::TxFlagInterface::TX_FLAG_REGISTER, std::make_tuple(dynamic_cast<ChainPoA::ForwardPoA*>(m_p), &publicKey, epoch, NULL)));
   return *Ptx;
}

Protocol::AbstractPreparedTx* ChainPoA::TxFactory::decode(Buffer::Binary encoded)
{
   return Protocol::Transaction::DecodeAs(m_p, encoded);
}
int ChainPoA::TxFactory::getEpochArg(int epoch)
{
   if (epoch == 0 || epoch <= 0) {
      return std::time(0);
   }
   return epoch;
}

ChainPoA::ProtocolTxConstructor* ChainPoA::TxFactory::createTx(
   int flag, std::tuple<ForwardPoA*, Protocol::PublicKey*, int, int> args)
{
   auto pTx = nullptr;
   try {
      ChainPoA::TxFlag* txflag = dynamic_cast<ChainPoA::TxFlag*>(m_p->txFlags()->getFlag(flag));
      txflag->arguments(args);
      auto pTx = txflag->create();
   } catch (Exception e) {
      throw std::invalid_argument(e.what());
   }
   return pTx;
}


ChainPoA::AccountUpgradeTxConstructor ChainPoA::TxFactory::accountUpgradeTx(int action, int epoch)
{
   ChainPoA::AccountUpgradeTxConstructor* Ptx = dynamic_cast<ChainPoA::AccountUpgradeTxConstructor*>(createTx(
      ChainPoA::TxFlagInterface::TX_FLAG_REGISTER, std::make_tuple(dynamic_cast<ChainPoA::ForwardPoA*>(m_p), nullptr, epoch, action)));
   return *Ptx;
}
