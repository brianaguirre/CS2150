; Brian Aguirre
; ba5bx
; threexplusone.s
; 11/18/2014


; RECURSIVE COLLATZ CONJECTURE:
; The file is separated into 4 components:
; There is the general calling convention in which variables are created
; and the registers are backed up, and then the two cases are defined.
; Case 1: x = 1 - simply returns 0 and then exits
; Case 2: x % 2 == 0, then this computes  x/2, recursively and calls back the function
; which either jumps to Case 2 again or Case 3:
; Case 3: x % 2 == 1, then this computes 3*x + 1, recursively then calling back the function
; which either jumps back to Case 3 again or Case 2:

;Optimization:
;Using bitshift instead of breaking it down in order to divide
;Allows for a quick way to see if the remainder in eax is even or odd
;Also combined lines and in order to better see what was happening but Also
;to not be redundant in terms of instructions/calculations.

global threexplusone
section .text

threexplusone:			;PART 1: GENERAL CALLING CONVENTION:
	push ebp 			;old base pointer
	mov esp, ebp		;new base pointer

	mov eax, [0] 		;set eax to 0
	mov eax, [esp + 4] 	;parmeter x 
	mov edi, eax 		;saving eax (backing it up) in edi

	cmp eax, 1 			;CASE 1: if (x == 1) - One
	je 	xiseven 		;Base Case

	shr eax, 1 			;CASE 2: if (x%2 == 0) - Even
	jnc xiseven 		;if no remainder, jump to the even cases
	mov eax, edi		;reset x after dividing by 2 to test if even
	jmp xisodd				;else CASE 3: if (x%2 == 1) - Odd



xisone:
	mov eax, 0 			;return 0
	ret

xiseven:
	mov eax, edi 		;Get x before the div by 2 (bit shift)
	push eax 			;push x	
	call threexplusone 	;recursive call back to see if 1, even, or odd
	inc eax 			;eax++: increment count of steps

	ret 				;return value

xisodd:
	mov eax, edi 		;Get x before the div by 2 (bit shift)
	imul eax, 3 		;3*x 
	add eax, 1 			;3*x + 1
	push eax
	call threexplusone  ;recursive call back to see if 1, even, or odd
	inc eax 			;eax++: increment count of steps
	jmp end


end:
	mov esp, ebp 		
	pop ebp
	ret
