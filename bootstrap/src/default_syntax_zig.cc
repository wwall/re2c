#include "src/parse/conf_parser.h"
const char* DEFAULT_SYNTAX_ZIG =
    "supported_apis = [\"simple\", \"generic\", \"record\"];\n"
    "supported_api_styles = [\"free-form\"];\n"
    "supported_code_models = [\"loop_switch\", \"recursive_functions\"];\n"
    "supported_targets = [\"code\", \"dot\"];\n"
    "supported_features = [\"nested_ifs\", \"case_ranges\"];\n"
    "\n"
    "semicolons = 1;\n"
    "implicit_bool_conversion = 0;\n"
    "backtick_quoted_strings = 0;\n"
    "standalone_single_quotes = 0;\n"
    "indentation_sensitive = 0;\n"
    "wrap_blocks_in_braces = 0;\n"
    "\n"
    "conf:api = default;\n"
    "conf:api:style = free-form;\n"
    "conf:api:sigil = \"@@\";\n"
    "conf:define:YYGETCOND:naked = 0;\n"
    "conf:define:YYSETCOND:naked = 0;\n"
    "conf:define:YYSETCOND@cond = \"@@\";\n"
    "conf:define:YYGETSTATE:naked = 0;\n"
    "conf:define:YYSETSTATE:naked = 0;\n"
    "conf:define:YYSETSTATE@state = \"@@\";\n"
    "conf:define:YYFILL@len = \"@@\";\n"
    "conf:define:YYFILL:naked = 0;\n"
    "conf:define:YYFN = [\"<undefined-function-name>;<undefined-function-type>\"];\n"
    "conf:yyfn:sep = \";\";\n"
    "conf:variable:yycond = \"yycond\";\n"
    "conf:variable:yyctable = \"yyctable\";\n"
    "conf:variable:yyaccept = \"yyaccept\";\n"
    "conf:variable:yytarget = \"yytarget\";\n"
    "conf:variable:yystate = \"yystate\";\n"
    "conf:variable:yynmatch = \"yynmatch\";\n"
    "conf:variable:yypmatch = \"yypmatch\";\n"
    "conf:variable:yyrecord = \"yyrecord\";\n"
    "conf:variable:yych = \"yych\";\n"
    "conf:variable:yych:conversion = 0;\n"
    "conf:variable:yych:literals = hex; // zig does not recognize '\\f' escape sequence => use hex\n"
    "conf:variable:yych:emit = (code_model.recursive_functions ? 0 : 1);\n"
    "conf:variable:yybm = \"yybm\";\n"
    "conf:variable:yybm:hex = 0;\n"
    "conf:variable:yyfill = \"\";\n"
    "conf:variable:yystable = \"\"; // deprecated\n"
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
    "conf:invert-captures = 0;\n"
    "conf:cond:abort = 1;\n"
    "conf:cond:prefix = \"yyc_\";\n"
    "conf:cond:enumprefix = \"yyc\";\n"
    "conf:cond:divider@cond = \"@@\";\n"
    "conf:cond:goto@cond = \"@@\";\n"
    "conf:state:abort = 1;\n"
    "conf:state:nextlabel = 0;\n"
    "conf:bit-vectors = 0;\n"
    "conf:debug-output = 0;\n"
    "conf:computed-gotos = 0;\n"
    "conf:computed-gotos:threshold = 9;\n"
    "conf:nested-ifs = 0;\n"
    "conf:case-insensitive = 0;\n"
    "conf:case-inverted = 0;\n"
    "conf:case-ranges = 1;\n"
    "conf:unsafe = 0;\n"
    "conf:monadic = 0;\n"
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
    "conf:label:yyfill = \"yyFillLabel\";\n"
    "conf:label:yyloop = \"\";\n"
    "conf:label:yyNext = \"yyNext\";\n"
    "conf:label:start = 0;\n"
    "\n"
    "conf:define:YYBACKUP = \"yybackup\";\n"
    "conf:define:YYBACKUPCTX = \"yybackupctx\";\n"
    "conf:define:YYCONDTYPE = \"YYCond\";\n"
    "conf:define:YYCOPYMTAG = sigil \"{lhs} = \" sigil \"{rhs};\";\n"
    "conf:define:YYCOPYSTAG = sigil \"{lhs} = \" sigil \"{rhs};\";\n"
    "conf:define:YYCTXMARKER = (api.record ? yyrecord \".\") \"yyctxmarker\";\n"
    "conf:define:YYCTYPE = \"u8\";\n"
    "conf:define:YYCURSOR = (api.record ? yyrecord \".\") \"yycursor\";\n"
    "conf:define:YYDEBUG = \"yydebug\";\n"
    "conf:define:YYFILL = \"yyfill\";\n"
    "conf:define:YYGETACCEPT = sigil \"{var}\";\n"
    "conf:define:YYGETCOND = \"yygetcond\";\n"
    "conf:define:YYGETSTATE = \"yygetstate\";\n"
    "conf:define:YYINPUT = (api.record ? yyrecord \".\") \"yyinput\";\n"
    "conf:define:YYLESSTHAN = \"yylessthan\";\n"
    "conf:define:YYLIMIT = (api.record ? yyrecord \".\") \"yylimit\";\n"
    "conf:define:YYMARKER = (api.record ? yyrecord \".\") \"yymarker\";\n"
    "conf:define:YYMAXFILL = \"yymaxfill\";\n"
    "conf:define:YYMAXNMATCH = \"yymaxnmatch\";\n"
    "conf:define:YYMTAGN = \"yymtagn\";\n"
    "conf:define:YYMTAGP = \"yymtagp\";\n"
    "conf:define:YYPEEK = \"yypeek\";\n"
    "conf:define:YYRESTORE = \"yyrestore\";\n"
    "conf:define:YYRESTORECTX = \"yyrestorectx\";\n"
    "conf:define:YYRESTORETAG = \"yyrestoretag\";\n"
    "conf:define:YYSETACCEPT = sigil \"{var} = \" sigil \"{val};\";\n"
    "conf:define:YYSETCOND = \"yysetcond\";\n"
    "conf:define:YYSETSTATE = \"yysetstate\";\n"
    "conf:define:YYSHIFT = \"yyshift\";\n"
    "conf:define:YYSHIFTSTAG = \"yyshiftstag\";\n"
    "conf:define:YYSHIFTMTAG = \"yyshiftmtag\";\n"
    "conf:define:YYSKIP = \"yyskip\";\n"
    "conf:define:YYSTAGN = \"yystagn\";\n"
    "conf:define:YYSTAGP = \"yystagp\";\n"
    "conf:tags:expression = (api.record ? yyrecord \".\") sigil;\n"
    "conf:tags:negative = (api.generic ? \"@@\" : \"std.math.maxInt(usize)\");\n"
    "conf:cond:divider = \"/* *********************************** */\";\n"
    "conf:cond:goto = \"goto \" sigil \";\";\n"
    "\n"
    "code:var_local = topindent \"var \" name \": \" type \" = \" (have_init? init : \"0\") \";\" nl;\n"
    "code:var_global = code:var_local;\n"
    "\n"
    "code:const_local = topindent \"const \" name \" = \" init \";\" nl;\n"
    "code:const_global = code:const_local;\n"
    "\n"
    "code:array_local = <undefined>;\n"
    "code:array_global = <undefined>;\n"
    "code:array_elem = array \"[\" index \"]\";\n"
    "\n"
    "code:type_int = \"i32\";\n"
    "code:type_uint = \"u32\";\n"
    "code:type_cond_enum = \"u32\";\n"
    "code:type_yybm = \"const u8\";\n"
    "code:type_yytarget = <undefined>;\n"
    "\n"
    "code:assign = topindent lhs \" = \" rhs \";\" nl;\n"
    "\n"
    "code:cmp_eq = \"==\";\n"
    "code:cmp_ne = \"!=\";\n"
    "code:cmp_lt = \"<\";\n"
    "code:cmp_gt = \">\";\n"
    "code:cmp_le = \"<=\";\n"
    "code:cmp_ge = \">=\";\n"
    "\n"
    "code:if_then_else =\n"
    "    [branch{0}: topindent \"if (\" cond \") {\" nl\n"
    "        indent [stmt: stmt] dedent]\n"
    "    [branch{1:-1}: topindent \"} else \" (have_cond? \"if (\" cond \") \") \"{\" nl\n"
    "        indent [stmt: stmt] dedent]\n"
    "    topindent \"}\" nl;\n"
    "\n"
    "code:if_then_else_oneline =\n"
    "    [branch{0}:    topindent \"if (\" cond \") { \" [stmt: stmt] \" }\" nl]\n"
    "    [branch{1:-1}: topindent \"else \" (have_cond? \"if (\" cond \") \") \" {\" [stmt: stmt] \" }\" nl];\n"
    "\n"
    "code:switch =\n"
    "    topindent \"switch (\" expr \") {\" nl\n"
    "        indent [case: case] dedent\n"
    "    topindent \"}\" nl;\n"
    "\n"
    "code:switch_cases =\n"
    "    [case{0:-2}: topindent case \",\" nl]\n"
    "    [case{-1}:   topindent case \" => {\" nl\n"
    "        indent [stmt: stmt] dedent\n"
    "    topindent \"},\" nl];\n"
    "\n"
    "code:switch_cases_oneline =\n"
    "    [case{0:-2}: topindent case \",\" nl]\n"
    "    [case{-1}:   topindent case \" => { \" [stmt: stmt] \" },\" nl];\n"
    "\n"
    "code:switch_case_range = [val{0}: val] (many ? \"...\" [val{-1}: val]);\n"
    "\n"
    "code:switch_case_default = \"else\";\n"
    "\n"
    "code:loop =\n"
    "    topindent \"while (true) {\" nl\n"
    "        indent [stmt: stmt] dedent\n"
    "    topindent \"}\" nl;\n"
    "\n"
    "code:goto = topindent \"goto \" label \";\" nl;\n"
    "\n"
    "code:enum = [elem: topindent \"const \" elem \": \" type \" = \" init \";\" nl];\n"
    "\n"
    "code:enum_elem = name;\n"
    "\n"
    "code:fndecl = <undefined>;\n"
    "\n"
    "code:fndef =\n"
    "    topindent \"fn \" name \"(\"\n"
    "        [arg{0:-2}: argname \": \" argtype \", \"]\n"
    "        [arg{-1}:   argname \": \" argtype]\n"
    "    \") \" type \" {\" nl\n"
    "        indent [stmt: stmt] dedent\n"
    "    \"}\" nl;\n"
    "\n"
    "code:fncall =\n"
    "    topindent (have_retval ? retval \" = \" name) \"(\" [arg{0:-2}: arg \", \"] [arg{-1}: arg] \");\" nl;\n"
    "\n"
    "code:tailcall =\n"
    "    topindent (have_retval ? \"return \" name) \"(\" [arg{0:-2}: arg \", \"] [arg{-1}: arg] \");\" nl;\n"
    "\n"
    "code:recursive_functions = [fn: fndef nl];\n"
    "\n"
    "code:fingerprint =\n"
    "    \"// Generated by re2zig\" (have_version? \" \" version) (have_date? \" on \" date) nl;\n"
    "\n"
    "code:line_info = <undefined>;\n"
    "\n"
    "code:abort = topindent \"@panic(\\\"internal lexer error\\\");\" nl;\n"
    "\n"
    "code:yydebug =\n"
    "    topindent (api.generic\n"
    "        ? YYDEBUG\n"
    "    : (api.record\n"
    "        ? YYDEBUG \"(\" yyrecord \");\"\n"
    "        : YYDEBUG \"(\" state \", \" yych \");\"\n"
    "    )) nl;\n"
    "\n"
    "code:yypeek =\n"
    "    topindent (code_model.recursive_functions ? \"var \" yych \": \" YYCTYPE : yych) \" = \" (api.generic\n"
    "        ? YYPEEK\n"
    "        : (cast ? \"@intCast(\") YYINPUT \"[\" YYCURSOR \"]\" (cast ? \")\")\n"
    "    ) \";\" nl;\n"
    "\n"
    "code:yyskip =\n"
    "    topindent (api.generic\n"
    "        ? YYSKIP\n"
    "        : YYCURSOR \" += 1;\"\n"
    "    ) nl;\n"
    "\n"
    "code:yybackup =\n"
    "    topindent (api.generic\n"
    "        ? YYBACKUP\n"
    "        : YYMARKER \" = \" YYCURSOR \";\"\n"
    "    ) nl;\n"
    "\n"
    "code:yybackupctx =\n"
    "    topindent (api.generic\n"
    "        ? YYBACKUPCTX\n"
    "        : YYCTXMARKER \" = \" YYCURSOR \";\"\n"
    "    ) nl;\n"
    "\n"
    "code:yyskip_yypeek =\n"
    "    topindent (code_model.recursive_functions ? YYCTYPE \" \") yych \" = \"\n"
    "        (cast ? \"@intCast(\") \"*++\" YYCURSOR (cast ? \")\") \";\" nl;\n"
    "\n"
    "code:yypeek_yyskip =\n"
    "    topindent (code_model.recursive_functions ? YYCTYPE \" \") yych \" = \"\n"
    "        (cast ? \"@intCast(\") \"*\" YYCURSOR \"++\" (cast ? \")\") \";\" nl;\n"
    "\n"
    "code:yyskip_yybackup =\n"
    "    topindent YYMARKER \" = ++\" YYCURSOR \";\" nl;\n"
    "\n"
    "code:yybackup_yyskip =\n"
    "    topindent YYMARKER \" = \" YYCURSOR \"++;\" nl;\n"
    "\n"
    "code:yybackup_yypeek =\n"
    "    topindent (code_model.recursive_functions ? YYCTYPE \" \") yych \" = \"\n"
    "        (cast ? \"@intCast(\") \"*(\" YYMARKER \" = \" YYCURSOR \")\" (cast ? \")\") \";\" nl;\n"
    "\n"
    "code:yyskip_yybackup_yypeek =\n"
    "    topindent (code_model.recursive_functions ? YYCTYPE \" \") yych \" = \"\n"
    "        (cast ? \"@intCast(\") \"*(\" YYMARKER \" = ++\" YYCURSOR \")\" (cast ? \")\") \";\" nl;\n"
    "\n"
    "code:yybackup_yypeek_yyskip =\n"
    "    topindent (code_model.recursive_functions ? YYCTYPE \" \") yych \" = \"\n"
    "        (cast ? \"@intCast(\") \"*(\" YYMARKER \" = \" YYCURSOR \"++\" (cast ? \")\") \");\" nl;\n"
    "\n"
    "code:yyrestore =\n"
    "    topindent (api.generic\n"
    "        ? YYRESTORE\n"
    "        : YYCURSOR \" = \" YYMARKER \";\"\n"
    "    ) nl;\n"
    "\n"
    "code:yyrestorectx =\n"
    "    topindent (api.generic\n"
    "        ? YYRESTORECTX\n"
    "        : YYCURSOR \" = \" YYCTXMARKER \";\"\n"
    "    ) nl;\n"
    "\n"
    "code:yyrestoretag =\n"
    "    topindent (api.generic\n"
    "        ? YYRESTORETAG\n"
    "        : YYCURSOR \" = \" tag \";\"\n"
    "    ) nl;\n"
    "\n"
    "code:yyshift =\n"
    "    topindent (api.generic\n"
    "        ? YYSHIFT\n"
    "        : YYCURSOR \" -= \" offset \";\"\n"
    "    ) nl;\n"
    "\n"
    "code:yyshiftstag =\n"
    "    topindent (nested ? \"if (\" tag \" != \" neg \") \")\n"
    "    (api.generic\n"
    "        ? YYSHIFTSTAG\n"
    "        : tag \" -= \" offset \";\"\n"
    "    ) nl;\n"
    "\n"
    "code:yyshiftmtag =\n"
    "    topindent YYSHIFTMTAG nl;\n"
    "\n"
    "code:yystagp =\n"
    "    topindent (api.generic\n"
    "        ? YYSTAGP\n"
    "        : tag \" = \" YYCURSOR \";\"\n"
    "    ) nl;\n"
    "\n"
    "code:yymtagp =\n"
    "    topindent YYMTAGP nl;\n"
    "\n"
    "code:yystagn =\n"
    "    topindent (api.generic\n"
    "        ? YYSTAGN\n"
    "        : tag \" = \" neg \";\"\n"
    "    ) nl;\n"
    "\n"
    "code:yymtagn =\n"
    "    topindent YYMTAGN nl;\n"
    "\n"
    "code:yycopystag =\n"
    "    topindent (api.generic\n"
    "        ? YYCOPYSTAG\n"
    "        : lhs \" = \" rhs \";\"\n"
    "    ) nl;\n"
    "\n"
    "code:yycopymtag =\n"
    "    topindent (api.generic\n"
    "        ? YYCOPYMTAG\n"
    "        : lhs \" = \" rhs \";\"\n"
    "    ) nl;\n"
    "\n"
    "code:yygetaccept =\n"
    "    (api.generic\n"
    "        ? YYGETACCEPT\n"
    "        : (api.record & (storable_state | code_model.recursive_functions) ? yyrecord \".\") var);\n"
    "\n"
    "code:yysetaccept =\n"
    "    topindent (api.generic\n"
    "        ? YYSETACCEPT\n"
    "        : (api.record & (storable_state | code_model.recursive_functions) ? yyrecord \".\")\n"
    "            var \" = \" val \";\"\n"
    "    ) nl;\n"
    "\n"
    "code:yygetcond =\n"
    "    (api.generic\n"
    "        ? YYGETCOND\n"
    "        : (api.record ? yyrecord \".\") var);\n"
    "\n"
    "code:yysetcond =\n"
    "    topindent (api.generic\n"
    "        ? YYSETCOND\n"
    "        : (api.record ? yyrecord \".\") var \" = \" val \";\"\n"
    "    ) nl;\n"
    "\n"
    "code:yygetstate =\n"
    "    (api.generic\n"
    "        ? YYGETSTATE\n"
    "        : (api.record ? yyrecord \".\") var);\n"
    "\n"
    "code:yysetstate =\n"
    "    topindent (api.generic\n"
    "        ? YYSETSTATE\n"
    "        : (api.record ? yyrecord \".\" var) \" = \" val \";\"\n"
    "    ) nl;\n"
    "\n"
    "code:yylessthan =\n"
    "    (api.generic\n"
    "        ? YYLESSTHAN\n"
    "        : (many\n"
    "            ? \"(\" YYLIMIT \" - \" YYCURSOR \") < \" need\n"
    "            : YYLIMIT \" <= \" YYCURSOR));\n"
    ;
