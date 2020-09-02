#include "polymorphism.h"
#include <stdio.h>
#include <malloc.h>

extern DefaultTextFormatter_function default_text_formatter_function;
extern Multiplier_function multiplier_function;

void doPrePostFixer()
{
    PrePostFixer angleBrackets;

    printf("\n--- start doPrePostFixer() ---\n\n");

    PrePostFixer12Ctorpcpc(&angleBrackets, "<<< ", " >>>");
    PPFprint5pc(&angleBrackets,"Hello World!");
    PPFprint5lc(&angleBrackets, -777, '\0');
    PPFprint5lc(&angleBrackets,350, '#');
    PPFprint5lc(&angleBrackets,(long int)3.14, '\0');

    printf("\n--- end doPrePostFixer() ---\n\n");
    PrePostFixer12Dtor(&angleBrackets);
}

void doPrePostDollarFixer()
{
    PrePostDollarFixer asterisks;
    printf("\n--- start doPrePostDollarFixer() ---\n\n");

    PrePostDollarFixer18Ctorpcpc(&asterisks,"***** ", " *****");
    PPDFprint5ic(&asterisks, -777,'$');
    PPDFprint5ic(&asterisks, 350,'#');
    PPDFprint5dc(&asterisks, 3.14f,'$');

    printf("\n--- end doPrePostDollarFixer() ---\n\n");

    PrePostDollarFixer18Dtor(&asterisks);

}

void doPrePostChecker()
{
    PrePostChecker check;

    printf("\n--- start doPrePostChecker() ---\n\n");

    PrePostChecker14Ctor(&check);
    PPCprintThisSymbolUsingFunc24(&check);
    PPCprintThisSymbolDirectly23(&check);
    PPCprintDollarSymbolByCastDirectly32(&check);
    PPCprintDollarSymbolByScopeDirectly33(&check);
    PPCprintThisSymbolByCastUsingFunc30(&check);
    PPCprintDollarSymbolByScopeUsingFunc33(&check);

    printf("\n--- end doPrePostChecker() ---\n\n");

    PrePostChecker14Dtor(&check);
}

void doPrePostFloatDollarFixer()
{
    PrePostFloatDollarFixer hashes;
    PrePostDollarFixer hashes2;

    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");

    PrePostFloatDollarFixer23Ctorpcpc(&hashes,"### ", " ###");
    PPFDFprintf(&hashes,(-777));
    PPFDFprintfc(&hashes, 350, '#');
    PPFDFprintf(&hashes, 3.14f);

    PrePostDollarFixer18CtorpPPDF(&hashes2, &(hashes.pre_post_dollar_fixer));
    PPDFprint5dc(&hashes2, 7.5,'$');
    PPDFprint5ic(&hashes2, 100, '$');

    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");

    PrePostDollarFixer18Dtor(&hashes2);
    PrePostFloatDollarFixer23Dtor(&hashes);
}

void runAsPrePostFixerRef(PrePostFixer* pp)
{
    printf("\n--- start runAsPrePostFixerRef() ---\n\n");

    ((PrePostFixer_function*)(pp->default_text_formatter.text_formater.vptr))->print(pp, 123, '\0');

    printf("\n--- end runAsPrePostFixerRef() ---\n\n");
}

void runAsPrePostDollarFixerRef(const PrePostDollarFixer* pp)
{
    printf("\n--- start runAsPrePostDollarFixerRef() ---\n\n");

    PPDFprint5ic(pp, 123,'$');


    printf("\n--- end runAsPrePostDollarFixerRef() ---\n\n");
}

void runAsPrePostDollarFixerObj(const PrePostDollarFixer pp)
{
    printf("\n--- start runAsPrePostDollarFixerObj() ---\n\n");

    PPDFprint5ic(&pp, 123, '$');

    printf("\n--- end runAsPrePostDollarFixerObj() ---\n\n");
}

void runAsPrePostHashFixerRef(PrePostHashFixer* pp)
{
    printf("\n--- start runAsPrePostHashFixerRef() ---\n\n");

    ((PrePostHashFixer_function*)(pp->pre_post_dollar_fixer.pre_post_fixer.default_text_formatter.text_formater.vptr))->print(pp, 123, '#');

    printf("\n--- end runAsPrePostHashFixerRef() ---\n\n");
}

void doMultiplier()
{
    Multiplier m1, m2, m3, m4;
    printf("\n--- start doMultiplier() ---\n\n");

    DefaultTextFormatter19Ctor(&(m1.default_text_formatter));
    m1.times = 3;
    printf("--- Multiplier CTOR: times = %d\n", m1.times);

    DefaultTextFormatter19Ctor(&(m2.default_text_formatter));
    m2.times = 5;
    printf("--- Multiplier CTOR: times = %d\n", m2.times);

    DefaultTextFormatter19_copy_Ctor(&(m3.default_text_formatter), &(m1.default_text_formatter));
    m3.times = m1.times;
    DefaultTextFormatter19_copy_Ctor(&(m4.default_text_formatter), &(m2.default_text_formatter));
    m4.times = m2.times;

    Multiplierprint5pc(&m1, "abc ");
    Multiplierprint5pc(&m2, "abc ");
    Multiplierprint5pc(&m3, "abc ");
    Multiplierprint5pc(&m4, "abc ");

    printf("\n--- start doMultiplier() ---\n\n");

    Multiplier10Dtor(&m4);
    Multiplier10Dtor(&m3);
    Multiplier10Dtor(&m2);
    Multiplier10Dtor(&m1);
}

