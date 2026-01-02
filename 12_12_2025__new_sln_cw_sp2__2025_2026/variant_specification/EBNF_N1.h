/*
Перевірка РБНФ №2 за допомогою коду
(помістити у файл "EBNF_N2.h")
*/


#define NONTERMINALS program_name, \
value_type, \
array_specify, \
declaration_element, \
\
other_declaration_ident, \
declaration, \
\
index_action, \
unary_operator, \
unary_operation, \
binary_operator, \
binary_action, \
left_expression, \
group_expression, \
\
expression, \
\
expression_or_cond_block__with_optional_assign, \
assign_to_right, \
\
if_expression, \
body_for_true, \
false_cond_block_without_else, \
body_for_false, \
cond_block, \
\
\
cycle_begin_expression, \
cycle_end_expression, \
cycle_counter, \
cycle_counter_lr_init, \
cycle_counter_init, \
cycle_counter_last_value, \
cycle_body, \
forto_cycle, \
statement, \
statement__or__block_statements,\
block_statements, \
input_rule, \
argument_for_input, \
output_rule, \
\
\
program_rule, \
\
non_zero_digit, \
digit__iteration, \
digit, \
unsigned_value, \
value, \
\
sign, \
ident, \
letter_in_upper_case, \
letter_in_lower_case, \
sign_plus, \
sign_minus
#define TOKENS \
tokenINTEGER16, \
tokenCOMMA, \
tokenNOT, \
tokenAND, \
tokenOR, \
tokenEQUAL, \
tokenNOTEQUAL, \
tokenLESS, \
tokenGREATER, \
tokenPLUS, \
tokenMINUS, \
tokenMUL, \
tokenDIV, \
tokenMOD, \
tokenGROUPEXPRESSIONBEGIN, \
tokenGROUPEXPRESSIONEND, \
tokenLRASSIGN, \
tokenELSE, \
tokenIF, \
tokenDO, \
tokenFOR, \
tokenTO, \
tokenEXIT, \
tokenGET, \
tokenPUT, \
tokenNAME, \
tokenBODY, \
tokenDATA, \
tokenBEGIN, \
tokenEND, \
tokenBEGINBLOCK, \
tokenENDBLOCK, \
tokenLEFTSQUAREBRACKETS, \
tokenRIGHTSQUAREBRACKETS, \
tokenSEMICOLON, \
digit_0, \
digit_1, \
digit_2, \
digit_3, \
digit_4, \
digit_5, \
digit_6, \
digit_7, \
digit_8, \
digit_9, \
tokenUNDERSCORE, \
A, \
B, \
C, \
D, \
E, \
F, \
G, \
H, \
I, \
J, \
K, \
L, \
M, \
N, \
O, \
P, \
Q, \
R, \
S, \
T, \
U, \
V, \
W, \
X, \
Y, \
Z, \
a, \
b, \
c, \
d, \
e, \
f, \
g, \
h, \
i, \
j, \
k, \
l, \
m, \
n, \
o, \
p, \
q, \
r, \
s, \
t, \
u, \
v, \
w, \
x, \
y, \
z
#define COMMENT_BEGIN_STR "#*"
#define COMMENT_END_STR   "*#"




tokenGROUPEXPRESSIONBEGIN = "(" >> BOUNDARIES;
tokenGROUPEXPRESSIONEND = ")" >> BOUNDARIES;
tokenLEFTSQUAREBRACKETS = "[" >> BOUNDARIES;
tokenRIGHTSQUAREBRACKETS = "]" >> BOUNDARIES;
tokenBEGINBLOCK = "{" >> BOUNDARIES;
tokenENDBLOCK = "}" >> BOUNDARIES;
tokenSEMICOLON = ";" >> BOUNDARIES;

// Maps to tokenInt32
tokenINTEGER16 = "Int32" >> STRICT_BOUNDARIES;
tokenCOMMA = "," >> BOUNDARIES;

tokenNOT = "Not" >> STRICT_BOUNDARIES;
tokenAND = "And" >> STRICT_BOUNDARIES;
tokenOR = "Or" >> STRICT_BOUNDARIES;

tokenEQUAL = "Eq" >> STRICT_BOUNDARIES;
tokenNOTEQUAL = "Neq" >> STRICT_BOUNDARIES;
tokenLESS = "Ls" >> STRICT_BOUNDARIES;
tokenGREATER = "Gr" >> STRICT_BOUNDARIES;

tokenPLUS = "++" >> BOUNDARIES;
tokenMINUS = "--" >> BOUNDARIES;
tokenMUL = "**" >> BOUNDARIES;
tokenDIV = "Div" >> STRICT_BOUNDARIES;
tokenMOD = "Mod" >> STRICT_BOUNDARIES;

