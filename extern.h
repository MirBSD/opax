/**	$MirOS: src/bin/pax/extern.h,v 1.26 2015/10/14 18:10:08 tg Exp $ */
/*	$OpenBSD: extern.h,v 1.34 2010/12/02 04:08:27 tedu Exp $	*/
/*	$NetBSD: extern.h,v 1.5 1996/03/26 23:54:16 mrg Exp $	*/

/*-
 * Copyright © 2013, 2015, 2016
 *	mirabilos <m@mirbsd.org>
 * Copyright (c) 1992 Keith Muller.
 * Copyright (c) 1992, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Keith Muller of the University of California, San Diego.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)extern.h	8.2 (Berkeley) 4/18/94
 */

/*
 * External references from each source file
 */


/*
 * ar.c
 */
int uar_stwr(int);
int uar_ismagic(char *);
int uar_id(char *, int) __attribute__((__noreturn__));
int uar_rd(ARCHD *, char *);
int uar_wr(ARCHD *);
int uar_wr_data(ARCHD *, int, off_t *);
off_t uar_endrd(void);
int uar_trail(ARCHD *, char *, int, int *) __attribute__((__noreturn__));

/*
 * ar_io.c
 */
extern const char *arcname;
extern const char *compress_program;
extern int force_one_volume;
int ar_open(const char *);
void ar_close(void);
void ar_drain(void);
int ar_set_wr(void);
int ar_app_ok(void);
int ar_read(char *, int);
int ar_write(char *, int);
int ar_rdsync(void);
int ar_fow(off_t, off_t *);
int ar_rev(off_t );
int ar_next(void);
extern int ar_do_keepopen;
int ar_next_keepopen(void);

/*
 * ar_subs.c
 */
extern u_long flcnt;
void list(void);
void extract(void);
void append(void);
void archive(void);
void copy(void);

/*
 * buf_subs.c
 */
extern int blksz;
extern int wrblksz;
extern int maxflt;
extern int rdblksz;
extern off_t wrlimit;
extern off_t rdcnt;
extern off_t wrcnt;
int wr_start(void);
int rd_start(void);
void cp_start(void);
int appnd_start(off_t);
int rd_sync(void);
void pback(char *, int);
int rd_skip(off_t);
void wr_fin(void);
int wr_rdbuf(char *, int);
int rd_wrbuf(char *, int);
int wr_skip(off_t);
int wr_rdfile(ARCHD *, int, off_t *);
int rd_wrfile(ARCHD *, int, off_t *);
void cp_file(ARCHD *, int, int);
int buf_fill(void);
int buf_fill_internal(int);
int buf_flush(int);

/*
 * cache.c
 */
int uidtb_start(void);
int gidtb_start(void);
int usrtb_start(void);
int grptb_start(void);
const char *name_uid(uid_t, int);
const char *name_gid(gid_t, int);
int uid_name(const char *, uid_t *);
int gid_name(const char *, gid_t *);

/*
 * cpio.c
 */
int cpio_strd(void);
int cpio_trail(ARCHD *, char *, int, int *);
int cpio_endwr(void);
int cpio_id(char *, int);
int cpio_rd(ARCHD *, char *);
off_t cpio_endrd(void);
int cpio_stwr(int);
int dist_stwr(int);
int cpio_wr(ARCHD *);
int vcpio_id(char *, int);
int crc_id(char *, int);
int crc_strd(void);
int vcpio_rd(ARCHD *, char *);
off_t vcpio_endrd(void);
int crc_stwr(int);
int v4root_stwr(int);
int v4norm_stwr(int);
int vcpio_wr(ARCHD *);
int bcpio_id(char *, int);
int bcpio_rd(ARCHD *, char *);
off_t bcpio_endrd(void);
int bcpio_wr(ARCHD *);

/*
 * file_subs.c
 */
extern char *gnu_name_string, *gnu_link_string;
int file_creat(ARCHD *);
void file_close(ARCHD *, int);
int lnk_creat(ARCHD *, int *);
int cross_lnk(ARCHD *);
int chk_same(ARCHD *);
int node_creat(ARCHD *);
int unlnk_exist(char *, int);
int chk_path(char *, uid_t, gid_t);
void set_ftime(char *fnm, time_t mtime, time_t atime, int frc);
int set_ids(char *, uid_t, gid_t);
int fset_ids(char *, int, uid_t, gid_t);
int set_lids(char *, uid_t, gid_t);
void set_pmode(char *, mode_t);
void fset_pmode(char *, int, mode_t);
int set_attr(const struct file_times *, int _force_times, mode_t, int _do_mode,
    int _in_sig);
