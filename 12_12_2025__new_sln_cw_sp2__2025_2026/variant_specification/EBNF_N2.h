#define NONTERMINALS program_name, \
value_type, \
array_specify, \
declaration_element, \
array_specify__optional, \
other_declaration_ident, \
declaration, \
other_declaration_ident__iteration, \
index_action, \
unary_operator, \
unary_operation, \
binary_operator, \
binary_action, \
left_expression, \
group_expression, \
index_action__optional, \
expression, \
binary_action__iteration, \
expression_or_cond_block__with_optional_assign, \
assign_to_right, \
assign_to_right__optional, \
if_expression, \
body_for_true, \
false_cond_block_without_else, \
body_for_false, \
cond_block, \
false_cond_block_without_else__iteration, \
body_for_false__optional, \
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
statement__iteration, \
expression__optional, \
program_rule, \
declaration__optional, \
non_zero_digit, \
digit__iteration, \
digit, \
unsigned_value, \
value, \
sign__optional, \
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



// --- Tokens Definition (Updated logic using old names) ---

tokenGROUPEXPRESSIONBEGIN = "(" >> BOUNDARIES;
tokenGROUPEXPRESSIONEND = ")" >> BOUNDARIES;
tokenLEFTSQUAREBRACKETS = "[" >> BOUNDARIES;
tokenRIGHTSQUAREBRACKETS = "]" >> BOUNDARIES;
tokenBEGINBLOCK = "{" >> BOUNDARIES;
tokenENDBLOCK = "}" >> BOUNDARIES;
tokenSEMICOLON = ";" >> BOUNDARIES;

tokenINTEGER16 = "Int32" >> STRICT_BOUNDARIES; /* «Ã≤Õ≈ÕŒ: "INTEGER16" -> "Int32" */
tokenCOMMA = "," >> BOUNDARIES;

tokenNOT = "Not" >> STRICT_BOUNDARIES; /* «Ã≤Õ≈ÕŒ: "NOT" -> "Not" */

tokenAND = "And" >> STRICT_BOUNDARIES; /* «Ã≤Õ≈ÕŒ: "AND" -> "And" */
tokenOR = "Or" >> STRICT_BOUNDARIES; /* «Ã≤Õ≈ÕŒ: "OR" -> "Or" */

tokenEQUAL = "Eq" >> STRICT_BOUNDARIES; /* «Ã≤Õ≈ÕŒ: "==" -> "Eq" */
tokenNOTEQUAL = "Neq" >> STRICT_BOUNDARIES; /* «Ã≤Õ≈ÕŒ: "!=" -> "Neq" */
tokenLESS = "Ls" >> STRICT_BOUNDARIES; /* «Ã≤Õ≈ÕŒ: "<" -> "Ls" */
tokenGREATER = "Gr" >> STRICT_BOUNDARIES; /* «Ã≤Õ≈ÕŒ: ">" -> "Gr" */

tokenPLUS = "++" >> BOUNDARIES; /* «Ã≤Õ≈ÕŒ: "+" -> "++" */
tokenMINUS = "--" >> BOUNDARIES; /* «Ã≤Õ≈ÕŒ: "-" -> "--" */
tokenMUL = "**" >> BOUNDARIES; /* «Ã≤Õ≈ÕŒ: "*" -> "**" */

tokenDIV = "Div" >> STRICT_BOUNDARIES; /* «Ã≤Õ≈ÕŒ: "DIV" -> "Div" */
tokenMOD = "Mod" >> STRICT_BOUNDARIES; /* «Ã≤Õ≈ÕŒ: "MOD" -> "Mod" */

tokenLRASSIGN = "->" >> BOUNDARIES; /* «Ã≤Õ≈ÕŒ: "=:" -> "->" (‚ËÍÓËÒÚÓ‚Û∫Ú¸Òˇ ‰Îˇ BIND) */

tokenELSE = "Else" >> STRICT_BOUNDARIES; /* «Ã≤Õ≈ÕŒ: "ELSE" -> "Else" */
tokenIF = "If" >> STRICT_BOUNDARIES; /* «Ã≤Õ≈ÕŒ: "IF" -> "If" */

tokenDO = "Do" >> STRICT_BOUNDARIES; /* «Ã≤Õ≈ÕŒ: "DO" -> "Do" */
tokenFOR = "For" >> STRICT_BOUNDARIES; /* «Ã≤Õ≈ÕŒ: "FOR" -> "For" */
tokenTO = "To" >> STRICT_BOUNDARIES; /* «Ã≤Õ≈ÕŒ: "TO" -> "To" */

tokenEXIT = "EXIT" >> STRICT_BOUNDARIES; /* ÕÂ ‚ËÍÓËÒÚÓ‚Û∫Ú¸Òˇ ‚ ÌÓ‚≥È ≈¡Õ‘, Á‡ÎË¯ÂÌÓ ˇÍ Á‡„ÎÛ¯Í‡ */

