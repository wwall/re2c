/* Generated by re2c */
// re2c $INPUT -o $OUTPUT -ib
// Copyright 2011 Google Inc. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "lexer.h"

#include <stdio.h>

#include "eval_env.h"
#include "util.h"

bool Lexer::Error(const string& message, string* err) {
  // Compute line/column.
  int line = 1;
  const char* line_start = input_.str_;
  for (const char* p = input_.str_; p < last_token_; ++p) {
    if (*p == '\n') {
      ++line;
      line_start = p + 1;
    }
  }
  int col = last_token_ ? (int)(last_token_ - line_start) : 0;

  char buf[1024];
  snprintf(buf, sizeof(buf), "%s:%d: ", filename_.AsString().c_str(), line);
  *err = buf;
  *err += message + "\n";

  // Add some context to the message.
  const int kTruncateColumn = 72;
  if (col > 0 && col < kTruncateColumn) {
    int len;
    bool truncated = true;
    for (len = 0; len < kTruncateColumn; ++len) {
      if (line_start[len] == 0 || line_start[len] == '\n') {
        truncated = false;
        break;
      }
    }
    *err += string(line_start, len);
    if (truncated)
      *err += "...";
    *err += "\n";
    *err += string(col, ' ');
    *err += "^ near here";
  }

  return false;
}

Lexer::Lexer(const char* input) {
  Start("input", input);
}

void Lexer::Start(StringPiece filename, StringPiece input) {
  filename_ = filename;
  input_ = input;
  ofs_ = input_.str_;
  last_token_ = NULL;
}

const char* Lexer::TokenName(Token t) {
  switch (t) {
  case ERROR:    return "lexing error";
  case BUILD:    return "'build'";
  case COLON:    return "':'";
  case DEFAULT:  return "'default'";
  case EQUALS:   return "'='";
  case IDENT:    return "identifier";
  case INCLUDE:  return "'include'";
  case INDENT:   return "indent";
  case NEWLINE:  return "newline";
  case PIPE2:    return "'||'";
  case PIPE:     return "'|'";
  case POOL:     return "'pool'";
  case RULE:     return "'rule'";
  case SUBNINJA: return "'subninja'";
  case TEOF:     return "eof";
  }
  return NULL;  // not reached
}

const char* Lexer::TokenErrorHint(Token expected) {
  switch (expected) {
  case COLON:
    return " ($ also escapes ':')";
  default:
    return "";
  }
}

string Lexer::DescribeLastError() {
  if (last_token_) {
    switch (last_token_[0]) {
    case '\t':
      return "tabs are not allowed, use spaces";
    }
  }
  return "lexing error";
}

void Lexer::UnreadToken() {
  ofs_ = last_token_;
}