int file_write(int, char *, int, int *, int *, int, char *);
void file_flush(int, char *, int);
void rdfile_close(ARCHD *, int *);
int set_crc(ARCHD *, int);

/*
 * ftree.c
 */
int ftree_start(void);
int ftree_add(char *, int);
void ftree_sel(ARCHD *);
void ftree_skipped_newer(void);
void ftree_chk(void);
int next_file(ARCHD *);

/*
 * gen_subs.c
 */
void ls_list(ARCHD *, time_t, FILE *);
void ls_tty(ARCHD *);
void safe_print(const char *, FILE *);
u_long asc_ul(char *, int, int);
int ul_asc(u_long, char *, int, int);
ot_type asc_ot(char *, int, int);
int ot_asc(ot_type, char *, int, int);
size_t fieldcpy(char *, size_t, const char *, size_t);

/*
 * getoldopt.c
 */
int getoldopt(int, char **, const char *);

/*
 * options.c
 */
extern FSUB fsub[];
extern int ford[];
void options(int, char **);
OPLIST * opt_next(void);
int opt_add(const char *);
int bad_opt(void);
void guess_compress_program(int);
char *chdname;

/*
 * pat_rep.c
 */
int rep_add(char *);
int pat_add(char *, char *);
void pat_chk(void);
int pat_sel(ARCHD *);
int pat_match(ARCHD *);
int mod_name(ARCHD *);
int set_dest(ARCHD *, char *, int);
int has_dotdot(const char *);

/*
 * pax.c
 */
extern int act;
extern FSUB *frmt;
extern int cflag;
extern int cwdfd;
extern int dflag;
extern int iflag;
extern int kflag;
extern int lflag;
extern int nflag;
extern int tflag;
extern int uflag;
extern int Vflag;
extern int vflag;
extern int Dflag;
extern int Hflag;
extern int Lflag;
extern int Xflag;
extern int Yflag;
extern int Zflag;
extern int zeroflag;
extern int vfpart;
extern int patime;
extern int pmtime;
extern int nodirs;
extern int pmode;
extern int pids;
extern int rmleadslash;
extern int exit_val;
extern int docrc;
extern char *dirptr;
extern const char *argv0;
extern FILE *listf;
extern char *tempfile;
extern char *tempbase;
extern int havechd;

int main(int, char **);

/*
 * sel_subs.c
 */
int sel_chk(ARCHD *);
int grp_add(char *);
int usr_add(char *);
int trng_add(char *);

/*
 * tables.c
 */
int lnk_start(void);
int chk_lnk(ARCHD *);
void purg_lnk(ARCHD *);
void lnk_end(void);
int ftime_start(void);
int chk_ftime(ARCHD *);
int sltab_start(void);
int sltab_add_sym(const char *_path, const char *_value, mode_t _mode);
int sltab_add_link(const char *, const struct stat *);
void sltab_process(int _in_sig);
int name_start(void);
int add_name(char *, int, char *);
void sub_name(char *, int *, size_t);
int dev_start(void);
int add_dev(ARCHD *);
int map_dev(ARCHD *, u_long, u_long);
int atdir_start(void);
void atdir_end(void);
void add_atdir(char *, dev_t, ino_t, time_t, time_t);
int do_atdir(const char *, dev_t, ino_t);
int dir_start(void);
void add_dir(char *, struct stat *, int);
void delete_dir(dev_t, ino_t);
void proc_dir(void);
u_int st_hash(const char *, int, int);
int flnk_start(void);
int chk_flnk(ARCHD *);

/*
 * tar.c
 */
extern char *gnu_hack_string;
int tar_endwr(void);
off_t tar_endrd(void);
int tar_trail(ARCHD *, char *, int, int *);
int tar_id(char *, int);
int tar_opt(void);
int tar_rd(ARCHD *, char *);
int tar_wr(ARCHD *);
int ustar_strd(void);
int ustar_stwr(int);
int ustar_id(char *, int);
int ustar_rd(ARCHD *, char *);
int ustar_wr(ARCHD *);

/*
 * tty_subs.c
 */
extern char fdgetline_err;
char *fdgetline(int);
int tty_init(void);
void tty_prnt(const char *, ...)
    __attribute__((__format__(__printf__, 1, 2)));
char *tty_rd(void);
void paxwarn(int, const char *, ...)
    __attribute__((__format__(__printf__, 2, 3)));
void syswarn(int, int, const char *, ...)
    __attribute__((__format__(__printf__, 3, 4)));

/*
 * portability glue
 */
#ifndef HAVE_STRLCPY
size_t strlcat(char *, const char *, size_t);
size_t strlcpy(char *, const char *, size_t);
#endif

#ifndef HAVE_STRMODE
void strmode(mode_t, char *);
#endif
