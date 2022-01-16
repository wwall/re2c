// Code generated by re2c, DO NOT EDIT.
//line "go/eof/02_bounds_checking.re":1
//go:generate re2go $INPUT -o $OUTPUT
package main

import "strings"

//line "go/eof/02_bounds_checking.go":9
var YYMAXFILL int = 1
//line "go/eof/02_bounds_checking.re":6


// Expects YYMAXFILL-padded string.
func lex(str string) int {
	// Pad string with YYMAXFILL zeroes at the end.
	buf := str + strings.Repeat("\000", YYMAXFILL)

	var cur int
	lim := len(buf)
	count := 0

	for { 
//line "go/eof/02_bounds_checking.go":24
{
	var yych byte
	if (lim - cur < 1) {
		return -1
	}
	yych = buf[cur]
	switch (yych) {
	case 0x00:
		goto yy1
	case ' ':
		goto yy3
	case '\'':
		goto yy5
	default:
		goto yy2
	}
yy1:
	cur += 1
//line "go/eof/02_bounds_checking.re":26
	{
			// Check that it is the sentinel, not some unexpected null.
			if cur - 1 == len(str) { return count } else { return -1 }
		}
//line "go/eof/02_bounds_checking.go":48
yy2:
	cur += 1
//line "go/eof/02_bounds_checking.re":32
	{ return -1 }
//line "go/eof/02_bounds_checking.go":53
yy3:
	cur += 1
	if (lim - cur < 1) {
		return -1
	}
	yych = buf[cur]
	switch (yych) {
	case ' ':
		goto yy3
	default:
		goto yy4
	}
yy4:
//line "go/eof/02_bounds_checking.re":31
	{ continue }
//line "go/eof/02_bounds_checking.go":69
yy5:
	cur += 1
	if (lim - cur < 1) {
		return -1
	}
	yych = buf[cur]
	switch (yych) {
	case '\'':
		goto yy6
	case '\\':
		goto yy7
	default:
		goto yy5
	}
yy6:
	cur += 1
//line "go/eof/02_bounds_checking.re":30
	{ count += 1; continue }
//line "go/eof/02_bounds_checking.go":88
yy7:
	cur += 1
	if (lim - cur < 1) {
		return -1
	}
	goto yy5
}
//line "go/eof/02_bounds_checking.re":33

	}
}

func main() {
	assert_eq := func(x, y int) { if x != y { panic("error") } }
	assert_eq(lex(""), 0)
	assert_eq(lex("'qu\000tes' 'are' 'fine: \\'' "), 3)
	assert_eq(lex("'unterminated\\'"), -1)
	assert_eq(lex("'unexpected \000 null\\'"), -1)
}
