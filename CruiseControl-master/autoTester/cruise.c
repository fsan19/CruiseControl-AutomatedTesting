/* sscc : C CODE OF SORTED EQUATIONS cruise - SIMULATION MODE */

/* AUXILIARY DECLARATIONS */

#ifndef STRLEN
#define STRLEN 81
#endif
#define _COND(A,B,C) ((A)?(B):(C))
#ifdef TRACE_ACTION
#include <stdio.h>
#endif
#ifndef NULL
#define NULL ((char*)0)
#endif

#ifndef __EXEC_STATUS_H_LOADED
#define __EXEC_STATUS_H_LOADED

typedef struct {
unsigned int start:1;
unsigned int kill:1;
unsigned int active:1;
unsigned int suspended:1;
unsigned int prev_active:1;
unsigned int prev_suspended:1;
unsigned int exec_index;
unsigned int task_exec_index;
void (*pStart)();
void (*pRet)();
} __ExecStatus;

#endif
#define __ResetExecStatus(status) {\
   status.prev_active = status.active; \
   status.prev_suspended = status.suspended; \
   status.start = status.kill = status.active = status.suspended = 0; }
#define __DSZ(V) (--(V)<=0)
#define BASIC_TYPES_DEFINED
typedef int boolean;
typedef int integer;
typedef char* string;
#define CSIMUL_H_LOADED
typedef struct {char text[STRLEN];} symbolic;
extern void _boolean(boolean*, boolean);
extern boolean _eq_boolean(boolean, boolean);
extern boolean _ne_boolean(boolean, boolean);
extern boolean _cond_boolean(boolean ,boolean ,boolean);
extern char* _boolean_to_text(boolean);
extern int _check_boolean(char*);
extern void _text_to_boolean(boolean*, char*);
extern void _integer(integer*, integer);
extern boolean _eq_integer(integer, integer);
extern boolean _ne_integer(integer, integer);
extern integer _cond_integer(boolean ,integer ,integer);
extern char* _integer_to_text(integer);
extern int _check_integer(char*);
extern void _text_to_integer(integer*, char*);
extern void _string(string, string);
extern boolean _eq_string(string, string);
extern boolean _ne_string(string, string);
extern string _cond_string(boolean ,string ,string);
extern char* _string_to_text(string);
extern int _check_string(char*);
extern void _text_to_string(string, char*);
extern void _float(float*, float);
extern boolean _eq_float(float, float);
extern boolean _ne_float(float, float);
extern float _cond_float(boolean ,float ,float);
extern char* _float_to_text(float);
extern int _check_float(char*);
extern void _text_to_float(float*, char*);
extern void _double(double*, double);
extern boolean _eq_double(double, double);
extern boolean _ne_double(double, double);
extern double _cond_double(boolean ,double ,double);
extern char* _double_to_text(double);
extern int _check_double(char*);
extern void _text_to_double(double*, char*);
extern void _symbolic(symbolic*, symbolic);
extern boolean _eq_symbolic(symbolic, symbolic);
extern boolean _ne_symbolic(symbolic, symbolic);
extern symbolic _cond_symbolic(boolean ,symbolic ,symbolic);
extern char* _symbolic_to_text(symbolic);
extern int _check_symbolic(char*);
extern void _text_to_symbolic(symbolic*, char*);
extern char* __PredefinedTypeToText(int, char*);
#define _true 1
#define _false 0
#define __cruise_GENERIC_TEST(TEST) return TEST;
typedef void (*__cruise_APF)();
static __cruise_APF *__cruise_PActionArray;
static int **__cruise_PCheckArray;
struct __SourcePoint {
int linkback;
int line;
int column;
int instance_index;
};
struct __InstanceEntry {
char *module_name;
int father_index;
char *dir_name;
char *file_name;
struct __SourcePoint source_point;
struct __SourcePoint end_point;
struct __SourcePoint instance_point;
};
struct __TaskEntry {
char *name;
int   nb_args_ref;
int   nb_args_val;
int  *type_codes_array;
struct __SourcePoint source_point;
};
struct __SignalEntry {
char *name;
int code;
int variable_index;
int present;
struct __SourcePoint source_point;
int number_of_emit_source_points;
struct __SourcePoint* emit_source_point_array;
int number_of_present_source_points;
struct __SourcePoint* present_source_point_array;
int number_of_access_source_points;
struct __SourcePoint* access_source_point_array;
};
struct __InputEntry {
char *name;
int hash;
char *type_name;
int is_a_sensor;
int type_code;
int multiple;
int signal_index;
int (*p_check_input)(char*);
void (*p_input_function)();
int present;
struct __SourcePoint source_point;
};
struct __ReturnEntry {
char *name;
int hash;
char *type_name;
int type_code;
int signal_index;
int exec_index;
int (*p_check_input)(char*);
void (*p_input_function)();
int present;
struct __SourcePoint source_point;
};
struct __ImplicationEntry {
int master;
int slave;
struct __SourcePoint source_point;
};
struct __ExclusionEntry {
int *exclusion_list;
struct __SourcePoint source_point;
};
struct __VariableEntry {
char *full_name;
char *short_name;
char *type_name;
int type_code;
int comment_kind;
int is_initialized;
char *p_variable;
char *source_name;
int written;
unsigned char written_in_transition;
unsigned char read_in_transition;
struct __SourcePoint source_point;
};
struct __ExecEntry {
int task_index;
int *var_indexes_array;
char **p_values_array;
struct __SourcePoint source_point;
};
struct __HaltEntry {
struct __SourcePoint source_point;
};
struct __NetEntry {
int known;
int value;
int number_of_source_points;
struct __SourcePoint* source_point_array;
};
struct __ModuleEntry {
char *version_id;
char *name;
int number_of_instances;
int number_of_tasks;
int number_of_signals;
int number_of_inputs;
int number_of_returns;
int number_of_sensors;
int number_of_outputs;
int number_of_locals;
int number_of_exceptions;
int number_of_implications;
int number_of_exclusions;
int number_of_variables;
int number_of_execs;
int number_of_halts;
int number_of_nets;
int number_of_states;
int state;
unsigned short *halt_list;
unsigned short *awaited_list;
unsigned short *emitted_list;
unsigned short *started_list;
unsigned short *killed_list;
unsigned short *suspended_list;
unsigned short *active_list;
int run_time_error_code;
int error_info;
void (*init)();
int (*run)();
int (*reset)();
char *(*show_variable)(int);
void (*set_variable)(int, char*, char*);
int (*check_value)(int, char*);
int (*execute_action)();
struct __InstanceEntry* instance_table;
struct __TaskEntry* task_table;
struct __SignalEntry* signal_table;
struct __InputEntry* input_table;
struct __ReturnEntry* return_table;
struct __ImplicationEntry* implication_table;
struct __ExclusionEntry* exclusion_table;
struct __VariableEntry* variable_table;
struct __ExecEntry* exec_table;
struct __HaltEntry* halt_table;
struct __NetEntry* net_table;
};

