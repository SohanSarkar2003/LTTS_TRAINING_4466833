#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>


typedef struct {
    int type;   
                
    void* data; 
} UndoOp;

int main() {
    int Q;
    scanf("%d", &Q);

    
    char* S = malloc(1000001);
    S[0] = '\0';
    int s_len = 0;

    
    UndoOp* undo_stack = malloc(Q * sizeof(UndoOp));
    int stack_top = -1;
    
   
    char W_buffer[1000001];

    for (int i = 0; i < Q; ++i) {
        int type;
        scanf("%d", &type);

        switch (type) {
            case 1: { 
                scanf("%s", W_buffer);
                int w_len = strlen(W_buffer);

                
                stack_top++;
                undo_stack[stack_top].type = 1;
                undo_stack[stack_top].data = (void*)(uintptr_t)w_len;

                
                memcpy(S + s_len, W_buffer, w_len);
                s_len += w_len;
                S[s_len] = '\0';
                break;
            }
            case 2: { 
                int k;
                scanf("%d", &k);

                
                char* deleted_str = malloc(k + 1);
                memcpy(deleted_str, S + s_len - k, k);
                deleted_str[k] = '\0';

                
                stack_top++;
                undo_stack[stack_top].type = 2;
                undo_stack[stack_top].data = (void*)deleted_str;

                
                s_len -= k;
                S[s_len] = '\0';
                break;
            }
            case 3: { 
                int k;
                scanf("%d", &k);
                
                printf("%c\n", S[k - 1]);
                break;
            }
            case 4: { 
                if (stack_top > -1) {
                    UndoOp op = undo_stack[stack_top--];

                    if (op.type == 1) { 
                        int len_to_delete = (int)(uintptr_t)op.data;
                        s_len -= len_to_delete;
                        S[s_len] = '\0';
                    } else { 
                        char* str_to_append = (char*)op.data;
                        int append_len = strlen(str_to_append);
                        
                        memcpy(S + s_len, str_to_append, append_len);
                        s_len += append_len;
                        S[s_len] = '\0';
                        
                        
                        free(str_to_append);
                    }
                }
                break;
            }
        }
    }

    
    free(S);
    for(int j = 0; j <= stack_top; j++) {
        if(undo_stack[j].type == 2) {
            free(undo_stack[j].data);
        }
    }
    free(undo_stack);
    
    return 0;
}
