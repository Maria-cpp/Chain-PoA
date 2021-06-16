//
// Created by Mahnoor on 6/9/2021.
//

#include "registertxconstructor.h"

ChainPoA::RegisterTxConstructor::RegisterTxConstructor(
   ChainPoA::ForwardPoA* p, Protocol::PublicKey newKey, int epoch)
   : ProtocolTxConstructor(p, 1, p->txFlags()->getWithName("register"), epoch)
   , m_pubKey{newKey}
   , m_regSign{m_regSign}
{
}
ChainPoA::RegisterTxConstructor ChainPoA::RegisterTxConstructor::setReferrer(
   Protocol::ChainAccountInterface* referrer, Protocol::Signature registrantSigrnature)
{
   m_referrer = referrer;
   m_regSign = registrantSigrnature;
   return *this;
}
ChainPoA::RegisterTxConstructor ChainPoA::RegisterTxConstructor::setMultiSigKeys(
   std::vector<Protocol::PublicKey> keys)
{
   if (keys.size() > 4) {
      // todo throw TxConstructException::Prop("account.multiSig", "Cannot add more than 4 public
   }
   m_multiSign.push_back(m_pubKey);
   for (auto key : keys) {
      m_multiSign.push_back(key);
   }
   return *this;
}
void ChainPoA::RegisterTxConstructor::beforeSerialize()
{
   Buffer::Binary data;
   std::string str = m_pubKey.compressed().binary()->raw();

   // Append new account's public key
   auto pubPad = Utils::str_pad(str, 33, '\0', 0);
   data.append(pubPad);
   data.append(hexToBin(m_referrer->getHash160()));

   // MultiSig?
   int multiSigCount = m_multiSign.size();
   data.append(Math::Encode_UInt1LE(multiSigCount));
   if (multiSigCount != 0) {
      for (auto pubKey : m_multiSign) {
         std::string str = pubKey.compressed().binary()->raw();
         data.append(Utils::str_pad(str, 33, '\0', 0));
      }
   }

   // Registrant's Signature
   if (!m_regSign.r().value().empty()) {
      data.append(hexToBin(m_regSign.r().hexits(false)));
      data.append(hexToBin(m_regSign.s().hexits(false)));
      data.append(Math::Encode_UInt1LE(m_regSign.v()));
   }
   m_data = *dynamic_cast<Buffer::Binary*>(data.readOnly(true));
}
