// Code generated by re2c, DO NOT EDIT.
//line "go/reuse/reuse.re":1
//go:generate re2go $INPUT -o $OUTPUT --input-encoding utf8
package main

// This example supports multiple input encodings: UTF-8 and UTF-32.
// Both lexers are generated from the same rules block, and the use
// blocks add only encoding-specific configurations.
//line "go/reuse/reuse.re":13


func lexUTF8(yyinput []uint8) int {
	var yycursor, yymarker int
	
//line "go/reuse/reuse.go":16
{
	var yych uint8
	yych = yyinput[yycursor]
	switch (yych) {
	case 0xE2:
		goto yy3
	default:
		goto yy1
	}
yy1:
	yycursor += 1
yy2:
//line "go/reuse/reuse.re":12
	{ return 1; }
//line "go/reuse/reuse.go":31
yy3:
	yycursor += 1
	yymarker = yycursor
	yych = yyinput[yycursor]
	switch (yych) {
	case 0x88:
		goto yy4
	default:
		goto yy2
	}
yy4:
	yycursor += 1
	yych = yyinput[yycursor]
	switch (yych) {
	case 0x80:
		goto yy6
	default:
		goto yy5
	}
yy5:
	yycursor = yymarker
	goto yy2
yy6:
	yycursor += 1
	yych = yyinput[yycursor]
	switch (yych) {
	case 'x':
		goto yy7
	default:
		goto yy5
	}
yy7:
	yycursor += 1
	yych = yyinput[yycursor]
	switch (yych) {
	case ' ':
		goto yy8
	default:
		goto yy5
	}
yy8:
	yycursor += 1
	yych = yyinput[yycursor]
	switch (yych) {
	case 0xE2:
		goto yy9
	default:
		goto yy5
	}
yy9:
	yycursor += 1
	yych = yyinput[yycursor]
	switch (yych) {
	case 0x88:
		goto yy10
	default:
		goto yy5
	}
yy10:
	yycursor += 1
	yych = yyinput[yycursor]
	switch (yych) {
	case 0x83:
		goto yy11
	default:
		goto yy5
	}
yy11:
	yycursor += 1
	yych = yyinput[yycursor]
	switch (yych) {
	case 'y':
		goto yy12
	default:
		goto yy5
	}
yy12:
	yycursor += 1
//line "go/reuse/reuse.re":11
	{ return 0; }
//line "go/reuse/reuse.go":112
}
//line "go/reuse/reuse.re":20

}

func lexUTF32(yyinput []uint32) int {
	var yycursor, yymarker int
	
//line "go/reuse/reuse.go":121
{
	var yych uint32
	yych = yyinput[yycursor]
	if (yych == 0x00002200) {
		goto yy15
	}
	yycursor += 1
yy14:
//line "go/reuse/reuse.re":12
	{ return 1; }
//line "go/reuse/reuse.go":132
yy15:
	yycursor += 1
	yymarker = yycursor
	yych = yyinput[yycursor]
	if (yych != 'x') {
		goto yy14
	}
	yycursor += 1
	yych = yyinput[yycursor]
	if (yych == ' ') {
		goto yy17
	}
yy16:
	yycursor = yymarker
	goto yy14
yy17:
	yycursor += 1
	yych = yyinput[yycursor]
	if (yych != 0x00002203) {
		goto yy16
	}
	yycursor += 1
	yych = yyinput[yycursor]
	if (yych != 'y') {
		goto yy16
	}
	yycursor += 1
//line "go/reuse/reuse.re":11
	{ return 0; }
//line "go/reuse/reuse.go":162
}
//line "go/reuse/reuse.re":28

}

func main() {
	assert_eq := func(x, y int) { if x != y { panic("error") } }
	assert_eq(lexUTF8([]uint8{0xe2, 0x88, 0x80, 0x78, 0x20, 0xe2, 0x88, 0x83, 0x79}), 0)
	assert_eq(lexUTF32([]uint32{0x2200, 0x78, 0x20, 0x2203, 0x79}), 0)
}
