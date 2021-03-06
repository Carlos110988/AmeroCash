/* cell_introduce1.c -- generated by Trunnel v1.5.1.
 * https://gitweb.torproject.org/trunnel.git
 * You probably shouldn't edit this file.
 */
#include <stdlib.h>
#include "trunnel-impl.h"

#include "cell_introduce1.h"

#define TRUNNEL_SET_ERROR_CODE(obj) \
  do {                              \
    (obj)->trunnel_error_code_ = 1; \
  } while (0)

#if defined(__COVERITY__) || defined(__clang_analyzer__)
/* If we're runnning a static analysis tool, we don't want it to complain
 * that some of our remaining-bytes checks are dead-code. */
int cellintroduce_deadcode_dummy__ = 0;
#define OR_DEAMCODE_DUMMY || cellintroduce_deadcode_dummy__
#else
#define OR_DEAMCODE_DUMMY
#endif

#define CHECK_REMAINING(nbytes, label)                           \
  do {                                                           \
    if (remaining < (nbytes) OR_DEAMCODE_DUMMY) {                \
      goto label;                                                \
    }                                                            \
  } while (0)

typedef struct cell_extension_st cell_extension_t;
cell_extension_t *cell_extension_new(void);
void cell_extension_free(cell_extension_t *victim);
ssize_t cell_extension_parse(cell_extension_t **output, const uint8_t *input, const size_t len_in);
ssize_t cell_extension_encoded_len(const cell_extension_t *obj);
ssize_t cell_extension_encode(uint8_t *output, size_t avail, const cell_extension_t *input);
const char *cell_extension_check(const cell_extension_t *obj);
int cell_extension_clear_errors(cell_extension_t *obj);
typedef struct link_specifier_st link_specifier_t;
link_specifier_t *link_specifier_new(void);
void link_specifier_free(link_specifier_t *victim);
ssize_t link_specifier_parse(link_specifier_t **output, const uint8_t *input, const size_t len_in);
ssize_t link_specifier_encoded_len(const link_specifier_t *obj);
ssize_t link_specifier_encode(uint8_t *output, size_t avail, const link_specifier_t *input);
const char *link_specifier_check(const link_specifier_t *obj);
int link_specifier_clear_errors(link_specifier_t *obj);
hs_cell_introduce1_t *
hs_cell_introduce1_new(void)
{
  hs_cell_introduce1_t *val = trunnel_calloc(1, sizeof(hs_cell_introduce1_t));
  if (NULL == val)
    return NULL;
  return val;
}

/** Release all storage held inside 'obj', but do not free 'obj'.
 */
static void
hs_cell_introduce1_clear(hs_cell_introduce1_t *obj)
{
  (void) obj;
  TRUNNEL_DYNARRAY_WIPE(&obj->auth_key);
  TRUNNEL_DYNARRAY_CLEAR(&obj->auth_key);
  cell_extension_free(obj->extensions);
  obj->extensions = NULL;
  TRUNNEL_DYNARRAY_WIPE(&obj->encrypted);
  TRUNNEL_DYNARRAY_CLEAR(&obj->encrypted);
}

void
hs_cell_introduce1_free(hs_cell_introduce1_t *obj)
{
  if (obj == NULL)
    return;
  hs_cell_introduce1_clear(obj);
  trunnel_memwipe(obj, sizeof(hs_cell_introduce1_t));
  trunnel_free_(obj);
}

size_t
hs_cell_introduce1_getlen_legacy_key_id(const hs_cell_introduce1_t *inp)
{
  (void)inp;  return TRUNNEL_SHA1_LEN;
}

uint8_t
hs_cell_introduce1_get_legacy_key_id(hs_cell_introduce1_t *inp, size_t idx)
{
  trunnel_assert(idx < TRUNNEL_SHA1_LEN);
  return inp->legacy_key_id[idx];
}

uint8_t
hs_cell_introduce1_getconst_legacy_key_id(const hs_cell_introduce1_t *inp, size_t idx)
{
  return hs_cell_introduce1_get_legacy_key_id((hs_cell_introduce1_t*)inp, idx);
}
int
hs_cell_introduce1_set_legacy_key_id(hs_cell_introduce1_t *inp, size_t idx, uint8_t elt)
{
  trunnel_assert(idx < TRUNNEL_SHA1_LEN);
  inp->legacy_key_id[idx] = elt;
  return 0;
}

uint8_t *
hs_cell_introduce1_getarray_legacy_key_id(hs_cell_introduce1_t *inp)
{
  return inp->legacy_key_id;
}
const uint8_t  *
hs_cell_introduce1_getconstarray_legacy_key_id(const hs_cell_introduce1_t *inp)
{
  return (const uint8_t  *)hs_cell_introduce1_getarray_legacy_key_id((hs_cell_introduce1_t*)inp);
}
uint8_t
hs_cell_introduce1_get_auth_key_type(const hs_cell_introduce1_t *inp)
{
  return inp->auth_key_type;
}
int
hs_cell_introduce1_set_auth_key_type(hs_cell_introduce1_t *inp, uint8_t val)
{
  if (! ((val == 0 || val == 1 || val == 2))) {
     TRUNNEL_SET_ERROR_CODE(inp);
     return -1;
  }
  inp->auth_key_type = val;
  return 0;
}
uint16_t
hs_cell_introduce1_get_auth_key_len(const hs_cell_introduce1_t *inp)
{
  return inp->auth_key_len;
}
int
hs_cell_introduce1_set_auth_key_len(hs_cell_introduce1_t *inp, uint16_t val)
{
  inp->auth_key_len = val;
  return 0;
}
size_t
hs_cell_introduce1_getlen_auth_key(const hs_cell_introduce1_t *inp)
{
  return TRUNNEL_DYNARRAY_LEN(&inp->auth_key);
}

uint8_t
hs_cell_introduce1_get_auth_key(hs_cell_introduce1_t *inp, size_t idx)
{
  return TRUNNEL_DYNARRAY_GET(&inp->auth_key, idx);
}

