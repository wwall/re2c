/* Generated by re2c 2.0.3 */
#line 1 "../../../benchmarks/submatch_dfa_aot/src/re2c/http_simple.re"
#include <assert.h>
#include <stdlib.h>
#include "common.h"

#line 15 "../../../benchmarks/submatch_dfa_aot/src/re2c/common.re"


typedef struct taglist_t {
    struct taglist_t *pred;
    long dist;
} taglist_t;

typedef struct taglistpool_t {
    taglist_t *head;
    taglist_t *next;
    taglist_t *last;
} taglistpool_t;

typedef struct {
    char *buf;
    char *lim;
    char *cur;
    char *mar;
    char *tok;
    char *yyt2;
char *yyt3;
char *yyt4;
char *yyt5;
char *yyt6;

    taglist_t *yyt1;
taglist_t *yyt7;
taglist_t *yyt8;
taglist_t *yyt9;

    taglistpool_t tlp;
    int eof;
} input_t;

static inline void taglistpool_clear(taglistpool_t *tlp, input_t *in)
{
    tlp->next = tlp->head;
    in->yyt1 = 0;
in->yyt7 = 0;
in->yyt8 = 0;
in->yyt9 = 0;

}

static inline void taglistpool_init(taglistpool_t *tlp)
{
    static const unsigned size = 1024 * 1024;
    tlp->head = (taglist_t*)malloc(size * sizeof(taglist_t));
    tlp->next = tlp->head;
    tlp->last = tlp->head + size;
}

static inline void taglistpool_free(taglistpool_t *tlp)
{
    free(tlp->head);
    tlp->head = tlp->next = tlp->last = NULL;
}

static inline void taglist(taglist_t **ptl, const char *b, const char *t, taglistpool_t *tlp)
{
#ifdef GROW_MTAG_LIST
    if (tlp->next >= tlp->last) {
        const unsigned size = tlp->last - tlp->head;
        taglist_t *head = (taglist_t*)malloc(2 * size * sizeof(taglist_t));
        memcpy(head, tlp->head, size * sizeof(taglist_t));
        free(tlp->head);
        tlp->head = head;
        tlp->next = head + size;
        tlp->last = head + size * 2;
    }
#else
    assert(tlp->next < tlp->last);
#endif
    taglist_t *tl = tlp->next++;
    tl->pred = *ptl;
    tl->dist = t - b;
    *ptl = tl;
}

#line 6 "../../../benchmarks/submatch_dfa_aot/src/re2c/include-eof/fill.re"


static inline int fill(input_t *in)
{
    size_t free;
    if (in->eof) return 1;

    free = in->tok - in->buf;
    assert(free > 0);

    memmove(in->buf, in->tok, in->lim - in->tok);
    in->lim -= free;
    in->cur -= free;
    in->mar -= free;
    in->tok -= free;
    if (in->yyt2) in->yyt2 -= free;
if (in->yyt3) in->yyt3 -= free;
if (in->yyt4) in->yyt4 -= free;
if (in->yyt5) in->yyt5 -= free;
if (in->yyt6) in->yyt6 -= free;


    in->lim += fread(in->lim, 1, free, stdin);
    in->lim[0] = 0;

    if (in->lim < in->buf + SIZE) {
        in->eof = 1;
    }

    return 0;
}

static inline void init_input(input_t *in)
{
    in->buf = (char*) malloc(SIZE + 1);
    in->lim = in->buf + SIZE;
    in->cur = in->lim;
    in->mar = in->lim;
    in->tok = in->lim;
    in->yyt2 = 0;
in->yyt3 = 0;
in->yyt4 = 0;
in->yyt5 = 0;
in->yyt6 = 0;

    in->yyt1 = 0;
in->yyt7 = 0;
in->yyt8 = 0;
in->yyt9 = 0;

    taglistpool_init(&in->tlp);
    in->eof = 0;
    fill(in);
}


static inline void free_input(input_t *in)
{
    free(in->buf);
    taglistpool_free(&in->tlp);
}

static int lex(input_t *in, Output *out);

