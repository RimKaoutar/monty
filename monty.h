#ifndef __MONTY_H__
#define __MONTY_H__

/* Constants */
#define VALID_DATA		0
#define MIN_ARGS		2

/* General Error Codes */
#define ERR_INVALID	100
#define ERR_MALLOC	101
#define ERR_INVLD_PARM	102
#define METH_STACK		300
#define METH_QUEUE		301

/* Op Errors Codes */
#define ERR_USAGE		200
#define ERR_PUSH		201
#define ERR_PINT		202
#define ERR_POP			203
#define ERR_SWAP		204
#define ERR_ADD			205
#define ERR_SUB			206
#define ERR_DIV			207
#define ERR_ZERO_DIV	208
#define ERR_MUL			209
#define ERR_MOD			210
#define ERR_PCHAR_F		211
#define ERR_PCHAR_E		212

#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;

int handle_execution(char *op_code, char *data, unsigned int line, int mstat);
void handle_error(int errno, char *opcode, unsigned int line, char *line_read);
void handle_inv_malloc(int errno, char *opcode, unsigned int line);
void handle_more_errors(int errno, unsigned int line);
void (*select_op(char *s))(stack_t **, unsigned int);
void handle_op_errors(int errno, unsigned int line);
void push(stack_t **stack, unsigned int data);
void check_read_permission(char *filename);
unsigned int count_stack(stack_t *stack);
int check_push_data(char *param);
void check_args_num(int argn);
int check_digits(char *s);
void free_stack(void);
void divide(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void push_queue(stack_t **stack, unsigned int data);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
FILE *open_file(char *filename);

#endif /* __MONTY_H__ */
