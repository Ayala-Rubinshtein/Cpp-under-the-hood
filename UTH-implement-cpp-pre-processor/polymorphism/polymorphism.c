#include "polymorphism.h"
#include "malloc.h"

/*  functions   */
TextFormatter_function text_formatter_function = {TextFormatterV13Dtor, NULL};
DefaultTextFormatter_function default_text_formatter_function = {DefaultTextFormatter19Dtor, DTFprint5pc};
PrePostFixer_function pre_post_fixer_function = {PrePostFixer12Dtor, PPFprint5pc, PPFprint5lc, PPFge_default_symbol16};
PrePostDollarFixer_function pre_post_dollar_fixer_function = {PrePostDollarFixer18Dtor, PPFprint5pc, PPDFprint5lc, PPDFge_default_symbol16};
PrePostHashFixer_function pre_post_hash_fixer_function = {PrePostHashFixer16Dtor, PPFprint5pc, PPHFprint5lc, PPHFge_default_symbol16};
PrePostFloatDollarFixer_function pre_post_float_dollar_fixer_function = {PrePostFloatDollarFixer23Dtor, PPFprint5pc, PPDFprint5lc, PPFDFge_default_symbol16};
PrePostChecker_function pre_post_checker_function = {PrePostChecker14Dtor, PPFprint5pc, PPDFprint5lc, PPFDFge_default_symbol16};
Multiplier_function multiplier_function = {Multiplier10Dtor, Multiplierprint5pc};

int next_id = 0;
/*   TextFormatter   */
void TextFormatterV13Dtor(TextFormatter *this){}

/*   DefaultTextFormatter   */
void DefaultTextFormatter19Ctor(DefaultTextFormatter *this)
{
    this->text_formater.vptr = (void*)&default_text_formatter_function;
    this->id = next_id ++;
    printf("--- DefaultTextFormatter Default CTOR\n########## C %d ##########\n", this->id);
}
void DefaultTextFormatter19Dtor(DefaultTextFormatter *this)
{
    printf("--- DefaultTextFormatter DTOR\n########## D %d ##########\n", this->id);
}
void DefaultTextFormatter19_copy_Ctor(DefaultTextFormatter *this, DefaultTextFormatter *other)
{
    this->id = next_id ++;
    printf("--- DefaultTextFormatter Copy CTOR, from id: %d\n########## C %d ##########\n", other->id, this->id);
}
DefaultTextFormatter* DTF19_E_operatorpDTF(DefaultTextFormatter *this, const DefaultTextFormatter*const other)
{
    printf("--- DefaultTextFormatter operator=(), from id: %d to id: %d\n", other->id, this->id);
    return this;
}
void DTFprint5pc(DefaultTextFormatter *this, const char *symbol)
{
    printf("%-60s | ", "[DefaultTextFormatter::print(const char*)]");
    printf("%s\n", symbol);
}

DefaultTextFormatter* generateFormatterArray()
{
    int i = 0;
    DefaultTextFormatter *ptr =  malloc(sizeof(DefaultTextFormatter) * 3) ;
    for (;i < 3; ++i)
    {
        DefaultTextFormatter19Ctor(ptr + i);
    }
    return ptr;
}

 /*   PrePostFixer   */
