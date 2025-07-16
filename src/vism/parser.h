#ifndef PARSER_H
#define PARSER_H
#include "lexer.h"
#include <stdbool.h>
#include <vm.h>

typedef enum {
  EK_PUSH,
  EK_POP,
  EK_LOAD,
  EK_ADD,
  EK_SUB,
  EK_MULT,
  EK_DIV,
  EK_CMP,
  EK_JMP,
  EK_JE,
  EK_JGE,
  EK_JG,
  EK_JLE,
  EK_JL,

  EK_INT,
  EK_LIT,
} ExprKind;

typedef struct {
  ExprKind kind;
  Tokens args;
} Expr;

typedef struct {
  size_t count;
  size_t cap;
  Expr *items;
} Exprs;

typedef struct {
  Tokens tokens;
  size_t pos;
  Token current;
  const char *file;
} Parser;

bool par_raw_consume(Parser *parser);
Token par_consume(Parser *parser);
Expr parse_expr(Parser *parser);

#endif /* end of include guard: PARSER_H */
