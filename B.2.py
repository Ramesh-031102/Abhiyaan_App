# Pothole detection
import cv2
import numpy as np

def getcontours(img):
    contours,hierarchy = cv2.findContours(img,cv2.RETT_EXTERNAL,cv2.CHAIN_APPROX_NONE)
    for count in contours:
        area = cv2.contourArea(count)
        peri = cv2.arcLength(count,True)
        if area > 800 and area < 1000 and peri > 100 and peri < 140:
            cv2.drawContours(contour,count,-1,[30,50,25],3)

vid = cv2.VideoCapture()
cv2.namedWindow('video',cv2.WND_PROP_FULLSCREEN)
cv2.setWindowProperty('video',cv2.WND_PROP_FULLSCREEN,cv2.WINDOW_FULLSCREEN)

while True:
    ret,image=vid.read()
    img=cv2.resize(image,(640,480))
    imgGray=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    imgblur=cv2.GaussianBlur(imgGray,(8,8),2.5)
    _,thrsh=cv2.threshold(imgblur,140,255,0)
    contour=img.copy()
    getcontours(thrsh)
    cv2.imshow('video',contour)
    if cv2.waitKey(1) & 0xFF==ord('q'):
        break