uint8_t
hs_cell_introduce1_getconst_auth_key(const hs_cell_introduce1_t *inp, size_t idx)
{
  return hs_cell_introduce1_get_auth_key((hs_cell_introduce1_t*)inp, idx);
}
int
hs_cell_introduce1_set_auth_key(hs_cell_introduce1_t *inp, size_t idx, uint8_t elt)
{
  TRUNNEL_DYNARRAY_SET(&inp->auth_key, idx, elt);
  return 0;
}
int
hs_cell_introduce1_add_auth_key(hs_cell_introduce1_t *inp, uint8_t elt)
{
#if SIZE_MAX >= UINT16_MAX
  if (inp->auth_key.n_ == UINT16_MAX)
    goto trunnel_alloc_failed;
#endif
  TRUNNEL_DYNARRAY_ADD(uint8_t, &inp->auth_key, elt, {});
  return 0;
 trunnel_alloc_failed:
  TRUNNEL_SET_ERROR_CODE(inp);
  return -1;
}

uint8_t *
hs_cell_introduce1_getarray_auth_key(hs_cell_introduce1_t *inp)
{
  return inp->auth_key.elts_;
}
const uint8_t  *
hs_cell_introduce1_getconstarray_auth_key(const hs_cell_introduce1_t *inp)
{
  return (const uint8_t  *)hs_cell_introduce1_getarray_auth_key((hs_cell_introduce1_t*)inp);
}
int
hs_cell_introduce1_setlen_auth_key(hs_cell_introduce1_t *inp, size_t newlen)
{
  uint8_t *newptr;
#if UINT16_MAX < SIZE_MAX
  if (newlen > UINT16_MAX)
    goto trunnel_alloc_failed;
#endif
  newptr = trunnel_dynarray_setlen(&inp->auth_key.allocated_,
                 &inp->auth_key.n_, inp->auth_key.elts_, newlen,
                 sizeof(inp->auth_key.elts_[0]), (trunnel_free_fn_t) NULL,
                 &inp->trunnel_error_code_);
  if (newlen != 0 && newptr == NULL)
    goto trunnel_alloc_failed;
  inp->auth_key.elts_ = newptr;
  return 0;
 trunnel_alloc_failed:
  TRUNNEL_SET_ERROR_CODE(inp);
  return -1;
}
struct cell_extension_st *
hs_cell_introduce1_get_extensions(hs_cell_introduce1_t *inp)
{
  return inp->extensions;
}
const struct cell_extension_st *
hs_cell_introduce1_getconst_extensions(const hs_cell_introduce1_t *inp)
{
  return hs_cell_introduce1_get_extensions((hs_cell_introduce1_t*) inp);
}
int
hs_cell_introduce1_set_extensions(hs_cell_introduce1_t *inp, struct cell_extension_st *val)
{
  if (inp->extensions && inp->extensions != val)
    cell_extension_free(inp->extensions);
  return hs_cell_introduce1_set0_extensions(inp, val);
}
int
hs_cell_introduce1_set0_extensions(hs_cell_introduce1_t *inp, struct cell_extension_st *val)
{
  inp->extensions = val;
  return 0;
}
size_t
hs_cell_introduce1_getlen_encrypted(const hs_cell_introduce1_t *inp)
{
  return TRUNNEL_DYNARRAY_LEN(&inp->encrypted);
}

uint8_t
hs_cell_introduce1_get_encrypted(hs_cell_introduce1_t *inp, size_t idx)
{
  return TRUNNEL_DYNARRAY_GET(&inp->encrypted, idx);
}

uint8_t
hs_cell_introduce1_getconst_encrypted(const hs_cell_introduce1_t *inp, size_t idx)
{
  return hs_cell_introduce1_get_encrypted((hs_cell_introduce1_t*)inp, idx);
}
int
hs_cell_introduce1_set_encrypted(hs_cell_introduce1_t *inp, size_t idx, uint8_t elt)
{
  TRUNNEL_DYNARRAY_SET(&inp->encrypted, idx, elt);
  return 0;
}
int
hs_cell_introduce1_add_encrypted(hs_cell_introduce1_t *inp, uint8_t elt)
{
  TRUNNEL_DYNARRAY_ADD(uint8_t, &inp->encrypted, elt, {});
  return 0;
 trunnel_alloc_failed:
  TRUNNEL_SET_ERROR_CODE(inp);
  return -1;
}

uint8_t *
hs_cell_introduce1_getarray_encrypted(hs_cell_introduce1_t *inp)
{
  return inp->encrypted.elts_;
}
const uint8_t  *
hs_cell_introduce1_getconstarray_encrypted(const hs_cell_introduce1_t *inp)
{
  return (const uint8_t  *)hs_cell_introduce1_getarray_encrypted((hs_cell_introduce1_t*)inp);
}
int
hs_cell_introduce1_setlen_encrypted(hs_cell_introduce1_t *inp, size_t newlen)
{
  uint8_t *newptr;
  newptr = trunnel_dynarray_setlen(&inp->encrypted.allocated_,
                 &inp->encrypted.n_, inp->encrypted.elts_, newlen,
                 sizeof(inp->encrypted.elts_[0]), (trunnel_free_fn_t) NULL,
                 &inp->trunnel_error_code_);
  if (newlen != 0 && newptr == NULL)
    goto trunnel_alloc_failed;
  inp->encrypted.elts_ = newptr;
  return 0;
 trunnel_alloc_failed:
  TRUNNEL_SET_ERROR_CODE(inp);
  return -1;
}
const char *
hs_cell_introduce1_check(const hs_cell_introduce1_t *obj)
{
  if (obj == NULL)
    return "Object was NULL";
  if (obj->trunnel_error_code_)
    return "A set function failed on this object";
  if (! (obj->auth_key_type == 0 || obj->auth_key_type == 1 || obj->auth_key_type == 2))
    return "Integer out of bounds";
  if (TRUNNEL_DYNARRAY_LEN(&obj->auth_key) != obj->auth_key_len)
    return "Length mismatch for auth_key";
  {
    const char *msg;
    if (NULL != (msg = cell_extension_check(obj->extensions)))
      return msg;
  }
  return NULL;
}

