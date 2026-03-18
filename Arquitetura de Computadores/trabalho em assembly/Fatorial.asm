.data
    inicio:  .asciiz "Digite um numero para calcular o fatorial: "
    resultado:  .asciiz "O fatorial e: "

.text
    li $v0, 4 
    la $a0, inicio  
    syscall

    li $v0, 5      
    syscall
    move $a0, $v0  

    jal fatorial

    li $v0, 4
    la $a0, resultado
    syscall

    li $v0, 1
    move $a0, $v1
    syscall

    li $v0, 10   
    syscall

fatorial:
    li $v1, 1     
    beq $a0, $zero, fim
    beq $a0, 1, fim

    loop:
        mul $v1, $v1, $a0
        addi $a0, $a0, -1
        bnez $a0, loop

    fim:
    jr $ra