Lexer::Token Lexer::ReadToken() {
  const char* p = ofs_;
  const char* q;
  const char* start;
  Lexer::Token token;
  for (;;) {
    start = p;
    
{
	unsigned char yych;
	unsigned int yyaccept = 0;
	static const unsigned char yybm[256] = {
		  0, 128, 128, 128, 128, 128, 128, 128,
		128, 128,   0, 128, 128, 128, 128, 128,
		128, 128, 128, 128, 128, 128, 128, 128,
		128, 128, 128, 128, 128, 128, 128, 128,
		160, 128, 128, 128, 128, 128, 128, 128,
		128, 128, 128, 128, 128, 192, 192, 128,
		192, 192, 192, 192, 192, 192, 192, 192,
		192, 192, 128, 128, 128, 128, 128, 128,
		128, 192, 192, 192, 192, 192, 192, 192,
		192, 192, 192, 192, 192, 192, 192, 192,
		192, 192, 192, 192, 192, 192, 192, 192,
		192, 192, 192, 128, 128, 128, 128, 192,
		128, 192, 192, 192, 192, 192, 192, 192,
		192, 192, 192, 192, 192, 192, 192, 192,
		192, 192, 192, 192, 192, 192, 192, 192,
		192, 192, 192, 128, 128, 128, 128, 128,
		128, 128, 128, 128, 128, 128, 128, 128,
		128, 128, 128, 128, 128, 128, 128, 128,
		128, 128, 128, 128, 128, 128, 128, 128,
		128, 128, 128, 128, 128, 128, 128, 128,
		128, 128, 128, 128, 128, 128, 128, 128,
		128, 128, 128, 128, 128, 128, 128, 128,
		128, 128, 128, 128, 128, 128, 128, 128,
		128, 128, 128, 128, 128, 128, 128, 128,
		128, 128, 128, 128, 128, 128, 128, 128,
		128, 128, 128, 128, 128, 128, 128, 128,
		128, 128, 128, 128, 128, 128, 128, 128,
		128, 128, 128, 128, 128, 128, 128, 128,
		128, 128, 128, 128, 128, 128, 128, 128,
		128, 128, 128, 128, 128, 128, 128, 128,
		128, 128, 128, 128, 128, 128, 128, 128,
		128, 128, 128, 128, 128, 128, 128, 128
	};
	yych = *p;
	if (yybm[0+yych] & 32) {
		goto yy6;
	}
	if (yych <= '^') {
		if (yych <= ',') {
			if (yych <= '\f') {
				if (yych <= 0x00) goto yy1;
				if (yych == '\n') goto yy4;
				goto yy2;
			} else {
				if (yych <= '\r') goto yy5;
				if (yych == '#') goto yy8;
				goto yy2;
			}
		} else {
			if (yych <= ':') {
				if (yych == '/') goto yy2;
				if (yych <= '9') goto yy9;
				goto yy11;
			} else {
				if (yych <= '=') {
					if (yych <= '<') goto yy2;
					goto yy12;
				} else {
					if (yych <= '@') goto yy2;
					if (yych <= 'Z') goto yy9;
					goto yy2;
				}
			}
		}
	} else {
		if (yych <= 'i') {
			if (yych <= 'b') {
				if (yych == '`') goto yy2;
				if (yych <= 'a') goto yy9;
				goto yy13;
			} else {
				if (yych == 'd') goto yy14;
				if (yych <= 'h') goto yy9;
				goto yy15;
			}
		} else {
			if (yych <= 'r') {
				if (yych == 'p') goto yy16;
				if (yych <= 'q') goto yy9;
				goto yy17;
			} else {
				if (yych <= 'z') {
					if (yych <= 's') goto yy18;
					goto yy9;
				} else {
					if (yych == '|') goto yy19;
					goto yy2;
				}
			}
		}
	}
yy1:
	++p;
	{ token = TEOF;     break; }
yy2:
	++p;
yy3:
	{ token = ERROR;    break; }
yy4:
	++p;
	{ token = NEWLINE;  break; }
yy5:
	yych = *++p;
	if (yych == '\n') goto yy20;
	goto yy3;
yy6:
	yyaccept = 0;
	yych = *(q = ++p);
	if (yybm[0+yych] & 32) {
		goto yy6;
	}
	if (yych <= '\f') {
		if (yych == '\n') goto yy4;
	} else {
		if (yych <= '\r') goto yy21;
		if (yych == '#') goto yy23;
	}
yy7:
	{ token = INDENT;   break; }
yy8:
	yyaccept = 1;
	yych = *(q = ++p);
	if (yych <= 0x00) goto yy3;
	goto yy24;
yy9:
	yych = *++p;
yy10:
	if (yybm[0+yych] & 64) {
		goto yy9;
	}
	{ token = IDENT;    break; }
yy11:
	++p;
	{ token = COLON;    break; }
yy12:
	++p;
	{ token = EQUALS;   break; }
yy13:
	yych = *++p;
	if (yych == 'u') goto yy25;
	goto yy10;
yy14:
	yych = *++p;
	if (yych == 'e') goto yy26;
	goto yy10;
yy15:
	yych = *++p;
	if (yych == 'n') goto yy27;
	goto yy10;
yy16:
	yych = *++p;
	if (yych == 'o') goto yy28;
	goto yy10;
yy17:
	yych = *++p;
	if (yych == 'u') goto yy29;
	goto yy10;
yy18:
	yych = *++p;
	if (yych == 'u') goto yy30;
	goto yy10;
yy19:
	yych = *++p;
	if (yych == '|') goto yy31;
	{ token = PIPE;     break; }
yy20:
	++p;
	{ token = NEWLINE;  break; }
yy21:
	yych = *++p;
	if (yych == '\n') goto yy20;
yy22:
	p = q;
	if (yyaccept == 0) goto yy7;
	else goto yy3;
yy23:
	yych = *++p;
yy24:
	if (yybm[0+yych] & 128) {
		goto yy23;
	}
	if (yych <= 0x00) goto yy22;
	++p;
	{ continue; }
yy25:
	yych = *++p;
	if (yych == 'i') goto yy32;
	goto yy10;
yy26:
	yych = *++p;
	if (yych == 'f') goto yy33;
	goto yy10;
yy27:
	yych = *++p;
	if (yych == 'c') goto yy34;
	goto yy10;
yy28:
	yych = *++p;
	if (yych == 'o') goto yy35;
	goto yy10;
yy29:
	yych = *++p;
	if (yych == 'l') goto yy36;
	goto yy10;
yy30:
	yych = *++p;
	if (yych == 'b') goto yy37;
	goto yy10;
yy31:
	++p;
	{ token = PIPE2;    break; }
yy32:
	yych = *++p;
	if (yych == 'l') goto yy38;
	goto yy10;
yy33:
	yych = *++p;
	if (yych == 'a') goto yy39;
	goto yy10;
yy34:
	yych = *++p;
	if (yych == 'l') goto yy40;
	goto yy10;
yy35:
	yych = *++p;
	if (yych == 'l') goto yy41;
	goto yy10;
yy36:
	yych = *++p;
	if (yych == 'e') goto yy42;
	goto yy10;
yy37:
	yych = *++p;
	if (yych == 'n') goto yy43;
	goto yy10;
yy38:
	yych = *++p;
	if (yych == 'd') goto yy44;
	goto yy10;
yy39:
	yych = *++p;
	if (yych == 'u') goto yy45;
	goto yy10;
yy40:
	yych = *++p;
	if (yych == 'u') goto yy46;
	goto yy10;
yy41:
	yych = *++p;
	if (yybm[0+yych] & 64) {
		goto yy9;
	}
	{ token = POOL;     break; }
yy42:
	yych = *++p;
	if (yybm[0+yych] & 64) {
		goto yy9;
	}
	{ token = RULE;     break; }
yy43:
	yych = *++p;
	if (yych == 'i') goto yy47;
	goto yy10;
yy44:
	yych = *++p;
	if (yybm[0+yych] & 64) {
		goto yy9;
	}
	{ token = BUILD;    break; }
yy45:
	yych = *++p;
	if (yych == 'l') goto yy48;
	goto yy10;
yy46:
	yych = *++p;
	if (yych == 'd') goto yy49;
	goto yy10;
yy47:
	yych = *++p;
	if (yych == 'n') goto yy50;
	goto yy10;
yy48:
	yych = *++p;
	if (yych == 't') goto yy51;
	goto yy10;
yy49:
	yych = *++p;
	if (yych == 'e') goto yy52;
	goto yy10;
yy50:
	yych = *++p;
	if (yych == 'j') goto yy53;
	goto yy10;
yy51:
	yych = *++p;
	if (yybm[0+yych] & 64) {
		goto yy9;
	}
	{ token = DEFAULT;  break; }
yy52:
	yych = *++p;
	if (yybm[0+yych] & 64) {
		goto yy9;
	}
	{ token = INCLUDE;  break; }
yy53:
	yych = *++p;
	if (yych != 'a') goto yy10;
	yych = *++p;
	if (yybm[0+yych] & 64) {
		goto yy9;
	}
	{ token = SUBNINJA; break; }
}

  }

  last_token_ = start;
  ofs_ = p;
  if (token != NEWLINE && token != TEOF)
    EatWhitespace();
  return token;
}