ssize_t
hs_cell_introduce1_encoded_len(const hs_cell_introduce1_t *obj)
{
  ssize_t result = 0;

  if (NULL != hs_cell_introduce1_check(obj))
     return -1;


  /* Length of u8 legacy_key_id[TRUNNEL_SHA1_LEN] */
  result += TRUNNEL_SHA1_LEN;

  /* Length of u8 auth_key_type IN [0, 1, 2] */
  result += 1;

  /* Length of u16 auth_key_len */
  result += 2;

  /* Length of u8 auth_key[auth_key_len] */
  result += TRUNNEL_DYNARRAY_LEN(&obj->auth_key);

  /* Length of struct cell_extension extensions */
  result += cell_extension_encoded_len(obj->extensions);

  /* Length of u8 encrypted[] */
  result += TRUNNEL_DYNARRAY_LEN(&obj->encrypted);
  return result;
}
int
hs_cell_introduce1_clear_errors(hs_cell_introduce1_t *obj)
{
  int r = obj->trunnel_error_code_;
  obj->trunnel_error_code_ = 0;
  return r;
}
ssize_t
hs_cell_introduce1_encode(uint8_t *output, const size_t avail, const hs_cell_introduce1_t *obj)
{
  ssize_t result = 0;
  size_t written = 0;
  uint8_t *ptr = output;
  const char *msg;
#ifdef TRUNNEL_CHECK_ENCODED_LEN
  const ssize_t encoded_len = hs_cell_introduce1_encoded_len(obj);
#endif

  if (NULL != (msg = hs_cell_introduce1_check(obj)))
    goto check_failed;

#ifdef TRUNNEL_CHECK_ENCODED_LEN
  trunnel_assert(encoded_len >= 0);
#endif

  /* Encode u8 legacy_key_id[TRUNNEL_SHA1_LEN] */
  trunnel_assert(written <= avail);
  if (avail - written < TRUNNEL_SHA1_LEN)
    goto truncated;
  memcpy(ptr, obj->legacy_key_id, TRUNNEL_SHA1_LEN);
  written += TRUNNEL_SHA1_LEN; ptr += TRUNNEL_SHA1_LEN;

  /* Encode u8 auth_key_type IN [0, 1, 2] */
  trunnel_assert(written <= avail);
  if (avail - written < 1)
    goto truncated;
  trunnel_set_uint8(ptr, (obj->auth_key_type));
  written += 1; ptr += 1;

  /* Encode u16 auth_key_len */
  trunnel_assert(written <= avail);
  if (avail - written < 2)
    goto truncated;
  trunnel_set_uint16(ptr, trunnel_htons(obj->auth_key_len));
  written += 2; ptr += 2;

  /* Encode u8 auth_key[auth_key_len] */
  {
    size_t elt_len = TRUNNEL_DYNARRAY_LEN(&obj->auth_key);
    trunnel_assert(obj->auth_key_len == elt_len);
    trunnel_assert(written <= avail);
    if (avail - written < elt_len)
      goto truncated;
    if (elt_len)
      memcpy(ptr, obj->auth_key.elts_, elt_len);
    written += elt_len; ptr += elt_len;
  }

  /* Encode struct cell_extension extensions */
  trunnel_assert(written <= avail);
  result = cell_extension_encode(ptr, avail - written, obj->extensions);
  if (result < 0)
    goto fail; /* XXXXXXX !*/
  written += result; ptr += result;

  /* Encode u8 encrypted[] */
  {
    size_t elt_len = TRUNNEL_DYNARRAY_LEN(&obj->encrypted);
    trunnel_assert(written <= avail);
    if (avail - written < elt_len)
      goto truncated;
    if (elt_len)
      memcpy(ptr, obj->encrypted.elts_, elt_len);
    written += elt_len; ptr += elt_len;
  }


  trunnel_assert(ptr == output + written);
#ifdef TRUNNEL_CHECK_ENCODED_LEN
  {
    trunnel_assert(encoded_len >= 0);
    trunnel_assert((size_t)encoded_len == written);
  }

#endif

  return written;

 truncated:
  result = -2;
  goto fail;
 check_failed:
  (void)msg;
  result = -1;
  goto fail;
 fail:
  trunnel_assert(result < 0);
  return result;
}

/** As hs_cell_introduce1_parse(), but do not allocate the output
 * object.
 */
static ssize_t
hs_cell_introduce1_parse_into(hs_cell_introduce1_t *obj, const uint8_t *input, const size_t len_in)
{
  const uint8_t *ptr = input;
  size_t remaining = len_in;
  ssize_t result = 0;
  (void)result;

  /* Parse u8 legacy_key_id[TRUNNEL_SHA1_LEN] */
  CHECK_REMAINING(TRUNNEL_SHA1_LEN, truncated);
  memcpy(obj->legacy_key_id, ptr, TRUNNEL_SHA1_LEN);
  remaining -= TRUNNEL_SHA1_LEN; ptr += TRUNNEL_SHA1_LEN;

  /* Parse u8 auth_key_type IN [0, 1, 2] */
  CHECK_REMAINING(1, truncated);
  obj->auth_key_type = (trunnel_get_uint8(ptr));
  remaining -= 1; ptr += 1;
  if (! (obj->auth_key_type == 0 || obj->auth_key_type == 1 || obj->auth_key_type == 2))
    goto fail;

  /* Parse u16 auth_key_len */
  CHECK_REMAINING(2, truncated);
  obj->auth_key_len = trunnel_ntohs(trunnel_get_uint16(ptr));
  remaining -= 2; ptr += 2;

  /* Parse u8 auth_key[auth_key_len] */
  CHECK_REMAINING(obj->auth_key_len, truncated);
  TRUNNEL_DYNARRAY_EXPAND(uint8_t, &obj->auth_key, obj->auth_key_len, {});
  obj->auth_key.n_ = obj->auth_key_len;
  if (obj->auth_key_len)
    memcpy(obj->auth_key.elts_, ptr, obj->auth_key_len);
  ptr += obj->auth_key_len; remaining -= obj->auth_key_len;

  /* Parse struct cell_extension extensions */
  result = cell_extension_parse(&obj->extensions, ptr, remaining);
  if (result < 0)
    goto relay_fail;
  trunnel_assert((size_t)result <= remaining);
  remaining -= result; ptr += result;

  /* Parse u8 encrypted[] */
  TRUNNEL_DYNARRAY_EXPAND(uint8_t, &obj->encrypted, remaining, {});
  obj->encrypted.n_ = remaining;
  if (remaining)
    memcpy(obj->encrypted.elts_, ptr, remaining);
  ptr += remaining; remaining -= remaining;
  trunnel_assert(ptr + remaining == input + len_in);
  return len_in - remaining;

 truncated:
  return -2;
 relay_fail:
  trunnel_assert(result < 0);
  return result;
 trunnel_alloc_failed:
  return -1;
 fail:
  result = -1;
  return result;
}

