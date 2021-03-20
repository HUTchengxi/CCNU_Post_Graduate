#include <stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} *Stack, *Node;

Stack stack;

void push(int data) {
    Node node = (Node) malloc(sizeof(Node));
    node->data = data;
    node->next = stack->next;
    stack->next = node;
}

Node pop() {
    Node node = stack->next;
    stack = stack->next;
    return node;
}

/**
 * optOne token optTwo
 * @param optOne
 * @param optTwo
 * @param token
 * @return
 */
int operator(int intTwo, int intOne, char *token) {

    if(*token == '+') {
        return intOne + intTwo;
    }
    if(*token == '-') {
        return intOne - intTwo;
    }
    if(*token == '*') {
        return  intTwo * intOne;
    }
    return intOne / intTwo;
}

/**
 * operator check
 * @param token
 * @return 1: true   2: false
 */
int operatorCheck(char token) {

    if(token == '+' || token == '-' || token == '*' || token == '/') {
        return 1;
    }
    return 2;
}

/**
 * 逆波兰表达式求值
 * https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/submissions/
 * @param tokens
 * @param tokensSize
 * @return
 */
int evalRPN(char ** tokens, int tokensSize){

    int idx;
    for(idx = 0; idx < tokensSize; idx++) {
        if(operatorCheck(*tokens[idx]) == 1) {
            push(operator(pop()->data, pop()->data, tokens[idx]));
            continue;
        }
        push(*tokens[idx] - '0');
    }
    return pop()->data;
}

int main() {

    stack = (Stack) malloc(sizeof(Stack));

    // 模拟数据
    char **tokens;
    int tokensSize = 5;
    tokens = (char**) malloc(sizeof(char *) * tokensSize);
    int idx = 0;
    char c1 = '2', c2 = '1', c3 = '+', c4 = '3', c5 = '*';
    tokens[idx++] = &c1;
    tokens[idx++] = &c2;
    tokens[idx++] = &c3;
    tokens[idx++] = &c4;
    tokens[idx++] = &c5;
    printf("result is %d\n", evalRPN(tokens, tokensSize));

    return 0;
}