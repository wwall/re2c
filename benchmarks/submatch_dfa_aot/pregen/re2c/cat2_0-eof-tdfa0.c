/* Generated by re2c 2.0.3 */
#line 1 "../../../benchmarks/submatch_dfa_aot/src/re2c/cat2_0.re"
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
    char *yyt1;
char *yyt2;
char *yyt3;
char *yyt4;

    
    taglistpool_t tlp;
    int eof;
} input_t;

static inline void taglistpool_clear(taglistpool_t *tlp, input_t *in)
{
    tlp->next = tlp->head;
    
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
    if (in->yyt1) in->yyt1 -= free;
if (in->yyt2) in->yyt2 -= free;
if (in->yyt3) in->yyt3 -= free;
if (in->yyt4) in->yyt4 -= free;


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
    in->yyt1 = 0;
in->yyt2 = 0;
in->yyt3 = 0;
in->yyt4 = 0;

    
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


static int lex(input_t *in, Output *out)
{
    const char
        *a0, *a1,
        *b0, *b1;
loop:
    in->tok = in->cur;

#line 171 "gen/re2c/cat2_0-eof-tdfa0.c"
{
	char yych;
	in->yyt1 = in->yyt2 = in->yyt3 = in->yyt4 = in->cur;
yyFillLabel3_0:
	yych = *in->cur;
	switch (yych) {
	case '\n':
		++in->cur;
		goto yy4;
	case 'a':
		++in->cur;
		in->yyt2 = in->yyt3 = in->yyt4 = in->cur;
		goto yy6;
	case 'b':
		++in->cur;
		in->yyt3 = in->yyt4 = in->cur;
		goto yy7;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_0;
			goto yy17;
		}
		++in->cur;
		goto yy2;
	}
yy2:
yy3:
#line 11 "../../../benchmarks/submatch_dfa_aot/src/re2c/cat2_0.re"
	{ return 1; }
#line 201 "gen/re2c/cat2_0-eof-tdfa0.c"
yy4:
	a0 = in->yyt1;
	b0 = in->yyt2;
	a1 = in->yyt3;
	b1 = in->yyt4;
#line 15 "../../../benchmarks/submatch_dfa_aot/src/re2c/cat2_0.re"
	{
        outs(out, a0, b0); outc(out, '.'); outs(out, b0, a1); outc(out, '.');
        outs(out, a1, b1); outc(out, '.'); outs(out, b1, in->cur);
        goto loop;
    }
#line 213 "gen/re2c/cat2_0-eof-tdfa0.c"
yy6:
	in->mar = in->cur;
yyFillLabel3_1:
	yych = *in->cur;
	switch (yych) {
	case '\n':
	case 'a':
	case 'b':	goto yy9;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_1;
		}
		goto yy3;
	}
yy7:
	in->mar = in->cur;
yyFillLabel3_2:
	yych = *in->cur;
	switch (yych) {
	case '\n':
	case 'a':
	case 'b':	goto yy12;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_2;
		}
		goto yy3;
	}
yy8:
yyFillLabel3_3:
	yych = *in->cur;
yy9:
	switch (yych) {
	case '\n':
		++in->cur;
		goto yy4;
	case 'a':
		++in->cur;
		in->yyt2 = in->yyt3 = in->yyt4 = in->cur;
		goto yy8;
	case 'b':
		++in->cur;
		in->yyt3 = in->yyt4 = in->cur;
		goto yy11;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_3;
		}
		goto yy10;
	}
yy10:
	in->cur = in->mar;
	goto yy3;
yy11:
yyFillLabel3_4:
	yych = *in->cur;
yy12:
	switch (yych) {
	case '\n':
		++in->cur;
		goto yy4;
	case 'a':
		++in->cur;
		in->yyt4 = in->cur;
		goto yy13;
	case 'b':
		++in->cur;
		in->yyt3 = in->yyt4 = in->cur;
		goto yy11;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_4;
		}
		goto yy10;
	}
yy13:
yyFillLabel3_5:
	yych = *in->cur;
	switch (yych) {
	case '\n':
		++in->cur;
		goto yy4;
	case 'a':
		++in->cur;
		in->yyt4 = in->cur;
		goto yy13;
	case 'b':
		++in->cur;
		goto yy15;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_5;
		}
		goto yy10;
	}
yy15:
yyFillLabel3_6:
	yych = *in->cur;
	switch (yych) {
	case '\n':
		++in->cur;
		goto yy4;
	case 'b':
		++in->cur;
		goto yy15;
	default:
		if (in->lim <= in->cur) {
			if (fill(in) == 0) goto yyFillLabel3_6;
		}
		goto yy10;
	}
yy17:
#line 5 "../../../benchmarks/submatch_dfa_aot/src/re2c/include-eof/fill.re"
	{ return 0; }
#line 328 "gen/re2c/cat2_0-eof-tdfa0.c"
}
#line 20 "../../../benchmarks/submatch_dfa_aot/src/re2c/cat2_0.re"

}
