include junks.inc
	.code
	;handling all movements in game
	move proc
	invoke resetBall
	invoke moveTheBallX
	invoke moveTheBallY
	invoke moveBall
	invoke moveRack, offset racket
	invoke moveRack2, offset racket2
	invoke resetPoints
	invoke accalerateBall



	

	ret
	move endp

	


	
	

	
	

	


	