#include "cruise.h"

/* EXTERN DECLARATIONS */

extern int __CheckVariables(int*);
extern void __ResetInput();
extern void __ResetExecs();
extern void __ResetVariables();
extern void __ResetVariableStatus();
extern void __AppendToList(unsigned short*, unsigned short);
extern void __ListCopy(unsigned short*, unsigned short**);
extern void __WriteVariable(int);
extern void __ResetVariable(int);
extern void __ResetModuleEntry();
extern void __ResetModuleEntryBeforeReaction();
extern void __ResetModuleEntryAfterReaction();
#ifndef _NO_EXTERN_DEFINITIONS
#ifndef _NO_CONSTANT_DEFINITIONS
#ifndef _SPEED_MIN_DEFINED
#ifndef SPEED_MIN
extern float SPEED_MIN;
#endif
#endif
#ifndef _SPEED_MAX_DEFINED
#ifndef SPEED_MAX
extern float SPEED_MAX;
#endif
#endif
#ifndef _PEDALS_MIN_DEFINED
#ifndef PEDALS_MIN
extern float PEDALS_MIN;
#endif
#endif
#ifndef _OFF_DEFINED
#ifndef OFF
extern integer OFF;
#endif
#endif
#ifndef _ON_DEFINED
#ifndef ON
extern integer ON;
#endif
#endif
#ifndef _DISABLE_DEFINED
#ifndef DISABLE
extern integer DISABLE;
#endif
#endif
#ifndef _STANDBY_DEFINED
#ifndef STANDBY
extern integer STANDBY;
#endif
#endif
#ifndef _SPEED_INC_DEFINED
#ifndef SPEED_INC
extern float SPEED_INC;
#endif
#endif
#endif
#ifndef _NO_FUNCTION_DEFINITIONS
#ifndef _regulateThrottle_DEFINED
#ifndef regulateThrottle
extern float regulateThrottle(integer ,float ,float);
#endif
#endif
#endif
#endif

/* INITIALIZED CONSTANTS */

/* MEMORY ALLOCATION */

static boolean __cruise_V0;
static boolean __cruise_V1;
static boolean __cruise_V2;
static boolean __cruise_V3;
static boolean __cruise_V4;
static boolean __cruise_V5;
static float __cruise_V6;
static boolean __cruise_V7;
static float __cruise_V8;
static boolean __cruise_V9;
static float __cruise_V10;
static boolean __cruise_V11;
static float __cruise_V12;
static float __cruise_V13;
static integer __cruise_V14;
static boolean __cruise_V15;
static boolean __cruise_V16;
static integer __cruise_V17;
static integer __cruise_V18;
static boolean __cruise_V19;
static boolean __cruise_V20;
static integer __cruise_V21;
static float __cruise_V22;
static boolean __cruise_V23;
static float __cruise_V24;

static unsigned short __cruise_HaltList[5];
static unsigned short __cruise_AwaitedList[14];
static unsigned short __cruise_EmittedList[14];
static unsigned short __cruise_StartedList[1];
static unsigned short __cruise_KilledList[1];
static unsigned short __cruise_SuspendedList[1];
static unsigned short __cruise_ActiveList[1];
static unsigned short __cruise_AllAwaitedList[14]={9,0,1,2,3,4,5,6,7,8};


/* INPUT FUNCTIONS */

void cruise_I_On () {
__cruise_V0 = _true;
}
void cruise_IS_On () {
__cruise_V0 = _true;
}
void cruise_I_Off () {
__cruise_V1 = _true;
}
void cruise_IS_Off () {
__cruise_V1 = _true;
}
void cruise_I_Resume () {
__cruise_V2 = _true;
}
void cruise_IS_Resume () {
__cruise_V2 = _true;
}
void cruise_I_Set () {
__cruise_V3 = _true;
}
void cruise_IS_Set () {
__cruise_V3 = _true;
}
void cruise_I_QuickAccel () {
__cruise_V4 = _true;
}
void cruise_IS_QuickAccel () {
__cruise_V4 = _true;
}
void cruise_I_QuickDecel () {
__cruise_V5 = _true;
}
void cruise_IS_QuickDecel () {
__cruise_V5 = _true;
}
void cruise_I_Accel (float __V) {
__WriteVariable(6);
__cruise_V6 = __V;
__cruise_V7 = _true;
}
void cruise_IS_Accel (string __V) {
__WriteVariable(6);
_text_to_float(&__cruise_V6,__V);
__cruise_V7 = _true;
}
void cruise_I_Brake (float __V) {
__WriteVariable(8);
__cruise_V8 = __V;
__cruise_V9 = _true;
}
void cruise_IS_Brake (string __V) {
__WriteVariable(8);
_text_to_float(&__cruise_V8,__V);
__cruise_V9 = _true;
}
void cruise_I_Speed (float __V) {
__WriteVariable(10);
__cruise_V10 = __V;
__cruise_V11 = _true;
}
void cruise_IS_Speed (string __V) {
__WriteVariable(10);
_text_to_float(&__cruise_V10,__V);
__cruise_V11 = _true;
}

/* FUNCTIONS RETURNING NUMBER OF EXEC */

int cruise_number_of_execs () {
return (0);
}


/* AUTOMATON (STATE ACTION-TREES) */

/* ACTIONS */

/* PREDEFINED ACTIONS */

/* PRESENT SIGNAL TESTS */

