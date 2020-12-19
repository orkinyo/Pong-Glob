include drd.inc
includelib drd.lib
include funcs.inc


.code
;handles drawing the points of the right racket
drawPointsRight proc

cmp rack2Points,0
	je drawZeroRight
	cmp rack2Points,1
	je drawOneRight
	cmp rack2Points,2
	je drawTwoRight
	cmp rack2Points,3
	je drawThreeRight
	cmp rack2Points,4
	je drawFourRight

	drawZeroRight:
	invoke drd_imageDraw,offset res.zeroCopy,512,10
ret
drawOneRight:
	invoke drd_imageDraw,offset res.oneCopy,512,10
ret
drawTwoRight:
	invoke drd_imageDraw,offset res.twoCopy,512,10
ret
drawThreeRight:
	invoke drd_imageDraw,offset res.threeCopy,512,10
ret
drawFourRight:
	invoke drd_imageDraw,offset res.fourCopy,512,10
ret


drawPointsRight endp


;handles drawing the points of the left racket
drawPointsLeft proc
	cmp rackPoints,0
	je drawZeroLeft
	cmp rackPoints,1
	je drawOneLeft
	cmp rackPoints,2
	je drawTwoLeft
	cmp rackPoints,3
	je drawThreeLeft
	cmp rackPoints,4
	je drawFourLeft

	
ret

drawZeroLeft:
	invoke drd_imageDraw,offset res.zero,450,10
ret
drawOneLeft:
	invoke drd_imageDraw,offset res.one,450,10
ret
drawTwoLeft:
	invoke drd_imageDraw,offset res.two,450,10
ret
drawThreeLeft:
	invoke drd_imageDraw,offset res.three,450,10
ret
drawFourLeft:
	invoke drd_imageDraw,offset res.four,450,10
ret



drawPointsLeft endp

;loads all the pictures
load proc
	invoke drd_init,1000,500,0
	invoke drd_imageLoadFile, offset res.bgpath, offset res.bg
	invoke drd_imageLoadFile, offset res.bluepath, offset res.blue
	invoke drd_imageLoadFile, offset res.racketpath, offset res.racket1
	invoke drd_imageLoadFile, offset res.racketpath, offset res.racket2
	invoke drd_imageLoadFile, offset res.zeroPath, offset res.zero
	invoke drd_imageLoadFile, offset res.onePath, offset res.one
	invoke drd_imageLoadFile, offset res.twoPath, offset res.two
	invoke drd_imageLoadFile, offset res.threePath, offset res.three
	invoke drd_imageLoadFile, offset res.fourPath, offset res.four
	invoke drd_imageLoadFile, offset res.zeroCopyPath, offset res.zeroCopy
	invoke drd_imageLoadFile, offset res.oneCopyPath, offset res.oneCopy
	invoke drd_imageLoadFile, offset res.twoCopyPath, offset res.twoCopy
	invoke drd_imageLoadFile, offset res.threeCopyPath, offset res.threeCopy
	invoke drd_imageLoadFile, offset res.fourCopyPath, offset res.fourCopy
	invoke drd_imageLoadFile, offset res.dotsPath, offset res.dots
	invoke drd_imageLoadFile, offset res.boostPath, offset res.boost
	invoke drd_imageLoadFile, offset res.boostLeftPath, offset res.boostLeft
	invoke drd_imageLoadFile, offset res.OpeningScreen, offset res.OpScreen

	invoke drd_imageSetTransparent, offset res.zero,0ffffffh
	invoke drd_imageSetTransparent, offset res.one,0ffffffh
	invoke drd_imageSetTransparent, offset res.two,0ffffffh
	invoke drd_imageSetTransparent, offset res.three,0ffffffh
	invoke drd_imageSetTransparent, offset res.four,0ffffffh
	invoke drd_imageSetTransparent, offset res.zeroCopy,0ffffffh
	invoke drd_imageSetTransparent, offset res.oneCopy,0ffffffh
	invoke drd_imageSetTransparent, offset res.twoCopy,0ffffffh
	invoke drd_imageSetTransparent, offset res.threeCopy,0ffffffh
	invoke drd_imageSetTransparent, offset res.fourCopy,0ffffffh
	invoke drd_imageSetTransparent, offset res.dots,0ffffffh
	invoke drd_imageSetTransparent, offset res.boost,0ffffffh
	invoke drd_imageSetTransparent, offset res.boostLeft,0ffffffh



		ret
	load endp

	update proc
	invoke drd_processMessages


	ret
	update endp

	;draws all the objects on the screen
	draw proc
	
			invoke drd_pixelsClear,0
									
			invoke drd_imageDraw, offset res.bg,0,0
			invoke drd_imageDraw, offset res.racket1,racket.pos.x,racket.pos.y
			invoke drd_imageDraw, offset res.racket2,racket2.pos.x,racket2.pos.y
			invoke drd_imageDraw, offset res.blue, posXBall, posYBall 
			invoke drd_imageDraw, offset res.dots,496,10
			invoke drd_imageDraw, offset res.boost,200,0
			invoke drd_imageDraw, offset res.boost,200,400
			invoke drd_imageDraw, offset res.boost,200,200
			invoke drd_imageDraw, offset res.boostLeft,740,0
			invoke drd_imageDraw, offset res.boostLeft,740,200
			invoke drd_imageDraw, offset res.boostLeft,740,400

			invoke drawPointsLeft
			invoke drawPointsRight
			invoke drd_flip
			

		


	ret
	draw endp


	drawOpScreen proc
		invoke drd_pixelsClear,0
		invoke drd_imageDraw, offset res.OpScreen,0,0
		
		ret	
	drawOpScreen endp








	;handles movment ingame
	movementManager proc
	invoke move
	invoke Sleep,5
	


	ret
	movementManager endp

