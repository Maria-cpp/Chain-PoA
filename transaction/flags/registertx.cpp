//
// Created by Mahnoor on 6/9/2021.
//

#include "registertx.h"

ChainPoA::RegisterTx::RegisterTx(
   const Buffer::Binary& bytes, Protocol::AbstractProtocolChain* p)
   : AbstractPreparedTx(p, bytes)
{
}

void ChainPoA::RegisterTx::decodeCallback()
{
   if (m_data.value().empty()) {
      spdlog::error("RegisterTx::{} Registration data not present", __FUNCTION__);
      //      throw TxDecodeException::Incomplete($this, 'Registration data not present');
   }
   int pos = 0;
   Buffer::Binary dataReader(m_data.raw());
   std::string pubKeybytes = dataReader.raw();
   pubKeybytes = dataReader.value(pos, 33);
   pos += 33;
   try {
      m_pubKEy = m_p->keyPair()->publicKeyfromEntropy(Buffer::Base16(pubKeybytes));
   } catch (...) {
      spdlog::error("RegisterTx::{} Registrant public key decode error", __FUNCTION__);
      //      throw TxDecodeException::Incomplete($this, 'Registrant public key decode error');
   }
   // Get the referrer's Id
   m_referrerHash160 = dataReader.value(pos, 20);
   pos += 20;

   // MultiSig?
   int multiSigCount = Math::Decode_UInt1LE(dataReader.value(pos, 1));
   pos += 1;
   if (multiSigCount > 0) {
      if (multiSigCount > 5) {
         spdlog::error("RegisterTx::{} MultiSig cannot have more than 5 public key", __FUNCTION__);
         //   throw TxDecodeException::Incomplete($this, 'MultiSig cannot have more than 5 public key');
      }

      std::string msKbytes;
      Protocol::PublicKey msKpub;
      std::vector<std::string> multiSigIndex;
      for (int i = 0; i < multiSigCount; i++) {
         msKbytes = dataReader.value(pos, 33);
         pos += 33;

         try {
            msKpub = m_p->keyPair()->publicKeyfromEntropy(Buffer::Base16(binToHex(msKbytes)));
            if (i == 0) {
               if (msKpub.compressed().value() != m_pubKEy.compressed().value()) {
                  spdlog::error(
                     "RegisterTx::{} MultiSig key 0 must be same as account public key",
                     __FUNCTION__);
                  //   throw TxDecodeException::Incomplete($this, 'MultiSig key 0 must be same as account public key');
               }
            }
         } catch (...) {
            spdlog::error(
               "RegisterTx::{} Register multiSig key " + std::to_string(i) + "decode error",
               __FUNCTION__);
            //  throw TxDecodeException::Incomplete($this, sprintf('Register multiSig key %d decode error', $i));
         }

         std::string compPubKey = msKpub.compressed().hexits(false);
         std::string msKpub1 = Utils::strToLower(compPubKey);
         auto itr = std::find_if(multiSigIndex.begin(), multiSigIndex.end(), [&](std::string pub) {
            return pub == compPubKey;
         });
         if (itr != multiSigIndex.end()) {
            spdlog::error(
               "RegidterTx::{} Repeating multiSig key at position " + std::to_string(i) +
                  " in signatures",
               __FUNCTION__);
            //   throw TxDecodeException::Incomplete($this, sprintf('Repeating multiSig key at index %d', $i));
         }
         multiSigIndex.emplace_back(compPubKey);
         m_multiSig.push_back(msKpub);
      }
   }
   // Registrant's signature
   try {
      std::string regSignR = dataReader.value(pos, 32);
      pos+=32;
      std::string regSignS = dataReader.value(pos, 32);
      pos+=32;
      int regSignV = Math::Decode_UInt1LE(dataReader.value(pos, 1));
      pos+=1;
      m_regSign = Protocol::Signature(Buffer::Base16(binToHex(regSignR)), Buffer::Base16(binToHex(regSignS)), regSignV);
   } catch (...) {
      spdlog::error("RegidterTx::{} Registrant signature decode error", __FUNCTION__);
      //       throw TxDecodeException::Incomplete($this, 'Registrant signature decode error');
   }
   if (dataReader.sizeInBytes() != pos) {
      spdlog::error("RegidterTx::{} Data contains unnecessary additional bytes", __FUNCTION__);
      //      throw TxDecodeException::Incomplete($this, 'Data contains unnecessary additional bytes');
   }
}


std::string ChainPoA::RegisterTx::getReferrer()
{
   return m_referrerHash160;
}

Protocol::PublicKey ChainPoA::RegisterTx::getPubKey()
{
   return m_pubKEy;
}

Protocol::Signature ChainPoA::RegisterTx::getRegSign()
{
   return m_regSign;
}

std::vector<Protocol::PublicKey> ChainPoA::RegisterTx::getMultiSig()
{
   return m_multiSig;
}


