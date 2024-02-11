/* Generated by re2c */
// re2rust $INPUT -o $OUTPUT --recursive-functions

use std::fs::File;
use std::io::{Read, Write};

const YYMAXFILL: usize = 1;

const BUFSIZE: usize = 4096;

struct State {
    file: File,
    buf: [u8; BUFSIZE],
    lim: usize,
    cur: usize,
    mar: usize,
    tok: usize,
    eof: bool,
    count: isize
}

#[derive(PartialEq)]
enum Fill { Ok, Eof, LongLexeme }

fn fill(st: &mut State, need: usize) -> Fill {
    if st.eof { return Fill::Eof; }

    // Error: lexeme too long. In real life can reallocate a larger buffer.
    if st.tok < need { return Fill::LongLexeme; }

    // Shift buffer contents (discard everything up to the current token).
    st.buf.copy_within(st.tok..st.lim, 0);
    st.lim -= st.tok;
    st.cur -= st.tok;
    st.mar = st.mar.overflowing_sub(st.tok).0; // underflows if marker is unused
    st.tok = 0;

    // Fill free space at the end of buffer with new data from file.
    let n = match st.file.read(&mut st.buf[st.lim..BUFSIZE - YYMAXFILL]) {
        Ok(n) => n,
        Err(why) => panic!("cannot read from file: {}", why)
    };
    st.lim += n;

    // If read zero characters, this is end of input => add zero padding
    // so that the lexer can access characters at the end of buffer.
    if n == 0 {
        st.eof = true;
        for i in 0..YYMAXFILL { st.buf[st.lim + i] = 0; }
        st.lim += YYMAXFILL;
    }

    return Fill::Ok;
}

fn lex_loop(st: &mut State) -> isize {
    st.tok = st.cur;
    return lex(st);
}


fn yy0(_st: &mut State) -> isize {
	if _st.lim - _st.cur < 1 {
		if fill(_st, 1) != Fill::Ok { return -1; }
	}
	let yych = unsafe {*_st.buf.get_unchecked(_st.cur)};
	_st.cur += 1;
	match yych {
		0x00 => yy1(_st),
		0x20 => yy3(_st),
		0x27 => yy5(_st),
		_ => yy2(_st),
	}
}

fn yy1(_st: &mut State) -> isize {
	{
        // Check that it is the sentinel, not some unexpected null.
        return if _st.tok == _st.lim - YYMAXFILL { _st.count } else { -1 }
    }
}

fn yy2(_st: &mut State) -> isize {
	{ return -1; }
}

fn yy3(_st: &mut State) -> isize {
	if _st.lim - _st.cur < 1 {
		if fill(_st, 1) != Fill::Ok { return -1; }
	}
	let yych = unsafe {*_st.buf.get_unchecked(_st.cur)};
	match yych {
		0x20 => {
			_st.cur += 1;
			yy3(_st)
		}
		_ => yy4(_st),
	}
}

fn yy4(_st: &mut State) -> isize {
	{ return lex_loop(_st); }
}

fn yy5(_st: &mut State) -> isize {
	if _st.lim - _st.cur < 1 {
		if fill(_st, 1) != Fill::Ok { return -1; }
	}
	let yych = unsafe {*_st.buf.get_unchecked(_st.cur)};
	_st.cur += 1;
	match yych {
		0x27 => yy6(_st),
		0x5C => yy7(_st),
		_ => yy5(_st),
	}
}

fn yy6(_st: &mut State) -> isize {
	{ _st.count += 1; return lex_loop(_st); }
}

fn yy7(_st: &mut State) -> isize {
	if _st.lim - _st.cur < 1 {
		if fill(_st, 1) != Fill::Ok { return -1; }
	}
	_st.cur += 1;
	yy5(_st)
}

fn lex(_st: &mut State) -> isize {
	yy0(_st)
}



fn main() {
    let fname = "input";
    let content = b"'qu\0tes' 'are' 'fine: \\'' ";

    // Prepare input file: a few times the size of the buffer, containing
    // strings with zeroes and escaped quotes.
    match File::create(fname) {
        Err(why) => panic!("cannot open {}: {}", fname, why),
        Ok(mut file) => match file.write_all(&content.repeat(BUFSIZE)) {
            Err(why) => panic!("cannot write to {}: {}", fname, why),
            Ok(_) => {}
        }
    };
    let count = 3 * BUFSIZE; // number of quoted strings written to file

    // Reopen input file for reading.
    let file = match File::open(fname) {
        Err(why) => panic!("cannot read file {}: {}", fname, why),
        Ok(file) => file,
    };

    // Initialize lexer state: all offsets are at the end of buffer.
    // This immediately triggers YYFILL, as the YYLESSTHAN condition is true.
    let lim = BUFSIZE - YYMAXFILL;
    let mut st = State {
        file: file,
        buf: [0; BUFSIZE],
        lim: lim,
        cur: lim,
        mar: lim,
        tok: lim,
        eof: false,
        count: 0
    };

    // Run the lexer.
    assert_eq!(lex_loop(&mut st), count as isize);

    // Cleanup: remove input file.
    match std::fs::remove_file(fname) {
        Err(why) => panic!("cannot remove {}: {}", fname, why),
        Ok(_) => {}
    }
}