int main(int argc, char **argv)
{
    PRE;
    input_t in;
    Output out;

    init_input(&in);
    init_output(&out);

    switch (lex(&in, &out)) {
        case 0:  break;
        case 1:  fprintf(stderr, "*** %s: syntax error\n", argv[0]); break;
        case 2:  fprintf(stderr, "*** %s: yyfill error\n", argv[0]); break;
        default: fprintf(stderr, "*** %s: panic\n", argv[0]); break;
    }

    flush(&out);
    free_output(&out);
    free_input(&in);

    POST;
    return 0;
}


static void print_headers(Output *out, const char *tok,
    const taglist_t *h1, const taglist_t *h2)
{
    if (!h2) return;
    print_headers(out, tok, h1->pred, h2->pred);
    OUT("header: ", tok + h1->dist, tok + h2->dist);
}

static int lex(input_t *in, Output *out)
{
    const char
        *s1, *v1, *v3, *m1, *rp1, *rt1,
        *s2, *v2, *v4, *m2, *rp2, *rt2;
    taglist_t *h1, *h2;

loop:
    in->tok = in->cur;

#line 196 "gen/re2c/http_simple-eof-tdfa0.c"
{
	char yych;
	in->yyt2 = in->cur;
yyFillLabel3_0:
	yych = *in->cur;
	switch (yych) {
	case '!':
	case '#':
	case '$':
	case '%':
	case '&':
	case '\'':
	case '*':
	case '+':
	case '-':
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '^':
	case '_':
	case '`':
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
	case 'z':
	case '|':
	case '~':
		++in->cur;
		goto yy4;
	case 'H':
		++in->cur;
		goto yy5;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_0;
			goto yy75;
		}
		++in->cur;
		goto yy2;
	}
yy2:
yy3:
#line 50 "../../../benchmarks/submatch_dfa_aot/src/re2c/http_simple.re"
	{ return 1; }
#line 296 "gen/re2c/http_simple-eof-tdfa0.c"
yy4:
	in->mar = in->cur;
yyFillLabel3_1:
	yych = *in->cur;
	switch (yych) {
	case ' ':
	case '!':
	case '#':
	case '$':
	case '%':
	case '&':
	case '\'':
	case '*':
	case '+':
	case '-':
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '^':
	case '_':
	case '`':
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
	case 'z':
	case '|':
	case '~':	goto yy9;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_1;
		}
		goto yy3;
	}
yy5:
	in->mar = in->cur;
yyFillLabel3_2:
	yych = *in->cur;
	switch (yych) {
	case ' ':
	case '!':
	case '#':
	case '$':
	case '%':
	case '&':
	case '\'':
	case '*':
	case '+':
	case '-':
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '^':
	case '_':
	case '`':
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
	case 'z':
	case '|':
	case '~':	goto yy9;
	case 'T':
		++in->cur;
		goto yy10;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_2;
		}
		goto yy3;
	}
yy6:
yyFillLabel3_3:
	yych = *in->cur;
	switch (yych) {
	case 0x00:
	case ' ':
	case '@':
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_3;
		}
		goto yy7;
	case '+':
	case '-':
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
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
	case 'z':
		++in->cur;
		goto yy13;
	case '/':
		++in->cur;
		goto yy15;
	default:	goto yy12;
	}
yy7:
	in->cur = in->mar;
	goto yy3;
yy8:
yyFillLabel3_4:
	yych = *in->cur;
yy9:
	switch (yych) {
	case ' ':
		++in->cur;
		in->yyt3 = in->cur;
		goto yy6;
	case '!':
	case '#':
	case '$':
	case '%':
	case '&':
	case '\'':
	case '*':
	case '+':
	case '-':
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '^':
	case '_':
	case '`':
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
	case 'z':
	case '|':
	case '~':
		++in->cur;
		goto yy8;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_4;
		}
		goto yy7;
	}
yy10:
yyFillLabel3_5:
	yych = *in->cur;
	switch (yych) {
	case 0x00:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_5;
		}
		goto yy7;
	case 'T':
		++in->cur;
		goto yy19;
	default:	goto yy9;
	}
yy11:
yyFillLabel3_6:
	yych = *in->cur;
yy12:
	switch (yych) {
	case ' ':
		++in->cur;
		goto yy20;
	case '!':
	case '$':
	case '%':
	case '&':
	case '\'':
	case '(':
	case ')':
	case '*':
	case '+':
	case ',':
	case '-':
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case ':':
	case ';':
	case '=':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
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
	case 'z':
	case '~':
		++in->cur;
		goto yy11;
	case '@':
		++in->cur;
		goto yy21;
	case '[':
	case ']':
		++in->cur;
		goto yy17;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_6;
		}
		goto yy7;
	}
