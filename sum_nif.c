#include <stdio.h>
#include "erl_nif.h"

#define MAXN 10000

extern int sum(int a, int b);
extern int string_length(char * string);

static ERL_NIF_TERM sum_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    int x, y, ret;
    if (!enif_get_int(env, argv[0], &x)) {
      return enif_make_badarg(env);
    }

    if (!enif_get_int(env, argv[1], &y)) {
      return enif_make_badarg(env);
    }

    ret = sum(x,y);
    return enif_make_int(env, ret);
}

static ERL_NIF_TERM factorial_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    int x,ret;
    if (!enif_get_int(env, argv[0], &x)) {
      return enif_make_badarg(env);
    }

    ret = factorial(x);
    return enif_make_int(env, ret);
}

static ERL_NIF_TERM string_length_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    int ret;
    char * string;
    string = malloc(MAXN*sizeof(char));
    if (!enif_get_string(env, argv[0], string, MAXN, ERL_NIF_LATIN1)) {
      return enif_make_badarg(env);
    }

    ret = string_length(string);
    free(string);
    return enif_make_int(env, ret);
}

static ERL_NIF_TERM binary_length_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  ErlNifBinary bin;
  enif_inspect_binary(env, argv[0], &bin);

  return enif_make_int(env, bin.size);
}

static ERL_NIF_TERM to_string_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  ErlNifBinary bin;
  enif_inspect_binary(env, argv[0], &bin);

  return enif_make_string(env, bin.data, ERL_NIF_LATIN1);
}


static ErlNifFunc nif_funcs[] = {
    {"sum", 2, sum_nif},
    {"factorial", 1, factorial_nif},
    {"binary_length", 1, binary_length_nif},
    {"to_string", 1, to_string_nif},
};

ERL_NIF_INIT(sum, nif_funcs, NULL, NULL, NULL, NULL);
