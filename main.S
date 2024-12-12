.data
array:  .word  1, -3, 4, -2, 6, -7,   
        .word 8, -9, 10, -11, 12, -13, 
        .word 14, 15, -16, -17, 18, -19, 
        .word 20, -21, 22, 23, -24, 25,
        .word -26, 27, 28, -29, 30, -31
newline: .asciiz "\n"               
pos_count: .word 0                  
neg_count: .word 0                  

.text
.globl main

# Функция для подсчёта положительных чисел
count_positive:
        la t0, array               
        li t1, 30                  
        li t2, 0                    
        li t6, 0                   
loop_positive:
        lw t5, 0(t0)                
        addi t0, t0, 4              
        bgez t5, increment_positive 
        j next_positive
increment_positive:
        addi t6, t6, 1              
next_positive:
        addi t2, t2, 1              
        bne t2, t1, loop_positive   
        jr ra                       

# Функция для подсчёта отрицательных чисел
count_negative:
        la t0, array                
        li t1, 30                   
        li t2, 0                    
        li t6, 0                    
loop_negative:
        lw t5, 0(t0)                
        addi t0, t0, 4              
        bltz t5, increment_negative 
        j next_negative
increment_negative:
        addi t6, t6, 1              
next_negative:
        addi t2, t2, 1              
        bne t2, t1, loop_negative   
        jr ra                       

main:       
        jal count_positive
        la t3, pos_count            
        sw t6, 0(t3)             
        
        jal count_negative
        la t4, neg_count            
        sw t6, 0(t4)                
        
        li a0, 1                    
        lw a1, 0(t3)                
        ecall

        li a0, 4                    
        la a1, newline              
        ecall
      
        li a0, 1                    
        lw a1, 0(t4)                
        ecall

        li a0, 4                    
        la a1, newline             
        ecall

        li a0, 10                   
        ecall