yy13:
yyFillLabel3_7:
	yych = *in->cur;
	switch (yych) {
	case ' ':
		++in->cur;
		goto yy20;
	case '!':
	case '$':
	case '%':
	case '&':
	case '\'':
	case '(':
	case ')':
	case '*':
	case ',':
	case ';':
	case '=':
	case '_':
	case '~':
		++in->cur;
		goto yy11;
	case '+':
	case '-':
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
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
	case 'z':
		++in->cur;
		goto yy13;
	case ':':
		++in->cur;
		goto yy22;
	case '@':
		++in->cur;
		goto yy21;
	case '[':
	case ']':
		++in->cur;
		goto yy17;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_7;
		}
		goto yy7;
	}
yy15:
yyFillLabel3_8:
	yych = *in->cur;
yy16:
	switch (yych) {
	case ' ':
		++in->cur;
		goto yy20;
	case '!':
	case '$':
	case '%':
	case '&':
	case '\'':
	case '(':
	case ')':
	case '*':
	case '+':
	case ',':
	case '-':
	case '.':
	case '/':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case ':':
	case ';':
	case '=':
	case '?':
	case '@':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
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
	case 'z':
	case '~':
		++in->cur;
		goto yy15;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_8;
		}
		goto yy7;
	}
yy17:
yyFillLabel3_9:
	yych = *in->cur;
yy18:
	switch (yych) {
	case ' ':
		++in->cur;
		goto yy20;
	case '!':
	case '$':
	case '%':
	case '&':
	case '\'':
	case '(':
	case ')':
	case '*':
	case '+':
	case ',':
	case '-':
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case ':':
	case ';':
	case '=':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '[':
	case ']':
	case '_':
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
	case 'z':
	case '~':
		++in->cur;
		goto yy17;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_9;
		}
		goto yy7;
	}
yy19:
yyFillLabel3_10:
	yych = *in->cur;
	switch (yych) {
	case 0x00:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_10;
		}
		goto yy7;
	case 'P':
		++in->cur;
		goto yy23;
	default:	goto yy9;
	}
yy20:
yyFillLabel3_11:
	yych = *in->cur;
	switch (yych) {
	case 'H':
		++in->cur;
		goto yy24;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_11;
		}
		goto yy7;
	}
yy21:
yyFillLabel3_12:
	yych = *in->cur;
	switch (yych) {
	case 0x00:
	case ' ':
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_12;
		}
		goto yy7;
	default:	goto yy18;
	}
yy22:
yyFillLabel3_13:
	yych = *in->cur;
	switch (yych) {
	case 0x00:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_13;
		}
		goto yy7;
	case '/':
		++in->cur;
		goto yy27;
	default:	goto yy26;
	}
yy23:
yyFillLabel3_14:
	yych = *in->cur;
	switch (yych) {
	case 0x00:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_14;
		}
		goto yy7;
	case '/':
		++in->cur;
		goto yy30;
	default:	goto yy9;
	}
yy24:
yyFillLabel3_15:
	yych = *in->cur;
	switch (yych) {
	case 'T':
		++in->cur;
		goto yy31;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_15;
		}
		goto yy7;
	}
yy25:
yyFillLabel3_16:
	yych = *in->cur;
yy26:
	switch (yych) {
	case ' ':
		++in->cur;
		goto yy20;
	case '!':
	case '$':
	case '%':
	case '&':
	case '\'':
	case '(':
	case ')':
	case '*':
	case '+':
	case ',':
	case '-':
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case ':':
	case ';':
	case '=':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
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
	case 'z':
	case '~':
		++in->cur;
		goto yy25;
	case '/':
	case '?':
		++in->cur;
		goto yy15;
	case '@':
		++in->cur;
		goto yy28;
	case '[':
	case ']':
		++in->cur;
		goto yy17;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_16;
		}
		goto yy7;
	}
yy27:
yyFillLabel3_17:
	yych = *in->cur;
	switch (yych) {
	case 0x00:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_17;
		}
		goto yy7;
	case '/':
		++in->cur;
		goto yy32;
	default:	goto yy16;
	}
