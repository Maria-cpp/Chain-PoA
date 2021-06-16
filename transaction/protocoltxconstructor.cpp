//
// Created by Mahnoor on 6/9/2021.
//

#include "protocoltxconstructor.h"
// TODO Uncomment after merge
ChainPoA::ProtocolTxConstructor::ProtocolTxConstructor(
   ForwardPoA* p, int ver, Protocol::AbstractTxFlag* flag, int epoch)
   : Protocol::AbstractTxConstructor(p, ver, flag, epoch)
{
}