void doFormatterArray()
{
    DefaultTextFormatter formatters[3];
    PrePostDollarFixer PPDF;
    Multiplier m;
    PrePostChecker PPC;
    int i=0;

    printf("\n--- start doFormatterArray() ---\n\n");

    PrePostDollarFixer18Ctorpcpc(&PPDF,"!!! ", " !!!" );
    DefaultTextFormatter19_copy_Ctor(formatters, &(PPDF.pre_post_fixer.default_text_formatter));
    PrePostDollarFixer18Dtor(&PPDF);

    DefaultTextFormatter19Ctor(&m.default_text_formatter);
    m.times = 4;
    printf("--- Multiplier CTOR: times = %d\n", m.times);
    DefaultTextFormatter19_copy_Ctor(formatters + 1, &(m.default_text_formatter));
    printf("--- Multiplier DTOR: times = %d\n", m.times);
    m.default_text_formatter.text_formater.vptr = (void*) &default_text_formatter_function;
    DefaultTextFormatter19Dtor(&(m.default_text_formatter));

    PrePostChecker14Ctor(&PPC);
    DefaultTextFormatter19_copy_Ctor(formatters + 2, &(PPC.pre_post_float_dollar_fixer.pre_post_dollar_fixer.pre_post_fixer.default_text_formatter));
    PrePostChecker14Dtor(&PPC);


    for (; i < 3; ++i)
        DTFprint5pc(formatters + i, "Hello World!");

    printf("\n--- end doFormatterArray() ---\n\n");

    DefaultTextFormatter19Dtor(formatters + 2);
    DefaultTextFormatter19Dtor(formatters + 1);
    DefaultTextFormatter19Dtor(formatters);
}

void doFormatterPtrs()
{
    DefaultTextFormatter **pfmt = NULL;
    PrePostDollarFixer *PPDF;
    Multiplier *m;
    PrePostChecker *PPC;
    int i = 0;

    printf("\n--- start doFormatterPtrs() ---\n\n");

    pfmt = malloc(sizeof(DefaultTextFormatter*) * 3);

    PPDF = malloc(sizeof(PrePostDollarFixer));
    PrePostDollarFixer18Ctorpcpc(PPDF,"!!! ", " !!!");
    m = malloc(sizeof(Multiplier));
    DefaultTextFormatter19Ctor(&(m->default_text_formatter));
    m->default_text_formatter.text_formater.vptr = (void*) &multiplier_function;
    m->times = 4;
    printf("--- Multiplier CTOR: times = %d\n", m->times);
    PPC = malloc(sizeof(PrePostChecker));
    PrePostChecker14Ctor(PPC);

    pfmt[0] = &(PPDF->pre_post_fixer.default_text_formatter);
    pfmt[1] = &(m->default_text_formatter);
    pfmt[2] = &(PPC->pre_post_float_dollar_fixer.pre_post_dollar_fixer.pre_post_fixer.default_text_formatter);

    for (; i < 3; ++i)
        ((DefaultTextFormatter_function*)(pfmt[i]->text_formater.vptr))->printpc( *(pfmt + i), "Hello World!");

    PrePostChecker14Dtor(PPC);
    Multiplier10Dtor(m);
    PrePostDollarFixer18Dtor(PPDF);

    printf("\n--- end doFormatterPtrs() ---\n\n");

    free(PPC);
    free(m);
    free(PPDF);
    free(pfmt);

}

void doFormatterDynamicArray()
{
    int i = 0;
    DefaultTextFormatter* formatters;
    printf("\n--- start doFormatterDynamicArray() ---\n\n");

    formatters = generateFormatterArray();

    for (; i < 3; ++i)
        DTFprint5pc(formatters + i, "Hello World!");

    printf("\n--- start doFormatterDynamicArray() ---\n\n");

    DefaultTextFormatter19Dtor(formatters + 2);
    DefaultTextFormatter19Dtor(formatters + 1);
    DefaultTextFormatter19Dtor(formatters);

    free(formatters);
}

int main()
{
    PrePostHashFixer hfix;
    PrePostDollarFixer hfix_other;

    printf("\n--- Start main() ---\n\n");

    doPrePostFixer();
    doPrePostDollarFixer();
    doPrePostFloatDollarFixer();
    doPrePostChecker();

    PrePostHashFixer16Ctori(&hfix, 4);
    runAsPrePostFixerRef( &(hfix.pre_post_dollar_fixer.pre_post_fixer));
    runAsPrePostDollarFixerRef((const PrePostDollarFixer *) &hfix);
    PrePostDollarFixer18CtorpPPDF(&hfix_other, &(hfix.pre_post_dollar_fixer));
    runAsPrePostDollarFixerObj(hfix_other);
    PrePostDollarFixer18Dtor(&hfix_other);
    runAsPrePostHashFixerRef(&hfix);

    doMultiplier();

    doFormatterArray();
    doFormatterPtrs();
    doFormatterDynamicArray();

    printf("\n--- End main() ---\n\n");

    PrePostHashFixer16Dtor(&hfix);

    return 0;
}


