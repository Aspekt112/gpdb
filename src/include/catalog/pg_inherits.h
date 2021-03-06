/*-------------------------------------------------------------------------
 *
 * pg_inherits.h
 *	  definition of the system "inherits" relation (pg_inherits)
 *	  along with the relation's initial contents.
 *
 *
 * Portions Copyright (c) 1996-2010, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * $PostgreSQL: pgsql/src/include/catalog/pg_inherits.h,v 1.30 2010/01/05 01:06:56 tgl Exp $
 *
 * NOTES
 *	  the genbki.pl script reads this file and generates .bki
 *	  information from the DATA() statements.
 *
 *-------------------------------------------------------------------------
 */
#ifndef PG_INHERITS_H
#define PG_INHERITS_H

#include "catalog/genbki.h"

/* ----------------
 *		pg_inherits definition.  cpp turns this into
 *		typedef struct FormData_pg_inherits
 * ----------------
 */
#define InheritsRelationId	2611

CATALOG(pg_inherits,2611) BKI_WITHOUT_OIDS
{
	Oid			inhrelid;
	Oid			inhparent;
	int4		inhseqno;
} FormData_pg_inherits;

/* GPDB added foreign key definitions for gpcheckcat. */
FOREIGN_KEY(inhrelid REFERENCES pg_class(oid));
FOREIGN_KEY(inhparent REFERENCES pg_class(oid));

/* ----------------
 *		Form_pg_inherits corresponds to a pointer to a tuple with
 *		the format of pg_inherits relation.
 * ----------------
 */
typedef FormData_pg_inherits *Form_pg_inherits;

/* ----------------
 *		compiler constants for pg_inherits
 * ----------------
 */
#define Natts_pg_inherits				3
#define Anum_pg_inherits_inhrelid		1
#define Anum_pg_inherits_inhparent		2
#define Anum_pg_inherits_inhseqno		3

/* ----------------
 *		pg_inherits has no initial contents
 * ----------------
 */

#endif   /* PG_INHERITS_H */
