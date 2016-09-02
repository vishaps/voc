/* voc 1.95 [2016/09/02] for gcc LP64 on cygwin xtspkaSfF */

#ifndef OPT__h
#define OPT__h

#define LARGE
#include "SYSTEM.h"
#include "OPS.h"

typedef
	struct OPT_ConstDesc *OPT_Const;

typedef
	OPS_String *OPT_ConstExt;

typedef
	struct OPT_ConstDesc {
		OPT_ConstExt ext;
		int64 intval, intval2;
		SET setval;
		LONGREAL realval;
	} OPT_ConstDesc;

typedef
	struct OPT_NodeDesc *OPT_Node;

typedef
	struct OPT_StrDesc *OPT_Struct;

typedef
	struct OPT_ObjDesc *OPT_Object;

typedef
	struct OPT_NodeDesc {
		OPT_Node left, right, link;
		int8 class, subcl;
		BOOLEAN readonly;
		OPT_Struct typ;
		OPT_Object obj;
		OPT_Const conval;
	} OPT_NodeDesc;

typedef
	struct OPT_ObjDesc {
		OPT_Object left, right, link, scope;
		OPS_Name name;
		BOOLEAN leaf;
		int8 mode, mnolev, vis, history;
		BOOLEAN used, fpdone;
		int64 fprint;
		OPT_Struct typ;
		OPT_Const conval;
		int64 adr, linkadr;
		int32 x;
	} OPT_ObjDesc;

typedef
	struct OPT_StrDesc {
		int8 form, comp, mno, extlev;
		int32 ref, sysflag;
		int64 n, size, align, txtpos;
		BOOLEAN allocated, pbused, pvused;
		char _prvt0[24];
		OPT_Struct BaseTyp;
		OPT_Object link, strobj;
	} OPT_StrDesc;


import void (*OPT_typSize)(OPT_Struct);
import OPT_Object OPT_topScope;
import OPT_Struct OPT_undftyp, OPT_bytetyp, OPT_booltyp, OPT_chartyp, OPT_sinttyp, OPT_inttyp, OPT_linttyp, OPT_pinttyp, OPT_ainttyp, OPT_int8typ, OPT_int16typ, OPT_int32typ, OPT_int64typ, OPT_realtyp, OPT_lrltyp, OPT_settyp, OPT_stringtyp, OPT_niltyp, OPT_notyp, OPT_sysptrtyp;
import int8 OPT_nofGmod;
import OPT_Object OPT_GlbMod[64];
import OPS_Name OPT_SelfName;
import BOOLEAN OPT_SYSimported;

import LONGINT *OPT_ConstDesc__typ;
import LONGINT *OPT_ObjDesc__typ;
import LONGINT *OPT_StrDesc__typ;
import LONGINT *OPT_NodeDesc__typ;

import void OPT_Close (void);
import void OPT_CloseScope (void);
import void OPT_Export (BOOLEAN *ext, BOOLEAN *new);
import void OPT_FPrintErr (OPT_Object obj, int32 errcode);
import void OPT_FPrintObj (OPT_Object obj);
import void OPT_FPrintStr (OPT_Struct typ);
import void OPT_Find (OPT_Object *res);
import void OPT_FindField (OPS_Name name, OPT_Struct typ, OPT_Object *res);
import void OPT_FindImport (OPT_Object mod, OPT_Object *res);
import void OPT_IdFPrint (OPT_Struct typ);
import void OPT_Import (OPS_Name aliasName, OPS_Name name, BOOLEAN *done);
import void OPT_Init (OPS_Name name, SET opt);
import void OPT_Insert (OPS_Name name, OPT_Object *obj);
import void OPT_InsertImport (OPT_Object obj, OPT_Object *root, OPT_Object *old);
import OPT_Struct OPT_IntType (int64 size);
import OPT_Const OPT_NewConst (void);
import OPT_ConstExt OPT_NewExt (void);
import OPT_Node OPT_NewNode (int8 class);
import OPT_Object OPT_NewObj (void);
import OPT_Struct OPT_NewStr (int8 form, int8 comp);
import void OPT_OpenScope (int8 level, OPT_Object owner);
import OPT_Struct OPT_ShorterOrLongerType (OPT_Struct x, int32 dir);
import void *OPT__init(void);


#endif