ssize_t
hs_cell_introduce1_parse(hs_cell_introduce1_t **output, const uint8_t *input, const size_t len_in)
{
  ssize_t result;
  *output = hs_cell_introduce1_new();
  if (NULL == *output)
    return -1;
  result = hs_cell_introduce1_parse_into(*output, input, len_in);
  if (result < 0) {
    hs_cell_introduce1_free(*output);
    *output = NULL;
  }
  return result;
}
hs_cell_introduce_ack_t *
hs_cell_introduce_ack_new(void)
{
  hs_cell_introduce_ack_t *val = trunnel_calloc(1, sizeof(hs_cell_introduce_ack_t));
  if (NULL == val)
    return NULL;
  return val;
}

/** Release all storage held inside 'obj', but do not free 'obj'.
 */
static void
hs_cell_introduce_ack_clear(hs_cell_introduce_ack_t *obj)
{
  (void) obj;
  cell_extension_free(obj->extensions);
  obj->extensions = NULL;
}

void
hs_cell_introduce_ack_free(hs_cell_introduce_ack_t *obj)
{
  if (obj == NULL)
    return;
  hs_cell_introduce_ack_clear(obj);
  trunnel_memwipe(obj, sizeof(hs_cell_introduce_ack_t));
  trunnel_free_(obj);
}

uint16_t
hs_cell_introduce_ack_get_status(const hs_cell_introduce_ack_t *inp)
{
  return inp->status;
}
int
hs_cell_introduce_ack_set_status(hs_cell_introduce_ack_t *inp, uint16_t val)
{
  if (! ((val == 0 || val == 1 || val == 2))) {
     TRUNNEL_SET_ERROR_CODE(inp);
     return -1;
  }
  inp->status = val;
  return 0;
}
struct cell_extension_st *
hs_cell_introduce_ack_get_extensions(hs_cell_introduce_ack_t *inp)
{
  return inp->extensions;
}
const struct cell_extension_st *
hs_cell_introduce_ack_getconst_extensions(const hs_cell_introduce_ack_t *inp)
{
  return hs_cell_introduce_ack_get_extensions((hs_cell_introduce_ack_t*) inp);
}
int
hs_cell_introduce_ack_set_extensions(hs_cell_introduce_ack_t *inp, struct cell_extension_st *val)
{
  if (inp->extensions && inp->extensions != val)
    cell_extension_free(inp->extensions);
  return hs_cell_introduce_ack_set0_extensions(inp, val);
}
int
hs_cell_introduce_ack_set0_extensions(hs_cell_introduce_ack_t *inp, struct cell_extension_st *val)
{
  inp->extensions = val;
  return 0;
}
const char *
hs_cell_introduce_ack_check(const hs_cell_introduce_ack_t *obj)
{
  if (obj == NULL)
    return "Object was NULL";
  if (obj->trunnel_error_code_)
    return "A set function failed on this object";
  if (! (obj->status == 0 || obj->status == 1 || obj->status == 2))
    return "Integer out of bounds";
  {
    const char *msg;
    if (NULL != (msg = cell_extension_check(obj->extensions)))
      return msg;
  }
  return NULL;
}

ssize_t
hs_cell_introduce_ack_encoded_len(const hs_cell_introduce_ack_t *obj)
{
  ssize_t result = 0;

  if (NULL != hs_cell_introduce_ack_check(obj))
     return -1;


  /* Length of u16 status IN [0, 1, 2] */
  result += 2;

  /* Length of struct cell_extension extensions */
  result += cell_extension_encoded_len(obj->extensions);
  return result;
}
int
hs_cell_introduce_ack_clear_errors(hs_cell_introduce_ack_t *obj)
{
  int r = obj->trunnel_error_code_;
  obj->trunnel_error_code_ = 0;
  return r;
}
ssize_t
hs_cell_introduce_ack_encode(uint8_t *output, const size_t avail, const hs_cell_introduce_ack_t *obj)
{
  ssize_t result = 0;
  size_t written = 0;
  uint8_t *ptr = output;
  const char *msg;
#ifdef TRUNNEL_CHECK_ENCODED_LEN
  const ssize_t encoded_len = hs_cell_introduce_ack_encoded_len(obj);
#endif

  if (NULL != (msg = hs_cell_introduce_ack_check(obj)))
    goto check_failed;

#ifdef TRUNNEL_CHECK_ENCODED_LEN
  trunnel_assert(encoded_len >= 0);
#endif

  /* Encode u16 status IN [0, 1, 2] */
  trunnel_assert(written <= avail);
  if (avail - written < 2)
    goto truncated;
  trunnel_set_uint16(ptr, trunnel_htons(obj->status));
  written += 2; ptr += 2;

  /* Encode struct cell_extension extensions */
  trunnel_assert(written <= avail);
  result = cell_extension_encode(ptr, avail - written, obj->extensions);
  if (result < 0)
    goto fail; /* XXXXXXX !*/
  written += result; ptr += result;


  trunnel_assert(ptr == output + written);
#ifdef TRUNNEL_CHECK_ENCODED_LEN
  {
    trunnel_assert(encoded_len >= 0);
    trunnel_assert((size_t)encoded_len == written);
  }

#endif

  return written;

 truncated:
  result = -2;
  goto fail;
 check_failed:
  (void)msg;
  result = -1;
  goto fail;
 fail:
  trunnel_assert(result < 0);
  return result;
}

/** As hs_cell_introduce_ack_parse(), but do not allocate the output
 * object.
 */
static ssize_t
hs_cell_introduce_ack_parse_into(hs_cell_introduce_ack_t *obj, const uint8_t *input, const size_t len_in)
{
  const uint8_t *ptr = input;
  size_t remaining = len_in;
  ssize_t result = 0;
  (void)result;

  /* Parse u16 status IN [0, 1, 2] */
  CHECK_REMAINING(2, truncated);
  obj->status = trunnel_ntohs(trunnel_get_uint16(ptr));
  remaining -= 2; ptr += 2;
  if (! (obj->status == 0 || obj->status == 1 || obj->status == 2))
    goto fail;

  /* Parse struct cell_extension extensions */
  result = cell_extension_parse(&obj->extensions, ptr, remaining);
  if (result < 0)
    goto relay_fail;
  trunnel_assert((size_t)result <= remaining);
  remaining -= result; ptr += result;
  trunnel_assert(ptr + remaining == input + len_in);
  return len_in - remaining;

 truncated:
  return -2;
 relay_fail:
  trunnel_assert(result < 0);
  return result;
 fail:
  result = -1;
  return result;
}

