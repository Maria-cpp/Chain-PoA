//
// Created by Mahnoor on 6/9/2021.
//

#ifndef FORWARDBLOCK_CPP_TXFLAGSINTERFACE_H
#define FORWARDBLOCK_CPP_TXFLAGSINTERFACE_H

namespace ChainPoA
{
class TxFlagInterface
{
   public:
   TxFlagInterface() = default;
   static const int TX_FLAG_GENESIS = 0x01;
   static const int TX_FLAG_REGISTER = 0x64;
   static const int TX_FLAG_TRANSFER = 0xc8;
   static const int TX_FLAG_ACCOUNT_UPGRADE = 0x11;
};
}    // namespace ChainPoA


#endif    // FORWARDBLOCK_CPP_TXFLAGSINTERFACE_H
