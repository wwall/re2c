// Code generated by re2c, DO NOT EDIT.
//go:generate re2go $INPUT -o $OUTPUT -i
package main

import "errors"

const u32Limit uint64 = 1<<32
var (
	eSyntax   = errors.New("syntax error")
	eOverflow = errors.New("overflow error")
)

func parse_u32(yyinput string) (uint32, error) {
	var yycursor, yymarker int
	result := uint64(0)

	add := func(base uint64, offset byte) {
		result = result * base + uint64(yyinput[yycursor-1] - offset)
		if result >= u32Limit {
			result = u32Limit
		}
	}

	
{
	var yych byte
	yych = yyinput[yycursor]
	switch (yych) {
	case '0':
		goto yy2
	case '1','2','3','4','5','6','7','8','9':
		goto yy4
	default:
		goto yy1
	}
yy1:
	yycursor += 1
	{ goto err }
yy2:
	yycursor += 1
	yymarker = yycursor
	yych = yyinput[yycursor]
	switch (yych) {
	case 'B':
		fallthrough
	case 'b':
		goto yy5
	case 'X':
		fallthrough
	case 'x':
		goto yy7
	default:
		goto yy3
	}
yy3:
	{ goto oct }
yy4:
	yycursor += 1
	yycursor -= 1
	{ goto dec }
yy5:
	yycursor += 1
	yych = yyinput[yycursor]
	switch (yych) {
	case '0','1':
		goto yy8
	default:
		goto yy6
	}
yy6:
	yycursor = yymarker
	goto yy3
yy7:
	yycursor += 1
	yych = yyinput[yycursor]
	switch (yych) {
	case '0','1','2','3','4','5','6','7','8','9':
		fallthrough
	case 'A','B','C','D','E','F':
		fallthrough
	case 'a','b','c','d','e','f':
		goto yy9
	default:
		goto yy6
	}
yy8:
	yycursor += 1
	yycursor -= 1
	{ goto bin }
yy9:
	yycursor += 1
	yycursor -= 1
	{ goto hex }
}

bin:
	
{
	var yych byte
	yych = yyinput[yycursor]
	switch (yych) {
	case 0x00:
		goto yy11
	case '0','1':
		goto yy13
	default:
		goto yy12
	}
yy11:
	yycursor += 1
	{ goto end }
yy12:
	yycursor += 1
	{ goto err }
yy13:
	yycursor += 1
	{ add(2, '0'); goto bin }
}

oct:
	
{
	var yych byte
	yych = yyinput[yycursor]
	switch (yych) {
	case 0x00:
		goto yy15
	case '0','1','2','3','4','5','6','7':
		goto yy17
	default:
		goto yy16
	}
yy15:
	yycursor += 1
	{ goto end }
yy16:
	yycursor += 1
	{ goto err }
yy17:
	yycursor += 1
	{ add(8, '0'); goto oct }
}

dec:
	
{
	var yych byte
	yych = yyinput[yycursor]
	switch (yych) {
	case 0x00:
		goto yy19
	case '0','1','2','3','4','5','6','7','8','9':
		goto yy21
	default:
		goto yy20
	}
yy19:
	yycursor += 1
	{ goto end }
yy20:
	yycursor += 1
	{ goto err }
yy21:
	yycursor += 1
	{ add(10, '0'); goto dec }
}

hex:
	
{
	var yych byte
	yych = yyinput[yycursor]
	switch (yych) {
	case 0x00:
		goto yy23
	case '0','1','2','3','4','5','6','7','8','9':
		goto yy25
	case 'A','B','C','D','E','F':
		goto yy26
	case 'a','b','c','d','e','f':
		goto yy27
	default:
		goto yy24
	}
yy23:
	yycursor += 1
	{ goto end }
yy24:
	yycursor += 1
	{ goto err }
yy25:
	yycursor += 1
	{ add(16, '0');    goto hex }
yy26:
	yycursor += 1
	{ add(16, 'A'-10); goto hex }
yy27:
	yycursor += 1
	{ add(16, 'a'-10); goto hex }
}

end:
	if result < u32Limit {
		return uint32(result), nil
	} else {
		return 0, eOverflow
	}
err:
	return 0, eSyntax
}

func main() {
	test := func(num uint32, str string, err error) {
		if n, e := parse_u32(str); !(n == num && e == err) {
			panic("error")
		}
	}
	test(1234567890, "1234567890\000", nil)
	test(13, "0b1101\000", nil)
	test(0x7fe, "0x007Fe\000", nil)
	test(0644, "0644\000", nil)
	test(0, "9999999999\000", eOverflow)
	test(0, "123??\000", eSyntax)
}
