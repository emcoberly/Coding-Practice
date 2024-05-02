#.data
#firstNumber:  .asciiz   "Enter first number: "
#secondNumber: .asciiz   "Enter second number: "

# assume $a0 and $a1 hold the numbers
.text
.globl main

main:
    addi $a0, $zero, 5
    addi $a1, $zero, 3

setup:
    add $t0, $zero, $a0   # $t0 = m
    add $t2, $zero, $a1   # $t2 = r
    xor $t1, $a0, -1
    addi $t1, $t1, 1      # $t1 = -m
    add  $t9, $zero, $zero# $t9 keps track of iterations i

    sll $s0, $t0, 24      # $s0 = A(m)
    sll $s1, $t1, 24      # $s1 = S(m)
    sll $t0, $t2, 16      # $t0 = P(r)

    # save numbers to compare for last digit + extra digit

    addi $s2, $zero, 1
    sll  $s3, $s2, 15     # $s3 compares to 01

    sll  $s2, $s2, 16     # $s2 compares to 10

    add  $s4, $s3, $s2    # $s4 = 11 shifted and is used for AND later for the above comparisons

booth:
    slti $t8, $t9, 8      # $t8 holds i < 8 bits
    beq  $t8, $zero, exit # exit if i == 8
    add  $t1, $zero, $t0  # $t1 holds a copy of P(r) for comparison
    and  $t1, $t1, $s4    # shift to match either 01 or 10
    beq  $t1, $s3, addp
    beq  $t1, $s2, addn
    b    shift

addp:
    add  $t0, $t0, $s0    # P(r) + A(m)
    b shift

addn:
    add  $t0, $t0, $s1    # P(r) + S(m)
    b shift

shift:
    slt  $t8, $t0, $zero  # check for sign extension
    srl  $t0, $t0, 1      # shift P(r) once
    addi $t9, $t9, 1      # increment i
    bne  $t8, $zero, sign
    b booth

sign:
    or   $t0, $t0, $s2    # sign extend
    b booth


exit:
    addi $t1, $t1, -1
    srl  $t1, $t1, 8      # for chopping off all but 8 bits (overflow), doesn't work with 16
    srl  $t0, $t0, 16     # move results down to 8 bits
    and  $t0, $t0, $t1    # t0 holds the final value
    addi $v0, $zero, 10
    syscall
