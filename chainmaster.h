//
// Created by Mahnoor on 6/9/2021.
//

#ifndef FORWARDBLOCK_CPP_CHAINMASTER_H
#define FORWARDBLOCK_CPP_CHAINMASTER_H
#include <protocol/src/accounts/chainaccountinterface.h>
#include <protocol/src/keypair/publickey.h>

//#include "forwardpoa.h"
namespace ChainPoA
{
class ChainMaster : public Protocol::PublicKey, Protocol::ChainAccountInterface
{
   public:
   ChainMaster() = default;
   ChainMaster(Protocol::AbstractProtocolChain* p);
   Protocol::PublicKey getPublicKey() override;
   int initialSupply();
   bool canForgeBlocks() override;
   std::string getHash160() override;

   std::vector<Protocol::PublicKey> getAllPublicKeys() override;
   Protocol::PublicKey getMultiSig1();
   Protocol::PublicKey getMultiSig2();
   Protocol::PublicKey getMultiSig3();
   Protocol::PublicKey getMultiSig4();
   Protocol::PublicKey getMultiSig5();

   Protocol::PublicKey getSignatory(int num);


   std::string PUBLIC_KEY = "02b62ac0d6870a7f1984de6e9997724178f33897ad0eb210a87185fce1e3bfe172";
   std::string MULTI_SIG_KEY_1 =
      "02b62ac0d6870a7f1984de6e9997724178f33897ad0eb210a87185fce1e3bfe172";
   std::string MULTI_SIG_KEY_2 =
      "02723a0478600bfcf861a51339d21fdd19c063e8598c85da6dfcec5dc690b1679d";
   std::string MULTI_SIG_KEY_3 =
      "024096c2184bc02efdf47d475991810b3adc91c1096542f42c15b3779c24d8ac86";
   std::string MULTI_SIG_KEY_4 =
      "039b9a061c2f9fe2a42cc9c9d4b45dd5a166151baa18d7494d0aad757b0595a922";
   std::string MULTI_SIG_KEY_5 =
      "02b5fca74e80bd92a2a170d49fed09125f38c29635db29c1cc628a91e94bdf2549";

   const int INITIAL_SUPPLY = 10000000000000000;
   std::map<int, Protocol::PublicKey> m_multiSigPubs;
};
}    // namespace ChainPoA

#endif    // FORWARDBLOCK_CPP_CHAINMASTER_H