static int __cruise_A1 () {
__cruise_GENERIC_TEST(__cruise_V0);
}
static int __cruise_Check1 [] = {1,0,0};
static int __cruise_A2 () {
__cruise_GENERIC_TEST(__cruise_V1);
}
static int __cruise_Check2 [] = {1,0,0};
static int __cruise_A3 () {
__cruise_GENERIC_TEST(__cruise_V2);
}
static int __cruise_Check3 [] = {1,0,0};
static int __cruise_A4 () {
__cruise_GENERIC_TEST(__cruise_V3);
}
static int __cruise_Check4 [] = {1,0,0};
static int __cruise_A5 () {
__cruise_GENERIC_TEST(__cruise_V4);
}
static int __cruise_Check5 [] = {1,0,0};
static int __cruise_A6 () {
__cruise_GENERIC_TEST(__cruise_V5);
}
static int __cruise_Check6 [] = {1,0,0};
static int __cruise_A7 () {
__cruise_GENERIC_TEST(__cruise_V7);
}
static int __cruise_Check7 [] = {1,0,0};
static int __cruise_A8 () {
__cruise_GENERIC_TEST(__cruise_V9);
}
static int __cruise_Check8 [] = {1,0,0};
static int __cruise_A9 () {
__cruise_GENERIC_TEST(__cruise_V11);
}
static int __cruise_Check9 [] = {1,0,0};

/* OUTPUT ACTIONS */

static void __cruise_A10 () {
#ifdef __OUTPUT
cruise_O_CruiseSpeed(__cruise_V12);
#endif
__AppendToList(__cruise_EmittedList,9);
}
static int __cruise_Check10 [] = {1,0,0};
static void __cruise_A11 () {
#ifdef __OUTPUT
cruise_O_ThrottleCmd(__cruise_V13);
#endif
__AppendToList(__cruise_EmittedList,10);
}
static int __cruise_Check11 [] = {1,0,0};
static void __cruise_A12 () {
#ifdef __OUTPUT
cruise_O_CruiseState(__cruise_V14);
#endif
__AppendToList(__cruise_EmittedList,11);
}
static int __cruise_Check12 [] = {1,0,0};

/* ASSIGNMENTS */

static void __cruise_A13 () {
__cruise_V0 = _false;
}
static int __cruise_Check13 [] = {1,0,1,0};
static void __cruise_A14 () {
__cruise_V1 = _false;
}
static int __cruise_Check14 [] = {1,0,1,1};
static void __cruise_A15 () {
__cruise_V2 = _false;
}
static int __cruise_Check15 [] = {1,0,1,2};
static void __cruise_A16 () {
__cruise_V3 = _false;
}
static int __cruise_Check16 [] = {1,0,1,3};
static void __cruise_A17 () {
__cruise_V4 = _false;
}
static int __cruise_Check17 [] = {1,0,1,4};
static void __cruise_A18 () {
__cruise_V5 = _false;
}
static int __cruise_Check18 [] = {1,0,1,5};
static void __cruise_A19 () {
__cruise_V7 = _false;
}
static int __cruise_Check19 [] = {1,0,1,7};
static void __cruise_A20 () {
__cruise_V9 = _false;
}
static int __cruise_Check20 [] = {1,0,1,9};
static void __cruise_A21 () {
__cruise_V11 = _false;
}
static int __cruise_Check21 [] = {1,0,1,11};
static void __cruise_A22 () {
__cruise_V15 = _false;
}
static int __cruise_Check22 [] = {1,0,1,15};
static void __cruise_A23 () {
__cruise_V16 = _false;
}
static int __cruise_Check23 [] = {1,0,1,16};
static void __cruise_A24 () {
__cruise_V17 = OFF;
}
static int __cruise_Check24 [] = {1,0,1,17};
static void __cruise_A25 () {
__cruise_V14 = __cruise_V17;
}
static int __cruise_Check25 [] = {1,1,17,1,14};
static void __cruise_A26 () {
__cruise_V17 = ON;
}
static int __cruise_Check26 [] = {1,0,1,17};
static void __cruise_A27 () {
__cruise_V15 = (__cruise_V10>=SPEED_MIN)&&(__cruise_V10<=SPEED_MAX);
}
static int __cruise_Check27 [] = {1,2,10,10,1,15};
static void __cruise_A28 () {
__cruise_V16 = __cruise_V6>PEDALS_MIN;
}
static int __cruise_Check28 [] = {1,1,6,1,16};
static void __cruise_A29 () {
__cruise_V17 = DISABLE;
}
static int __cruise_Check29 [] = {1,0,1,17};
static void __cruise_A30 () {
__cruise_V17 = ON;
}
static int __cruise_Check30 [] = {1,0,1,17};
static void __cruise_A31 () {
__cruise_V17 = ON;
}
static int __cruise_Check31 [] = {1,0,1,17};
static void __cruise_A32 () {
__cruise_V17 = DISABLE;
}
static int __cruise_Check32 [] = {1,0,1,17};
static void __cruise_A33 () {
__cruise_V17 = STANDBY;
}
static int __cruise_Check33 [] = {1,0,1,17};
static void __cruise_A34 () {
__cruise_V17 = OFF;
}
static int __cruise_Check34 [] = {1,0,1,17};
static void __cruise_A35 () {
__cruise_V14 = __cruise_V17;
}
static int __cruise_Check35 [] = {1,1,17,1,14};
static void __cruise_A36 () {
__cruise_V18 = __cruise_V14;
}
static int __cruise_Check36 [] = {1,1,14,1,18};
static void __cruise_A37 () {
__cruise_V19 = _false;
}
static int __cruise_Check37 [] = {1,0,1,19};
static void __cruise_A38 () {
__cruise_V20 = _false;
}
static int __cruise_Check38 [] = {1,0,1,20};
static void __cruise_A39 () {
__cruise_V21 = 0;
}
static int __cruise_Check39 [] = {1,0,1,21};
static void __cruise_A40 () {
__cruise_V22 = (float)0.0;
}
static int __cruise_Check40 [] = {1,0,1,22};
static void __cruise_A41 () {
__cruise_V13 = __cruise_V22;
}
static int __cruise_Check41 [] = {1,1,22,1,13};
static void __cruise_A42 () {
__cruise_V19 = __cruise_V14==ON;
}
static int __cruise_Check42 [] = {1,1,14,1,19};
static void __cruise_A43 () {
__cruise_V20 = (__cruise_V14==ON)&&(__cruise_V18==OFF);
}
static int __cruise_Check43 [] = {1,2,14,18,1,20};
static void __cruise_A44 () {
__cruise_V21 = 1;
}
static int __cruise_Check44 [] = {1,0,1,21};
static void __cruise_A45 () {
__cruise_V21 = 0;
}
static int __cruise_Check45 [] = {1,0,1,21};
static void __cruise_A46 () {
__cruise_V22 = regulateThrottle(__cruise_V21, __cruise_V12, __cruise_V10);
}
static int __cruise_Check46 [] = {1,3,21,12,10,1,22};
static void __cruise_A47 () {
__cruise_V22 = __cruise_V6;
}
static int __cruise_Check47 [] = {1,1,6,1,22};
static void __cruise_A48 () {
__cruise_V13 = __cruise_V22;
}
static int __cruise_Check48 [] = {1,1,22,1,13};
static void __cruise_A49 () {
__cruise_V23 = _false;
}
static int __cruise_Check49 [] = {1,0,1,23};
static void __cruise_A50 () {
__cruise_V24 = (float)0.0;
}
static int __cruise_Check50 [] = {1,0,1,24};
static void __cruise_A51 () {
__cruise_V12 = __cruise_V24;
}
static int __cruise_Check51 [] = {1,1,24,1,12};
static void __cruise_A52 () {
__cruise_V23 = !(__cruise_V14==OFF);
}
static int __cruise_Check52 [] = {1,1,14,1,23};
static void __cruise_A53 () {
__cruise_V24 = __cruise_V10;
}
static int __cruise_Check53 [] = {1,1,10,1,24};
static void __cruise_A54 () {
__cruise_V24 = __cruise_V10;
}
static int __cruise_Check54 [] = {1,1,10,1,24};
static void __cruise_A55 () {
__cruise_V24 = __cruise_V24-SPEED_INC;
}
static int __cruise_Check55 [] = {1,1,24,1,24};
static void __cruise_A56 () {
__cruise_V24 = __cruise_V24+SPEED_INC;
}
static int __cruise_Check56 [] = {1,1,24,1,24};
static void __cruise_A57 () {
__cruise_V24 = SPEED_MIN;
}
static int __cruise_Check57 [] = {1,0,1,24};
static void __cruise_A58 () {
__cruise_V24 = SPEED_MAX;
}
static int __cruise_Check58 [] = {1,0,1,24};
static void __cruise_A59 () {
__cruise_V12 = __cruise_V24;
}
static int __cruise_Check59 [] = {1,1,24,1,12};

