int main(int argc, char *argv[])
{
  InputBuffer *input_buffer = new_input_buffer_create();
  while (true)
  {
    print_prompt();
    read_input(input_buffer);

    if (strcmp(input_buffer->buffer, "exit") == 0)
    {
      close_input_buffer(input_buffer);
      exit(EXIT_SUCCESS);
    }
    else
    {
      printf("Unrecognized command '%s'.\n", input_buffer->buffer);
    }
  }
}

typedef struct {
  char* buffer;
  size_t buffer_length;
  ssize_t buffer_size;
} InputBuffer;

InputBuffer* new_input_buffer_create() {
  InputBuffer* input_buffer = malloc(sizeof(InputBuffer));
  input_buffer->buffer = NULL;
  input_buffer->buffer_length = 0;
  input_buffer->buffer_size = 0;
  return input_buffer;
}

void print_prompt() {
  printf("db > ");
}

ssize_getline(char **lineptr, size_t *n, FILE *stream)