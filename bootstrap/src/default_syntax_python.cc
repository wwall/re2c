#include "src/parse/conf_parser.h"
const char* DEFAULT_SYNTAX_PYTHON =
    "supported_apis = [\"generic\"];\n"
    "// \"recursive_functions\" works syntactically, but causes stack overflows due to non-tail recusion\n"
    "supported_code_models = [\"loop_switch\"];\n"
    "supported_targets = [\"code\", \"dot\"];\n"
    "supported_features = [\"nested_ifs\"];\n"
    "\n"
    "semicolons = 0;\n"
    "implicit_bool_conversion = 0;\n"
    "backtick_quoted_strings = 0;\n"
    "standalone_single_quotes = 0;\n"
    "indentation_sensitive = 1;\n"
    "\n"
    "conf:api = custom;\n"
    "conf:api:style = free-form;\n"
    "conf:api:sigil = \"@@\";\n"
    "conf:header = \"\";\n"
    "conf:eof = -1;\n"
    "conf:sentinel = -1;\n"
    "conf:yyfill:enable = 1;\n"
    "conf:yyfill:parameter = 1;\n"
    "conf:yyfill:check = 1;\n"
    "conf:tags = 0;\n"
    "conf:leftmost-captures = 0;\n"
    "conf:posix-captures = 0;\n"
    "conf:tags:prefix = \"yyt\";\n"
    "conf:tags:expression = \"@@\";\n"
    "conf:invert-captures = 0;\n"
    "conf:define:YYBACKUP = \"YYBACKUP\";\n"
    "conf:define:YYBACKUPCTX = \"YYBACKUPCTX\";\n"
    "conf:define:YYCONDTYPE = \"yycondtype\";\n"
    "conf:define:YYCTYPE = \"yyctype\";\n"
    "conf:define:YYCTXMARKER = \"YYCTXMARKER\";\n"
    "conf:define:YYCURSOR = \"YYCURSOR\";\n"
    "conf:define:YYDEBUG = \"YYDEBUG\";\n"
    "conf:define:YYFILL = \"YYFILL\";\n"
    "conf:define:YYFILL@len = \"@@\";\n"
    "conf:define:YYFILL:naked = 0;\n"
    "conf:define:YYGETCONDITION = \"YYGETCONDITION\";\n"
    "conf:define:YYGETCONDITION:naked = 0;\n"
    "conf:define:YYGETSTATE = \"YYGETSTATE\";\n"
    "conf:define:YYGETSTATE:naked = 0;\n"
    "conf:define:YYLESSTHAN = \"YYLESSTHAN\";\n"
    "conf:define:YYLIMIT = \"YYLIMIT\";\n"
    "conf:define:YYMARKER = \"YYMARKER\";\n"
    "conf:define:YYMAXFILL = \"YYMAXFILL\";\n"
    "conf:define:YYMAXNMATCH = \"YYMAXNMATCH\";\n"
    "conf:define:YYMTAGN = \"YYMTAGN\";\n"
    "conf:define:YYMTAGP = \"YYMTAGP\";\n"
    "conf:define:YYPEEK = \"YYPEEK\";\n"
    "conf:define:YYRESTORE = \"YYRESTORE\";\n"
    "conf:define:YYRESTORECTX = \"YYRESTORECTX\";\n"
    "conf:define:YYRESTORETAG = \"YYRESTORETAG\";\n"
    "conf:define:YYSETCONDITION = \"YYSETCONDITION\";\n"
    "conf:define:YYSETCONDITION@cond = \"@@\";\n"
    "conf:define:YYSETCONDITION:naked = 0;\n"
    "conf:define:YYSETSTATE = \"YYSETSTATE\";\n"
    "conf:define:YYSETSTATE:naked = 0;\n"
    "conf:define:YYSETSTATE@state = \"@@\";\n"
    "conf:define:YYSHIFT = \"YYSHIFT\";\n"
    "conf:define:YYSHIFTSTAG = \"YYSHIFTSTAG\";\n"
    "conf:define:YYSHIFTMTAG = \"YYSHIFTMTAG\";\n"
    "conf:define:YYSKIP = \"YYSKIP\";\n"
    "conf:define:YYSTAGN = \"YYSTAGN\";\n"
    "conf:define:YYSTAGP = \"YYSTAGP\";\n"
    "conf:define:YYFN = [\"<undefined-function-name>;<undefined-function-type>\"];\n"
    "conf:yyfn:sep = \";\";\n"
    "conf:variable:yyctable = \"yyctable\";\n"
    "conf:variable:yyaccept = \"yyaccept\";\n"
    "conf:variable:yytarget = \"yytarget\";\n"
    "conf:variable:yystate = \"yystate\";\n"
    "conf:variable:yych = \"yych\";\n"
    "conf:variable:yych:conversion = 0;\n"
    "conf:variable:yych:literals = hex;\n"
    "conf:variable:yych:emit = 0;\n"
    "conf:variable:yybm = \"yybm\";\n"
    "conf:variable:yybm:hex = 0;\n"
    "conf:variable:yystable = \"\"; // deprecated\n"
    "conf:cond:abort = 0; // default case causes [redundant-case] warnings\n"
    "conf:cond:prefix = \"yyc_\";\n"
    "conf:cond:enumprefix = \"YYC_\";\n"
    "conf:cond:divider = \"(* *********************************** *)\";\n"
    "conf:cond:divider@cond = \"@@\";\n"
    "conf:cond:goto = \"\";\n"
    "conf:cond:goto@cond = \"@@\";\n"
    "conf:state:abort = 1;\n"
    "conf:state:nextlabel = 0;\n"
    "conf:bit-vectors = 0;\n"
    "conf:debug-output = 0;\n"
    "conf:computed-gotos = 0;\n"
    "conf:computed-gotos:threshold = 9;\n"
    "conf:nested-ifs = 1;\n"
    "conf:case-insensitive = 0;\n"
    "conf:case-inverted = 0;\n"
    "conf:case-ranges = 0;\n"
    "conf:unsafe = 0;\n"
    "conf:encoding:ebcdic = 0;\n"
    "conf:encoding:utf32 = 0;\n"
    "conf:encoding:ucs2 = 0;\n"
    "conf:encoding:utf16 = 0;\n"
    "conf:encoding:utf8 = 0;\n"
    "conf:encoding-policy = ignore;\n"
    "conf:empty-class = match-empty;\n"
    "conf:indent:string = \"    \";\n"
    "conf:indent:top = 0;\n"
    "conf:label:prefix = \"yy\";\n"
    "conf:label:yyfill = \"\";\n"
    "conf:label:yyloop = \"\";\n"
    "conf:label:yyNext = \"\";\n"
    "conf:label:start = 0;\n"
    "\n"
    "code:var_local = topindent name (have_init ? \" = \" init) nl;\n"
    "code:var_global = code:var_local;\n"
    "\n"
    "code:const_local = topindent name \" = \" init nl;\n"
    "code:const_global = code:const_local;\n"
    "\n"
    "// code:array_local\n"
    "// code:array_global\n"
    "code:array_elem = array \"[\" index \"]\";\n"
    "\n"
    "// code:type_int\n"
    "// code:type_uint\n"
    "// code:type_cond_enum\n"
    "// code:type_yybm\n"
    "// code:type_yytarget\n"
    "\n"
    "code:assign = [lhs: topindent lhs \" = \" rhs nl];\n"
    "code:assign_op = topindent lhs \" = \" lhs \" \" op \" \" rhs nl;\n"
    "\n"
    "code:if_then_else =\n"
    "    [branch{0}: topindent \"if \" cond \":\" nl\n"
    "        indent [stmt: stmt] dedent]\n"
    "    [branch{1:-1}: topindent (have_cond? \"elif \" cond : \"else\") \":\" nl\n"
    "        indent [stmt: stmt] dedent];\n"
    "\n"
    "code:switch =\n"
    "    topindent \"match \" expr \":\" nl\n"
    "        indent [case: case] dedent;\n"
    "\n"
    "code:switch_cases = topindent \"case \"\n"
    "    [case{0:-2}: case \"|\"]\n"
    "    [case{-1}:   case \":\" nl]\n"
    "        indent [stmt: stmt] dedent;\n"
    "\n"
    "code:switch_case_range = (multival\n"
    "    ? [val{0}: val] [val{1:-1}: \"|\" val]\n"
    "    : [val{0}: val]);\n"
    "\n"
    "code:switch_case_default = \"_\";\n"
    "\n"
    "code:loop =\n"
    "    topindent \"while True:\" nl\n"
    "        indent [stmt: stmt] dedent;\n"
    "\n"
    "code:enum = [elem: elem \" = \" init nl];\n"
    "\n"
    "code:enum_elem = name;\n"
    "\n"
    "code:fndef =\n"
    "    \"def \" name \"(\" [arg{0}: argname] [arg{1:-1}: \", \" argname] \"):\" nl\n"
    "        indent [stmt: stmt] dedent;\n"
    "\n"
    "code:fncall =\n"
    "    topindent (have_retval ? retval \" = \") name \"(\" [arg{0:-2}: arg \", \"] [arg{-1}: arg] \")\" nl;\n"
    "\n"
    "code:tailcall =\n"
    "    topindent (have_retval ? \"return \") name \"(\" [arg{0:-2}: arg \", \"] [arg{-1}: arg] \")\" nl;\n"
    "\n"
    "code:recursive_functions = [fn: fndef nl];\n"
    "\n"
    "code:fingerprint =\n"
    "    \"# Generated by re2c\" (version? \" \" version) (date? \" on \" date) nl;\n"
    "\n"
    "code:abort = topindent \"raise \\\"internal lexer error\\\"\" nl;\n"
    "\n"
    "code:yyaccept = topindent var \" = \" num nl;\n"
    "\n"
    "code:yydebug = topindent debug \" \" state \" \" char nl;\n"
    "\n"
    "code:yypeek = topindent char \" = \" peek (api_style.functions ? \"()\") nl;\n"
    "\n"
    "code:yyskip = topindent skip (api_style.functions ? \"()\") nl;\n"
    "\n"
    "code:yybackup = topindent backup (api_style.functions ? \"()\") nl;\n"
    ;