ssize_t
hs_cell_introduce_ack_parse(hs_cell_introduce_ack_t **output, const uint8_t *input, const size_t len_in)
{
  ssize_t result;
  *output = hs_cell_introduce_ack_new();
  if (NULL == *output)
    return -1;
  result = hs_cell_introduce_ack_parse_into(*output, input, len_in);
  if (result < 0) {
    hs_cell_introduce_ack_free(*output);
    *output = NULL;
  }
  return result;
}
hs_cell_introduce_encrypted_t *
hs_cell_introduce_encrypted_new(void)
{
  hs_cell_introduce_encrypted_t *val = trunnel_calloc(1, sizeof(hs_cell_introduce_encrypted_t));
  if (NULL == val)
    return NULL;
  val->onion_key_type = 1;
  return val;
}

/** Release all storage held inside 'obj', but do not free 'obj'.
 */
static void
hs_cell_introduce_encrypted_clear(hs_cell_introduce_encrypted_t *obj)
{
  (void) obj;
  cell_extension_free(obj->extensions);
  obj->extensions = NULL;
  TRUNNEL_DYNARRAY_WIPE(&obj->onion_key);
  TRUNNEL_DYNARRAY_CLEAR(&obj->onion_key);
  {

    unsigned idx;
    for (idx = 0; idx < TRUNNEL_DYNARRAY_LEN(&obj->nspecs); ++idx) {
      link_specifier_free(TRUNNEL_DYNARRAY_GET(&obj->nspecs, idx));
    }
  }
  TRUNNEL_DYNARRAY_WIPE(&obj->nspecs);
  TRUNNEL_DYNARRAY_CLEAR(&obj->nspecs);
  TRUNNEL_DYNARRAY_WIPE(&obj->pad);
  TRUNNEL_DYNARRAY_CLEAR(&obj->pad);
}

void
hs_cell_introduce_encrypted_free(hs_cell_introduce_encrypted_t *obj)
{
  if (obj == NULL)
    return;
  hs_cell_introduce_encrypted_clear(obj);
  trunnel_memwipe(obj, sizeof(hs_cell_introduce_encrypted_t));
  trunnel_free_(obj);
}

size_t
hs_cell_introduce_encrypted_getlen_rend_cookie(const hs_cell_introduce_encrypted_t *inp)
{
  (void)inp;  return TRUNNEL_REND_COOKIE_LEN;
}

uint8_t
hs_cell_introduce_encrypted_get_rend_cookie(hs_cell_introduce_encrypted_t *inp, size_t idx)
{
  trunnel_assert(idx < TRUNNEL_REND_COOKIE_LEN);
  return inp->rend_cookie[idx];
}

uint8_t
hs_cell_introduce_encrypted_getconst_rend_cookie(const hs_cell_introduce_encrypted_t *inp, size_t idx)
{
  return hs_cell_introduce_encrypted_get_rend_cookie((hs_cell_introduce_encrypted_t*)inp, idx);
}
int
hs_cell_introduce_encrypted_set_rend_cookie(hs_cell_introduce_encrypted_t *inp, size_t idx, uint8_t elt)
{
  trunnel_assert(idx < TRUNNEL_REND_COOKIE_LEN);
  inp->rend_cookie[idx] = elt;
  return 0;
}

uint8_t *
hs_cell_introduce_encrypted_getarray_rend_cookie(hs_cell_introduce_encrypted_t *inp)
{
  return inp->rend_cookie;
}
const uint8_t  *
hs_cell_introduce_encrypted_getconstarray_rend_cookie(const hs_cell_introduce_encrypted_t *inp)
{
  return (const uint8_t  *)hs_cell_introduce_encrypted_getarray_rend_cookie((hs_cell_introduce_encrypted_t*)inp);
}
struct cell_extension_st *
hs_cell_introduce_encrypted_get_extensions(hs_cell_introduce_encrypted_t *inp)
{
  return inp->extensions;
}
const struct cell_extension_st *
hs_cell_introduce_encrypted_getconst_extensions(const hs_cell_introduce_encrypted_t *inp)
{
  return hs_cell_introduce_encrypted_get_extensions((hs_cell_introduce_encrypted_t*) inp);
}
int
hs_cell_introduce_encrypted_set_extensions(hs_cell_introduce_encrypted_t *inp, struct cell_extension_st *val)
{
  if (inp->extensions && inp->extensions != val)
    cell_extension_free(inp->extensions);
  return hs_cell_introduce_encrypted_set0_extensions(inp, val);
}
int
hs_cell_introduce_encrypted_set0_extensions(hs_cell_introduce_encrypted_t *inp, struct cell_extension_st *val)
{
  inp->extensions = val;
  return 0;
}
uint8_t
hs_cell_introduce_encrypted_get_onion_key_type(const hs_cell_introduce_encrypted_t *inp)
{
  return inp->onion_key_type;
}
int
hs_cell_introduce_encrypted_set_onion_key_type(hs_cell_introduce_encrypted_t *inp, uint8_t val)
{
  if (! ((val == 1))) {
     TRUNNEL_SET_ERROR_CODE(inp);
     return -1;
  }
  inp->onion_key_type = val;
  return 0;
}
uint16_t
hs_cell_introduce_encrypted_get_onion_key_len(const hs_cell_introduce_encrypted_t *inp)
{
  return inp->onion_key_len;
}
int
hs_cell_introduce_encrypted_set_onion_key_len(hs_cell_introduce_encrypted_t *inp, uint16_t val)
{
  inp->onion_key_len = val;
  return 0;
}
size_t
hs_cell_introduce_encrypted_getlen_onion_key(const hs_cell_introduce_encrypted_t *inp)
{
  return TRUNNEL_DYNARRAY_LEN(&inp->onion_key);
}

uint8_t
hs_cell_introduce_encrypted_get_onion_key(hs_cell_introduce_encrypted_t *inp, size_t idx)
{
  return TRUNNEL_DYNARRAY_GET(&inp->onion_key, idx);
}

