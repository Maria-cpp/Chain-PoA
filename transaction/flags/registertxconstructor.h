//
// Created by Mahnoor on 6/9/2021.
//

#ifndef FORWARDBLOCK_CPP_REGISTERTXCONSTRUCTOR_H
#define FORWARDBLOCK_CPP_REGISTERTXCONSTRUCTOR_H

#include "../protocoltxconstructor.h"
#include "../../forwardpoa.h"
#include <protocol/src/keypair/publickey.h>
#include <protocol/src/keypair/privatekey/signature.h>
#include <protocol/src/accounts/chainaccountinterface.h>
#include <protocol/src/transactions/txflags.h>

namespace ChainPoA
{
class RegisterTxConstructor : public ProtocolTxConstructor
{
   private:
       Protocol::PublicKey m_pubKey;
       Protocol::ChainAccountInterface* m_referrer;
       Protocol::Signature m_regSign;
       std::vector<Protocol::PublicKey> m_multiSign;

   public:
       RegisterTxConstructor(ForwardPoA* p, Protocol::PublicKey newKey, int epoch);
       RegisterTxConstructor setReferrer(Protocol::ChainAccountInterface* referrer, 
                                         Protocol::Signature registrantSigrnature);
       RegisterTxConstructor setMultiSigKeys(std::vector<Protocol::PublicKey> keys);

   protected:
       void beforeSerialize();

};

}


#endif    // FORWARDBLOCK_CPP_REGISTERTXCONSTRUCTOR_H
