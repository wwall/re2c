/* Generated by re2c */
// re2rust $INPUT -o $OUTPUT

use std::fs::File;
use std::io::{Read, Write};

const BUFSIZE: usize = 4096;

struct State {
    file: File,
    buf: [u8; BUFSIZE],
    lim: usize,
    cur: usize,
    mar: usize,
    tok: usize,
    eof: bool,
}

#[derive(PartialEq)]
enum Fill { Ok, Eof, LongLexeme }

fn fill(st: &mut State) -> Fill {
    if st.eof { return Fill::Eof; }

    // Error: lexeme too long. In real life could reallocate a larger buffer.
    if st.tok < 1 { return Fill::LongLexeme; }

    // Shift buffer contents (discard everything up to the current token).
    st.buf.copy_within(st.tok..st.lim, 0);
    st.lim -= st.tok;
    st.cur -= st.tok;
    st.mar = st.mar.overflowing_sub(st.tok).0; // may underflow if marker is unused
    st.tok = 0;

    // Fill free space at the end of buffer with new data from file.
    match st.file.read(&mut st.buf[st.lim..BUFSIZE - 1]) { // -1 for sentinel
        Ok(n) => {
            st.lim += n;
            st.eof = n == 0; // end of file
            st.buf[st.lim] = 0; // append sentinel
        }
        Err(why) => panic!("cannot read from file: {}", why)
    }

    return Fill::Ok;
}

fn lex(st: &mut State) -> isize {
    let mut count: isize = 0;

    'lex: loop {
        st.tok = st.cur;
    
{
	#[allow(unused_assignments)]
	let mut yych : u8 = 0;
	let mut yystate : usize = 0;
	'yyl: loop {
		match yystate {
			0 => {
				yych = unsafe {*st.buf.get_unchecked(st.cur)};
				match yych {
					0x20 => {
						st.cur += 1;
						yystate = 3;
						continue 'yyl;
					}
					0x27 => {
						st.cur += 1;
						yystate = 5;
						continue 'yyl;
					}
					_ => {
						if st.cur >= st.lim {
							if fill(st) == Fill::Ok {
								yystate = 0;
								continue 'yyl;
							}
							yystate = 10;
							continue 'yyl;
						}
						st.cur += 1;
						yystate = 1;
						continue 'yyl;
					}
				}
			}
			1 => {
				yystate = 2;
				continue 'yyl;
			}
			2 => { return -1; },
			3 => {
				yych = unsafe {*st.buf.get_unchecked(st.cur)};
				match yych {
					0x20 => {
						st.cur += 1;
						yystate = 3;
						continue 'yyl;
					}
					_ => {
						if st.cur >= st.lim {
							if fill(st) == Fill::Ok {
								yystate = 3;
								continue 'yyl;
							}
						}
						yystate = 4;
						continue 'yyl;
					}
				}
			}
			4 => { continue 'lex; },
			5 => {
				st.mar = st.cur;
				yych = unsafe {*st.buf.get_unchecked(st.cur)};
				if yych >= 0x01 {
					yystate = 7;
					continue 'yyl;
				}
				if st.cur >= st.lim {
					if fill(st) == Fill::Ok {
						yystate = 5;
						continue 'yyl;
					}
					yystate = 2;
					continue 'yyl;
				}
				st.cur += 1;
				yystate = 6;
				continue 'yyl;
			}
			6 => {
				yych = unsafe {*st.buf.get_unchecked(st.cur)};
				yystate = 7;
				continue 'yyl;
			}
			7 => {
				match yych {
					0x27 => {
						st.cur += 1;
						yystate = 8;
						continue 'yyl;
					}
					0x5C => {
						st.cur += 1;
						yystate = 9;
						continue 'yyl;
					}
					_ => {
						if st.cur >= st.lim {
							if fill(st) == Fill::Ok {
								yystate = 6;
								continue 'yyl;
							}
							yystate = 11;
							continue 'yyl;
						}
						st.cur += 1;
						yystate = 6;
						continue 'yyl;
					}
				}
			}
			8 => { count += 1; continue 'lex; },
			9 => {
				yych = unsafe {*st.buf.get_unchecked(st.cur)};
				if yych <= 0x00 {
					if st.cur >= st.lim {
						if fill(st) == Fill::Ok {
							yystate = 9;
							continue 'yyl;
						}
						yystate = 11;
						continue 'yyl;
					}
					st.cur += 1;
					yystate = 6;
					continue 'yyl;
				}
				st.cur += 1;
				yystate = 6;
				continue 'yyl;
			}
			10 => { return count; },
			11 => {
				st.cur = st.mar;
				yystate = 2;
				continue 'yyl;
			}
			_ => {
				panic!("internal lexer error");
			}
		}
	}
}
}
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
    let lim = BUFSIZE - 1;
    let mut st = State {
        file: file,
        // Sentinel (at `lim` offset) is set to null, which triggers YYFILL.
        buf: [0; BUFSIZE],
        lim: lim,
        cur: lim,
        mar: lim,
        tok: lim,
        eof: false,
    };

    // Run the lexer.
    assert_eq!(lex(&mut st), count as isize);

    // Cleanup: remove input file.
    match std::fs::remove_file(fname) {
        Err(why) => panic!("cannot remove {}: {}", fname, why),
        Ok(_) => {}
    }
}