/* PROCEDURE CALLS */

/* CONDITIONS */

static int __cruise_A60 () {
__cruise_GENERIC_TEST(__cruise_V17==OFF);
}
static int __cruise_Check60 [] = {1,1,17,0};
static int __cruise_A61 () {
__cruise_GENERIC_TEST(__cruise_V8>PEDALS_MIN);
}
static int __cruise_Check61 [] = {1,1,8,0};
static int __cruise_A62 () {
__cruise_GENERIC_TEST(__cruise_V17==ON);
}
static int __cruise_Check62 [] = {1,1,17,0};
static int __cruise_A63 () {
__cruise_GENERIC_TEST(__cruise_V16||!(__cruise_V15));
}
static int __cruise_Check63 [] = {1,2,16,15,0};
static int __cruise_A64 () {
__cruise_GENERIC_TEST(__cruise_V17==DISABLE);
}
static int __cruise_Check64 [] = {1,1,17,0};
static int __cruise_A65 () {
__cruise_GENERIC_TEST(!(__cruise_V16)&&__cruise_V15);
}
static int __cruise_Check65 [] = {1,2,16,15,0};
static int __cruise_A66 () {
__cruise_GENERIC_TEST(__cruise_V17==STANDBY);
}
static int __cruise_Check66 [] = {1,1,17,0};
static int __cruise_A67 () {
__cruise_GENERIC_TEST(!(__cruise_V16)&&__cruise_V15);
}
static int __cruise_Check67 [] = {1,2,16,15,0};
static int __cruise_A68 () {
__cruise_GENERIC_TEST(__cruise_V19);
}
static int __cruise_Check68 [] = {1,1,19,0};
static int __cruise_A69 () {
__cruise_GENERIC_TEST(__cruise_V20);
}
static int __cruise_Check69 [] = {1,1,20,0};
static int __cruise_A70 () {
__cruise_GENERIC_TEST(__cruise_V23);
}
static int __cruise_Check70 [] = {1,1,23,0};
static int __cruise_A71 () {
__cruise_GENERIC_TEST(__cruise_V18==OFF);
}
static int __cruise_Check71 [] = {1,1,18,0};
static int __cruise_A72 () {
__cruise_GENERIC_TEST(__cruise_V24<SPEED_MIN);
}
static int __cruise_Check72 [] = {1,1,24,0};
static int __cruise_A73 () {
__cruise_GENERIC_TEST(__cruise_V24>SPEED_MAX);
}
static int __cruise_Check73 [] = {1,1,24,0};

/* DECREMENTS */

/* START ACTIONS */

/* KILL ACTIONS */

/* SUSPEND ACTIONS */

/* ACTIVATE ACTIONS */

/* WRITE ARGS ACTIONS */

/* RESET ACTIONS */

static void __cruise_A74 () {
;
__ResetVariable(6);
}
static int __cruise_Check74 [] = {1,0,0};
static void __cruise_A75 () {
;
__ResetVariable(8);
}
static int __cruise_Check75 [] = {1,0,0};
static void __cruise_A76 () {
;
__ResetVariable(10);
}
static int __cruise_Check76 [] = {1,0,0};
static void __cruise_A77 () {
;
__ResetVariable(12);
}
static int __cruise_Check77 [] = {1,0,0};
static void __cruise_A78 () {
;
__ResetVariable(13);
}
static int __cruise_Check78 [] = {1,0,0};
static void __cruise_A79 () {
;
__ResetVariable(14);
}
static int __cruise_Check79 [] = {1,0,0};
static void __cruise_A80 () {
;
__ResetVariable(18);
}
static int __cruise_Check80 [] = {1,0,0};

