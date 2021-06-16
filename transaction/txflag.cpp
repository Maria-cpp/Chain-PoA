//
// Created by Mahnoor on 6/9/2021.
//

#include "txflag.h"
#include "../forwardpoa.h"
#include "protocoltxconstructor.h"
#include <transaction/flags/accountupgradetxconstructor.h>
#include <transaction/flags/genesistx.h>
#include <transaction/flags/genesistxconstructor.h>
#include <transaction/flags/registertx.h>
#include <transaction/flags/registertxconstructor.h>

ChainPoA::TxFlag::TxFlag(Protocol::AbstractProtocolChain* p, int id, std::string name)
   : Protocol::AbstractTxFlag{p, id, name}
{
   auto pascalCase = Utils::pascalCase(name);
   // Create TX clas
   std::string str = R"(ForwardBlock\Chain\PoA\Transactions\Flags)" + pascalCase + "TxConstructor";
   //   m_createClass = str;
   m_createClass = name;
   // TODO
   // throw new \UnexpectedValueException('Cannot find "%s" tx create class');

   std::string str2 = R"(ForwardBlock\Chain\PoA\Transactions\Flags\)" + pascalCase + "Tx";
   m_decodeClass = name;
   // TODO
   //     throw new \UnexpectedValueException('Cannot find "%s" tx decode class');
}
Protocol::AbstractTxConstructor* ChainPoA::TxFlag::create()
{
   if (m_createClass == "AccountUpgradeTxConstructor") {
      return new AccountUpgradeTxConstructor(m_FPoA, m_epoch, m_action);
   } else if (m_createClass == "GenesisTxConstructor") {
      return new GenesisTxConstructor(m_FPoA, m_epoch);
   } else if (m_createClass == "RegisterTxConstructor") {
      return new RegisterTxConstructor(m_FPoA, m_pub, m_epoch);
   } else {
      spdlog::error("TxFlag::{} No constructor matches", __FUNCTION__);
   }
}


Protocol::AbstractPreparedTx* ChainPoA::TxFlag::decode(const Buffer::Binary& encoded)
{
   Protocol::AbstractPreparedTx* (*ptr)(
      Protocol::AbstractPreparedTx * self, Protocol::AbstractProtocolChain * p, Buffer::Binary encoded);
   ptr = &Protocol::AbstractPreparedTx::Decode;    // todo testing required


   if (m_createClass == "AccountUpgradeTx") {
      AccountUpgradeTx* AccObj = new AccountUpgradeTx();
      ptr(AccObj, m_p, encoded);
   } else if (m_createClass == "GenesisTx") {
      GenesisTx* GenObj = new GenesisTx();
      ptr(GenObj, m_p, encoded);
   } else if (m_createClass == "RegisterTx") {
      RegisterTx* RegObj = new RegisterTx();
      ptr(RegObj, m_p, encoded);
   } else {
      spdlog::error("TxFlag::{} No Tx matches", __FUNCTION__);
   }
}

Protocol::AbstractTxReceipt* ChainPoA::TxFlag::newReceipt(
   Protocol::AbstractPreparedTx* tx, int blockHeightContext)
{
   // TODO once forward poa core docker complete
   auto receiptClass = Utils::pascalCase(m_name);
   if (receiptClass == "AbstractFinalReceipt") {
      // return AbstractFinalReceipt();
   } else if (receiptClass == "AccountUpgradeReceipt") {
      // return AccountUpgradeReceipt();
   } else if (receiptClass == "GenesisReceipt") {
      // return new GenesisReceipt();
   } else if (receiptClass == "RegisterReceipt") {
      //  return new RegisterReceipt();
   } else {
      spdlog::error("TxFlag::{} No Receipt matches", __FUNCTION__);
   }
}
Protocol::AbstractTxReceipt* ChainPoA::TxFlag::decodeReceipt(
   Protocol::AbstractPreparedTx* tx, Buffer::Binary, int blockHeightContext)
{
   // TODO once forward poa core docker complete
   return nullptr;
}
void ChainPoA::TxFlag::arguments(std::tuple<ForwardPoA*, Protocol::PublicKey*, int, int> args)
{
   m_FPoA = std::get<0>(args);
   m_pub = *std::get<1>(args);
   m_epoch = std::get<2>(args);
   m_action = std::get<3>(args);
}
