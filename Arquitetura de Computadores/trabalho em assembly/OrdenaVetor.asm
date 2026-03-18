.data
vetor:  .word 0:5
inicio: .asciiz "Digite o valor:"
endl:   .asciiz "\n"

.text  
    jal entradaValores
    jal ordenaValores
    jal imprimeValoresOrdenados
   
    li $v0, 10
    syscall

entradaValores:
    li $t0, 0
    la $t1, vetor 

loopEntrada:
    beq $t0, 5, saidaEntrada
    li $v0, 4
    la $a0, inicio
    syscall
    
    li $v0, 5
    syscall
    sw $v0, ($t1) 
    addi $t0, $t0, 1 
    addi $t1, $t1, 4 
    j loopEntrada 

saidaEntrada:
    jr $ra

ordenaValores:
    li $t0, 0 

loopExterno:
    beq $t0, 4, saidaOrdenacao
    li $t2, 0 
    la $t1, vetor 
    
loopInterno:
    beq $t2, 4, atualizaContadores
    lw $t3, ($t1) 
    lw $t4, 4($t1) 
    ble $t3, $t4, semTroca
    sw $t4, ($t1)
    sw $t3, 4($t1)
    
semTroca:
    addi $t1, $t1, 4
    addi $t2, $t2, 1
    j loopInterno
    
atualizaContadores:
    addi $t0, $t0, 1
    j loopExterno

saidaOrdenacao:
    jr $ra

imprimeValoresOrdenados:
    li $t0, 0
    la $t1, vetor
    
loopImpressao:
    beq $t0, 5, saidaImpressao
    lw $a0, ($t1)
    li $v0, 1
    syscall
    
    li $v0, 4
    la $a0, endl
    syscall
    
    addi $t0, $t0, 1
    addi $t1, $t1, 4
    j loopImpressao
    
saidaImpressao:
    jr $ra