yy28:
yyFillLabel3_18:
	yych = *in->cur;
	switch (yych) {
	case ' ':
		++in->cur;
		goto yy20;
	case '!':
	case '$':
	case '%':
	case '&':
	case '\'':
	case '(':
	case ')':
	case '*':
	case '+':
	case ',':
	case '-':
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case ':':
	case ';':
	case '=':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
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
	case 'z':
	case '~':
		++in->cur;
		goto yy28;
	case '/':
	case '?':
	case '@':
		++in->cur;
		goto yy15;
	case '[':
	case ']':
		++in->cur;
		goto yy17;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_18;
		}
		goto yy7;
	}
yy30:
yyFillLabel3_19:
	yych = *in->cur;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		++in->cur;
		goto yy33;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_19;
		}
		goto yy7;
	}
yy31:
yyFillLabel3_20:
	yych = *in->cur;
	switch (yych) {
	case 'T':
		++in->cur;
		goto yy34;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_20;
		}
		goto yy7;
	}
yy32:
yyFillLabel3_21:
	yych = *in->cur;
	switch (yych) {
	case 0x00:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_21;
		}
		goto yy7;
	case '@':
		++in->cur;
		goto yy15;
	default:	goto yy36;
	}
yy33:
yyFillLabel3_22:
	yych = *in->cur;
	switch (yych) {
	case '.':
		++in->cur;
		goto yy39;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_22;
		}
		goto yy7;
	}
yy34:
yyFillLabel3_23:
	yych = *in->cur;
	switch (yych) {
	case 'P':
		++in->cur;
		goto yy40;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_23;
		}
		goto yy7;
	}
yy35:
yyFillLabel3_24:
	yych = *in->cur;
yy36:
	switch (yych) {
	case ' ':
		++in->cur;
		goto yy20;
	case '!':
	case '$':
	case '%':
	case '&':
	case '\'':
	case '(':
	case ')':
	case '*':
	case '+':
	case ',':
	case '-':
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case ':':
	case ';':
	case '=':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
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
	case 'z':
	case '~':
		++in->cur;
		goto yy35;
	case '/':
	case '?':
		++in->cur;
		goto yy15;
	case '@':
	case '[':
	case ']':
		++in->cur;
		goto yy37;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_24;
		}
		goto yy7;
	}
yy37:
yyFillLabel3_25:
	yych = *in->cur;
	switch (yych) {
	case ' ':
		++in->cur;
		goto yy20;
	case '!':
	case '$':
	case '%':
	case '&':
	case '\'':
	case '(':
	case ')':
	case '*':
	case '+':
	case ',':
	case '-':
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case ':':
	case ';':
	case '=':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '[':
	case ']':
	case '_':
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
	case 'z':
	case '~':
		++in->cur;
		goto yy37;
	case '/':
	case '?':
	case '@':
		++in->cur;
		goto yy15;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_25;
		}
		goto yy7;
	}
yy39:
yyFillLabel3_26:
	yych = *in->cur;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		++in->cur;
		goto yy41;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_26;
		}
		goto yy7;
	}
yy40:
yyFillLabel3_27:
	yych = *in->cur;
	switch (yych) {
	case '/':
		++in->cur;
		goto yy42;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_27;
		}
		goto yy7;
	}
yy41:
yyFillLabel3_28:
	yych = *in->cur;
	switch (yych) {
	case ' ':
		++in->cur;
		goto yy43;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_28;
		}
		goto yy7;
	}
yy42:
yyFillLabel3_29:
	yych = *in->cur;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		++in->cur;
		goto yy44;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_29;
		}
		goto yy7;
	}
yy43:
yyFillLabel3_30:
	yych = *in->cur;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		++in->cur;
		goto yy45;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_30;
		}
		goto yy7;
	}
yy44:
yyFillLabel3_31:
	yych = *in->cur;
	switch (yych) {
	case '.':
		++in->cur;
		goto yy46;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_31;
		}
		goto yy7;
	}
yy45:
yyFillLabel3_32:
	yych = *in->cur;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		++in->cur;
		goto yy47;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_32;
		}
		goto yy7;
	}
