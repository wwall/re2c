#ifndef _RE2C_DFA_ENCODING_UTF16_RANGE_
#define _RE2C_DFA_ENCODING_UTF16_RANGE_

#include "src/dfa/encoding/range_suffix.h"
#include "src/dfa/encoding/utf16/utf16.h"

namespace re2c {

void UTF16addContinuous1(RangeSuffix * & root, uint16_t l, uint16_t h);
void UTF16addContinuous2(RangeSuffix * & root, uint16_t l_ld, uint16_t h_ld, uint16_t l_tr, uint16_t h_tr);
void UTF16splitByContinuity(RangeSuffix * & root, uint16_t l_ld, uint16_t h_ld, uint16_t l_tr, uint16_t h_tr);
void UTF16splitByRuneLength(RangeSuffix * & root, utf16::rune l, utf16::rune h);

} // namespace re2c

#endif // _RE2C_DFA_ENCODING_UTF16_RANGE_
