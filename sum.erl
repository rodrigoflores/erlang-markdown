-module(sum).
-export([sum/2, factorial/1, binary_length/1, to_string/1]).
-on_load(init/0).

init() ->
    ok = erlang:load_nif("./sum_nif", 2).

sum(_X, _Y) ->
    exit(nif_library_not_loaded).

string_length(_Y) ->
    exit(nif_library_not_loaded).

binary_length(_Y) ->
    exit(nif_library_not_loaded).

factorial(_) ->
    exit(nif_library_not_loaded).

to_string(_) ->
    exit(nif_library_not_loaded).
