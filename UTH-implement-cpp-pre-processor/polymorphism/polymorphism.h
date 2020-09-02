#ifndef __CPP2C_POLYMORPHISM_H__
#define __CPP2C_POLYMORPHISM_H__
#include <stdio.h>


/*   TextFormatter   */
typedef struct TextFormatter TextFormatter;
typedef struct TextFormatter_function TextFormatter_function;
void TextFormatterV13Dtor(TextFormatter *this);
void TextFormatterV_printpc(TextFormatter const *this, const char* text);

/*   DefaultTextFormatter   */
typedef struct DefaultTextFormatter DefaultTextFormatter;
typedef struct DefaultTextFormatter_function DefaultTextFormatter_function;
void DefaultTextFormatter19Ctor(DefaultTextFormatter *this);
void DefaultTextFormatter19_copy_Ctor(DefaultTextFormatter *this, DefaultTextFormatter *other);
DefaultTextFormatter* DTF19_E_operatorpDTF(DefaultTextFormatter *this, const DefaultTextFormatter*const other);
void DefaultTextFormatter19Dtor(DefaultTextFormatter *this);
/*virtual*/void DTFprint5pc(DefaultTextFormatter *this, const char *symbol);
DefaultTextFormatter* generateFormatterArray();


/*   PrePostFixer   */
typedef struct PrePostFixer PrePostFixer;
typedef struct PrePostFixer_function PrePostFixer_function;
void PrePostFixer12Ctorpcpc(PrePostFixer *this, const char *prefix, const char *postfix);
void PrePostFixer12Dtor(PrePostFixer *this);
/*virtual*/void PPFprint5pc(PrePostFixer *this, const char *text);
/*virtual*/void PPFprint5lc(PrePostFixer const *this, long num, char symbol);
/*virtual & inline*/char PPFge_default_symbol16(void const *this);

/*   PrePostDollarFixer   */
typedef struct PrePostDollarFixer PrePostDollarFixer;
typedef struct PrePostDollarFixer_function PrePostDollarFixer_function;
void PrePostDollarFixer18Ctorpcpc(PrePostDollarFixer *this, const char *prefix, const char *postfix);
void PrePostDollarFixer18CtorpPPDF(PrePostDollarFixer *this, PrePostDollarFixer *other);
void PrePostDollarFixer18Dtor(PrePostDollarFixer *this);
void PPDFprint5ic(const PrePostDollarFixer *const this, int num, char symbol);
void PPDFprint5lc(const PrePostDollarFixer *this, long num, char symbol);
void PPDFprint5dc(const PrePostDollarFixer *this, double num, char symbol);
/*virtual & inline*/char PPDFge_default_symbol16(void const *this);

/*   PrePostHashFixer   */
typedef struct PrePostHashFixer PrePostHashFixer;
typedef struct PrePostHashFixer_function PrePostHashFixer_function;
void PrePostHashFixer16Ctori(PrePostHashFixer *this, int prc);
void PrePostHashFixer16Dtor(PrePostHashFixer *this);
void PPHFprint5ic(PrePostHashFixer *this, int num, char symbol);
void PPHFprint5lc(PrePostHashFixer *this, long num, char symbol);
char PPHFge_default_symbol16(void const *this);

/*   PrePostFloatDollarFixer   */
typedef struct PrePostFloatDollarFixer PrePostFloatDollarFixer;
typedef struct PrePostFloatDollarFixer_function PrePostFloatDollarFixer_function;
void PrePostFloatDollarFixer23Ctorpcpc(PrePostFloatDollarFixer *this, const char *prefix, const char *postfix);
void PrePostFloatDollarFixer23Dtor(PrePostFloatDollarFixer *this);
void PPFDFprintf(const PrePostFloatDollarFixer *this, float num);
void PPFDFprintfc(const PrePostFloatDollarFixer *this, float num, char symble);
char PPFDFge_default_symbol16(void const *this);