/* ACTION SEQUENCES */


static int *__cruise_CheckArray[] = {
0,
__cruise_Check1,
__cruise_Check2,
__cruise_Check3,
__cruise_Check4,
__cruise_Check5,
__cruise_Check6,
__cruise_Check7,
__cruise_Check8,
__cruise_Check9,
__cruise_Check10,
__cruise_Check11,
__cruise_Check12,
__cruise_Check13,
__cruise_Check14,
__cruise_Check15,
__cruise_Check16,
__cruise_Check17,
__cruise_Check18,
__cruise_Check19,
__cruise_Check20,
__cruise_Check21,
__cruise_Check22,
__cruise_Check23,
__cruise_Check24,
__cruise_Check25,
__cruise_Check26,
__cruise_Check27,
__cruise_Check28,
__cruise_Check29,
__cruise_Check30,
__cruise_Check31,
__cruise_Check32,
__cruise_Check33,
__cruise_Check34,
__cruise_Check35,
__cruise_Check36,
__cruise_Check37,
__cruise_Check38,
__cruise_Check39,
__cruise_Check40,
__cruise_Check41,
__cruise_Check42,
__cruise_Check43,
__cruise_Check44,
__cruise_Check45,
__cruise_Check46,
__cruise_Check47,
__cruise_Check48,
__cruise_Check49,
__cruise_Check50,
__cruise_Check51,
__cruise_Check52,
__cruise_Check53,
__cruise_Check54,
__cruise_Check55,
__cruise_Check56,
__cruise_Check57,
__cruise_Check58,
__cruise_Check59,
__cruise_Check60,
__cruise_Check61,
__cruise_Check62,
__cruise_Check63,
__cruise_Check64,
__cruise_Check65,
__cruise_Check66,
__cruise_Check67,
__cruise_Check68,
__cruise_Check69,
__cruise_Check70,
__cruise_Check71,
__cruise_Check72,
__cruise_Check73,
__cruise_Check74,
__cruise_Check75,
__cruise_Check76,
__cruise_Check77,
__cruise_Check78,
__cruise_Check79,
__cruise_Check80
};
static int **__cruise_PCheckArray =  __cruise_CheckArray;

/* INIT FUNCTION */

#ifndef NO_INIT
void cruise_initialize () {
}
#endif

/* SHOW VARIABLE FUNCTION */

char* __cruise_show_variable (int __V) {
extern struct __VariableEntry __cruise_VariableTable[];
struct __VariableEntry* p_var = &__cruise_VariableTable[__V];
if (p_var->type_code < 0) {return __PredefinedTypeToText(p_var->type_code, p_var->p_variable);
} else {
switch (p_var->type_code) {
default: return 0;
}
}
}

/* SET VARIABLE FUNCTION */

static void __cruise_set_variable(int __Type, char* __pVar, char* __Text) {
}

/* CHECK VALUE FUNCTION */

static int __cruise_check_value (int __Type, char* __Text) {
return 0;
}

/* SIMULATION TABLES */

struct __InstanceEntry __cruise_InstanceTable [] = {
{"cruise",0,"","cruise.strl",{1,1,1,0},{1,57,1,0},{0,0,0,0}},
{"NextState",0,"","cruise.strl",{1,118,1,1},{1,210,1,1},{1,15,5,0}},
{"DriverControl",0,"","cruise.strl",{1,59,1,2},{1,116,1,2},{1,33,5,0}},
{"CruiseSpeedManager",0,"","cruise.strl",{1,212,1,3},{1,270,1,3},{1,46,5,0}},
};