// Maps to tokenBIND (->)
tokenLRASSIGN = "->" >> BOUNDARIES;

tokenELSE = "Else" >> STRICT_BOUNDARIES;
tokenIF = "If" >> STRICT_BOUNDARIES;

tokenDO = "Do" >> STRICT_BOUNDARIES;
tokenFOR = "For" >> STRICT_BOUNDARIES;
tokenTO = "To" >> STRICT_BOUNDARIES;

// Maps to tokenScan
tokenGET = "Scan" >> STRICT_BOUNDARIES;
// Maps to tokenPrint
tokenPUT = "Print" >> STRICT_BOUNDARIES;

// Maps to tokenStartprogram
tokenNAME = "Startprogram" >> STRICT_BOUNDARIES;
// Maps to tokenVariable
tokenDATA = "Variable" >> STRICT_BOUNDARIES;

// Maps to tokenStartblock
tokenBEGIN = "Startblock" >> STRICT_BOUNDARIES;
// Maps to tokenEndblock
tokenEND = "Endblock" >> STRICT_BOUNDARIES;

// Unused tokens in new EBNF but kept for definition compatibility
tokenEXIT = "EXIT" >> STRICT_BOUNDARIES; // Unused
tokenBODY = "BODY" >> STRICT_BOUNDARIES; // Unused

tokenUNDERSCORE = "_";


program_name = SAME_RULE(ident);
value_type = SAME_RULE(tokenINTEGER16);

declaration_element = ident >> -(tokenLEFTSQUAREBRACKETS >> unsigned_value >> tokenRIGHTSQUAREBRACKETS);

other_declaration_ident = tokenCOMMA >> declaration_element;
declaration = value_type >> declaration_element >> *other_declaration_ident;

index_action = tokenLEFTSQUAREBRACKETS >> expression >> tokenRIGHTSQUAREBRACKETS;
unary_operator = SAME_RULE(tokenNOT);
unary_operation = unary_operator >> expression;
binary_operator = tokenAND | tokenOR | tokenEQUAL | tokenNOTEQUAL | tokenLESS | tokenGREATER | tokenPLUS | tokenMINUS | tokenMUL | tokenDIV | tokenMOD;
binary_action = binary_operator >> expression;
left_expression = group_expression | unary_operation | cond_block | value | ident >> -index_action;

expression = left_expression >> *binary_action;

group_expression = tokenGROUPEXPRESSIONBEGIN >> expression >> tokenGROUPEXPRESSIONEND;

// bind_expression (mapped to expression_or_cond_block__with_optional_assign)
expression_or_cond_block__with_optional_assign = expression >> -(tokenLRASSIGN >> ident >> -index_action);


if_expression = SAME_RULE(expression);

// body_for_true__with_optionally_return_value (mapped to body_for_true)
body_for_true = SAME_RULE(block_statements);

// false_cond_block_without_else__with_optionally_return_value (mapped to false_cond_block_without_else)
false_cond_block_without_else = tokenELSE >> tokenIF >> if_expression >> body_for_true;

// body_for_false__with_optionally_return_value (mapped to body_for_false)
body_for_false = tokenELSE >> block_statements;

// cond_block__with_optionally_return_value (mapped to cond_block)
cond_block = tokenIF >> if_expression >> body_for_true >> *false_cond_block_without_else >> -body_for_false;


cycle_begin_expression = SAME_RULE(expression);
cycle_end_expression = SAME_RULE(expression);
cycle_counter = SAME_RULE(ident);
cycle_counter_lr_init = cycle_begin_expression >> tokenLRASSIGN >> cycle_counter;
cycle_counter_init = SAME_RULE(cycle_counter_lr_init);
cycle_counter_last_value = SAME_RULE(cycle_end_expression);
cycle_body = tokenDO >> (statement | block_statements);

// forto_cycle
forto_cycle = tokenFOR >> cycle_counter_init >> tokenTO >> cycle_counter_last_value >> cycle_body;

// input (mapped to input_rule)
input_rule = tokenGET >> (ident >> -index_action | tokenGROUPEXPRESSIONBEGIN >> ident >> -index_action >> tokenGROUPEXPRESSIONEND);

// output (mapped to output_rule)
output_rule = tokenPUT >> expression;

// statement
statement = expression_or_cond_block__with_optional_assign | forto_cycle | input_rule | output_rule | tokenSEMICOLON;

block_statements = tokenBEGINBLOCK >> *statement >> tokenENDBLOCK;

// program (mapped to program_rule)
program_rule = BOUNDARIES >> tokenNAME >> tokenBEGIN >> tokenDATA >> (-declaration) >> tokenSEMICOLON >> *statement >> tokenEND;

value = -sign >> unsigned_value >> BOUNDARIES;

