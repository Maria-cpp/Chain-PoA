//
// Created by Mahnoor on 6/9/2021.
//

#include "genesistxconstructor.h"
ChainPoA::GenesisTxConstructor::GenesisTxConstructor(ChainPoA::ForwardPoA* p, int epoch)
   : ProtocolTxConstructor{p, 1, p->txFlags()->getWithName("genesis"), epoch}
{
}
void ChainPoA::GenesisTxConstructor::beforeSerialize()
{
   Buffer::Binary data;

   auto chainMaster = dynamic_cast<ForwardPoA*>(m_p)->chainMaster();
   data.append(chainMaster->compressed().binary()->getBufferData());

   for (auto publicKey : chainMaster->getAllPublicKeys()) {
      data.append(publicKey.compressed().binary()->getBufferData());
   }

   data.append(Math::Encode_UInt8LE(chainMaster->initialSupply()));

   m_data = *dynamic_cast<Buffer::Binary*>(data.readOnly(true));
}