yy46:
yyFillLabel3_33:
	yych = *in->cur;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		++in->cur;
		in->yyt4 = in->cur;
		goto yy48;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_33;
		}
		goto yy7;
	}
yy47:
yyFillLabel3_34:
	yych = *in->cur;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		++in->cur;
		goto yy49;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_34;
		}
		goto yy7;
	}
yy48:
yyFillLabel3_35:
	yych = *in->cur;
	switch (yych) {
	case '\n':
		++in->cur;
		in->yyt9 = in->yyt1;
		taglist(&in->yyt9, in->tok, in->tok - 1, &in->tlp);
		in->yyt7 = in->yyt8;
		taglist(&in->yyt7, in->tok, in->cur, &in->tlp);
		taglist(&in->yyt8, in->tok, in->tok - 1, &in->tlp);
		in->yyt5 = in->yyt6 = NULL;
		goto yy50;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_35;
		}
		goto yy7;
	}
yy49:
yyFillLabel3_36:
	yych = *in->cur;
	switch (yych) {
	case ' ':
		++in->cur;
		in->yyt5 = in->yyt6 = in->cur;
		goto yy51;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_36;
		}
		goto yy7;
	}
yy50:
yyFillLabel3_37:
	yych = *in->cur;
	switch (yych) {
	case 0x00:
	case ':':
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_37;
		}
		goto yy7;
	case '\n':
		++in->cur;
		goto yy53;
	default:	goto yy56;
	}
yy51:
yyFillLabel3_38:
	yych = *in->cur;
	switch (yych) {
	case 0x00:
	case 0x01:
	case 0x02:
	case 0x03:
	case 0x04:
	case 0x05:
	case 0x06:
	case 0x07:
	case 0x08:
	case '\v':
	case '\f':
	case '\r':
	case 0x0E:
	case 0x0F:
	case 0x10:
	case 0x11:
	case 0x12:
	case 0x13:
	case 0x14:
	case 0x15:
	case 0x16:
	case 0x17:
	case 0x18:
	case 0x19:
	case 0x1A:
	case 0x1B:
	case 0x1C:
	case 0x1D:
	case 0x1E:
	case 0x7F:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_38;
		}
		goto yy7;
	case '\n':
		++in->cur;
		in->yyt9 = in->yyt1;
		taglist(&in->yyt9, in->tok, in->tok - 1, &in->tlp);
		in->yyt7 = in->yyt8;
		taglist(&in->yyt7, in->tok, in->cur, &in->tlp);
		taglist(&in->yyt8, in->tok, in->tok - 1, &in->tlp);
		in->yyt2 = in->yyt3 = in->yyt4 = NULL;
		goto yy50;
	default:
		++in->cur;
		in->yyt6 = in->cur;
		goto yy51;
	}
yy53:
	m1 = in->yyt2;
	rt1 = in->yyt3;
	v4 = in->yyt4;
	rp1 = in->yyt5;
	rp2 = in->yyt6;
	h1 = in->yyt8;
	h2 = in->yyt9;
	m2 = in->yyt3;
	if (in->yyt3 != NULL) m2 -= 1;
	rt2 = in->yyt4;
	if (in->yyt4 != NULL) rt2 -= 9;
	v3 = in->yyt4;
	if (in->yyt4 != NULL) v3 -= 8;
	v1 = in->yyt5;
	if (in->yyt5 != NULL) v1 -= 13;
	v2 = in->yyt5;
	if (in->yyt5 != NULL) v2 -= 5;
	s1 = in->yyt5;
	if (in->yyt5 != NULL) s1 -= 4;
	s2 = in->yyt5;
	if (in->yyt5 != NULL) s2 -= 1;
#line 51 "../../../benchmarks/submatch_dfa_aot/src/re2c/http_simple.re"
	{
        if (s1) {
            OUT("version: ", v1, v2);
            OUT("status: ", s1, s2);
            OUT("reason: ", rp1, rp2);
        }
        if (m1) {
            OUT("method: ", m1, m2);
            OUT("request: ", rt1, rt2);
            OUT("version: ", v3, v4);
        }
        print_headers(out, in->tok, h1, h2);
        outc(out, '\n');

        taglistpool_clear(&in->tlp, in);
        goto loop;
    }
#line 1968 "gen/re2c/http_simple-eof-tdfa0.c"
yy55:
yyFillLabel3_39:
	yych = *in->cur;
