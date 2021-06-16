//
// Created by Mahnoor on 6/9/2021.
//

#ifndef FORWARDBLOCK_CPP_GENESISTX_H
#define FORWARDBLOCK_CPP_GENESISTX_H

#include <forwardblock-protocol-cpp/src/abstractprotocolchain.h>
#include <forwardblock-protocol-cpp/src/keypair/keypairfactory.h>
#include <forwardblock-protocol-cpp/src/keypair/publickey.h>
#include <forwardblock-protocol-cpp/src/transactions/abstractpreparedTx.h>


namespace ChainPoA
{
class GenesisTx : public Protocol::AbstractPreparedTx
{
   public:
       GenesisTx(const Buffer::Binary& bytes = {""}, Protocol::AbstractProtocolChain* p = nullptr);
   protected:
   Protocol::PublicKey m_chainMasterPubKey;
   std::vector<Protocol::PublicKey> m_signers;
   int m_initialSupply;
   void decodeCallback();
//   std::vector<Protocol::PublicKey> array();
};

}    // namespace ChainPoA


#endif    // FORWARDBLOCK_CPP_GENESISTX_H