bool Lexer::PeekToken(Token token) {
  Token t = ReadToken();
  if (t == token)
    return true;
  UnreadToken();
  return false;
}

void Lexer::EatWhitespace() {
  const char* p = ofs_;
  const char* q;
  for (;;) {
    ofs_ = p;
    
{
	unsigned char yych;
	static const unsigned char yybm[256] = {
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		128,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0
	};
	yych = *p;
	if (yybm[0+yych] & 128) {
		goto yy58;
	}
	if (yych <= 0x00) goto yy55;
	if (yych == '$') goto yy59;
	goto yy56;
yy55:
	++p;
	{ break; }
yy56:
	++p;
yy57:
	{ break; }
yy58:
	yych = *++p;
	if (yybm[0+yych] & 128) {
		goto yy58;
	}
	{ continue; }
yy59:
	yych = *(q = ++p);
	if (yych == '\n') goto yy60;
	if (yych == '\r') goto yy61;
	goto yy57;
yy60:
	++p;
	{ continue; }
yy61:
	yych = *++p;
	if (yych == '\n') goto yy62;
	p = q;
	goto yy57;
yy62:
	++p;
	{ continue; }
}

  }
}

bool Lexer::ReadIdent(string* out) {
  const char* p = ofs_;
  const char* start;
  for (;;) {
    start = p;
    
{
	unsigned char yych;
	static const unsigned char yybm[256] = {
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0, 128, 128,   0,
		128, 128, 128, 128, 128, 128, 128, 128,
		128, 128,   0,   0,   0,   0,   0,   0,
		  0, 128, 128, 128, 128, 128, 128, 128,
		128, 128, 128, 128, 128, 128, 128, 128,
		128, 128, 128, 128, 128, 128, 128, 128,
		128, 128, 128,   0,   0,   0,   0, 128,
		  0, 128, 128, 128, 128, 128, 128, 128,
		128, 128, 128, 128, 128, 128, 128, 128,
		128, 128, 128, 128, 128, 128, 128, 128,
		128, 128, 128,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,   0,   0
	};
	yych = *p;
	if (yybm[0+yych] & 128) {
		goto yy64;
	}
	++p;
	{
      last_token_ = start;
      return false;
    }
yy64:
	yych = *++p;
	if (yybm[0+yych] & 128) {
		goto yy64;
	}
	{
      out->assign(start, p - start);
      break;
    }
}

  }
  last_token_ = start;
  ofs_ = p;
  EatWhitespace();
  return true;
}

