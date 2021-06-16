//
// Created by Mahnoor on 6/9/2021.
//

#ifndef FORWARDBLOCK_CPP_TXFLAG_H
#define FORWARDBLOCK_CPP_TXFLAG_H

#include "../utils/utils.h"
#include <forwardblock-protocol-cpp/src/transactions/abstracttxflag.h>
#include <forwardblock-protocol-cpp/src/keypair/publickey.h>

#include <string>
namespace ChainPoA
{

class ProtocolTxConstructor;
class ForwardPoA;
class TxFlag : public Protocol::AbstractTxFlag
{
   private:
   std::string m_createClass;
   std::string m_decodeClass;

   //memeber variables for constructor
   ForwardPoA* m_FPoA;
   Protocol::PublicKey m_pub;
   int m_action;
   int m_epoch;

   public:
   TxFlag(Protocol::AbstractProtocolChain* p, int id, std::string name);
   Protocol::AbstractTxConstructor* create() override;
   Protocol::AbstractPreparedTx* decode(const Buffer::Binary& encoded) override;
   Protocol::AbstractTxReceipt* newReceipt(Protocol::AbstractPreparedTx* tx, int blockHeightContext);
   Protocol::AbstractTxReceipt* decodeReceipt(Protocol::AbstractPreparedTx* tx, Buffer::Binary, int blockHeightContext) override;
   void arguments(std::tuple<ForwardPoA*, Protocol::PublicKey*, int, int> args);
};
}    // namespace ChainPoA


#endif    // FORWARDBLOCK_CPP_TXFLAG_H