yy56:
	switch (yych) {
	case '!':
	case '#':
	case '$':
	case '%':
	case '&':
	case '\'':
	case '*':
	case '+':
	case '-':
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '^':
	case '_':
	case '`':
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
	case 'z':
	case '|':
	case '~':
		++in->cur;
		goto yy55;
	case ':':
		++in->cur;
		in->yyt9 = in->yyt1;
		taglist(&in->yyt9, in->tok, in->cur, &in->tlp);
		goto yy57;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_39;
		}
		goto yy7;
	}
yy57:
yyFillLabel3_40:
	yych = *in->cur;
	switch (yych) {
	case 0x00:
	case 0x01:
	case 0x02:
	case 0x03:
	case 0x04:
	case 0x05:
	case 0x06:
	case 0x07:
	case 0x08:
	case '\v':
	case '\f':
	case '\r':
	case 0x0E:
	case 0x0F:
	case 0x10:
	case 0x11:
	case 0x12:
	case 0x13:
	case 0x14:
	case 0x15:
	case 0x16:
	case 0x17:
	case 0x18:
	case 0x19:
	case 0x1A:
	case 0x1B:
	case 0x1C:
	case 0x1D:
	case 0x1E:
	case 0x7F:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_40;
		}
		goto yy7;
	case '\t':
	case ' ':
		++in->cur;
		in->yyt9 = in->yyt1;
		taglist(&in->yyt9, in->tok, in->cur, &in->tlp);
		goto yy57;
	case '\n':
		++in->cur;
		in->yyt8 = in->yyt7;
		taglist(&in->yyt8, in->tok, in->cur, &in->tlp);
		goto yy59;
	default:
		++in->cur;
		in->yyt9 = in->yyt1;
		taglist(&in->yyt9, in->tok, in->cur, &in->tlp);
		goto yy60;
	}
yy59:
yyFillLabel3_41:
	yych = *in->cur;
	switch (yych) {
	case '\t':
	case ' ':
		++in->cur;
		in->yyt9 = in->yyt1;
		taglist(&in->yyt9, in->tok, in->cur, &in->tlp);
		goto yy57;
	case '\n':
		++in->cur;
		in->yyt8 = in->yyt7;
		goto yy53;
	case '!':
	case '#':
	case '$':
	case '%':
	case '&':
	case '\'':
	case '*':
	case '+':
	case '-':
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '^':
	case '_':
	case '`':
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
	case 'z':
	case '|':
	case '~':
		++in->cur;
		in->yyt1 = in->yyt9;
		in->yyt7 = in->yyt8;
		goto yy55;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_41;
		}
		goto yy7;
	}
yy60:
yyFillLabel3_42:
	yych = *in->cur;
	switch (yych) {
	case 0x00:
	case 0x01:
	case 0x02:
	case 0x03:
	case 0x04:
	case 0x05:
	case 0x06:
	case 0x07:
	case 0x08:
	case '\v':
	case '\f':
	case '\r':
	case 0x0E:
	case 0x0F:
	case 0x10:
	case 0x11:
	case 0x12:
	case 0x13:
	case 0x14:
	case 0x15:
	case 0x16:
	case 0x17:
	case 0x18:
	case 0x19:
	case 0x1A:
	case 0x1B:
	case 0x1C:
	case 0x1D:
	case 0x1E:
	case 0x7F:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_42;
		}
		goto yy7;
	case '\t':
		++in->cur;
		goto yy62;
	case '\n':
		++in->cur;
		in->yyt8 = in->yyt7;
		taglist(&in->yyt8, in->tok, in->cur, &in->tlp);
		goto yy59;
	case ' ':
		++in->cur;
		in->yyt9 = in->yyt1;
		taglist(&in->yyt9, in->tok, in->cur, &in->tlp);
		goto yy64;
	default:
		++in->cur;
		in->yyt9 = in->yyt1;
		taglist(&in->yyt9, in->tok, in->cur, &in->tlp);
		goto yy60;
	}
