#pragma once

#define likely(x)       __builtin_expect((x),1)
#define unlikely(x)     __builtin_expect((x),0)

//namespace
//{
//    void escape(void * p)
//    {
//        asm volatile("" : : "g"(p) /**input from c++ to c*/: "memory"/*clobber: what part of the program is modified while this assembly run*/);
//    }
//
//    void clobber()
//    {
//        asm volatile("" : : : "memory"); // write in all memory
//    }
//}

#define CONCATENATE(arg1, arg2)  CONCATENATE1(arg1, arg2)
#define CONCATENATE1(arg1, arg2) CONCATENATE2(arg1, arg2)
#define CONCATENATE2(arg1, arg2) arg1##arg2

#define VA_FOR_EACH_IMPL(...) __VA_ARGS__##_END
#define VA_FOR_EACH(...) VA_FOR_EACH_IMPL(__VA_ARGS__)

// Don't mind this (maybe use boost preprocessor some day)
#define CALL_MACRO_FOR_EACH_1(MACRO_FUNCTOR, ARG, ...) MACRO_FUNCTOR(ARG)
#define CALL_MACRO_FOR_EACH_2(MACRO_FUNCTOR, ARG, ...) MACRO_FUNCTOR(ARG); CALL_MACRO_FOR_EACH_1(MACRO_FUNCTOR, __VA_ARGS__);
#define CALL_MACRO_FOR_EACH_3(MACRO_FUNCTOR, ARG, ...) MACRO_FUNCTOR(ARG); CALL_MACRO_FOR_EACH_2(MACRO_FUNCTOR, __VA_ARGS__);
#define CALL_MACRO_FOR_EACH_4(MACRO_FUNCTOR, ARG, ...) MACRO_FUNCTOR(ARG); CALL_MACRO_FOR_EACH_3(MACRO_FUNCTOR, __VA_ARGS__);
#define CALL_MACRO_FOR_EACH_5(MACRO_FUNCTOR, ARG, ...) MACRO_FUNCTOR(ARG); CALL_MACRO_FOR_EACH_4(MACRO_FUNCTOR, __VA_ARGS__);
#define CALL_MACRO_FOR_EACH_6(MACRO_FUNCTOR, ARG, ...) MACRO_FUNCTOR(ARG); CALL_MACRO_FOR_EACH_5(MACRO_FUNCTOR, __VA_ARGS__);
#define CALL_MACRO_FOR_EACH_7(MACRO_FUNCTOR, ARG, ...) MACRO_FUNCTOR(ARG); CALL_MACRO_FOR_EACH_6(MACRO_FUNCTOR, __VA_ARGS__);
#define CALL_MACRO_FOR_EACH_8(MACRO_FUNCTOR, ARG, ...) MACRO_FUNCTOR(ARG); CALL_MACRO_FOR_EACH_7(MACRO_FUNCTOR, __VA_ARGS__);
#define CALL_MACRO_FOR_EACH_9(MACRO_FUNCTOR, ARG, ...) MACRO_FUNCTOR(ARG); CALL_MACRO_FOR_EACH_8(MACRO_FUNCTOR, __VA_ARGS__);
#define CALL_MACRO_FOR_EACH_10(MACRO_FUNCTOR, ARG, ...) MACRO_FUNCTOR(ARG); CALL_MACRO_FOR_EACH_9(MACRO_FUNCTOR, __VA_ARGS__);
#define CALL_MACRO_FOR_EACH_11(MACRO_FUNCTOR, ARG, ...) MACRO_FUNCTOR(ARG); CALL_MACRO_FOR_EACH_10(MACRO_FUNCTOR, __VA_ARGS__);
#define CALL_MACRO_FOR_EACH_12(MACRO_FUNCTOR, ARG, ...) MACRO_FUNCTOR(ARG); CALL_MACRO_FOR_EACH_11(MACRO_FUNCTOR, __VA_ARGS__);
#define CALL_MACRO_FOR_EACH_13(MACRO_FUNCTOR, ARG, ...) MACRO_FUNCTOR(ARG); CALL_MACRO_FOR_EACH_12(MACRO_FUNCTOR, __VA_ARGS__);
#define CALL_MACRO_FOR_EACH_14(MACRO_FUNCTOR, ARG, ...) MACRO_FUNCTOR(ARG); CALL_MACRO_FOR_EACH_13(MACRO_FUNCTOR, __VA_ARGS__);
#define CALL_MACRO_FOR_EACH_15(MACRO_FUNCTOR, ARG, ...) MACRO_FUNCTOR(ARG); CALL_MACRO_FOR_EACH_14(MACRO_FUNCTOR, __VA_ARGS__);
#define CALL_MACRO_FOR_EACH_16(MACRO_FUNCTOR, ARG, ...) MACRO_FUNCTOR(ARG); CALL_MACRO_FOR_EACH_15(MACRO_FUNCTOR, __VA_ARGS__);
#define CALL_MACRO_FOR_EACH_17(MACRO_FUNCTOR, ARG, ...) MACRO_FUNCTOR(ARG); CALL_MACRO_FOR_EACH_16(MACRO_FUNCTOR, __VA_ARGS__);
#define CALL_MACRO_FOR_EACH_18(MACRO_FUNCTOR, ARG, ...) MACRO_FUNCTOR(ARG); CALL_MACRO_FOR_EACH_17(MACRO_FUNCTOR, __VA_ARGS__);
#define CALL_MACRO_FOR_EACH_19(MACRO_FUNCTOR, ARG, ...) MACRO_FUNCTOR(ARG); CALL_MACRO_FOR_EACH_18(MACRO_FUNCTOR, __VA_ARGS__);
#define CALL_MACRO_FOR_EACH_20(MACRO_FUNCTOR, ARG, ...) MACRO_FUNCTOR(ARG); CALL_MACRO_FOR_EACH_19(MACRO_FUNCTOR, __VA_ARGS__);

#define CALL_MACRO_FOR_EACH_NARG(...) CALL_MACRO_FOR_EACH_NARG_(__VA_ARGS__, CALL_MACRO_FOR_EACH_RSEQ_N())
#define CALL_MACRO_FOR_EACH_NARG_(...) CALL_MACRO_FOR_EACH_ARG_N(__VA_ARGS__)
#define CALL_MACRO_FOR_EACH_ARG_N(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, N, ...) N
#define CALL_MACRO_FOR_EACH_RSEQ_N() 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0

#define CALL_MACRO_FOR_EACH_(N, MACRO_FUNCTOR, ARG, ...) CONCATENATE(CALL_MACRO_FOR_EACH_, N)(MACRO_FUNCTOR, ARG, __VA_ARGS__)
#define CALL_MACRO_FOR_EACH(MACRO_FUNCTOR, ARG, ...) CALL_MACRO_FOR_EACH_(CALL_MACRO_FOR_EACH_NARG(ARG, __VA_ARGS__), MACRO_FUNCTOR, ARG, __VA_ARGS__)
