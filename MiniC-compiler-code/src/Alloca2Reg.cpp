//
// Created by Fan Long on 2020/12/9.
//

/* Alloca to Register Optimization */

//add more header files if your want
#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/IR/CFG.h"
#include <set>

using namespace llvm;

// Note in this code, I have used both "iterator" (like in the line 194) methods for going over the basic blocks
// or instuctions or any iterable like maps or sets, to indicate we can loop over them either way.

namespace {
    struct Alloca2RegPass : public FunctionPass {
        static char ID;
        Alloca2RegPass() : FunctionPass(ID) {}
       /* Omitted for privacy. */
    };
}

char Alloca2RegPass::ID = 0;

static RegisterPass<Alloca2RegPass> X("alloca2reg", "Alloca-to-register pass for minic", false, false);

// Automatically enable the pass.
// http://adriansampson.net/blog/clangpass.html
static void registerAlloca2RegPass(const PassManagerBuilder &,
                                    legacy::PassManagerBase &PM) {
    PM.add(new Alloca2RegPass());
}
static RegisterStandardPasses
        RegisterMyPass(PassManagerBuilder::EP_EarlyAsPossible,
                       registerAlloca2RegPass);
