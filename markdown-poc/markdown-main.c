#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "markdown.h"
#include "buffer.h"
#include "html.h"

struct sd_callbacks callbacks;
struct sd_markdown *markdown;
struct html_renderopt options;


#define READ_UNIT 1024
#define OUTPUT_UNIT 64

int main(int argc, const char *argv[]) {
  struct buf *input, *output;
  char * input_text;

  input_text = malloc(1024*sizeof(char));
  
  strcpy(input_text, "### Never Gonna Give you up ###\n * OK\n * Not OK \n * Good lord! ");
  input = bufnew(READ_UNIT);
  bufgrow(input, READ_UNIT);
  bufputs(input, input_text);

  output = bufnew(OUTPUT_UNIT);

  sdhtml_renderer(&callbacks, &options, 0);
  markdown = sd_markdown_new(0, 16, &callbacks, &options);
  sd_markdown_render(output, input->data, input->size, markdown);

  printf("%s", output->data);

  bufrelease(input);
  bufrelease(output);

  return 0;
}
