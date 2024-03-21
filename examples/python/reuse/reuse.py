# Generated by re2c
# re2py $INPUT -o $OUTPUT --input-encoding utf8

# This example supports multiple input encodings: UTF-8 and UTF-32.
# Both lexers are generated from the same rules block, and the use
# blocks add only encoding-specific configurations.


def lex_utf8(str):
    cur = 0
    
    yystate = 0
    while True:
        match yystate:
            case 0:
                yych = str[cur]
                cur += 1
                match yych:
                    case 0xE2:
                        yystate = 3
                        continue
                    case _:
                        yystate = 1
                        continue
            case 1:
                yystate = 2
                continue
            case 2:
                return None
            case 3:
                mar = cur
                yych = str[cur]
                match yych:
                    case 0x88:
                        cur += 1
                        yystate = 4
                        continue
                    case _:
                        yystate = 2
                        continue
            case 4:
                yych = str[cur]
                match yych:
                    case 0x80:
                        cur += 1
                        yystate = 6
                        continue
                    case _:
                        yystate = 5
                        continue
            case 5:
                cur = mar
                yystate = 2
                continue
            case 6:
                yych = str[cur]
                match yych:
                    case 0x78:
                        cur += 1
                        yystate = 7
                        continue
                    case _:
                        yystate = 5
                        continue
            case 7:
                yych = str[cur]
                match yych:
                    case 0x20:
                        cur += 1
                        yystate = 8
                        continue
                    case _:
                        yystate = 5
                        continue
            case 8:
                yych = str[cur]
                match yych:
                    case 0xE2:
                        cur += 1
                        yystate = 9
                        continue
                    case _:
                        yystate = 5
                        continue
            case 9:
                yych = str[cur]
                match yych:
                    case 0x88:
                        cur += 1
                        yystate = 10
                        continue
                    case _:
                        yystate = 5
                        continue
            case 10:
                yych = str[cur]
                match yych:
                    case 0x83:
                        cur += 1
                        yystate = 11
                        continue
                    case _:
                        yystate = 5
                        continue
            case 11:
                yych = str[cur]
                match yych:
                    case 0x79:
                        cur += 1
                        yystate = 12
                        continue
                    case _:
                        yystate = 5
                        continue
            case 12:
                return cur
            case _:
                raise "internal lexer error"


def lex_utf32(str):
    cur = 0
    
    yystate = 0
    while True:
        match yystate:
            case 0:
                yych = str[cur]
                cur += 1
                if yych == 0x00002200:
                    yystate = 2
                    continue
                yystate = 1
                continue
            case 1:
                return None
            case 2:
                mar = cur
                yych = str[cur]
                if yych != 0x00000078:
                    yystate = 1
                    continue
                cur += 1
                yych = str[cur]
                if yych == 0x00000020:
                    cur += 1
                    yystate = 4
                    continue
                yystate = 3
                continue
            case 3:
                cur = mar
                yystate = 1
                continue
            case 4:
                yych = str[cur]
                if yych != 0x00002203:
                    yystate = 3
                    continue
                cur += 1
                yych = str[cur]
                if yych != 0x00000079:
                    yystate = 3
                    continue
                cur += 1
                return cur
            case _:
                raise "internal lexer error"


s8 = [0xe2, 0x88, 0x80, 0x78, 0x20, 0xe2, 0x88, 0x83, 0x79]
assert lex_utf8(s8) == len(s8)

s32 = [0x2200, 0x78, 0x20, 0x2203, 0x79]
assert lex_utf32(s32) == len(s32)