yy62:
yyFillLabel3_43:
	yych = *in->cur;
	switch (yych) {
	case 0x00:
	case 0x01:
	case 0x02:
	case 0x03:
	case 0x04:
	case 0x05:
	case 0x06:
	case 0x07:
	case 0x08:
	case '\v':
	case '\f':
	case '\r':
	case 0x0E:
	case 0x0F:
	case 0x10:
	case 0x11:
	case 0x12:
	case 0x13:
	case 0x14:
	case 0x15:
	case 0x16:
	case 0x17:
	case 0x18:
	case 0x19:
	case 0x1A:
	case 0x1B:
	case 0x1C:
	case 0x1D:
	case 0x1E:
	case 0x7F:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_43;
		}
		goto yy7;
	case '\t':
		++in->cur;
		goto yy62;
	case '\n':
		++in->cur;
		in->yyt1 = in->yyt7;
		taglist(&in->yyt1, in->tok, in->cur, &in->tlp);
		goto yy66;
	case ' ':
		++in->cur;
		in->yyt9 = in->yyt1;
		taglist(&in->yyt9, in->tok, in->cur, &in->tlp);
		goto yy64;
	default:
		++in->cur;
		in->yyt9 = in->yyt1;
		taglist(&in->yyt9, in->tok, in->cur, &in->tlp);
		goto yy67;
	}
yy64:
yyFillLabel3_44:
	yych = *in->cur;
	switch (yych) {
	case 0x00:
	case 0x01:
	case 0x02:
	case 0x03:
	case 0x04:
	case 0x05:
	case 0x06:
	case 0x07:
	case 0x08:
	case '\v':
	case '\f':
	case '\r':
	case 0x0E:
	case 0x0F:
	case 0x10:
	case 0x11:
	case 0x12:
	case 0x13:
	case 0x14:
	case 0x15:
	case 0x16:
	case 0x17:
	case 0x18:
	case 0x19:
	case 0x1A:
	case 0x1B:
	case 0x1C:
	case 0x1D:
	case 0x1E:
	case 0x7F:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_44;
		}
		goto yy7;
	case '\t':
		++in->cur;
		goto yy62;
	case '\n':
		++in->cur;
		in->yyt8 = in->yyt7;
		taglist(&in->yyt8, in->tok, in->cur, &in->tlp);
		goto yy59;
	case ' ':
		++in->cur;
		in->yyt9 = in->yyt1;
		taglist(&in->yyt9, in->tok, in->cur, &in->tlp);
		goto yy64;
	default:
		++in->cur;
		in->yyt9 = in->yyt1;
		taglist(&in->yyt9, in->tok, in->cur, &in->tlp);
		goto yy68;
	}
yy66:
yyFillLabel3_45:
	yych = *in->cur;
	switch (yych) {
	case '\n':
		++in->cur;
		in->yyt8 = in->yyt7;
		goto yy53;
	case '!':
	case '#':
	case '$':
	case '%':
	case '&':
	case '\'':
	case '*':
	case '+':
	case '-':
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '^':
	case '_':
	case '`':
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
	case 'z':
	case '|':
	case '~':
		++in->cur;
		in->yyt7 = in->yyt1;
		in->yyt1 = in->yyt9;
		goto yy55;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_45;
		}
		goto yy7;
	}
yy67:
yyFillLabel3_46:
	yych = *in->cur;
	switch (yych) {
	case 0x00:
	case 0x01:
	case 0x02:
	case 0x03:
	case 0x04:
	case 0x05:
	case 0x06:
	case 0x07:
	case 0x08:
	case '\v':
	case '\f':
	case '\r':
	case 0x0E:
	case 0x0F:
	case 0x10:
	case 0x11:
	case 0x12:
	case 0x13:
	case 0x14:
	case 0x15:
	case 0x16:
	case 0x17:
	case 0x18:
	case 0x19:
	case 0x1A:
	case 0x1B:
	case 0x1C:
	case 0x1D:
	case 0x1E:
	case 0x7F:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_46;
		}
		goto yy7;
	case '\t':
		++in->cur;
		goto yy69;
	case '\n':
		++in->cur;
		in->yyt8 = in->yyt7;
		taglist(&in->yyt8, in->tok, in->cur, &in->tlp);
		goto yy59;
	default:
		++in->cur;
		in->yyt9 = in->yyt1;
		taglist(&in->yyt9, in->tok, in->cur, &in->tlp);
		goto yy60;
	}
