const char* DEFAULT_SYNTAX_RUST =
    "api = [generic];\n"
    "api_style = [freeform, functions];\n"
    "code_model = [loop_switch, recursive_functions];\n"
    "target = [code, dot];\n"
    "\n"
    "computed_goto = unsupported;\n"
    "case_ranges = unsupported;\n"
    "constants = upper_case;\n"
    "yyctype_literals = hex;\n"
    "semicolons = yes;\n"
    "abort_in_default_case = yes;\n"
    "implicit_bool_conversion = no;\n"
    "backtick_quoted_strings = no;\n"
    "standalone_single_quotes = yes;\n"
    "\n"
    "conf:api = default;\n"
    "conf:api:style = functions;\n"
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
    "conf:define:YYCONDTYPE = \"YYCONDTYPE\";\n"
    "conf:define:YYCTYPE = \"YYCTYPE\";\n"
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
    "conf:define:YYFN = [\"YYFN[0]\", \"YYFN[1]\"];\n"
    "conf:variable:yyctable = \"yyctable\";\n"
    "conf:variable:yyaccept = \"yyaccept\";\n"
    "conf:variable:yytarget = \"yytarget\";\n"
    "conf:variable:yystate = \"yystate\";\n"
    "conf:variable:yych = \"yych\";\n"
    "conf:variable:yych:conversion = 0;\n"
    "conf:variable:yych:emit = (code_model.recursive_functions ? 0 : 1);\n"
    "conf:variable:yybm = \"yybm\";\n"
    "conf:variable:yybm:hex = 0;\n"
    "conf:variable:yystable = \"\"; // deprecated\n"
    "conf:cond:prefix = \"yyc_\";\n"
    "conf:cond:enumprefix = \"yyc\";\n"
    "conf:cond:divider = \"/* *********************************** */\";\n"
    "conf:cond:divider@cond = \"@@\";\n"
    "conf:cond:goto = \"goto @@;\";\n"
    "conf:cond:goto@cond = \"@@\";\n"
    "conf:state:abort = 0;\n"
    "conf:state:nextlabel = 0;\n"
    "conf:bit-vectors = 0;\n"
    "conf:debug-output = 0;\n"
    "conf:computed-gotos = 0;\n"
    "conf:computed-gotos:threshold = 9;\n"
    "conf:nested-ifs = 0;\n"
    "conf:case-insensitive = 0;\n"
    "conf:case-inverted = 0;\n"
    "conf:case-ranges = 0;\n"
    "conf:unsafe = 1;\n"
    "conf:encoding:ebcdic = 0;\n"
    "conf:encoding:utf32 = 0;\n"
    "conf:encoding:ucs2 = 0;\n"
    "conf:encoding:utf16 = 0;\n"
    "conf:encoding:utf8 = 0;\n"
    "conf:encoding-policy = ignore;\n"
    "conf:empty-class = match-empty;\n"
    "conf:indent:string = \"\\t\";\n"
    "conf:indent:top = 0;\n"
    "conf:label:prefix = \"yy\";\n"
    "conf:label:yyfill = \"yyFillLabel\";\n"
    "conf:label:yyloop = \"\";\n"
    "conf:label:yyNext = \"yyNext\";\n"
    "conf:label:start = 0;\n"
    "\n"
    "code:var =\n"
    "    // In Rust uninitialized variable is an error, but if the compiler is able to see\n"
    "    // that all paths overwrite the initial value, it warns about unused assignments.\n"
    "    (have_init? \"\" : topindent \"#[allow(unused_assignments)]\" nl)\n"
    "    topindent \"let mut \" name \" : \" type \" = \" (have_init? init : \"0\") \";\" nl;\n"
    "\n"
    "code:const = topindent \"const \" name \": \" type \" = \" init \";\" nl;\n"
    "\n"
    "// code:array\n"
    "\n"
    "code:type_int = \"isize\";\n"
    "code:type_uint = \"usize\";\n"
    "code:type_cond_enum = (storable_state? \"isize\" : \"usize\");\n"
    "// code:type_yybm\n"
    "// code:type_yytarget\n"
    "\n"
    "code:if_then_else =\n"
    "    [branch{0}: topindent \"if \" cond \" {\" nl\n"
    "        indent [stmt: stmt] dedent]\n"
    "    [branch{1:-1}: topindent \"} else \" (have_cond? \"if \" cond \" \") \"{\" nl\n"
    "        indent [stmt: stmt] dedent]\n"
    "    topindent \"}\" nl;\n"
    "\n"
    "code:switch =\n"
    "    topindent \"match \" expr \" {\" nl\n"
    "        indent [case: case] dedent\n"
    "    topindent \"}\" nl;\n"
    "\n"
    "code:switch_cases =\n"
    "    [case{0:-2}: topindent case \" |\" nl]\n"
    "    [case{-1}:   topindent case \" => {\" nl\n"
    "        indent [stmt: stmt] dedent\n"
    "    topindent \"}\" nl];\n"
    "\n"
    "code:switch_cases_oneline =\n"
    "    [case{0:-2}: topindent case \" |\" nl]\n"
    "    [case{-1}:   topindent case \" => \" [stmt: stmt]];\n"
    "\n"
    "code:switch_case_range = [val{0}: val] (multival ? \" ..= \" [val{-1}: val]);\n"
    "\n"
    "code:switch_case_default = \"_\";\n"
    "\n"
    "code:loop =\n"
    "    topindent (loop_label? label \": \") \"loop {\" nl\n"
    "        indent [stmt: stmt] dedent\n"
    "    topindent \"}\" nl;\n"
    "\n"
    "// In Rust `continue` statements have labels, use it to avoid ambiguity.\n"
    "code:loop_label = \"'yyl\";\n"
    "\n"
    "code:enum = [elem: topindent \"const \" elem \": \" type \" = \" init \";\" nl];\n"
    "\n"
    "code:enum_elem = name;\n"
    "\n"
    "code:fndef =\n"
    "    topindent \"fn \" name \"(\"\n"
    "        [arg{0:-2}: argtype \" \" argname \", \"]\n"
    "        [arg{-1}:   argtype \" \" argname]\n"
    "    \") ->\" (have_type ? \" \" type) \" {\" nl\n"
    "        indent [stmt: stmt] dedent\n"
    "    \"}\" nl;\n"
    "\n"
    "code:fncall = name \"(\" [arg{0:-2}: arg \", \"] [arg{-1}: arg] \")\";\n"
    "\n"
    "code:tailcall = topindent name \"(\" [arg{0:-2}: arg \", \"] [arg{-1}: arg] \")\" nl;\n"
    "\n"
    "code:recursive_functions = [fn: fndef nl];\n"
    "\n"
    "code:fingerprint = \"/* Generated by re2c\" (version? \" \" version) (date? \" on \" date) \" */\" nl;\n"
    "\n"
    "// No line directives in Rust: https://github.com/rust-lang/rfcs/issues/1862.\n"
    "//code:line_info\n"
    "\n"
    "code:abort = topindent \"panic!(\\\"internal lexer error\\\");\" nl;\n"
    "\n"
    "code:yyaccept = topindent var \" = \" num \";\" nl;\n"
    "\n"
    "code:yydebug = topindent debug \"(\" state \", \" char \");\" nl;\n"
    "\n"
    "code:yypeek =\n"
    "    topindent (code_model.recursive_functions ? \"let mut \") char \" = \"\n"
    "        (unsafe? \"unsafe {\" peek \"}\" : peek)\n"
    "        (api_style.functions ? \"()\")\n"
    "        \";\" nl;\n"
    "\n"
    "code:yyskip = topindent skip (api_style.functions ? \"();\") nl;\n"
    "\n"
    "code:yybackup = topindent backup (api_style.functions ? \"();\") nl;\n"
    ;