uint8_t
hs_cell_introduce_encrypted_getconst_onion_key(const hs_cell_introduce_encrypted_t *inp, size_t idx)
{
  return hs_cell_introduce_encrypted_get_onion_key((hs_cell_introduce_encrypted_t*)inp, idx);
}
int
hs_cell_introduce_encrypted_set_onion_key(hs_cell_introduce_encrypted_t *inp, size_t idx, uint8_t elt)
{
  TRUNNEL_DYNARRAY_SET(&inp->onion_key, idx, elt);
  return 0;
}
int
hs_cell_introduce_encrypted_add_onion_key(hs_cell_introduce_encrypted_t *inp, uint8_t elt)
{
#if SIZE_MAX >= UINT16_MAX
  if (inp->onion_key.n_ == UINT16_MAX)
    goto trunnel_alloc_failed;
#endif
  TRUNNEL_DYNARRAY_ADD(uint8_t, &inp->onion_key, elt, {});
  return 0;
 trunnel_alloc_failed:
  TRUNNEL_SET_ERROR_CODE(inp);
  return -1;
}

uint8_t *
hs_cell_introduce_encrypted_getarray_onion_key(hs_cell_introduce_encrypted_t *inp)
{
  return inp->onion_key.elts_;
}
const uint8_t  *
hs_cell_introduce_encrypted_getconstarray_onion_key(const hs_cell_introduce_encrypted_t *inp)
{
  return (const uint8_t  *)hs_cell_introduce_encrypted_getarray_onion_key((hs_cell_introduce_encrypted_t*)inp);
}
int
hs_cell_introduce_encrypted_setlen_onion_key(hs_cell_introduce_encrypted_t *inp, size_t newlen)
{
  uint8_t *newptr;
#if UINT16_MAX < SIZE_MAX
  if (newlen > UINT16_MAX)
    goto trunnel_alloc_failed;
#endif
  newptr = trunnel_dynarray_setlen(&inp->onion_key.allocated_,
                 &inp->onion_key.n_, inp->onion_key.elts_, newlen,
                 sizeof(inp->onion_key.elts_[0]), (trunnel_free_fn_t) NULL,
                 &inp->trunnel_error_code_);
  if (newlen != 0 && newptr == NULL)
    goto trunnel_alloc_failed;
  inp->onion_key.elts_ = newptr;
  return 0;
 trunnel_alloc_failed:
  TRUNNEL_SET_ERROR_CODE(inp);
  return -1;
}
uint8_t
hs_cell_introduce_encrypted_get_nspec(const hs_cell_introduce_encrypted_t *inp)
{
  return inp->nspec;
}
int
hs_cell_introduce_encrypted_set_nspec(hs_cell_introduce_encrypted_t *inp, uint8_t val)
{
  inp->nspec = val;
  return 0;
}
size_t
hs_cell_introduce_encrypted_getlen_nspecs(const hs_cell_introduce_encrypted_t *inp)
{
  return TRUNNEL_DYNARRAY_LEN(&inp->nspecs);
}

struct link_specifier_st *
hs_cell_introduce_encrypted_get_nspecs(hs_cell_introduce_encrypted_t *inp, size_t idx)
{
  return TRUNNEL_DYNARRAY_GET(&inp->nspecs, idx);
}

 const struct link_specifier_st *
hs_cell_introduce_encrypted_getconst_nspecs(const hs_cell_introduce_encrypted_t *inp, size_t idx)
{
  return hs_cell_introduce_encrypted_get_nspecs((hs_cell_introduce_encrypted_t*)inp, idx);
}
int
hs_cell_introduce_encrypted_set_nspecs(hs_cell_introduce_encrypted_t *inp, size_t idx, struct link_specifier_st * elt)
{
  link_specifier_t *oldval = TRUNNEL_DYNARRAY_GET(&inp->nspecs, idx);
  if (oldval && oldval != elt)
    link_specifier_free(oldval);
  return hs_cell_introduce_encrypted_set0_nspecs(inp, idx, elt);
}
int
hs_cell_introduce_encrypted_set0_nspecs(hs_cell_introduce_encrypted_t *inp, size_t idx, struct link_specifier_st * elt)
{
  TRUNNEL_DYNARRAY_SET(&inp->nspecs, idx, elt);
  return 0;
}
int
hs_cell_introduce_encrypted_add_nspecs(hs_cell_introduce_encrypted_t *inp, struct link_specifier_st * elt)
{
#if SIZE_MAX >= UINT8_MAX
  if (inp->nspecs.n_ == UINT8_MAX)
    goto trunnel_alloc_failed;
#endif
  TRUNNEL_DYNARRAY_ADD(struct link_specifier_st *, &inp->nspecs, elt, {});
  return 0;
 trunnel_alloc_failed:
  TRUNNEL_SET_ERROR_CODE(inp);
  return -1;
}

struct link_specifier_st * *
hs_cell_introduce_encrypted_getarray_nspecs(hs_cell_introduce_encrypted_t *inp)
{
  return inp->nspecs.elts_;
}
const struct link_specifier_st *  const  *
hs_cell_introduce_encrypted_getconstarray_nspecs(const hs_cell_introduce_encrypted_t *inp)
{
  return (const struct link_specifier_st *  const  *)hs_cell_introduce_encrypted_getarray_nspecs((hs_cell_introduce_encrypted_t*)inp);
}
int
hs_cell_introduce_encrypted_setlen_nspecs(hs_cell_introduce_encrypted_t *inp, size_t newlen)
{
  struct link_specifier_st * *newptr;
#if UINT8_MAX < SIZE_MAX
  if (newlen > UINT8_MAX)
    goto trunnel_alloc_failed;
#endif
  newptr = trunnel_dynarray_setlen(&inp->nspecs.allocated_,
                 &inp->nspecs.n_, inp->nspecs.elts_, newlen,
                 sizeof(inp->nspecs.elts_[0]), (trunnel_free_fn_t) link_specifier_free,
                 &inp->trunnel_error_code_);
  if (newlen != 0 && newptr == NULL)
    goto trunnel_alloc_failed;
  inp->nspecs.elts_ = newptr;
  return 0;
 trunnel_alloc_failed:
  TRUNNEL_SET_ERROR_CODE(inp);
  return -1;
}
size_t
hs_cell_introduce_encrypted_getlen_pad(const hs_cell_introduce_encrypted_t *inp)
{
  return TRUNNEL_DYNARRAY_LEN(&inp->pad);
}

