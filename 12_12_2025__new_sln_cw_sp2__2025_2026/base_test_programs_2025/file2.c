#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"

int data[8192] = {0};
int contextStack[8192] = {0}, contextStackIndex = 0;
int opStack[8192] = {0}, opStackIndex = 0, opTemp = 0;
int lastBindDataIndex = 0;

int main() {
    contextStackIndex = 0;
    opStackIndex = 0;
    opTemp = 0;
    lastBindDataIndex = 0;

    //";"

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //"Scan"
    (void)scanf_s("%d", &opTemp);
    data[opStack[opStackIndex]] = opTemp, opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"4"
    opStack[++opStackIndex] = opTemp = 0x00000004;

    //"Scan"
    (void)scanf_s("%d", &opTemp);
    data[opStack[opStackIndex]] = opTemp, opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"8"
    opStack[++opStackIndex] = opTemp = 0x00000008;

    //"Scan"
    (void)scanf_s("%d", &opTemp);
    data[opStack[opStackIndex]] = opTemp, opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"If"

    //"_aa0"
    opStack[++opStackIndex] = opTemp = data[0x00000000];

    //"_bb0"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"Gr"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] > opStack[opStackIndex]; --opStackIndex;

    //"_aa0"
    opStack[++opStackIndex] = opTemp = data[0x00000000];

    //"_cc0"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"Gr"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] > opStack[opStackIndex]; --opStackIndex;

    //"And"
    opTemp = opStack[opStackIndex - 1] &= opStack[opStackIndex]; --opStackIndex;

    //null statement (non-context)

    //after cond expresion (after "If")
    if (opTemp == 0) goto LABEL__AFTER_THEN_00007FF752F25958;

    //"_aa0"
    opStack[++opStackIndex] = opTemp = data[0x00000000];

    //"12"
    opStack[++opStackIndex] = opTemp = 0x0000000C;

    //"->"
    lastBindDataIndex = opStack[opStackIndex];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex - 1], opStackIndex = 0;

    //null statement (non-context)

    //";" (after "then"-part of If-operator)
    opTemp = 1;
LABEL__AFTER_THEN_00007FF752F25958:

    //"Else" (part of "ElseIf")
    if (opTemp != 0) goto LABEL__AFTER_ELSE_00007FF752F27670;

    //"_bb0"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"_aa0"
    opStack[++opStackIndex] = opTemp = data[0x00000000];

    //"Gr"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] > opStack[opStackIndex]; --opStackIndex;

    //"_bb0"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"_cc0"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"Gr"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] > opStack[opStackIndex]; --opStackIndex;

    //"And"
    opTemp = opStack[opStackIndex - 1] &= opStack[opStackIndex]; --opStackIndex;

    //null statement (non-context)

    //after cond expresion (after "ElseIf")
    if (opTemp == 0) goto LABEL__AFTER_THEN_00007FF752F2A428;

    //"_bb0"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"12"
    opStack[++opStackIndex] = opTemp = 0x0000000C;

    //"->"
    lastBindDataIndex = opStack[opStackIndex];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex - 1], opStackIndex = 0;

    //null statement (non-context)

    //"}" (after "then"-part of ElseIf-operator)
    opTemp = 1;
LABEL__AFTER_ELSE_00007FF752F27670:
LABEL__AFTER_THEN_00007FF752F2A428:

    //"Else"
    if (opTemp != 0) goto LABEL__AFTER_ELSE_00007FF752F2C140;

    //"_cc0"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"12"
    opStack[++opStackIndex] = opTemp = 0x0000000C;

    //"->"
    lastBindDataIndex = opStack[opStackIndex];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex - 1], opStackIndex = 0;

    //null statement (non-context)

    //";" (after "Else")
LABEL__AFTER_ELSE_00007FF752F2C140:

    //null statement (non-context)

    //"_mm0"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"Print"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"If"

    //"_aa0"
    opStack[++opStackIndex] = opTemp = data[0x00000000];

    //"_bb0"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"Eq"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] == opStack[opStackIndex]; --opStackIndex;

    //"_aa0"
    opStack[++opStackIndex] = opTemp = data[0x00000000];

    //"_cc0"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"Eq"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] == opStack[opStackIndex]; --opStackIndex;

    //"And"
    opTemp = opStack[opStackIndex - 1] &= opStack[opStackIndex]; --opStackIndex;

    //"_bb0"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"_cc0"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"Eq"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] == opStack[opStackIndex]; --opStackIndex;

    //"And"
    opTemp = opStack[opStackIndex - 1] &= opStack[opStackIndex]; --opStackIndex;

    //null statement (non-context)

    //after cond expresion (after "If")
    if (opTemp == 0) goto LABEL__AFTER_THEN_00007FF752F339C8;

    //"1"
    opStack[++opStackIndex] = opTemp = 0x00000001;

    //"Print"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";"

    //";" (after "then"-part of If-operator)
    opTemp = 1;
LABEL__AFTER_THEN_00007FF752F339C8:

    //"Else"
    if (opTemp != 0) goto LABEL__AFTER_ELSE_00007FF752F356E0;

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //"Print"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";"

    //";" (after "Else")
LABEL__AFTER_ELSE_00007FF752F356E0:

    //"If"

    //"_aa0"
    opStack[++opStackIndex] = opTemp = data[0x00000000];

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //"Ls"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] < opStack[opStackIndex]; --opStackIndex;

    //"_bb0"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //"Ls"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] < opStack[opStackIndex]; --opStackIndex;

    //"Or"
    opTemp = opStack[opStackIndex - 1] |= opStack[opStackIndex]; --opStackIndex;

    //"_cc0"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //"Ls"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] < opStack[opStackIndex]; --opStackIndex;

    //"Or"
    opTemp = opStack[opStackIndex - 1] |= opStack[opStackIndex]; --opStackIndex;

    //null statement (non-context)

    //after cond expresion (after "If")
    if (opTemp == 0) goto LABEL__AFTER_THEN_00007FF752F3B250;

    //"-1"
    opStack[++opStackIndex] = opTemp = 0xFFFFFFFF;

    //"Print"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";"

    //";" (after "then"-part of If-operator)
    opTemp = 1;
LABEL__AFTER_THEN_00007FF752F3B250:

    //"Else"
    if (opTemp != 0) goto LABEL__AFTER_ELSE_00007FF752F3CF68;

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //"Print"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";"

    //";" (after "Else")
LABEL__AFTER_ELSE_00007FF752F3CF68:

    //"If"

    //"_aa0"
    opStack[++opStackIndex] = opTemp = data[0x00000000];

    //"_bb0"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"_cc0"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"++"
    opTemp = opStack[opStackIndex - 1] += opStack[opStackIndex]; --opStackIndex;

    //"Ls"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] < opStack[opStackIndex]; --opStackIndex;

    //"Not"
    opTemp = opStack[opStackIndex] = !opStack[opStackIndex];

    //null statement (non-context)

    //after cond expresion (after "If")
    if (opTemp == 0) goto LABEL__AFTER_THEN_00007FF752F41610;

    //"10"
    opStack[++opStackIndex] = opTemp = 0x0000000A;

    //"Print"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";"

    //";" (after "then"-part of If-operator)
    opTemp = 1;
LABEL__AFTER_THEN_00007FF752F41610:

    //"Else"
    if (opTemp != 0) goto LABEL__AFTER_ELSE_00007FF752F43328;

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //"Print"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";"

    //";" (after "Else")
LABEL__AFTER_ELSE_00007FF752F43328:

    return 0;
}