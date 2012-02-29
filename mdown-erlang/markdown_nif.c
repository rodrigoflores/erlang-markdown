#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "erl_nif.h"

#include "markdown.h"
#include "html.h"
#include "buffer.h"

#define OUTPUT_SIZE 64 

struct sd_callbacks callbacks;
struct sd_markdown *markdown;
struct html_renderopt options;

void * cleanup(void * item) {
  return NULL;
}

static ERL_NIF_TERM to_markdown_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  ErlNifBinary markdown_binary, html_binary;
  struct buf *input, *output;
  char * output_data;
  void *alocation;
  ErlNifResourceType * type = enif_open_resource_type(env, NULL, "mem_resource", cleanup, ERL_NIF_RT_CREATE, NULL);


  if(!enif_inspect_binary(env, argv[0], &markdown_binary)){
    enif_make_badarg(env);
  }

  input = bufnew(markdown_binary.size);
  bufputs(input, markdown_binary.data);

  output = bufnew(OUTPUT_SIZE);

  sdhtml_renderer(&callbacks, &options, 0);
  markdown = sd_markdown_new(0, 16, &callbacks, &options);
  sd_markdown_render(output, input->data, input->size, markdown);

  output_data = malloc(sizeof(char)*(output->size+5));
  strcpy(output_data, output->data);
  alocation = enif_alloc_resource(type, sizeof(char *)*(output->size+5));

  bufrelease(input);
  bufrelease(output);

  return enif_make_resource_binary(env, alocation, output->data, output->size);
}

static ErlNifFunc nif_funcs[] =
{
    {"to_html", 1, to_markdown_nif}
};

ERL_NIF_INIT(markdown,nif_funcs,NULL,NULL,NULL,NULL);