bool Lexer::ReadEvalString(EvalString* eval, bool path, string* err) {
  const char* p = ofs_;
  const char* q;
  const char* start;
  for (;;) {
    start = p;
    
{
	unsigned char yych;
	static const unsigned char yybm[256] = {
		  0,  16,  16,  16,  16,  16,  16,  16,
		 16,  16,   0,  16,  16,   0,  16,  16,
		 16,  16,  16,  16,  16,  16,  16,  16,
		 16,  16,  16,  16,  16,  16,  16,  16,
		 32,  16,  16,  16,   0,  16,  16,  16,
		 16,  16,  16,  16,  16, 208, 144,  16,
		208, 208, 208, 208, 208, 208, 208, 208,
		208, 208,   0,  16,  16,  16,  16,  16,
		 16, 208, 208, 208, 208, 208, 208, 208,
		208, 208, 208, 208, 208, 208, 208, 208,
		208, 208, 208, 208, 208, 208, 208, 208,
		208, 208, 208,  16,  16,  16,  16, 208,
		 16, 208, 208, 208, 208, 208, 208, 208,
		208, 208, 208, 208, 208, 208, 208, 208,
		208, 208, 208, 208, 208, 208, 208, 208,
		208, 208, 208,  16,   0,  16,  16,  16,
		 16,  16,  16,  16,  16,  16,  16,  16,
		 16,  16,  16,  16,  16,  16,  16,  16,
		 16,  16,  16,  16,  16,  16,  16,  16,
		 16,  16,  16,  16,  16,  16,  16,  16,
		 16,  16,  16,  16,  16,  16,  16,  16,
		 16,  16,  16,  16,  16,  16,  16,  16,
		 16,  16,  16,  16,  16,  16,  16,  16,
		 16,  16,  16,  16,  16,  16,  16,  16,
		 16,  16,  16,  16,  16,  16,  16,  16,
		 16,  16,  16,  16,  16,  16,  16,  16,
		 16,  16,  16,  16,  16,  16,  16,  16,
		 16,  16,  16,  16,  16,  16,  16,  16,
		 16,  16,  16,  16,  16,  16,  16,  16,
		 16,  16,  16,  16,  16,  16,  16,  16,
		 16,  16,  16,  16,  16,  16,  16,  16,
		 16,  16,  16,  16,  16,  16,  16,  16
	};
	yych = *p;
	if (yybm[0+yych] & 16) {
		goto yy67;
	}
	if (yych <= '\r') {
		if (yych <= 0x00) goto yy66;
		if (yych <= '\n') goto yy68;
		goto yy69;
	} else {
		if (yych <= ' ') goto yy68;
		if (yych <= '$') goto yy70;
		goto yy68;
	}
yy66:
	++p;
	{
      last_token_ = start;
      return Error("unexpected EOF", err);
    }
yy67:
	yych = *++p;
	if (yybm[0+yych] & 16) {
		goto yy67;
	}
	{
      eval->AddText(StringPiece(start, p - start));
      continue;
    }
yy68:
	++p;
	{
      if (path) {
        p = start;
        break;
      } else {
        if (*start == '\n')
          break;
        eval->AddText(StringPiece(start, 1));
        continue;
      }
    }
yy69:
	yych = *++p;
	if (yych == '\n') goto yy71;
	{
      last_token_ = start;
      return Error(DescribeLastError(), err);
    }
yy70:
	yych = *++p;
	if (yybm[0+yych] & 64) {
		goto yy78;
	}
	if (yych <= ' ') {
		if (yych <= '\f') {
			if (yych == '\n') goto yy74;
			goto yy72;
		} else {
			if (yych <= '\r') goto yy75;
			if (yych <= 0x1F) goto yy72;
			goto yy76;
		}
	} else {
		if (yych <= '/') {
			if (yych == '$') goto yy77;
			goto yy72;
		} else {
			if (yych <= ':') goto yy79;
			if (yych <= '`') goto yy72;
			if (yych <= '{') goto yy80;
			goto yy72;
		}
	}
yy71:
	++p;
	{
      if (path)
        p = start;
      break;
    }
yy72:
	++p;
yy73:
	{
      last_token_ = start;
      return Error("bad $-escape (literal $ must be written as $$)", err);
    }
yy74:
	yych = *++p;
	if (yybm[0+yych] & 32) {
		goto yy74;
	}
	{
      continue;
    }
yy75:
	yych = *++p;
	if (yych == '\n') goto yy81;
	goto yy73;
yy76:
	++p;
	{
      eval->AddText(StringPiece(" ", 1));
      continue;
    }
yy77:
	++p;
	{
      eval->AddText(StringPiece("$", 1));
      continue;
    }
yy78:
	yych = *++p;
	if (yybm[0+yych] & 64) {
		goto yy78;
	}
	{
      eval->AddSpecial(StringPiece(start + 1, p - start - 1));
      continue;
    }
yy79:
	++p;
	{
      eval->AddText(StringPiece(":", 1));
      continue;
    }
yy80:
	yych = *(q = ++p);
	if (yybm[0+yych] & 128) {
		goto yy82;
	}
	goto yy73;
yy81:
	yych = *++p;
	if (yych == ' ') goto yy81;
	{
      continue;
    }
yy82:
	yych = *++p;
	if (yybm[0+yych] & 128) {
		goto yy82;
	}
	if (yych == '}') goto yy83;
	p = q;
	goto yy73;
yy83:
	++p;
	{
      eval->AddSpecial(StringPiece(start + 2, p - start - 3));
      continue;
    }
}

  }
  last_token_ = start;
  ofs_ = p;
  if (path)
    EatWhitespace();
  // Non-path strings end in newlines, so there's no whitespace to eat.
  return true;
}
