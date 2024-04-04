# Generated by re2c
# re2py $INPUT -o $OUTPUT

from collections import namedtuple
from enum import Enum
import os

NONE = -1
BUFSIZE = 4096

SemVer = namedtuple('SemVer', 'major minor patch')

class State:
    def __init__(self, fname):
        self.file = open(fname, "rb")
        self.buf = bytearray(BUFSIZE)
        self.lim = BUFSIZE - 1 # exclude terminating null
        self.cur = self.lim
        self.mar = self.lim
        self.tok = self.lim
        self.eof = False
        
        self.yyt1 = NONE
        self.yyt2 = NONE
        self.yyt3 = NONE

    def __del__(self):
        self.file.close()

class Status(Enum):
    OK = 0
    EOF = 1
    LONG_LEXEME = 2

def fill(st):
    if st.eof:
        return Status.EOF

    # Error: lexeme too long. In real life could reallocate a larger buffer.
    if st.tok < 1:
        return Status.LONG_LEXEME

    # Shift buffer contents (discard everything up to the current token).
    st.buf = st.buf[st.tok:st.lim]
    st.cur -= st.tok;
    st.mar -= st.tok;
    st.lim -= st.tok;
    st.tok = 0;

    # Fill free space at the end of buffer with new data from file.
    bytes = st.file.read(BUFSIZE - st.lim - 1) # -1 for sentinel
    if not bytes:
        st.eof = True # end of file
    else:
        st.lim += len(bytes);
        st.buf += bytes

    st.buf += b'\0' # append sentinel

    return Status.OK

def lex(st, count):
    vers = []
    while True:
        st.tok = st.cur
        
        yystate = 0
        while True:
            match yystate:
                case 0:
                    yych = st.buf[st.cur]
                    if yych <= 0x00:
                        if st.cur >= st.lim:
                            if fill(st) == Status.OK:
                                yystate = 0
                                continue
                            yystate = 11
                            continue
                        st.cur += 1
                        yystate = 1
                        continue
                    if yych <= 0x2F:
                        st.cur += 1
                        yystate = 1
                        continue
                    if yych <= 0x39:
                        st.cur += 1
                        yystate = 3
                        continue
                    st.cur += 1
                    yystate = 1
                    continue
                case 1:
                    yystate = 2
                    continue
                case 2:
                    return None
                case 3:
                    st.mar = st.cur
                    yych = st.buf[st.cur]
                    if yych <= 0x2E:
                        if yych <= 0x00:
                            if st.cur >= st.lim:
                                if fill(st) == Status.OK:
                                    yystate = 3
                                    continue
                            yystate = 2
                            continue
                        if yych <= 0x2D:
                            yystate = 2
                            continue
                        st.cur += 1
                        yystate = 4
                        continue
                    else:
                        if yych <= 0x2F:
                            yystate = 2
                            continue
                        if yych <= 0x39:
                            st.cur += 1
                            yystate = 6
                            continue
                        yystate = 2
                        continue
                case 4:
                    yych = st.buf[st.cur]
                    if yych <= 0x00:
                        if st.cur >= st.lim:
                            if fill(st) == Status.OK:
                                yystate = 4
                                continue
                        yystate = 5
                        continue
                    if yych <= 0x2F:
                        yystate = 5
                        continue
                    if yych <= 0x39:
                        st.yyt1 = st.cur
                        st.cur += 1
                        yystate = 7
                        continue
                    yystate = 5
                    continue
                case 5:
                    st.cur = st.mar
                    yystate = 2
                    continue
                case 6:
                    yych = st.buf[st.cur]
                    if yych <= 0x2E:
                        if yych <= 0x00:
                            if st.cur >= st.lim:
                                if fill(st) == Status.OK:
                                    yystate = 6
                                    continue
                            yystate = 5
                            continue
                        if yych <= 0x2D:
                            yystate = 5
                            continue
                        st.cur += 1
                        yystate = 4
                        continue
                    else:
                        if yych <= 0x2F:
                            yystate = 5
                            continue
                        if yych <= 0x39:
                            st.cur += 1
                            yystate = 6
                            continue
                        yystate = 5
                        continue
                case 7:
                    yych = st.buf[st.cur]
                    if yych <= 0x2D:
                        if yych <= 0x00:
                            if st.cur >= st.lim:
                                if fill(st) == Status.OK:
                                    yystate = 7
                                    continue
                            yystate = 5
                            continue
                        if yych != 0x0A:
                            yystate = 5
                            continue
                        st.yyt2 = st.cur
                        st.yyt3 = NONE
                        st.cur += 1
                        yystate = 8
                        continue
                    else:
                        if yych <= 0x2E:
                            st.yyt2 = st.cur
                            st.cur += 1
                            yystate = 9
                            continue
                        if yych <= 0x2F:
                            yystate = 5
                            continue
                        if yych <= 0x39:
                            st.cur += 1
                            yystate = 7
                            continue
                        yystate = 5
                        continue
                case 8:
                    t2 = st.yyt1
                    t3 = st.yyt2
                    t4 = st.yyt3
                    t1 = st.yyt1
                    t1 += -1
                    major = int(st.buf[st.tok:t1]);
                    minor = int(st.buf[t2:t3]);
                    patch = int(st.buf[t4:st.cur - 1]) if t4 != NONE else 0
                    vers.append(SemVer(major, minor, patch))
                    break
                case 9:
                    yych = st.buf[st.cur]
                    if yych <= 0x00:
                        if st.cur >= st.lim:
                            if fill(st) == Status.OK:
                                yystate = 9
                                continue
                        yystate = 5
                        continue
                    if yych <= 0x2F:
                        yystate = 5
                        continue
                    if yych >= 0x3A:
                        yystate = 5
                        continue
                    st.yyt3 = st.cur
                    st.cur += 1
                    yystate = 10
                    continue
                case 10:
                    yych = st.buf[st.cur]
                    if yych <= 0x0A:
                        if yych <= 0x00:
                            if st.cur >= st.lim:
                                if fill(st) == Status.OK:
                                    yystate = 10
                                    continue
                            yystate = 5
                            continue
                        if yych <= 0x09:
                            yystate = 5
                            continue
                        st.cur += 1
                        yystate = 8
                        continue
                    else:
                        if yych <= 0x2F:
                            yystate = 5
                            continue
                        if yych <= 0x39:
                            st.cur += 1
                            yystate = 10
                            continue
                        yystate = 5
                        continue
                case 11:
                    return vers
                case _:
                    raise "internal lexer error"


def main():
    fname = "input"
    verstr = b"1.22.333\n"
    expect = [SemVer(1, 22, 333)] * BUFSIZE

    # Prepare input file.
    f = open(fname, "wb")
    for i in range(BUFSIZE):
        f.write(verstr)
    f.close()

    # Run lexer on the prepared file.
    st = State(fname)
    assert lex(st, 0) == expect

    # Cleanup.
    os.remove(fname)

if __name__ == '__main__':
    main()