struct __SignalEntry __cruise_SignalTable [] = {
{"On",33,0,0,{1,3,11,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"Off",33,0,0,{1,3,14,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"Resume",33,0,0,{1,3,19,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"Set",33,0,0,{1,3,27,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"QuickAccel",33,0,0,{1,3,32,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"QuickDecel",33,0,0,{1,3,44,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"Accel",1,6,0,{1,5,11,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"Brake",1,8,0,{1,6,11,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"Speed",1,10,0,{1,7,11,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"CruiseSpeed",2,12,0,{1,9,12,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"ThrottleCmd",2,13,0,{1,10,12,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"CruiseState",2,14,0,{1,11,12,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"isBrakePressed",40,0,0,{1,147,16,1},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL}};

struct __InputEntry __cruise_InputTable [] = {
{"On",88,0,0,-1,0,0,0,cruise_IS_On,0,{1,3,11,0}},
{"Off",81,0,0,-1,0,1,0,cruise_IS_Off,0,{1,3,14,0}},
{"Resume",19,0,0,-1,0,2,0,cruise_IS_Resume,0,{1,3,19,0}},
{"Set",98,0,0,-1,0,3,0,cruise_IS_Set,0,{1,3,27,0}},
{"QuickAccel",72,0,0,-1,0,4,0,cruise_IS_QuickAccel,0,{1,3,32,0}},
{"QuickDecel",77,0,0,-1,0,5,0,cruise_IS_QuickDecel,0,{1,3,44,0}},
{"Accel",68,"float",0,-5,0,6,_check_float,cruise_IS_Accel,0,{1,5,11,0}},
{"Brake",81,"float",0,-5,0,7,_check_float,cruise_IS_Brake,0,{1,6,11,0}},
{"Speed",93,"float",0,-5,0,8,_check_float,cruise_IS_Speed,0,{1,7,11,0}}};

struct __VariableEntry __cruise_VariableTable [] = {
{"__cruise_V0","V0","boolean",-2,2,0,(char*)&__cruise_V0,"On",0,0,0,{1,3,11,0}},
{"__cruise_V1","V1","boolean",-2,2,0,(char*)&__cruise_V1,"Off",0,0,0,{1,3,14,0}},
{"__cruise_V2","V2","boolean",-2,2,0,(char*)&__cruise_V2,"Resume",0,0,0,{1,3,19,0}},
{"__cruise_V3","V3","boolean",-2,2,0,(char*)&__cruise_V3,"Set",0,0,0,{1,3,27,0}},
{"__cruise_V4","V4","boolean",-2,2,0,(char*)&__cruise_V4,"QuickAccel",0,0,0,{1,3,32,0}},
{"__cruise_V5","V5","boolean",-2,2,0,(char*)&__cruise_V5,"QuickDecel",0,0,0,{1,3,44,0}},
{"__cruise_V6","V6","float",-5,1,0,(char*)&__cruise_V6,"Accel",0,0,0,{1,5,11,0}},
{"__cruise_V7","V7","boolean",-2,2,0,(char*)&__cruise_V7,"Accel",0,0,0,{1,5,11,0}},
{"__cruise_V8","V8","float",-5,1,0,(char*)&__cruise_V8,"Brake",0,0,0,{1,6,11,0}},
{"__cruise_V9","V9","boolean",-2,2,0,(char*)&__cruise_V9,"Brake",0,0,0,{1,6,11,0}},
{"__cruise_V10","V10","float",-5,1,0,(char*)&__cruise_V10,"Speed",0,0,0,{1,7,11,0}},
{"__cruise_V11","V11","boolean",-2,2,0,(char*)&__cruise_V11,"Speed",0,0,0,{1,7,11,0}},
{"__cruise_V12","V12","float",-5,1,0,(char*)&__cruise_V12,"CruiseSpeed",0,0,0,{1,9,12,0}},
{"__cruise_V13","V13","float",-5,1,0,(char*)&__cruise_V13,"ThrottleCmd",0,0,0,{1,10,12,0}},
{"__cruise_V14","V14","integer",-3,1,0,(char*)&__cruise_V14,"CruiseState",0,0,0,{1,11,12,0}},
{"__cruise_V15","V15","boolean",-2,0,0,(char*)&__cruise_V15,"isLegalSpeed",0,0,0,{1,139,9,1}},
{"__cruise_V16","V16","boolean",-2,0,0,(char*)&__cruise_V16,"isAccelPressed",0,0,0,{1,140,9,1}},
{"__cruise_V17","V17","integer",-3,0,0,(char*)&__cruise_V17,"state",0,0,0,{1,143,9,1}},
{"__cruise_V18","V18","integer",-3,10,0,(char*)&__cruise_V18,"CruiseState",0,0,0,{1,65,11,2}},
{"__cruise_V19","V19","boolean",-2,0,0,(char*)&__cruise_V19,"enRegulate",0,0,0,{1,78,9,2}},
{"__cruise_V20","V20","boolean",-2,0,0,(char*)&__cruise_V20,"enThrottle",0,0,0,{1,79,9,2}},
{"__cruise_V21","V21","integer",-3,0,0,(char*)&__cruise_V21,"isGoingOn",0,0,0,{1,80,9,2}},
{"__cruise_V22","V22","float",-5,0,0,(char*)&__cruise_V22,"throttleVal",0,0,0,{1,81,9,2}},
{"__cruise_V23","V23","boolean",-2,0,0,(char*)&__cruise_V23,"enManage",0,0,0,{1,230,9,3}},
{"__cruise_V24","V24","float",-5,0,0,(char*)&__cruise_V24,"newCruiseSpeed",0,0,0,{1,231,9,3}}
};

struct __HaltEntry __cruise_HaltTable [] = {
{{1,57,1,0}},
{{1,148,9,1}},
{{1,87,9,2}},
{{1,236,9,3}}
};


static void __cruise__reset_input () {
__cruise_V0 = _false;
__cruise_V1 = _false;
__cruise_V2 = _false;
__cruise_V3 = _false;
__cruise_V4 = _false;
__cruise_V5 = _false;
__cruise_V7 = _false;
__cruise_V9 = _false;
__cruise_V11 = _false;
}


/* MODULE DATA FOR SIMULATION */

int cruise();
int cruise_reset();

static struct __ModuleEntry __cruise_ModuleData = {
"Simulation interface release 5","cruise",
4,0,13,9,0,0,3,1,0,0,0,25,0,4,0,0,0,
__cruise_HaltList,
__cruise_AwaitedList,
__cruise_EmittedList,
__cruise_StartedList,
__cruise_KilledList,
__cruise_SuspendedList,
__cruise_ActiveList,
0,0,
cruise_initialize,cruise,cruise_reset,
__cruise_show_variable,__cruise_set_variable,__cruise_check_value,0,
__cruise_InstanceTable,
0,
__cruise_SignalTable,__cruise_InputTable,0,
0,0,
__cruise_VariableTable,
0,
__cruise_HaltTable,
0};

/* REDEFINABLE BIT TYPE */

#ifndef __SSC_BIT_TYPE_DEFINED
typedef char __SSC_BIT_TYPE;
#endif

/* REGISTER VARIABLES */

static __SSC_BIT_TYPE __cruise_R[4] = {_true,
 _false,
 _false,
 _false};

/* AUTOMATON ENGINE */

int cruise () {
/* AUXILIARY VARIABLES */

static __SSC_BIT_TYPE E[33];

__cruise_ModuleData.awaited_list = __cruise_AwaitedList;
__ResetModuleEntryBeforeReaction();
E[0] = __cruise_R[0]&&!((__CheckVariables(__cruise_CheckArray[7]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__cruise_A7()));
if (E[0]) {
__CheckVariables(__cruise_CheckArray[74]);__cruise_A74();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A74\n");
#endif
}
E[1] = __cruise_R[0]&&!((__CheckVariables(__cruise_CheckArray[8]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 8\n"),
#endif
__cruise_A8()));
if (E[1]) {
__CheckVariables(__cruise_CheckArray[75]);__cruise_A75();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A75\n");
#endif
}
E[2] = __cruise_R[0]&&!((__CheckVariables(__cruise_CheckArray[9]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 9\n"),
#endif
__cruise_A9()));
if (E[2]) {
__CheckVariables(__cruise_CheckArray[76]);__cruise_A76();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A76\n");
#endif
}
if (__cruise_R[0]) {
__CheckVariables(__cruise_CheckArray[77]);__cruise_A77();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A77\n");
#endif
}
if (__cruise_R[0]) {
__CheckVariables(__cruise_CheckArray[80]);__cruise_A80();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A80\n");
#endif
}
if (__cruise_R[0]) {
__CheckVariables(__cruise_CheckArray[49]);__cruise_A49();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A49\n");
#endif
}
if (__cruise_R[0]) {
__CheckVariables(__cruise_CheckArray[50]);__cruise_A50();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A50\n");
#endif
}
if (__cruise_R[0]) {
__CheckVariables(__cruise_CheckArray[51]);__cruise_A51();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A51\n");
#endif
}
E[3] = __cruise_R[3]&&!(__cruise_R[0]);
if (__cruise_R[0]) {
__CheckVariables(__cruise_CheckArray[22]);__cruise_A22();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A22\n");
#endif
}
if (__cruise_R[0]) {
__CheckVariables(__cruise_CheckArray[23]);__cruise_A23();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A23\n");
#endif
}
if (__cruise_R[0]) {
__CheckVariables(__cruise_CheckArray[24]);__cruise_A24();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A24\n");
#endif
}
E[4] = __cruise_R[1]&&!(__cruise_R[0]);
E[5] = E[4]&&(__CheckVariables(__cruise_CheckArray[60]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 60\n"),
#endif
__cruise_A60());
E[6] = E[5]&&(__CheckVariables(__cruise_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__cruise_A1());
if (E[6]) {
__CheckVariables(__cruise_CheckArray[26]);__cruise_A26();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A26\n");
#endif
}
E[7] = E[5]&&!((__CheckVariables(__cruise_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__cruise_A1()));
E[5] = E[4]&&!(E[5]);
E[4] = E[5]&&(__CheckVariables(__cruise_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__cruise_A2());
if (E[4]) {
__CheckVariables(__cruise_CheckArray[34]);__cruise_A34();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A34\n");
#endif
}
E[5] = E[5]&&!((__CheckVariables(__cruise_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__cruise_A2()));
if (E[5]) {
__CheckVariables(__cruise_CheckArray[27]);__cruise_A27();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A27\n");
#endif
}
if (E[5]) {
__CheckVariables(__cruise_CheckArray[28]);__cruise_A28();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A28\n");
#endif
}
E[8] = E[5]&&(__CheckVariables(__cruise_CheckArray[61]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 61\n"),
#endif
__cruise_A61());
if (E[8]) {
__AppendToList(__cruise_EmittedList,12);
}
E[9] = E[8]||(E[5]&&!(E[8]));
E[10] = E[9]&&E[8];
if (E[10]) {
__CheckVariables(__cruise_CheckArray[33]);__cruise_A33();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A33\n");
#endif
}
E[8] = E[9]&&!(E[8]);
E[9] = E[8]&&(__CheckVariables(__cruise_CheckArray[62]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 62\n"),
#endif
__cruise_A62());
E[11] = E[9]&&(__CheckVariables(__cruise_CheckArray[63]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 63\n"),
#endif
__cruise_A63());
if (E[11]) {
__CheckVariables(__cruise_CheckArray[29]);__cruise_A29();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A29\n");
#endif
}
E[8] = E[8]&&!(E[9]);
E[12] = E[8]&&(__CheckVariables(__cruise_CheckArray[64]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 64\n"),
#endif
__cruise_A64());
E[13] = E[12]&&(__CheckVariables(__cruise_CheckArray[65]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 65\n"),
#endif
__cruise_A65());
if (E[13]) {
__CheckVariables(__cruise_CheckArray[30]);__cruise_A30();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A30\n");
#endif
}
E[8] = E[8]&&!(E[12]);
E[14] = E[8]&&(__CheckVariables(__cruise_CheckArray[66]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 66\n"),
#endif
__cruise_A66());
E[15] = E[14]&&(__CheckVariables(__cruise_CheckArray[3]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__cruise_A3());
E[16] = E[15]&&(__CheckVariables(__cruise_CheckArray[67]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 67\n"),
#endif
__cruise_A67());
if (E[16]) {
__CheckVariables(__cruise_CheckArray[31]);__cruise_A31();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A31\n");
#endif
}
E[15] = E[15]&&!(E[16]);
if (E[15]) {
__CheckVariables(__cruise_CheckArray[32]);__cruise_A32();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A32\n");
#endif
}
E[17] = E[14]&&!((__CheckVariables(__cruise_CheckArray[3]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__cruise_A3()));
E[14] = E[6]||E[7]||E[4]||E[10]||E[11]||(E[9]&&!(E[11]))||E[13]||(E[12]&&!(E[13]))||E[16]||E[15]||E[17]||(E[8]&&!(E[14]));
E[8] = __cruise_R[0]||E[14];
if (E[8]) {
__AppendToList(__cruise_EmittedList,11);
}
E[17] = E[3]&&E[8];
if (__cruise_R[0]) {
__CheckVariables(__cruise_CheckArray[79]);__cruise_A79();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A79\n");
#endif
}
if (__cruise_R[0]) {
__CheckVariables(__cruise_CheckArray[25]);__cruise_A25();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A25\n");
#endif
}
if (E[14]) {
__CheckVariables(__cruise_CheckArray[35]);__cruise_A35();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A35\n");
#endif
}
if (E[17]) {
__CheckVariables(__cruise_CheckArray[52]);__cruise_A52();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A52\n");
#endif
}
E[12] = E[17]&&(__CheckVariables(__cruise_CheckArray[70]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 70\n"),
#endif
__cruise_A70());
E[9] = E[12]&&(__CheckVariables(__cruise_CheckArray[71]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 71\n"),
#endif
__cruise_A71());
if (E[9]) {
__CheckVariables(__cruise_CheckArray[53]);__cruise_A53();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A53\n");
#endif
}
E[7] = E[9]||(E[12]&&!(E[9]));
E[18] = E[7]&&(__CheckVariables(__cruise_CheckArray[4]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__cruise_A4());
if (E[18]) {
__CheckVariables(__cruise_CheckArray[54]);__cruise_A54();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A54\n");
#endif
}
E[7] = E[7]&&!((__CheckVariables(__cruise_CheckArray[4]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__cruise_A4()));
E[19] = E[7]&&(__CheckVariables(__cruise_CheckArray[6]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__cruise_A6());
if (E[19]) {
__CheckVariables(__cruise_CheckArray[55]);__cruise_A55();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A55\n");
#endif
}
E[7] = E[7]&&!((__CheckVariables(__cruise_CheckArray[6]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__cruise_A6()));
E[7] = E[19]||E[7];
E[20] = E[7]&&(__CheckVariables(__cruise_CheckArray[5]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__cruise_A5());
if (E[20]) {
__CheckVariables(__cruise_CheckArray[56]);__cruise_A56();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A56\n");
#endif
}
E[7] = E[7]&&!((__CheckVariables(__cruise_CheckArray[5]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__cruise_A5()));
E[7] = E[18]||E[20]||E[7];
E[21] = E[7]&&(__CheckVariables(__cruise_CheckArray[72]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 72\n"),
#endif
__cruise_A72());
if (E[21]) {
__CheckVariables(__cruise_CheckArray[57]);__cruise_A57();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A57\n");
#endif
}
E[7] = E[7]&&!(E[21]);
E[22] = E[7]&&(__CheckVariables(__cruise_CheckArray[73]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 73\n"),
#endif
__cruise_A73());
if (E[22]) {
__CheckVariables(__cruise_CheckArray[58]);__cruise_A58();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A58\n");
#endif
}
E[12] = E[21]||E[22]||(E[7]&&!(E[22]))||(E[17]&&!(E[12]));
if (E[12]) {
__CheckVariables(__cruise_CheckArray[59]);__cruise_A59();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A59\n");
#endif
}
if (__cruise_R[0]||E[12]) {
__AppendToList(__cruise_EmittedList,9);
}
if (__cruise_R[0]||E[12]) {
__CheckVariables(__cruise_CheckArray[10]);__cruise_A10();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A10\n");
#endif
}
if (__cruise_R[0]) {
__CheckVariables(__cruise_CheckArray[78]);__cruise_A78();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A78\n");
#endif
}
if (__cruise_R[0]) {
__CheckVariables(__cruise_CheckArray[37]);__cruise_A37();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A37\n");
#endif
}
if (__cruise_R[0]) {
__CheckVariables(__cruise_CheckArray[38]);__cruise_A38();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A38\n");
#endif
}
if (__cruise_R[0]) {
__CheckVariables(__cruise_CheckArray[39]);__cruise_A39();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A39\n");
#endif
}
if (__cruise_R[0]) {
__CheckVariables(__cruise_CheckArray[40]);__cruise_A40();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A40\n");
#endif
}
if (__cruise_R[0]) {
__CheckVariables(__cruise_CheckArray[41]);__cruise_A41();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A41\n");
#endif
}
E[7] = __cruise_R[2]&&!(__cruise_R[0]);
E[23] = E[7]&&E[8];
if (E[23]) {
__CheckVariables(__cruise_CheckArray[42]);__cruise_A42();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A42\n");
#endif
}
E[24] = E[23]&&(__CheckVariables(__cruise_CheckArray[68]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 68\n"),
#endif
__cruise_A68());
if (E[24]) {
__CheckVariables(__cruise_CheckArray[43]);__cruise_A43();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A43\n");
#endif
}
E[25] = E[24]&&(__CheckVariables(__cruise_CheckArray[69]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 69\n"),
#endif
__cruise_A69());
if (E[25]) {
__CheckVariables(__cruise_CheckArray[44]);__cruise_A44();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A44\n");
#endif
}
E[26] = E[24]&&!(E[25]);
if (E[26]) {
__CheckVariables(__cruise_CheckArray[45]);__cruise_A45();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A45\n");
#endif
}
E[27] = E[25]||E[26];
if (E[27]) {
__CheckVariables(__cruise_CheckArray[46]);__cruise_A46();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A46\n");
#endif
}
E[28] = E[23]&&!(E[24]);
if (E[28]) {
__CheckVariables(__cruise_CheckArray[47]);__cruise_A47();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A47\n");
#endif
}
E[29] = E[27]||E[28];
if (E[29]) {
__CheckVariables(__cruise_CheckArray[48]);__cruise_A48();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A48\n");
#endif
}
if (__cruise_R[0]||E[29]) {
__AppendToList(__cruise_EmittedList,10);
}
if (__cruise_R[0]||E[29]) {
__CheckVariables(__cruise_CheckArray[11]);__cruise_A11();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A11\n");
#endif
}
if (E[8]) {
__CheckVariables(__cruise_CheckArray[12]);__cruise_A12();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A12\n");
#endif
}
E[30] = E[14]||__cruise_R[0];
E[7] = __cruise_R[0]||E[29]||(__cruise_R[2]&&E[7]&&!(E[8]));
E[3] = __cruise_R[0]||E[12]||(__cruise_R[3]&&E[3]&&!(E[8]));
E[31] = __cruise_R[1]||__cruise_R[2]||__cruise_R[3];
E[31] = (E[30]||E[7]||E[3])&&((E[31]&&!(__cruise_R[1]))||E[30])&&((E[31]&&!(__cruise_R[2]))||E[7])&&((E[31]&&!(__cruise_R[3]))||E[3]);
if (E[8]&&E[31]) {
__CheckVariables(__cruise_CheckArray[36]);__cruise_A36();
#ifdef TRACE_ACTION
fprintf(stderr, "__cruise_A36\n");
#endif
}
E[32] = !(_true);
__cruise_R[0] = !(_true);
__cruise_R[1] = E[30];
if (__cruise_R[1]) { __AppendToList(__cruise_HaltList,1); }
__cruise_R[2] = E[7];
if (__cruise_R[2]) { __AppendToList(__cruise_HaltList,2); }
__cruise_R[3] = E[3];
if (__cruise_R[3]) { __AppendToList(__cruise_HaltList,3); }
if (!E[31]) { __AppendToList(__cruise_HaltList,0); }
__ResetModuleEntryAfterReaction();
__cruise_ModuleData.awaited_list = __cruise_AllAwaitedList;
__cruise__reset_input();
return E[31];
}

/* AUTOMATON RESET */

int cruise_reset () {
__cruise_ModuleData.awaited_list = __cruise_AwaitedList;
__ResetModuleEntry();
__cruise_ModuleData.awaited_list = __cruise_AllAwaitedList;
__cruise_ModuleData.state = 0;
__cruise_R[0] = _true;
__cruise_R[1] = _false;
__cruise_R[2] = _false;
__cruise_R[3] = _false;
__cruise__reset_input();
return 0;
}
char* CompilationType = "Compiled Sorted Equations";

int __NumberOfModules = 1;
struct __ModuleEntry* __ModuleTable[] = {
&__cruise_ModuleData
};
