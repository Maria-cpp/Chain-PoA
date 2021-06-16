//
// Created by Mahnoor on 6/9/2021.
//

#ifndef FORWARDBLOCK_CPP_LEDGERENTRYFLAGS_H
#define FORWARDBLOCK_CPP_LEDGERENTRYFLAGS_H

namespace ChainPoA
{
class LedgerEntryFlags
{
   public:
   /** @var int Initial supply as per genesis */
   const int TX_RECEIPT_G_INIT_SUPPLY = 0x01;
   /** @var int Chain-master mint op */
   const int TX_RECEIPT_MINT = 0x02;
   /** @var int Fee deduction per byte */
   const int TX_RECEIPT_DEBIT_FEE = 0x64;
   /** @var int Transfer's debit from payer */
   const int TX_RECEIPT_TRANSFER_DEBIT = 201;
   /** @var int Transfer's credit to payee */
   const int TX_RECEIPT_TRANSFER_CREDIT = 202;
   /** @var int Transfer's fee */
   const int TX_RECEIPT_TRANSFER_FEE = 203;
   /** @var int Registration charges */
   const int TX_RECEIPT_REGISTER = 301;
   /** @var int Referrer commission */
   const int TX_RECEIPT_REGISTER_REF_COM = 302;
};

}    // namespace ChainPoA


#endif    // FORWARDBLOCK_CPP_LEDGERENTRYFLAGS_H