uint8_t
hs_cell_introduce_encrypted_get_pad(hs_cell_introduce_encrypted_t *inp, size_t idx)
{
  return TRUNNEL_DYNARRAY_GET(&inp->pad, idx);
}

uint8_t
hs_cell_introduce_encrypted_getconst_pad(const hs_cell_introduce_encrypted_t *inp, size_t idx)
{
  return hs_cell_introduce_encrypted_get_pad((hs_cell_introduce_encrypted_t*)inp, idx);
}
int
hs_cell_introduce_encrypted_set_pad(hs_cell_introduce_encrypted_t *inp, size_t idx, uint8_t elt)
{
  TRUNNEL_DYNARRAY_SET(&inp->pad, idx, elt);
  return 0;
}
int
hs_cell_introduce_encrypted_add_pad(hs_cell_introduce_encrypted_t *inp, uint8_t elt)
{
  TRUNNEL_DYNARRAY_ADD(uint8_t, &inp->pad, elt, {});
  return 0;
 trunnel_alloc_failed:
  TRUNNEL_SET_ERROR_CODE(inp);
  return -1;
}

uint8_t *
hs_cell_introduce_encrypted_getarray_pad(hs_cell_introduce_encrypted_t *inp)
{
  return inp->pad.elts_;
}
const uint8_t  *
hs_cell_introduce_encrypted_getconstarray_pad(const hs_cell_introduce_encrypted_t *inp)
{
  return (const uint8_t  *)hs_cell_introduce_encrypted_getarray_pad((hs_cell_introduce_encrypted_t*)inp);
}
int
hs_cell_introduce_encrypted_setlen_pad(hs_cell_introduce_encrypted_t *inp, size_t newlen)
{
  uint8_t *newptr;
  newptr = trunnel_dynarray_setlen(&inp->pad.allocated_,
                 &inp->pad.n_, inp->pad.elts_, newlen,
                 sizeof(inp->pad.elts_[0]), (trunnel_free_fn_t) NULL,
                 &inp->trunnel_error_code_);
  if (newlen != 0 && newptr == NULL)
    goto trunnel_alloc_failed;
  inp->pad.elts_ = newptr;
  return 0;
 trunnel_alloc_failed:
  TRUNNEL_SET_ERROR_CODE(inp);
  return -1;
}
const char *
hs_cell_introduce_encrypted_check(const hs_cell_introduce_encrypted_t *obj)
{
  if (obj == NULL)
    return "Object was NULL";
  if (obj->trunnel_error_code_)
    return "A set function failed on this object";
  {
    const char *msg;
    if (NULL != (msg = cell_extension_check(obj->extensions)))
      return msg;
  }
  if (! (obj->onion_key_type == 1))
    return "Integer out of bounds";
  if (TRUNNEL_DYNARRAY_LEN(&obj->onion_key) != obj->onion_key_len)
    return "Length mismatch for onion_key";
  {
    const char *msg;

    unsigned idx;
    for (idx = 0; idx < TRUNNEL_DYNARRAY_LEN(&obj->nspecs); ++idx) {
      if (NULL != (msg = link_specifier_check(TRUNNEL_DYNARRAY_GET(&obj->nspecs, idx))))
        return msg;
    }
  }
  if (TRUNNEL_DYNARRAY_LEN(&obj->nspecs) != obj->nspec)
    return "Length mismatch for nspecs";
  return NULL;
}

ssize_t
hs_cell_introduce_encrypted_encoded_len(const hs_cell_introduce_encrypted_t *obj)
{
  ssize_t result = 0;

  if (NULL != hs_cell_introduce_encrypted_check(obj))
     return -1;


  /* Length of u8 rend_cookie[TRUNNEL_REND_COOKIE_LEN] */
  result += TRUNNEL_REND_COOKIE_LEN;

  /* Length of struct cell_extension extensions */
  result += cell_extension_encoded_len(obj->extensions);

  /* Length of u8 onion_key_type IN [1] */
  result += 1;

  /* Length of u16 onion_key_len */
  result += 2;

  /* Length of u8 onion_key[onion_key_len] */
  result += TRUNNEL_DYNARRAY_LEN(&obj->onion_key);

  /* Length of u8 nspec */
  result += 1;

  /* Length of struct link_specifier nspecs[nspec] */
  {

    unsigned idx;
    for (idx = 0; idx < TRUNNEL_DYNARRAY_LEN(&obj->nspecs); ++idx) {
      result += link_specifier_encoded_len(TRUNNEL_DYNARRAY_GET(&obj->nspecs, idx));
    }
  }

  /* Length of u8 pad[] */
  result += TRUNNEL_DYNARRAY_LEN(&obj->pad);
  return result;
}
int
hs_cell_introduce_encrypted_clear_errors(hs_cell_introduce_encrypted_t *obj)
{
  int r = obj->trunnel_error_code_;
  obj->trunnel_error_code_ = 0;
  return r;
}
ssize_t
hs_cell_introduce_encrypted_encode(uint8_t *output, const size_t avail, const hs_cell_introduce_encrypted_t *obj)
{
  ssize_t result = 0;
  size_t written = 0;
  uint8_t *ptr = output;
  const char *msg;
#ifdef TRUNNEL_CHECK_ENCODED_LEN
  const ssize_t encoded_len = hs_cell_introduce_encrypted_encoded_len(obj);
#endif

  if (NULL != (msg = hs_cell_introduce_encrypted_check(obj)))
    goto check_failed;

#ifdef TRUNNEL_CHECK_ENCODED_LEN
  trunnel_assert(encoded_len >= 0);
#endif

  /* Encode u8 rend_cookie[TRUNNEL_REND_COOKIE_LEN] */
  trunnel_assert(written <= avail);
  if (avail - written < TRUNNEL_REND_COOKIE_LEN)
    goto truncated;
  memcpy(ptr, obj->rend_cookie, TRUNNEL_REND_COOKIE_LEN);
  written += TRUNNEL_REND_COOKIE_LEN; ptr += TRUNNEL_REND_COOKIE_LEN;

  /* Encode struct cell_extension extensions */
  trunnel_assert(written <= avail);
  result = cell_extension_encode(ptr, avail - written, obj->extensions);
  if (result < 0)
    goto fail; /* XXXXXXX !*/
  written += result; ptr += result;

  /* Encode u8 onion_key_type IN [1] */
  trunnel_assert(written <= avail);
  if (avail - written < 1)
    goto truncated;
  trunnel_set_uint8(ptr, (obj->onion_key_type));
  written += 1; ptr += 1;

  /* Encode u16 onion_key_len */
  trunnel_assert(written <= avail);
  if (avail - written < 2)
    goto truncated;
  trunnel_set_uint16(ptr, trunnel_htons(obj->onion_key_len));
  written += 2; ptr += 2;

  /* Encode u8 onion_key[onion_key_len] */
  {
    size_t elt_len = TRUNNEL_DYNARRAY_LEN(&obj->onion_key);
    trunnel_assert(obj->onion_key_len == elt_len);
    trunnel_assert(written <= avail);
    if (avail - written < elt_len)
      goto truncated;
    if (elt_len)
      memcpy(ptr, obj->onion_key.elts_, elt_len);
    written += elt_len; ptr += elt_len;
  }

  /* Encode u8 nspec */
  trunnel_assert(written <= avail);
  if (avail - written < 1)
    goto truncated;
  trunnel_set_uint8(ptr, (obj->nspec));
  written += 1; ptr += 1;

  /* Encode struct link_specifier nspecs[nspec] */
  {

    unsigned idx;
    for (idx = 0; idx < TRUNNEL_DYNARRAY_LEN(&obj->nspecs); ++idx) {
      trunnel_assert(written <= avail);
      result = link_specifier_encode(ptr, avail - written, TRUNNEL_DYNARRAY_GET(&obj->nspecs, idx));
      if (result < 0)
        goto fail; /* XXXXXXX !*/
      written += result; ptr += result;
    }
  }

  /* Encode u8 pad[] */
  {
    size_t elt_len = TRUNNEL_DYNARRAY_LEN(&obj->pad);
    trunnel_assert(written <= avail);
    if (avail - written < elt_len)
      goto truncated;
    if (elt_len)
      memcpy(ptr, obj->pad.elts_, elt_len);
    written += elt_len; ptr += elt_len;
  }


  trunnel_assert(ptr == output + written);
#ifdef TRUNNEL_CHECK_ENCODED_LEN
  {
    trunnel_assert(encoded_len >= 0);
    trunnel_assert((size_t)encoded_len == written);
  }

#endif

  return written;

 truncated:
  result = -2;
  goto fail;
 check_failed:
  (void)msg;
  result = -1;
  goto fail;
 fail:
  trunnel_assert(result < 0);
  return result;
}

