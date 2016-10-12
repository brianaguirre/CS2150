; Brian Aguirre Parada
; ba5bx
; mathlib.s
; November 05, 2014 


; POWER METHOD
; Calculates a number raised to another number
; a ^ b

global power
section .text

power:
    ; prologue
    push    ebp             ;Old base pointer
    mov     ebp, esp        ;New values for the pointers   


    push    ebx             ;Needed registers for loop
    push    esi     
    push    edi 

    mov ebx, [ebp + 8]      ; sets eax to int a
    mov esi, [ebp + 12]     ; sets esi to int b
    xor     eax, eax        ; clears eax to 0

    cmp     esi, 1
    jnle    loop_power      ; Note: a^0 = 1, and a^1 = a, so will keep looping only if b > 1

    cmp     esi, 1          ; a ^ 1 = a, so if (b == 1) return a
    jne     loop_power      ; continue loop if (b > 1) 
    mov     eax, ebx        ; moves the calculated int to eax
    jmp     pwr_complete    ; calculations complete

loop_power:
    dec     esi             ; b--
    push    ebx             ; push a
    push    esi             ; push b
    call    power           ; recursion of the itself
    pop     esi             ; reset esi
    pop     ebx             ; reset ebx
    push    eax             ; recursion variable
    push    ebx             ; push a
    call    product         ; prduct of the recursion: a * power(ebx, esi)  
    mov     edi, eax        ; temp value stored in edi
    pop     eax             
    mov     eax, edi        ; eax gets the return value of the calculation
    pop     ebx

pwr_complete:
    ; epilogue
    pop     edi             ; restores registers
    pop     esi
    pop     ebx
    pop     ebp
    ret

global product
section .text

;PRODUCT METHOD
;Logic provided by TA - Will
product:
    ; prologue
    push    ebp             ;Old base pointer
    mov     ebp, esp    
    push    edx             ; edx will store int a
    push    esi             ; esi will store int b

    ;Values for loop
    xor     eax, eax        ; sets eax to 0, will be the total
    mov     edx, [ebp+8]    ; sets edx to int a
    mov     esi, [ebp+12]   ; sets esi to int b

    cmp esi, 0              ; for > 0 cases
    je  prdct_complete        ; if b == 0, jump to end

loop_product:
    add     eax, edx        ; add a to running total
    dec     esi             ; decrement b 
    cmp     esi, 0
    jg      loop_product    ; if b > 0, jump to start of loop

prdct_complete:
    ;will come here once b b == 0
    ;prduct is complete and restore registers that were used
    ; epilogue
    pop     esi     ;retores where b was stored
    pop     edx     ;restores where a was stored
    pop     ebp  
    ret
