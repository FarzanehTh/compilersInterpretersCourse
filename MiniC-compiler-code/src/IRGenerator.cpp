//
// Created by Fan Long on 2020/12/6.
//

//add more header files if your want
#include "IRGenerator.h"
#include "llvm/IR/Module.h"
#include "Declarations.h"
#include "Program.h"
#include "Exprs.h"
#include "Statements.h"
#include <iostream>

namespace minicc {

    /********************** member helper functions **********************/

    llvm::Value* IRGenerator::createGEPInstruction(VarReference *varRef, llvm::Value *arrPtrValue) {
        /* Omitted for privacy. */
    }

    llvm::Value* IRGenerator::translateLogicalBinaryExpr(BinaryExpr *expr) {

        llvm::Function *parentFunc = TheBuilder->GetInsertBlock()->getParent();
        llvm::BasicBlock *currentBasicBlock = TheBuilder->GetInsertBlock();
        llvm::BasicBlock *slowBasicBlock = llvm::BasicBlock::Create(*TheContext, "logical-slow-bb", parentFunc);
        llvm::BasicBlock *outBasicBlock = llvm::BasicBlock::Create(*TheContext, "logical-out-bb", parentFunc);
        /* Omitted for privacy. */
    }

    void IRGenerator::setParametersLlvmValues(FuncDeclaration *func, VarSymbolTable *varTable) {
        /* Omitted for privacy. */
    }

    void IRGenerator::allocateParameters(FuncDeclaration *func, llvm::Function *llvmFunc) {
        
        ScopeStatement *funcBody = func->body();
        VarSymbolTable *varTable = funcBody->scopeVarTable();
        /* Omitted for privacy. */
    }

    void IRGenerator::allocateLocalVars(VarSymbolTable *varTable, std::vector<std::string> varNamesVector) {
       /* Omitted for privacy. */
    }

    void IRGenerator::allocateGlobalVars(VarSymbolTable *varTable, std::vector<std::string> varNamesVector) {
        /* Omitted for privacy. */
    }

    /*****************************************************************************/

    void IRGenerator::visitProgram(Program *prog) {
        //Initlize llvm module and builder
        TheModule = std::make_unique<llvm::Module>(ModuleName, *TheContext);
        /* Omitted for privacy. */
    }

    /* Omitted for privacy. */

    void IRGenerator::visitBinaryExpr(BinaryExpr *expr) {

        llvm::Value *exprLlvmValue = nullptr;
        Expr::ExprOpcode opCode = expr->opcode();
        /* Omitted for privacy. */
        setLlvmValueForExpr(expr, exprLlvmValue);
    }

    /* Omitted for privacy. */

    void IRGenerator::visitScope(ScopeStatement *stmt) {
        /* Omitted for privacy. */
    }
}