void PrePostFixer12Ctorpcpc(PrePostFixer *this, const char *prefix, const char *postfix)
{
    this->default_text_formatter.text_formater.vptr = (void*) &pre_post_fixer_function;
    DefaultTextFormatter19Ctor(&(this->default_text_formatter));
    this->pre = prefix;
    this->post = postfix;
    printf("--- PrePostFixer CTOR: \"%s\"...\"%s\"\n", this->pre, this->post);
}
void PrePostFixer12Dtor(PrePostFixer *this)
{
    printf("--- PrePostFixer DTOR: \"%s\"...\"%s\"\n", this->pre, this->post);
    this->default_text_formatter.text_formater.vptr = (void*) &default_text_formatter_function;
    DefaultTextFormatter19Dtor(&(this->default_text_formatter));
}
void PPFprint5pc(PrePostFixer *this, const char *text)
{
    printf("%-60s | ", "[PrePostFixer::print(const char*)]");
    printf("%s%s%s\n", this->pre, text, this->post);
}
void PPFprint5lc(PrePostFixer const *this, long num, char symbol)
{
    printf("%-60s | ", "[PrePostFixer::print(long, char)]");
    printf("-->\n");

    if (symbol)
    {
        printf("%-60s | ","[PrePostFixer::print_num(long, char)]");
        printf("%s%c%ld%s\n", this->pre, symbol, num, this->post);    }
    else
    {
        printf("%-60s | ","[PrePostFixer::print_num(long)]");
        printf("%s%ld%s\n", this->pre, num, this->post);
    }
}
char PPFge_default_symbol16(void const *this)
{
    return '\0';
}

/*   PrePostDollarFixer   */
void PrePostDollarFixer18Ctorpcpc(PrePostDollarFixer *this, const char *prefix, const char *postfix)
{
    PrePostFixer12Ctorpcpc(&(this->pre_post_fixer), prefix, postfix);
    this->pre_post_fixer.default_text_formatter.text_formater.vptr = (void*)&pre_post_dollar_fixer_function;
    printf("--- PrePostDollarFixer CTOR: \"%s\"...\"%s\"\n", this->pre_post_fixer.pre, this->pre_post_fixer.post);
}
void PrePostDollarFixer18CtorpPPDF(PrePostDollarFixer *this, PrePostDollarFixer *other)
{
    DefaultTextFormatter19_copy_Ctor(&(this->pre_post_fixer.default_text_formatter), &(other->pre_post_fixer.default_text_formatter));
    this->pre_post_fixer.default_text_formatter.text_formater.vptr = (void*) &pre_post_fixer_function;
    this->pre_post_fixer.pre = other->pre_post_fixer.pre;
    this->pre_post_fixer.post = other->pre_post_fixer.post;
    this->pre_post_fixer.default_text_formatter.text_formater.vptr = (void*) &pre_post_dollar_fixer_function;
    printf("--- PrePostDollarFixer Copy CTOR: \"%s\"...\"%s\"\n", this->pre_post_fixer.pre, this->pre_post_fixer.post);
}
void PrePostDollarFixer18Dtor(PrePostDollarFixer *this)
{
    printf("--- PrePostDollarFixer DTOR: \"%s\"...\"%s\"\n", this->pre_post_fixer.pre, this->pre_post_fixer.post);
    this->pre_post_fixer.default_text_formatter.text_formater.vptr = (void*) &pre_post_fixer_function;
    PrePostFixer12Dtor(&(this->pre_post_fixer));
}
void PPDFprint5ic(const PrePostDollarFixer *const  this, int num, char symbol)
{
    printf("%-60s | ", "[PrePostDollarFixer::print(int, char)]");
    printf("-->\n");
    ((PrePostDollarFixer_function*) this->pre_post_fixer.default_text_formatter.text_formater.vptr)->print(this, (long)num, symbol);
}
void PPDFprint5lc(const PrePostDollarFixer *this, long num, char symbol)
{
    printf("%-60s | ","[PrePostDollarFixer::print(long, char)]");
    printf("-->\n");

    PPFprint5lc(&(this->pre_post_fixer),num, symbol);
}
void PPDFprint5dc(const PrePostDollarFixer *this, double num, char symbol)
{
    printf("%-60s | ","[PrePostDollarFixer::print(double, char)]");
    printf("%s%c%f%s\n", this->pre_post_fixer.pre, symbol, num, this->pre_post_fixer.post);
}
char PPDFge_default_symbol16(void const *this)
{
    return '$';
}