/** As hs_cell_introduce_encrypted_parse(), but do not allocate the
 * output object.
 */
static ssize_t
hs_cell_introduce_encrypted_parse_into(hs_cell_introduce_encrypted_t *obj, const uint8_t *input, const size_t len_in)
{
  const uint8_t *ptr = input;
  size_t remaining = len_in;
  ssize_t result = 0;
  (void)result;

  /* Parse u8 rend_cookie[TRUNNEL_REND_COOKIE_LEN] */
  CHECK_REMAINING(TRUNNEL_REND_COOKIE_LEN, truncated);
  memcpy(obj->rend_cookie, ptr, TRUNNEL_REND_COOKIE_LEN);
  remaining -= TRUNNEL_REND_COOKIE_LEN; ptr += TRUNNEL_REND_COOKIE_LEN;

  /* Parse struct cell_extension extensions */
  result = cell_extension_parse(&obj->extensions, ptr, remaining);
  if (result < 0)
    goto relay_fail;
  trunnel_assert((size_t)result <= remaining);
  remaining -= result; ptr += result;

  /* Parse u8 onion_key_type IN [1] */
  CHECK_REMAINING(1, truncated);
  obj->onion_key_type = (trunnel_get_uint8(ptr));
  remaining -= 1; ptr += 1;
  if (! (obj->onion_key_type == 1))
    goto fail;

  /* Parse u16 onion_key_len */
  CHECK_REMAINING(2, truncated);
  obj->onion_key_len = trunnel_ntohs(trunnel_get_uint16(ptr));
  remaining -= 2; ptr += 2;

  /* Parse u8 onion_key[onion_key_len] */
  CHECK_REMAINING(obj->onion_key_len, truncated);
  TRUNNEL_DYNARRAY_EXPAND(uint8_t, &obj->onion_key, obj->onion_key_len, {});
  obj->onion_key.n_ = obj->onion_key_len;
  if (obj->onion_key_len)
    memcpy(obj->onion_key.elts_, ptr, obj->onion_key_len);
  ptr += obj->onion_key_len; remaining -= obj->onion_key_len;

  /* Parse u8 nspec */
  CHECK_REMAINING(1, truncated);
  obj->nspec = (trunnel_get_uint8(ptr));
  remaining -= 1; ptr += 1;

  /* Parse struct link_specifier nspecs[nspec] */
  TRUNNEL_DYNARRAY_EXPAND(link_specifier_t *, &obj->nspecs, obj->nspec, {});
  {
    link_specifier_t * elt;
    unsigned idx;
    for (idx = 0; idx < obj->nspec; ++idx) {
      result = link_specifier_parse(&elt, ptr, remaining);
      if (result < 0)
        goto relay_fail;
      trunnel_assert((size_t)result <= remaining);
      remaining -= result; ptr += result;
      TRUNNEL_DYNARRAY_ADD(link_specifier_t *, &obj->nspecs, elt, {link_specifier_free(elt);});
    }
  }

  /* Parse u8 pad[] */
  TRUNNEL_DYNARRAY_EXPAND(uint8_t, &obj->pad, remaining, {});
  obj->pad.n_ = remaining;
  if (remaining)
    memcpy(obj->pad.elts_, ptr, remaining);
  ptr += remaining; remaining -= remaining;
  trunnel_assert(ptr + remaining == input + len_in);
  return len_in - remaining;

 truncated:
  return -2;
 relay_fail:
  trunnel_assert(result < 0);
  return result;
 trunnel_alloc_failed:
  return -1;
 fail:
  result = -1;
  return result;
}

ssize_t
hs_cell_introduce_encrypted_parse(hs_cell_introduce_encrypted_t **output, const uint8_t *input, const size_t len_in)
{
  ssize_t result;
  *output = hs_cell_introduce_encrypted_new();
  if (NULL == *output)
    return -1;
  result = hs_cell_introduce_encrypted_parse_into(*output, input, len_in);
  if (result < 0) {
    hs_cell_introduce_encrypted_free(*output);
    *output = NULL;
  }
  return result;
}
