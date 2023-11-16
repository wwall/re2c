/* Generated by re2c */
// re2rust $INPUT -o $OUTPUT -c

const YYC_INIT: usize = 0;
const YYC_BIN: usize = 10;
const YYC_OCT: usize = 13;
const YYC_DEC: usize = 16;
const YYC_HEX: usize = 19;


const ERROR: u64 = std::u32::MAX as u64 + 1; // overflow

// Add digit with the given base, checking for overflow.
fn add(num: &mut u64, str: &[u8], cur: usize, offs: u8, base: u64) {
    let digit = unsafe { str.get_unchecked(cur - 1) } - offs;
    *num = std::cmp::min(*num * base + digit as u64, ERROR);
}

fn parse_u32(str: &[u8]) -> Option<u32> {
    assert_eq!(str.last(), Some(&0)); // expect null-terminated input

    let (mut cur, mut mar) = (0, 0);
    let mut cond = YYC_INIT;
    let mut num = 0u64; // Store number in u64 to simplify overflow checks.

    'lex: loop {
{
	#[allow(unused_assignments)]
	let mut yych : u8 = 0;
	let mut yystate : usize = cond;
	'yyl: loop {
		match yystate {
			0 => {
				yych = unsafe {*str.get_unchecked(cur)};
				cur += 1;
				match yych {
					0x30 => {
						yystate = 2;
						continue 'yyl;
					}
					0x31 ..= 0x39 => {
						yystate = 4;
						continue 'yyl;
					}
					_ => {
						yystate = 1;
						continue 'yyl;
					}
				}
			}
			1 => { return None; }
			2 => {
				mar = cur;
				yych = unsafe {*str.get_unchecked(cur)};
				match yych {
					0x42 |
					0x62 => {
						cur += 1;
						yystate = 5;
						continue 'yyl;
					}
					0x58 |
					0x78 => {
						cur += 1;
						yystate = 7;
						continue 'yyl;
					}
					_ => {
						yystate = 3;
						continue 'yyl;
					}
				}
			}
			3 => {
				cond = YYC_OCT;
				yystate = YYC_OCT;
				continue 'yyl;
			}
			4 => {
				cur = (cur as isize + -1) as usize;
				cond = YYC_DEC;
				yystate = YYC_DEC;
				continue 'yyl;
			}
			5 => {
				yych = unsafe {*str.get_unchecked(cur)};
				match yych {
					0x30 ..= 0x31 => {
						cur += 1;
						yystate = 8;
						continue 'yyl;
					}
					_ => {
						yystate = 6;
						continue 'yyl;
					}
				}
			}
			6 => {
				cur = mar;
				yystate = 3;
				continue 'yyl;
			}
			7 => {
				yych = unsafe {*str.get_unchecked(cur)};
				match yych {
					0x30 ..= 0x39 |
					0x41 ..= 0x46 |
					0x61 ..= 0x66 => {
						cur += 1;
						yystate = 9;
						continue 'yyl;
					}
					_ => {
						yystate = 6;
						continue 'yyl;
					}
				}
			}
			8 => {
				cur = (cur as isize + -1) as usize;
				cond = YYC_BIN;
				yystate = YYC_BIN;
				continue 'yyl;
			}
			9 => {
				cur = (cur as isize + -1) as usize;
				cond = YYC_HEX;
				yystate = YYC_HEX;
				continue 'yyl;
			}
			10 => {
				yych = unsafe {*str.get_unchecked(cur)};
				cur += 1;
				match yych {
					0x30 ..= 0x31 => {
						yystate = 12;
						continue 'yyl;
					}
					_ => {
						yystate = 11;
						continue 'yyl;
					}
				}
			}
			11 => {
            return if num < ERROR { Some(num as u32) } else { None };
        }
			12 => { add(&mut num, str, cur, 48, 2);  continue 'lex; }
			13 => {
				yych = unsafe {*str.get_unchecked(cur)};
				cur += 1;
				match yych {
					0x30 ..= 0x37 => {
						yystate = 15;
						continue 'yyl;
					}
					_ => {
						yystate = 14;
						continue 'yyl;
					}
				}
			}
			14 => {
            return if num < ERROR { Some(num as u32) } else { None };
        }
			15 => { add(&mut num, str, cur, 48, 8);  continue 'lex; }
			16 => {
				yych = unsafe {*str.get_unchecked(cur)};
				cur += 1;
				match yych {
					0x30 ..= 0x39 => {
						yystate = 18;
						continue 'yyl;
					}
					_ => {
						yystate = 17;
						continue 'yyl;
					}
				}
			}
			17 => {
            return if num < ERROR { Some(num as u32) } else { None };
        }
			18 => { add(&mut num, str, cur, 48, 10); continue 'lex; }
			19 => {
				yych = unsafe {*str.get_unchecked(cur)};
				cur += 1;
				match yych {
					0x30 ..= 0x39 => {
						yystate = 21;
						continue 'yyl;
					}
					0x41 ..= 0x46 => {
						yystate = 22;
						continue 'yyl;
					}
					0x61 ..= 0x66 => {
						yystate = 23;
						continue 'yyl;
					}
					_ => {
						yystate = 20;
						continue 'yyl;
					}
				}
			}
			20 => {
            return if num < ERROR { Some(num as u32) } else { None };
        }
			21 => { add(&mut num, str, cur, 48, 16); continue 'lex; }
			22 => { add(&mut num, str, cur, 55, 16); continue 'lex; }
			23 => { add(&mut num, str, cur, 87, 16); continue 'lex; }
			_ => {
				panic!("internal lexer error")
			}
		}
	}
}
}
}

fn main() {
    assert_eq!(parse_u32(b"\0"), None);
    assert_eq!(parse_u32(b"1234567890\0"), Some(1234567890));
    assert_eq!(parse_u32(b"0b1101\0"), Some(13));
    assert_eq!(parse_u32(b"0x7Fe\0"), Some(2046));
    assert_eq!(parse_u32(b"0644\0"), Some(420));
    assert_eq!(parse_u32(b"9999999999\0"), None);
}
