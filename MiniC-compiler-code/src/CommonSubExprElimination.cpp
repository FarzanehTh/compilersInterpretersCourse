/* Common Subexpression Elimination Optimization */

#include <set>

#include "llvm/IR/CFG.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"

using namespace llvm;

namespace {
    struct CommonSubExprEliminationPass : public FunctionPass {
        static char ID;
        CommonSubExprEliminationPass() : FunctionPass(ID) {}

        std::set<Instruction*> instructionsToDelete;
        
        virtual bool runOnFunction(Function &F) {
            errs() << "Running CommonSubExprElimination on function called " << F.getName() << "!\n";
            bool needOptimization = true;
            while (needOptimization) {
                for (Function::iterator basicBlockIt = F.begin(); basicBlockIt != F.end(); basicBlockIt++) {
                    BasicBlock *basicBlock = &(*basicBlockIt);
                    for (BasicBlock::iterator it1 = basicBlock->begin(); it1 != basicBlock->end(); it1++) {
                        Instruction *instruction1 = &(*it1);
                        llvm::Value *loadPtrOperand = nullptr;
                        if (llvm::isa<llvm::LoadInst>(instruction1)) {
                            loadPtrOperand = ((LoadInst *)instruction1)->getPointerOperand();
                        }
                        /* Omitted for privacy. */
                    }
                }
                /* Omitted for privacy. */
            }

            // 2. Clear the data structures used in this function pass. Note this is needed since the data
            // structures of this struct is global among all of the functions of the module on which this
            // pass is being run.
            instructionsToDelete.clear();

            return true;
        }
    };
}  // namespace

char CommonSubExprEliminationPass::ID = 1;

static RegisterPass<CommonSubExprEliminationPass> X("commonSubExprElimination", "Common-SubExpr-Elimination pass for minic", false, false);

// Automatically enable the pass.
// http://adriansampson.net/blog/clangpass.html
static void registerCommonSubExprEliminationPass(const PassManagerBuilder &, legacy::PassManagerBase &PM) {
     PM.add(new CommonSubExprEliminationPass()); 
}
static RegisterStandardPasses RegisterMyPass(PassManagerBuilder::EP_EarlyAsPossible, registerCommonSubExprEliminationPass);
