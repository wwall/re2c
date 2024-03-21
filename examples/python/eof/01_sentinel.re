# re2py $INPUT -o $OUTPUT

# expect a null-terminated string
def lex(str):
    cur = 0
    count = 0

    while True:
    /*!re2c
        re2c:define:YYPEEK = "str[cur]";
        re2c:define:YYSKIP = "cur += 1";
        re2c:yyfill:enable = 0;
        re2c:indent:top = 2;

        *      { return -1 }
        [\x00] { return count }
        [ ]+   { break }
        [a-z]+ {
            count += 1
            break
        }
    */

assert lex(b"\0") == 0
assert lex(b"one two three\0") == 3
assert lex(b"f0ur\0") == -1
