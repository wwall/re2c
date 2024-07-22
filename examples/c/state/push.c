/* Generated by re2c */
#line 1 "c/state/push.re"
// re2c $INPUT -o $OUTPUT -f
#include <assert.h>
#include <stdio.h>
#include <string.h>

#define DEBUG 0
#define LOG(...) if (DEBUG) fprintf(stderr, __VA_ARGS__);

// Use a small buffer to cover the case when a lexeme doesn't fit.
// In real world use a larger buffer.
#define BUFSIZE 10

struct State {
    FILE *file;
    char buf[BUFSIZE + 1], *lim, *cur, *mar, *tok;
    int state;
};

typedef enum {END, READY, WAITING, BAD_PACKET, BIG_PACKET} Status;

static Status fill(State &st) {
    const size_t shift = st.tok - st.buf;
    const size_t used = st.lim - st.tok;
    const size_t free = BUFSIZE - used;

    // Error: no space. In real life can reallocate a larger buffer.
    if (free < 1) return BIG_PACKET;

    // Shift buffer contents (discard already processed data).
    memmove(st.buf, st.tok, used);
    st.lim -= shift;
    st.cur -= shift;
    st.mar -= shift;
    st.tok -= shift;

    // Fill free space at the end of buffer with new data.
    const size_t read = fread(st.lim, 1, free, st.file);
    st.lim += read;
    st.lim[0] = 0; // append sentinel symbol

    return READY;
}

static Status lex(State &st, unsigned int *recv) {
    char yych;
    
#line 50 "c/state/push.c"
switch (st.state) {
	case 0:
		if (st.lim <= st.cur) goto yy8;
		goto yyFillLabel0;
	case 1:
		if (st.lim <= st.cur) goto yy3;
		goto yyFillLabel1;
	case 2:
		if (st.lim <= st.cur) goto yy7;
		goto yyFillLabel2;
	default: goto yy0;
}
#line 46 "c/state/push.re"


    for (;;) {
        st.tok = st.cur;
    
#line 69 "c/state/push.c"
yy0:
yyFillLabel0:
	yych = *st.cur;
	switch (yych) {
		case 'a':
		case 'b':
		case 'c':
		case 'd':
		case 'e':
		case 'f':
		case 'g':
		case 'h':
		case 'i':
		case 'j':
		case 'k':
		case 'l':
		case 'm':
		case 'n':
		case 'o':
		case 'p':
		case 'q':
		case 'r':
		case 's':
		case 't':
		case 'u':
		case 'v':
		case 'w':
		case 'x':
		case 'y':
		case 'z': goto yy4;
		default:
			if (st.lim <= st.cur) {
				st.state = 0;
				return WAITING;
			}
			goto yy2;
	}
yy2:
	++st.cur;
yy3:
	st.state = -1;
#line 63 "c/state/push.re"
	{ return BAD_PACKET; }
#line 113 "c/state/push.c"
yy4:
	st.mar = ++st.cur;
yyFillLabel1:
	yych = *st.cur;
	switch (yych) {
		case ';': goto yy5;
		case 'a':
		case 'b':
		case 'c':
		case 'd':
		case 'e':
		case 'f':
		case 'g':
		case 'h':
		case 'i':
		case 'j':
		case 'k':
		case 'l':
		case 'm':
		case 'n':
		case 'o':
		case 'p':
		case 'q':
		case 'r':
		case 's':
		case 't':
		case 'u':
		case 'v':
		case 'w':
		case 'x':
		case 'y':
		case 'z': goto yy6;
		default:
			if (st.lim <= st.cur) {
				st.state = 1;
				return WAITING;
			}
			goto yy3;
	}
yy5:
	++st.cur;
	st.state = -1;
#line 65 "c/state/push.re"
	{ *recv = *recv + 1; continue; }
#line 158 "c/state/push.c"
yy6:
	++st.cur;
yyFillLabel2:
	yych = *st.cur;
	switch (yych) {
		case ';': goto yy5;
		case 'a':
		case 'b':
		case 'c':
		case 'd':
		case 'e':
		case 'f':
		case 'g':
		case 'h':
		case 'i':
		case 'j':
		case 'k':
		case 'l':
		case 'm':
		case 'n':
		case 'o':
		case 'p':
		case 'q':
		case 'r':
		case 's':
		case 't':
		case 'u':
		case 'v':
		case 'w':
		case 'x':
		case 'y':
		case 'z': goto yy6;
		default:
			if (st.lim <= st.cur) {
				st.state = 2;
				return WAITING;
			}
			goto yy7;
	}
yy7:
	st.cur = st.mar;
	goto yy3;
yy8:
	st.state = -1;
#line 64 "c/state/push.re"
	{ return END; }
#line 205 "c/state/push.c"
#line 66 "c/state/push.re"

    }
}

void test(const char **packets, Status expect) {
    // Create a pipe (open the same file for reading and writing).
    const char *fname = "pipe";
    FILE *fw = fopen(fname, "w");
    FILE *fr = fopen(fname, "r");
    setvbuf(fw, NULL, _IONBF, 0);
    setvbuf(fr, NULL, _IONBF, 0);

    // Initialize lexer state: `state` value is -1, all pointers are at the end
    // of buffer.
    State st;
    st.file = fr;
    st.cur = st.mar = st.tok = st.lim = st.buf + BUFSIZE;
    // Sentinel (at YYLIMIT pointer) is set to zero, which triggers YYFILL.
    st.lim[0] = 0;
    st.state = -1;

    // Main loop. The buffer contains incomplete data which appears packet by
    // packet. When the lexer needs more input it saves its internal state and
    // returns to the caller which should provide more input and resume lexing.
    Status status;
    unsigned int send = 0, recv = 0;
    for (;;) {
        status = lex(st, &recv);
        if (status == END) {
            LOG("done: got %u packets\n", recv);
            break;
        } else if (status == WAITING) {
            LOG("waiting...\n");
            if (*packets) {
                LOG("sent packet %u\n", send);
                fprintf(fw, "%s", *packets++);
                ++send;
            }
            status = fill(st);
            LOG("queue: '%s'\n", st.buf);
            if (status == BIG_PACKET) {
                LOG("error: packet too big\n");
                break;
            }
            assert(status == READY);
        } else {
            assert(status == BAD_PACKET);
            LOG("error: ill-formed packet\n");
            break;
        }
    }

    // Check results.
    assert(status == expect);
    if (status == END) assert(recv == send);

    // Cleanup: remove input file.
    fclose(fw);
    fclose(fr);
    remove(fname);
}

int main() {
    const char *packets1[] = {0};
    const char *packets2[] = {"zero;", "one;", "two;", "three;", "four;", 0};
    const char *packets3[] = {"zer0;", 0};
    const char *packets4[] = {"looooooooooong;", 0};

    test(packets1, END);
    test(packets2, END);
    test(packets3, BAD_PACKET);
    test(packets4, BIG_PACKET);

    return 0;
}
