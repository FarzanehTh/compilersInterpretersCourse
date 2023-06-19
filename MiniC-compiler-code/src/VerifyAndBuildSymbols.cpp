//
// Created by Fan Long on 2020/12/4.
//

//Add necessary headers you want
#include "VerifyAndBuildSymbols.h"
#include "Declarations.h"
#include "Terms.h"
#include "Types.h"
#include "Exprs.h"
#include "Statements.h"
#include "Program.h"
#include <string>
#include <sstream>
#include <iostream>

namespace minicc {

    /*********************** helper functions *************************/

    void addErrorMessage(std::string msg, ASTNode *node, std::vector<ErrorMessage> &Errors) {
        struct ErrorMessage errorMsg(std::string(msg), node->srcLoc());
        Errors.push_back(errorMsg);
    }

    void insertFunctionDeclaration(FuncDeclaration *funcDecl, FuncSymbolTable *funcTable, std::vector<ErrorMessage> &Errors) {

        std::string funcName = funcDecl->name();
        /* Omitted for privacy. */
    }

   /* Omitted for privacy. */
    /****************************************************************************/

    void VerifyAndBuildSymbols::visitASTNode(ASTNode *node) {
        /* Omitted for privacy. */
        ASTVisitor::visitASTNode(node);
    }

    void VerifyAndBuildSymbols::visitProgram(Program *prog) {

        /* Omitted for privacy. */
        // now loop over the children
        ASTVisitor::visitProgram(prog);
    }

    void VerifyAndBuildSymbols::visitVarDecl(VarDeclaration *decl) {
        
        /* Omitted for privacy. */
    }

    void VerifyAndBuildSymbols::visitFuncDecl(FuncDeclaration *func) {

        // Check return type of the function does not match with each other
        // Check number of parameters should match with each other
        // Check each parameter type should match with each other
        // Check there should be only one definition of the function
        // Check parameters cannot have the same name
        // Check the last statement a function body must be return if the return type is not void

        /* Omitted for privacy. */
        ASTVisitor::visitFuncDecl(func);
    }

    /* Omitted for privacy. */

    void VerifyAndBuildSymbols::visitVarExpr(VarExpr *expr) {
    /* Omitted for privacy. */
    }

    void VerifyAndBuildSymbols::visitAssignmentExpr(AssignmentExpr *expr) {
        // invoke verifyVarReference to verify
        // Also, check var and assigned expression must have the same type
        /* Omitted for privacy. */
    }

    void VerifyAndBuildSymbols::visitIntLiteralExpr(IntLiteralExpr *literal) {
        /* Omitted for privacy. */
    }

    void VerifyAndBuildSymbols::visitBoolLiteralExpr(BoolLiteralExpr *literal) {
        /* Omitted for privacy. */
    }

    //print collected error messages
    std::string VerifyAndBuildSymbols::genErrorMessages() {
        /* Omitted for privacy. */
    }

}