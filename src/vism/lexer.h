#ifndef LEXER_H
#define LEXER_H
#define CHIMERA_STRIP_PREFIX
#include <chimera.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
  size_t row;
  size_t col;
} Position;

typedef struct {
  Position pos;
  char *literal;
} Span;

typedef enum {
  TK_ERR,
  TK_WHITESPACE,

  TK_NOP,

  TK_INT_LIT,
  TK_LIT,

  // KeyWords
  TK_PUSH,
  TK_POP,

  TK_LOAD,

  TK_ADD,
  TK_SUB,
  TK_MULT,
  TK_DIV,

  TK_CMP,

  TK_JMP,
  TK_JE,
  TK_JGE,
  TK_JG,
  TK_JLE,
  TK_JL,

  TK_SYSCALL,
} TokenKind;

typedef struct {
  TokenKind kind;
  char *id;
} TK_Map;

extern TK_Map TK_MAP[];

extern TK_Map KeyWordMap[];

typedef struct {
  Span span;
  TokenKind kind;
} Token;

char *print_token(Token t, bool with_value);

typedef struct {
  Token *items;
  size_t count;
  size_t cap;
} Tokens;

typedef struct {
  char *input;
  size_t pos;
  char current;
  Position cpos;
  const char *file;
} Lexer;

char lex_consume(Lexer *lexer);
Token next_token(Lexer *lexer);
#endif /* end of include guard: LEXER_H */
