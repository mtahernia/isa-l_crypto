/**********************************************************************
  Copyright(c) 2024 Intel Corporation All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions
  are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in
      the documentation and/or other materials provided with the
      distribution.
    * Neither the name of Intel Corporation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**********************************************************************/

#ifndef _SHA1_MB_INTERNAL_H_
#define _SHA1_MB_INTERNAL_H_

/**
 *  @file sha1_mb_internal.h
 *  @brief Multi-buffer CTX API function prototypes and structures
 *
 */

#include <stdint.h>
#include <string.h>

#include "sha1_mb.h"
#include "multi_buffer.h"
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************
 * Scheduler (internal) level out-of-order function prototypes
 ******************************************************************/

void
_sha1_mb_mgr_init_sse(SHA1_MB_JOB_MGR *state);
SHA1_JOB *
_sha1_mb_mgr_submit_sse(SHA1_MB_JOB_MGR *state, SHA1_JOB *job);
SHA1_JOB *
_sha1_mb_mgr_flush_sse(SHA1_MB_JOB_MGR *state);

#define _sha1_mb_mgr_init_avx _sha1_mb_mgr_init_sse
SHA1_JOB *
_sha1_mb_mgr_submit_avx(SHA1_MB_JOB_MGR *state, SHA1_JOB *job);
SHA1_JOB *
_sha1_mb_mgr_flush_avx(SHA1_MB_JOB_MGR *state);

void
_sha1_mb_mgr_init_avx2(SHA1_MB_JOB_MGR *state);
SHA1_JOB *
_sha1_mb_mgr_submit_avx2(SHA1_MB_JOB_MGR *state, SHA1_JOB *job);
SHA1_JOB *
_sha1_mb_mgr_flush_avx2(SHA1_MB_JOB_MGR *state);

void
_sha1_mb_mgr_init_avx512(SHA1_MB_JOB_MGR *state);
SHA1_JOB *
_sha1_mb_mgr_submit_avx512(SHA1_MB_JOB_MGR *state, SHA1_JOB *job);
SHA1_JOB *
_sha1_mb_mgr_flush_avx512(SHA1_MB_JOB_MGR *state);

void
_sha1_mb_mgr_init_sse_ni(SHA1_MB_JOB_MGR *state);
SHA1_JOB *
_sha1_mb_mgr_submit_sse_ni(SHA1_MB_JOB_MGR *state, SHA1_JOB *job);
SHA1_JOB *
_sha1_mb_mgr_flush_sse_ni(SHA1_MB_JOB_MGR *state);

void
_sha1_mb_mgr_init_avx512_ni(SHA1_MB_JOB_MGR *state);
SHA1_JOB *
_sha1_mb_mgr_submit_avx512_ni(SHA1_MB_JOB_MGR *state, SHA1_JOB *job);
SHA1_JOB *
_sha1_mb_mgr_flush_avx512_ni(SHA1_MB_JOB_MGR *state);

#ifdef __cplusplus
}
#endif

#endif // _SHA1_MB_INERNAL_H_