/*    PrePostHashFixer   */
void PrePostHashFixer16Ctori(PrePostHashFixer *this, int prc)
{
    PrePostDollarFixer18Ctorpcpc(&(this->pre_post_dollar_fixer), "===> ", " <===");
    this->pre_post_dollar_fixer.pre_post_fixer.default_text_formatter.text_formater.vptr = (void*) &pre_post_hash_fixer_function;
    this->precision = prc;
    printf("--- PrePostHashFixer CTOR: \"%s\"...\"%s\", precision: %d\n", this->pre_post_dollar_fixer.pre_post_fixer.pre, this->pre_post_dollar_fixer.pre_post_fixer.post, this->precision);

    printf("%-60s | ","[PrePostHashFixer::print(double, char)]");

    printf("%s[%c%.*f]%s\n", this->pre_post_dollar_fixer.pre_post_fixer.pre, '#', this->precision, 9999.9999, this->pre_post_dollar_fixer.pre_post_fixer.post);
}
void PrePostHashFixer16Dtor(PrePostHashFixer *this)
{
    printf("--- PrePostHashFixer DTOR: \"%s\"...\"%s\"\n", this->pre_post_dollar_fixer.pre_post_fixer.pre, this->pre_post_dollar_fixer.pre_post_fixer.post);
    this->pre_post_dollar_fixer.pre_post_fixer.default_text_formatter.text_formater.vptr = (void*)&pre_post_dollar_fixer_function;
    PrePostDollarFixer18Dtor(&(this->pre_post_dollar_fixer));
}
void PPHFprint5ic(PrePostHashFixer *this, int num, char symbol)
{
    printf("%-60s | ","[PrePostHashFixer::print(int, char)]");
    printf("-->\n");

    printf("%-60s | ","[PrePostHashFixer::print(double, char)]");

    printf("%s[%c%.*f]%s\n", this->pre_post_dollar_fixer.pre_post_fixer.pre, symbol, this->precision, (double)num, this->pre_post_dollar_fixer.pre_post_fixer.post);
}
void PPHFprint5lc(PrePostHashFixer *this, long num, char symbol)
{
    printf("%-60s | ","[PrePostHashFixer::print(long, char)]");
    printf("-->\n");

    printf("%-60s | ","[PrePostHashFixer::print(double, char)]");

    printf("%s[%c%.*f]%s\n", this->pre_post_dollar_fixer.pre_post_fixer.pre, symbol, this->precision, (double)num, this->pre_post_dollar_fixer.pre_post_fixer.post);
}
char PPHFge_default_symbol16(void const *this)
{
    return '#';
}

/*   PrePostFloatDollarFixer   */
void PrePostFloatDollarFixer23Ctorpcpc(PrePostFloatDollarFixer *this, const char *prefix, const char *postfix)
{
    PrePostDollarFixer18Ctorpcpc(&(this->pre_post_dollar_fixer), prefix, postfix);
    this->pre_post_dollar_fixer.pre_post_fixer.default_text_formatter.text_formater.vptr = (void*)&pre_post_float_dollar_fixer_function;
    printf("--- PrePostFloatDollarFixer CTOR: \"%s\"...\"%s\"\n", this->pre_post_dollar_fixer.pre_post_fixer.pre, this->pre_post_dollar_fixer.pre_post_fixer.post);
}
void PrePostFloatDollarFixer23Dtor(PrePostFloatDollarFixer *this)
{
    printf("--- PrePostFloatDollarFixer DTOR: \"%s\"...\"%s\"\n", this->pre_post_dollar_fixer.pre_post_fixer.pre, this->pre_post_dollar_fixer.pre_post_fixer.post);
    this->pre_post_dollar_fixer.pre_post_fixer.default_text_formatter.text_formater.vptr = (void*)&pre_post_hash_fixer_function;
    PrePostDollarFixer18Dtor(&(this->pre_post_dollar_fixer));
}
void PPFDFprintf(const PrePostFloatDollarFixer *this, float num)
{
    printf("%-60s | ","[PrePostFloatDollarFixer::print(float)]");
    printf("-->\n");

    PPFDFprintfc(this, num, '@');
}
void PPFDFprintfc(const PrePostFloatDollarFixer *this, float num, char symbol)
{
    printf("%-60s | ","[PrePostFloatDollarFixer::print(float, char)]");

    printf("%s%c%.2f%s\n", this->pre_post_dollar_fixer.pre_post_fixer.pre, symbol, num, this->pre_post_dollar_fixer.pre_post_fixer.post);
}
char PPFDFge_default_symbol16(void const *this)
{
    return '@';
}