tokenGET = "Scan" >> STRICT_BOUNDARIES; /* «Ã≤Õ≈ÕŒ: "GET" -> "Scan" */
tokenPUT = "Print" >> STRICT_BOUNDARIES; /* «Ã≤Õ≈ÕŒ: "PUT" -> "Print" */

tokenNAME = "Startprogram" >> STRICT_BOUNDARIES; /* «Ã≤Õ≈ÕŒ: "NAME" -> "Startprogram" */
tokenBODY = "BODY" >> STRICT_BOUNDARIES; /* ÕÂ ‚ËÍÓËÒÚÓ‚Û∫Ú¸Òˇ, ‡ÎÂ ‚ËÁÌ‡˜ÂÌÓ ‚ Ï‡ÍÓÒ≥ */
tokenDATA = "Variable" >> STRICT_BOUNDARIES; /* «Ã≤Õ≈ÕŒ: "DATA" -> "Variable" */
tokenBEGIN = "Startblock" >> STRICT_BOUNDARIES; /* «Ã≤Õ≈ÕŒ: "BEGIN" -> "Startblock" */
tokenEND = "Endblock" >> STRICT_BOUNDARIES; /* «Ã≤Õ≈ÕŒ: "END" -> "Endblock" */


// --- Grammar Rules ---

program_name = SAME_RULE(ident);
value_type = SAME_RULE(tokenINTEGER16);

array_specify = tokenLEFTSQUAREBRACKETS >> unsigned_value >> tokenRIGHTSQUAREBRACKETS;
array_specify__optional = array_specify | ""; /* –Â‡Î≥Á‡ˆ≥ˇ ÓÔˆ≥ÓÌ‡Î¸ÌÓÒÚ≥ */
declaration_element = ident >> array_specify__optional;

other_declaration_ident = tokenCOMMA >> declaration_element;
declaration = value_type >> declaration_element >> other_declaration_ident__iteration;
other_declaration_ident__iteration = other_declaration_ident >> other_declaration_ident__iteration | ""; /* ≤ÚÂ‡ˆ≥ˇ */


index_action = tokenLEFTSQUAREBRACKETS >> expression >> tokenRIGHTSQUAREBRACKETS;
index_action__optional = index_action | "";

unary_operator = SAME_RULE(tokenNOT);
unary_operation = unary_operator >> expression;

binary_operator = tokenAND | tokenOR | tokenEQUAL | tokenNOTEQUAL | tokenLESS | tokenGREATER | tokenPLUS | tokenMINUS | tokenMUL | tokenDIV | tokenMOD;
binary_action = binary_operator >> expression;

left_expression = group_expression | unary_operation | ident >> index_action__optional | value; /* «Ã≤Õ≈ÕŒ: ÔÓˇ‰ÓÍ, ÔË·‡ÌÓ cond_block Á Î≥‚Ó„Ó ‚Ë‡ÁÛ Á„≥‰ÌÓ ≈¡Õ‘ */

expression = left_expression >> binary_action__iteration;
binary_action__iteration = binary_action >> binary_action__iteration | "";

group_expression = tokenGROUPEXPRESSIONBEGIN >> expression >> tokenGROUPEXPRESSIONEND;

/* «Ã≤Õ≈ÕŒ: –Â‡Î≥Á‡ˆ≥ˇ bind_expression ˜ÂÂÁ ≥ÒÌÛ˛˜≥ ÁÏ≥ÌÌ≥ */
/* expression_or_cond_block__with_optional_assign ‚≥‰ÔÓ‚≥‰‡∫ Ô‡‚ËÎÛ: bind_expression = expression >> "->" >> ident >> -index_action */
/* ÃË ‚ËÍÓËÒÚÓ‚Û∫ÏÓ assign_to_right__optional ˇÍ "-> ident -index_action", ‡ÎÂ ÓÒÍ≥Î¸ÍË bind Ó·Ó‚'ˇÁÍÓ‚ËÈ, Ó·ËÏÓ ˆÂ ÔˇÏÓ: */
assign_to_right = tokenLRASSIGN >> ident >> index_action__optional;
expression_or_cond_block__with_optional_assign = expression >> assign_to_right;
assign_to_right__optional = assign_to_right | ""; // «‡ÎË¯ÂÌÓ ‰Îˇ ÒÛÏ≥ÒÌÓÒÚ≥ Á ≥Ì¯ËÏË ˜‡ÒÚËÌ‡ÏË, ˇÍ˘Ó ÚÂ·‡

if_expression = SAME_RULE(expression);

/* «Ã≤Õ≈ÕŒ: block_statements__with_optionally_return_value Â‡Î≥ÁÓ‚‡ÌÓ ÚÛÚ */
expression__optional = expression | "";
body_for_true = tokenBEGINBLOCK >> statement__iteration >> expression__optional >> tokenENDBLOCK;