/*   PrePostChecker   */
typedef struct PrePostChecker PrePostChecker;
typedef struct PrePostChecker_function PrePostChecker_function;
void PrePostChecker14Ctor(PrePostChecker *this);
void PrePostChecker14Dtor(PrePostChecker *this);
void PPCprintThisSymbolUsingFunc24(const PrePostChecker *this);
void PPCprintThisSymbolDirectly23(const PrePostChecker *this);
void PPCprintThisSymbolByCastUsingFunc30(const PrePostChecker *this);
void PPCprintDollarSymbolByScopeUsingFunc33(const PrePostChecker *this);
void PPCprintDollarSymbolByCastDirectly32(const PrePostChecker *this);
void PPCprintDollarSymbolByScopeDirectly33(const PrePostChecker *this);

/*   Multiplier   */
typedef  struct Multiplier Multiplier;
typedef struct Multiplier_function Multiplier_function;
void Multiplier10Dtor(Multiplier *this);
void Multiplierprint5pc(Multiplier *this, const char *text);

struct TextFormatter
{
    void *vptr;
};
struct TextFormatter_function
{
    void(*TextFormatterV13Dtor)(struct TextFormatter *this);
    void(*printpc)(struct TextFormatter const *this, const char* text);
};

struct DefaultTextFormatter
{
    TextFormatter text_formater;
    int id;
};
struct DefaultTextFormatter_function
{
    void (*DefaultTextFormatter19Dtor)(DefaultTextFormatter *this);
    /*virtual*/void (*printpc)(DefaultTextFormatter *this, const char *text);
};

struct PrePostFixer
{
    DefaultTextFormatter default_text_formatter;
    const char* pre;
    const char* post;
};
struct PrePostFixer_function
{
    void (*PrePostFixer12Dtor)(PrePostFixer *this);
/*virtual*/void (*printpc)(PrePostFixer *this, const char *text);
/*virtual*/void (*print)(PrePostFixer const *this, long num, char symbol);
/*virtual & inline*/char (*getDefaultSymbol)(void const *this);
};

struct PrePostDollarFixer
{
    PrePostFixer pre_post_fixer;
};
struct PrePostDollarFixer_function
{
    void (*PrePostDollarFixer18Dtor)(PrePostDollarFixer *this);
    void (*printpc)(PrePostFixer *this, const char *text);
    void (*print)(const PrePostDollarFixer *const this, long num, char symbol);
    char (*getDefaultSymbol)(void const *this);
};

struct PrePostHashFixer
{
    PrePostDollarFixer pre_post_dollar_fixer;
    int precision;
};
struct PrePostHashFixer_function
{
    void (*PrePostHashFixer16Dtor)(PrePostHashFixer *this);
    void (*printpc)(PrePostFixer *this, const char *text);
    void (*print)(PrePostHashFixer *this, long num, char symbol);
    char (*getDefaultSymbol)(void const *this);
};

struct PrePostFloatDollarFixer
{
    PrePostDollarFixer pre_post_dollar_fixer;
};
struct PrePostFloatDollarFixer_function
{
    void (*PrePostFloatDollarFixer23Dtor)(PrePostFloatDollarFixer *this);
    void (*printpc)(PrePostFixer *this, const char *text);
    void (*print)(const PrePostDollarFixer *const this, long num, char symbol);
    char (*getDefaultSymbol)(void const *this);
};

struct PrePostChecker
{
    PrePostFloatDollarFixer pre_post_float_dollar_fixer;
};
struct PrePostChecker_function
{
    void (*PrePostChecker14Dtor)(PrePostChecker *this);
    void (*printpc)(PrePostFixer *this, const char *text);
    void (*print)(const PrePostDollarFixer *const this, long num, char symbol);
    char (*getDefaultSymbol)(void const *this);
};

struct Multiplier
{
    DefaultTextFormatter default_text_formatter;
    int times;
};
struct Multiplier_function
{
    void (*Dtor)(Multiplier *this);
    void (*printpc)(Multiplier *this, const char *text);
};

#endif