/*   PrePostChecker   */
void PrePostChecker14Ctor(PrePostChecker *this)
{
    PrePostFloatDollarFixer23Ctorpcpc(&(this->pre_post_float_dollar_fixer),"[[[[ ", " ]]]]");
    this->pre_post_float_dollar_fixer.pre_post_dollar_fixer.pre_post_fixer.default_text_formatter.text_formater.vptr = (void*)&pre_post_checker_function;
    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", this->pre_post_float_dollar_fixer.pre_post_dollar_fixer.pre_post_fixer.pre, this->pre_post_float_dollar_fixer.pre_post_dollar_fixer.pre_post_fixer.post);
}
void PrePostChecker14Dtor(PrePostChecker *this)
{
    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", this->pre_post_float_dollar_fixer.pre_post_dollar_fixer.pre_post_fixer.pre, this->pre_post_float_dollar_fixer.pre_post_dollar_fixer.pre_post_fixer.post);
    this->pre_post_float_dollar_fixer.pre_post_dollar_fixer.pre_post_fixer.default_text_formatter.text_formater.vptr = (void*)&pre_post_float_dollar_fixer_function;
    PrePostFloatDollarFixer23Dtor(&(this->pre_post_float_dollar_fixer));
}
void PPCprintThisSymbolUsingFunc24(const PrePostChecker *this)
{
    printf("%-60s | ","[PrePostChecker::printThisSymbolUsingFunc()]");

   printf("Default symbol is %c\n", ((PrePostChecker_function*)(this->pre_post_float_dollar_fixer.pre_post_dollar_fixer.pre_post_fixer.default_text_formatter.text_formater.vptr))->getDefaultSymbol(this));
}
void PPCprintThisSymbolDirectly23(const PrePostChecker *this)
{
    printf("%-60s | ","[PrePostChecker::printThisSymbolDirectly()]");

    printf("Default symbol is %c\n", '@');
}
void PPCprintThisSymbolByCastUsingFunc30(const PrePostChecker *this)
{
    printf("%-60s | ","[PrePostChecker::printDollarSymbolByCastUsingFunc()]");

    printf("Default symbol is %c\n",( (PrePostChecker_function*)(((PrePostDollarFixer*)(this))->pre_post_fixer.default_text_formatter.text_formater.vptr))->getDefaultSymbol(this));
}
void PPCprintDollarSymbolByScopeUsingFunc33(const PrePostChecker *this)
{
    printf("%-60s | ","[PrePostChecker::printDollarSymbolByScopeUsingFunc()]");

    printf("Default symbol is %c\n", '$');
}
void PPCprintDollarSymbolByCastDirectly32(const PrePostChecker *this)
{
    printf("%-60s | ","[PrePostChecker::printDollarSymbolByCastDirectly()]");

    printf("Default symbol is %c\n", '$');
}
void PPCprintDollarSymbolByScopeDirectly33(const PrePostChecker *this)
{
    printf("%-60s | ","[PrePostChecker::printDollarSymbolByScopeDirectly()]");

    printf("Default symbol is %c\n", '$');
}

/*   Multiplier   */
void Multiplierprint5pc(Multiplier *this, const char *text)
{
    int i = 0;

    printf("%-60s | ","[Multiplier::print(const char*)]");

    for (; i < (this->times); ++i)
        printf("%s", text);
    printf("\n");
}
void Multiplier10Dtor(Multiplier *this)
{
    printf("--- Multiplier DTOR: times = %d\n", this->times);
    this->default_text_formatter.text_formater.vptr = (void*)&default_text_formatter_function;
    DefaultTextFormatter19Dtor(&(this->default_text_formatter));
}