/* «Ã≤Õ≈ÕŒ: ÀÓ„≥Í‡ ELSE IF */
false_cond_block_without_else = tokenELSE >> tokenIF >> if_expression >> body_for_true;
false_cond_block_without_else__iteration = false_cond_block_without_else >> false_cond_block_without_else__iteration | "";

/* «Ã≤Õ≈ÕŒ: ÀÓ„≥Í‡ ELSE */
body_for_false = tokenELSE >> body_for_true; /* “ÛÚ body_for_true ‚ËÍÓËÒÚÓ‚Û∫Ú¸Òˇ ˇÍ block_statements__with_optionally_return_value */
body_for_false__optional = body_for_false | "";

/* «Ã≤Õ≈ÕŒ: Cond Block */
/* cond_block__with_optionally_return_value_and_optionally_bind */
/* ŒÒÍ≥Î¸ÍË ÒÚÛÍÚÛ‡ ÁÏ≥ÌÌËı Ù≥ÍÒÓ‚‡Ì‡, ÏË Á‡ÔËÒÛ∫ÏÓ ÔÓ‚ÌÂ Ô‡‚ËÎÓ ÚÛÚ */
cond_block = tokenIF >> if_expression >> body_for_true >> false_cond_block_without_else__iteration >> body_for_false__optional >> assign_to_right__optional;


cycle_begin_expression = SAME_RULE(expression);
cycle_end_expression = SAME_RULE(expression);
cycle_counter = SAME_RULE(ident);
cycle_counter_lr_init = cycle_begin_expression >> tokenLRASSIGN >> cycle_counter;
cycle_counter_init = SAME_RULE(cycle_counter_lr_init);
cycle_counter_last_value = SAME_RULE(cycle_end_expression);

cycle_body = tokenDO >> statement__or__block_statements;
forto_cycle = tokenFOR >> cycle_counter_init >> tokenTO >> cycle_counter_last_value >> cycle_body; /* «Ã≤Õ≈ÕŒ: fordownto_cycle -> forto_cycle, tokenDOWNTO -> tokenTO */

statement__or__block_statements = statement | block_statements;

input_rule = tokenGET >> argument_for_input;
argument_for_input = ident >> index_action__optional | tokenGROUPEXPRESSIONBEGIN >> ident >> index_action__optional >> tokenGROUPEXPRESSIONEND;

output_rule = tokenPUT >> expression;

/* «Ã≤Õ≈ÕŒ: statement ‚ÍÎ˛˜‡∫ bind, cond_block, cycle, input, output */
statement = expression_or_cond_block__with_optional_assign | cond_block | forto_cycle | input_rule | output_rule | tokenSEMICOLON; /* «Ã≤Õ≈ÕŒ: fordownto_cycle -> forto_cycle */
statement__iteration = statement >> statement__iteration | "";

block_statements = tokenBEGINBLOCK >> statement__iteration >> tokenENDBLOCK;

/* «Ã≤Õ≈ÕŒ: program_rule - ÔË·‡ÌÓ tokenBODY, ÁÏ≥ÌÂÌÓ ÔÓˇ‰ÓÍ, ÔË·‡ÌÓ program_name */
declaration__optional = declaration | "";
program_rule = BOUNDARIES >> tokenNAME >> tokenBEGIN >> tokenDATA >> declaration__optional >> tokenSEMICOLON >> statement__iteration >> tokenEND;


/* --- Low Level Rules --- */

/* «Ã≤Õ≈ÕŒ: sign = sign_plus | sign_minus (ÌÂ qi::char_('-') >> qi::char_('-')) */
sign_plus = SAME_RULE(tokenPLUS);
sign_minus = SAME_RULE(tokenMINUS);
sign = sign_plus | sign_minus;
sign__optional = sign | "";

value = sign__optional >> unsigned_value >> BOUNDARIES;

unsigned_value = (non_zero_digit >> digit__iteration | digit_0) >> BOUNDARIES;
digit__iteration = digit >> digit__iteration | "";

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

/* «Ã≤Õ≈ÕŒ: Ident = _ + 2 lower case + digit (ÌÂ _ + digit + 2 upper case) */
ident = tokenUNDERSCORE >> letter_in_lower_case >> letter_in_lower_case >> digit >> STRICT_BOUNDARIES;

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

/* «‡„ÎÛ¯ÍË ‰Îˇ ÌÂ‚ËÍÓËÒÚÓ‚Û‚‡ÌËı ÁÏ≥ÌÌËı Á Ï‡ÍÓÒÛ */
letter_in_upper_case = a;
A = "A"; B = "B"; C = "C"; D = "D"; E = "E"; F = "F"; G = "G"; H = "H"; I = "I"; J = "J"; K = "K"; L = "L"; M = "M"; N = "N";
O = "O"; P = "P"; Q = "Q"; R = "R"; S = "S"; T = "T"; U = "U"; V = "V"; W = "W"; X = "X"; Y = "Y"; Z = "Z";

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