sign = sign_plus | sign_minus;
sign_plus = SAME_RULE(tokenPLUS);
sign_minus = SAME_RULE(tokenMINUS);
unsigned_value = (non_zero_digit >> *digit | digit_0) >> BOUNDARIES;

digit_0 = '0';
digit = digit_0 | non_zero_digit;
digit_1 = '1';
digit_2 = '2';
digit_3 = '3';
digit_4 = '4';
digit_5 = '5';
digit_6 = '6';
digit_7 = '7';
digit_8 = '8';
digit_9 = '9';
non_zero_digit = digit_1 | digit_2 | digit_3 | digit_4 | digit_5 | digit_6 | digit_7 | digit_8 | digit_9;
tokenUNDERSCORE = "_";

// ident = _ + 2 lower case letters + digit
ident =
!(
	tokenINTEGER16 |
	tokenCOMMA |
	tokenNOT |
	tokenAND |
	tokenOR |
	tokenEQUAL |
	tokenNOTEQUAL |
	tokenLESS |
	tokenGREATER |
	tokenPLUS |
	tokenMINUS |
	tokenMUL |
	tokenDIV |
	tokenMOD |
	tokenGROUPEXPRESSIONBEGIN |
	tokenGROUPEXPRESSIONEND |
	tokenLRASSIGN |
	tokenELSE |
	tokenIF |
	tokenDO |
	tokenFOR |
	tokenTO |
	tokenEXIT |
	tokenGET |
	tokenPUT |
	tokenNAME |
	tokenBODY |
	tokenDATA |
	tokenBEGIN |
	tokenEND |
	tokenBEGINBLOCK |
	tokenENDBLOCK |
	tokenLEFTSQUAREBRACKETS |
	tokenRIGHTSQUAREBRACKETS |
	tokenSEMICOLON
	) >>
	tokenUNDERSCORE >> letter_in_lower_case >> letter_in_lower_case >> digit >> STRICT_BOUNDARIES;

// Lowercase letters (active for ident)
a = "a";
b = "b";
c = "c";
d = "d";
e = "e";
f = "f";
g = "g";
h = "h";
i = "i";
j = "j";
k = "k";
l = "l";
m = "m";
n = "n";
o = "o";
p = "p";
q = "q";
r = "r";
s = "s";
t = "t";
u = "u";
v = "v";
w = "w";
x = "x";
y = "y";
z = "z";
letter_in_lower_case = a | b | c | d | e | f | g | h | i | j | k | l | m | n | o | p | q | r | s | t | u | v | w | x | y | z;

// Unused rules definition to satisfy macros
letter_in_upper_case = a; // Dummy
A = "A"; B = "B"; C = "C"; D = "D"; E = "E"; F = "F"; G = "G"; H = "H"; I = "I"; J = "J"; K = "K"; L = "L"; M = "M"; N = "N";
O = "O"; P = "P"; Q = "Q"; R = "R"; S = "S"; T = "T"; U = "U"; V = "V"; W = "W"; X = "X"; Y = "Y"; Z = "Z";
array_specify = SAME_RULE(ident); // Dummy
argument_for_input = SAME_RULE(ident); // Dummy
digit__iteration = SAME_RULE(digit); // Dummy
assign_to_right = SAME_RULE(ident); // Dummy
statement__or__block_statements = SAME_RULE(statement); // Dummy

STRICT_BOUNDARIES = (BOUNDARY >> *(BOUNDARY)) | (!(qi::alpha | qi::char_("_")));
BOUNDARIES = (BOUNDARY >> *(BOUNDARY) | NO_BOUNDARY);
BOUNDARY = BOUNDARY__SPACE | BOUNDARY__TAB | BOUNDARY__VERTICAL_TAB | BOUNDARY__FORM_FEED | BOUNDARY__CARRIAGE_RETURN | BOUNDARY__LINE_FEED | BOUNDARY__NULL;
BOUNDARY__SPACE = " ";
BOUNDARY__TAB = "\t";
BOUNDARY__VERTICAL_TAB = "\v";
BOUNDARY__FORM_FEED = "\f";
BOUNDARY__CARRIAGE_RETURN = "\r";
BOUNDARY__LINE_FEED = "\n";
BOUNDARY__NULL = "\0";
NO_BOUNDARY = "";
#define WHITESPACES \
STRICT_BOUNDARIES, \
BOUNDARIES, \
BOUNDARY, \
BOUNDARY__SPACE, \
BOUNDARY__TAB, \
BOUNDARY__VERTICAL_TAB, \
BOUNDARY__FORM_FEED, \
BOUNDARY__CARRIAGE_RETURN, \
BOUNDARY__LINE_FEED, \
BOUNDARY__NULL, \
NO_BOUNDARY