yy68:
yyFillLabel3_47:
	yych = *in->cur;
	switch (yych) {
	case 0x00:
	case 0x01:
	case 0x02:
	case 0x03:
	case 0x04:
	case 0x05:
	case 0x06:
	case 0x07:
	case 0x08:
	case '\v':
	case '\f':
	case '\r':
	case 0x0E:
	case 0x0F:
	case 0x10:
	case 0x11:
	case 0x12:
	case 0x13:
	case 0x14:
	case 0x15:
	case 0x16:
	case 0x17:
	case 0x18:
	case 0x19:
	case 0x1A:
	case 0x1B:
	case 0x1C:
	case 0x1D:
	case 0x1E:
	case 0x7F:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_47;
		}
		goto yy7;
	case '\t':
		++in->cur;
		goto yy71;
	case '\n':
		++in->cur;
		in->yyt8 = in->yyt7;
		taglist(&in->yyt8, in->tok, in->cur, &in->tlp);
		goto yy59;
	default:
		++in->cur;
		in->yyt9 = in->yyt1;
		taglist(&in->yyt9, in->tok, in->cur, &in->tlp);
		goto yy60;
	}
yy69:
yyFillLabel3_48:
	yych = *in->cur;
	switch (yych) {
	case '\t':
	case ' ':
		++in->cur;
		goto yy69;
	case '\n':
		++in->cur;
		in->yyt1 = in->yyt7;
		taglist(&in->yyt1, in->tok, in->cur, &in->tlp);
		goto yy66;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_48;
		}
		goto yy7;
	}
yy71:
yyFillLabel3_49:
	yych = *in->cur;
	switch (yych) {
	case 0x00:
	case 0x01:
	case 0x02:
	case 0x03:
	case 0x04:
	case 0x05:
	case 0x06:
	case 0x07:
	case 0x08:
	case '\v':
	case '\f':
	case '\r':
	case 0x0E:
	case 0x0F:
	case 0x10:
	case 0x11:
	case 0x12:
	case 0x13:
	case 0x14:
	case 0x15:
	case 0x16:
	case 0x17:
	case 0x18:
	case 0x19:
	case 0x1A:
	case 0x1B:
	case 0x1C:
	case 0x1D:
	case 0x1E:
	case 0x7F:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_49;
		}
		goto yy7;
	case '\t':
		++in->cur;
		goto yy71;
	case '\n':
		++in->cur;
		in->yyt1 = in->yyt7;
		taglist(&in->yyt1, in->tok, in->cur, &in->tlp);
		goto yy66;
	case ' ':
		++in->cur;
		goto yy73;
	default:
		++in->cur;
		in->yyt9 = in->yyt1;
		taglist(&in->yyt9, in->tok, in->cur, &in->tlp);
		goto yy67;
	}
yy73:
yyFillLabel3_50:
	yych = *in->cur;
	switch (yych) {
	case 0x00:
	case 0x01:
	case 0x02:
	case 0x03:
	case 0x04:
	case 0x05:
	case 0x06:
	case 0x07:
	case 0x08:
	case '\v':
	case '\f':
	case '\r':
	case 0x0E:
	case 0x0F:
	case 0x10:
	case 0x11:
	case 0x12:
	case 0x13:
	case 0x14:
	case 0x15:
	case 0x16:
	case 0x17:
	case 0x18:
	case 0x19:
	case 0x1A:
	case 0x1B:
	case 0x1C:
	case 0x1D:
	case 0x1E:
	case 0x7F:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_50;
		}
		goto yy7;
	case '\t':
		++in->cur;
		goto yy71;
	case '\n':
		++in->cur;
		in->yyt8 = in->yyt7;
		taglist(&in->yyt8, in->tok, in->cur, &in->tlp);
		goto yy59;
	case ' ':
		++in->cur;
		goto yy73;
	default:
		++in->cur;
		in->yyt9 = in->yyt1;
		taglist(&in->yyt9, in->tok, in->cur, &in->tlp);
		goto yy68;
	}
yy75:
#line 5 "../../../benchmarks/submatch_dfa_aot/src/re2c/include-eof/fill.re"
	{ return 0; }
#line 2722 "gen/re2c/http_simple-eof-tdfa0.c"
}
#line 68 "../../../benchmarks/submatch_dfa_aot/src/re2c/http_simple.re"

}
