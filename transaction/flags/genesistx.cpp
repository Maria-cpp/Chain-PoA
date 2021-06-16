//
// Created by Mahnoor on 6/9/2021.
//

#include "genesistx.h"

ChainPoA::GenesisTx::GenesisTx(const Buffer::Binary& bytes, Protocol::AbstractProtocolChain* p)
   : AbstractPreparedTx(p, bytes)
{
}

void ChainPoA::GenesisTx::decodeCallback()
{
   if (!m_data.value().empty()) {
      Buffer::Binary dataReader(m_data.raw());
      int pos = 0;

      // ChainMaster Identifier
      m_chainMasterPubKey = m_p->keyPair()->publicKeyfromEntropy(
         Buffer::Base16(binToHex(dataReader.value(pos, 33))));

      pos += 33;

      // Signers
      for (int i = 0; i < 5; i++) {
         m_signers.push_back(m_p->keyPair()->publicKeyfromEntropy(
            Buffer::Base16(binToHex(dataReader.value(pos, 33)))));
         pos += 33;
      }

      // Initial Supply
      m_initialSupply = Math::Decode_UInt8LE(dataReader.value(pos, 8));
      pos += 8;

      // Extra bytes?
      if (pos < dataReader.getSize()) {
         // todo throw ($this, 'Data contains unnecessary additional bytes');
      }
   }
}
