//
// Created by Mahnoor on 6/9/2021.
//

#ifndef FORWARDBLOCK_CPP_FORWARDPOA_H
#define FORWARDBLOCK_CPP_FORWARDPOA_H
#include "chainmaster.h"
#include "transaction/ledgerentryflags.h"
#include "transaction/txflag.h"
#include "transaction/txflagsinterface.h"
#include <forwardblock-protocol-cpp/src/abstractprotocolchain.h>
#include <forwardblock-protocol-cpp/src/protocolconstants.h>
#include <forwardblock-protocol-cpp/src/transactions/receipts/ledgerflags.h>
#include <forwardblock-protocol-cpp/src/transactions/abstracttxflag.h>
#include "string"

namespace ChainPoA
{
class TxFactory;

class ForwardPoA : public Protocol::AbstractProtocolChain, TxFlagInterface, LedgerEntryFlags
{
   public:
   ForwardPoA() = default;
   /**
    * ForwardPoA constructor.
    * @param configPath string
    */
   ForwardPoA(const std::string& configPath);
   ChainMaster* chainMaster();
   void registerTxFlags(std::shared_ptr<Protocol::TxFlags> flags) override;

   /**
    * @param f AbstractTxFlag
    * @param blockHeightContext int
    * @return bool
    */
   bool isEnabledTxFlag( Protocol::AbstractTxFlag& f, int blockHeightContext) override;

   std::string PROTOCOL_VERSION = "0.1.1";
//   Todo change the path accordingly in future
   std::string CORE_PROTOCOL_NAMESPACE = R"(ForwardBlock\Blockchain\Shared\Protocol)";

   /**
    * @param blockHeightContext int
    * @return int
    */
   int getForkId(int blockHeightContext);

   TxFactory* getTxFactory();

   /**
    * @param dec int
    * @param name string
    * @return TxFlag
    */
   TxFlag* createTxFlag(int dec, std::string name);

   private:
   ChainMaster* m_chainMaster;
   TxFactory* m_txF;
};
}    // namespace ChainPoA

#endif    // FORWARDBLOCK_CPP_FORWARDPOA_H
