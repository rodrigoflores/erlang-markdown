-module(markdown).
-export([to_html/1]).
-on_load(init/0).

init() ->
    ok = erlang:load_nif("./markdown",1).

to_html(_) ->
    exit(nif_library_not_loaded).
