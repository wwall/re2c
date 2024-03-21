# re2py $INPUT -o $OUTPUT --input-encoding utf8

# This example supports multiple input encodings: UTF-8 and UTF-32.
# Both lexers are generated from the same rules block, and the use
# blocks add only encoding-specific configurations.
/*!rules:re2c
    re2c:define:YYPEEK    = "str[cur]";
    re2c:define:YYSKIP    = "cur += 1";
    re2c:define:YYBACKUP  = "mar = cur";
    re2c:define:YYRESTORE = "cur = mar";
    re2c:yyfill:enable = 0;
    re2c:indent:top = 1;

    "∀x ∃y" { return cur }
    *       { return None }
*/

def lex_utf8(str):
    cur = 0
    /*!use:re2c
        re2c:encoding:utf8 = 1;
    */

def lex_utf32(str):
    cur = 0
    /*!use:re2c
        re2c:encoding:utf32 = 1;
    */

s8 = [0xe2, 0x88, 0x80, 0x78, 0x20, 0xe2, 0x88, 0x83, 0x79]
assert lex_utf8(s8) == len(s8)

s32 = [0x2200, 0x78, 0x20, 0x2203, 0x79]
assert lex_utf32(s32) == len(s32)
