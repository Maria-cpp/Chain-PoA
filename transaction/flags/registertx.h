//
// Created by Mahnoor on 6/9/2021.
//

#ifndef FORWARDBLOCK_CPP_REGISTERTX_H
#define FORWARDBLOCK_CPP_REGISTERTX_H


#include <data-types-v0.0.0/src/buffer/base16.h>
#include <data-types-v0.0.0/src/buffer/binary.h>
#include <forwardblock-protocol-cpp/src/keypair/keypairfactory.h>
#include <forwardblock-protocol-cpp/src/keypair/privatekey/signature.h>
#include <forwardblock-protocol-cpp/src/keypair/publickey.h>
#include <forwardblock-protocol-cpp/src/transactions/abstractpreparedTx.h>
#include <utils/mathencodings.h>
#include <utils/utils.h>

namespace ChainPoA
{
class RegisterTx : public Protocol::AbstractPreparedTx
{
   public:
   RegisterTx(
      const Buffer::Binary& bytes = {""},
      Protocol::AbstractProtocolChain* p = nullptr);
   void decodeCallback();
   std::string getReferrer();
   Protocol::PublicKey getPubKey();
   Protocol::Signature getRegSign();
   std::vector<Protocol::PublicKey> getMultiSig();

   private:
   std::string m_referrerHash160;
   Protocol::PublicKey m_pubKEy;
   Protocol::Signature m_regSign;
   std::vector<Protocol::PublicKey> m_multiSig;
};
}    // namespace ChainPoA

#endif    // FORWARDBLOCK_CPP_REGISTERTX_H
