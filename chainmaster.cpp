//
// Created by Mahnoor on 6/9/2021.
//

#include "chainmaster.h"

ChainPoA::ChainMaster::ChainMaster(Protocol::AbstractProtocolChain* p) : PublicKey(p, {}, Buffer::Base16("") , false)
{
}

std::vector<Protocol::PublicKey> ChainPoA::ChainMaster::getAllPublicKeys()
{
   std::vector<Protocol::PublicKey> pubkey;
   for (int i = 0; i <= 5; i++)
      pubkey.push_back(getSignatory(i));
   return pubkey;
}

Protocol::PublicKey ChainPoA::ChainMaster::getPublicKey()
{
   return *this;
}
int ChainPoA::ChainMaster::initialSupply()
{
   return INITIAL_SUPPLY;
}
bool ChainPoA::ChainMaster::canForgeBlocks()
{
   return true;
}

Protocol::PublicKey ChainPoA::ChainMaster::getMultiSig1()
{
   return getSignatory(1);
}
Protocol::PublicKey ChainPoA::ChainMaster::getMultiSig2()
{
   return getSignatory(2);
}
Protocol::PublicKey ChainPoA::ChainMaster::getMultiSig3()
{
   return getSignatory(3);
}
Protocol::PublicKey ChainPoA::ChainMaster::getMultiSig4()
{
   return getSignatory(4);
}
Protocol::PublicKey ChainPoA::ChainMaster::getMultiSig5()
{
   return getSignatory(5);
}

Protocol::PublicKey ChainPoA::ChainMaster::getSignatory(int num)
{
   if (m_multiSigPubs[num].getPubKey().empty()) {
      // Need to ask Sir Furqan
   }
   return m_multiSigPubs[num];
}
std::string ChainPoA::ChainMaster::getHash160() {

}
